import bpy
from bpy.props import IntProperty, FloatProperty
import mathutils
import bmesh
from bpy_extras import view3d_utils


class ModalSelectOperator(bpy.types.Operator):
    """Move an object with the mouse, example"""
    bl_idname = "object.modal_select_operator"
    bl_label = "Simple Modal Select Operator"

    def modal(self, context, event):
        min_dist = 10
        ob = context.active_object
        region = context.region
        region_3d = context.space_data.region_3d
        found = False
        dest_e = None
        
        if event.type == 'MOUSEMOVE':
            mouse_pos = mathutils.Vector(event.mouse_region_x, event.mouse_region_y)
            for e in self.edges:
                v1 = e.verts[0]
                v2 = e.verts[1]
                world_v1 = ob.matrix_world * v1.co.copy()
                world_v2 = ob.matrix_world * v2.co.copy()
                screen_v1 = view3d_utils.location_3d_to_region_2d(region, region_3d, world_v1)
                screen_v2 = view3d_utils.location_3d_to_region_2d(region, region_3d, world_v2)
                dir = mathutils.Vector(screen_v1 - screen_v2)
                pdist = mathutils.Vector(mouse_pos - screen_v1)
                dist = pdist.cross(dir).length() / dir.length()
                if dist < min_dist:
                    min_dist = dist
                    dest_e = e
                    found = True
                    
            if found:
                #handle the loop sel here
                e_set = {}
                e_set = walker(self.edge, 0, e_set, dest_e)
                for e in e_set:
                    e.select = True
            context.object.update()

        elif event.type == 'LEFTMOUSE':
            bpy.data.meshes[context.object.name].update()
            return {'FINISHED'}

        elif event.type in {'RIGHTMOUSE', 'ESC'}:
            bpy.data.meshes[context.object.name].update()
            return {'CANCELLED'}

        return {'RUNNING_MODAL'}

    def invoke(self, context, event):
        if context.object:
            self.obj = context.object
            self.bm = bmesh.from_edit_mesh(self.obj.data)
            edge = [e for e in self.bm.edges if e.select]
            if len(edge) > 1:
                self.report({'WARNING'}, "More than one edge selected, not support yet")
            self.edge = edge[0]
            self.edges, self.is_loop = get_loop_edges(self.edge)
            context.window_manager.modal_handler_add(self)
            return {'RUNNING_MODAL'}
        else:
            self.report({'WARNING'}, "No active object, could not finish")
            return {'CANCELLED'}
    
    @classmethod
    def poll(cls, context):
        ob = context.active_object
        return (ob and ob.type == 'MESH' and context.mode == 'EDIT_MESH')
    
    
#util funcs
def get_loop_edges(e):
    e_set = set()
    is_loop = walker(e, 0, e_set)
    if is_loop:
        return e_set, is_loop
    else:
        walker(e, 1, e_set) 
    return list(e_set), is_loop       
        
def walker(e, dir, s, end=None):
    l = e.link_loops[dir]
    is_loop = False
    while len(l.face.edges) == 4:
        side = l.link_loop_next
        if side.link_loop_radial_next == side:
            is_loop = False
            break
        side = side.link_loop_radial_next
        edge = side.link_loop_next.edge
        l = edge.link_loops[dir]
        if edge in s:
            is_loop = True
            break
        else:
            s.add(edge)
        if end and edge == end:
            break
        
    return is_loop


def register():
    bpy.utils.register_class(ModalSelectOperator)


def unregister():
    bpy.utils.unregister_class(ModalSelectOperator)


if __name__ == "__main__":
    register()

    # test call
    bpy.ops.object.modal_select_operator('INVOKE_DEFAULT')

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
            mouse_pos = mathutils.Vector((event.mouse_region_x, event.mouse_region_y))
            print(mouse_pos)
            for elist in self.edges:
                for e in elist:
                    v1 = e.verts[0]
                    v2 = e.verts[1]
                    world_v1 = ob.matrix_world * v1.co.copy()
                    world_v2 = ob.matrix_world * v2.co.copy()
                    screen_v1 = view3d_utils.location_3d_to_region_2d(region, region_3d, world_v1)
                    screen_v2 = view3d_utils.location_3d_to_region_2d(region, region_3d, world_v2)
                    dir = mathutils.Vector(screen_v1 - screen_v2)
                    pdist = mathutils.Vector(mouse_pos - screen_v1)
                    dist = pdist.cross(dir) / dir.length
                    if dist < min_dist:
                        min_dist = dist
                        dest_e = e
                        found = True
                    
            if found:
                #handle the loop sel here
                for elist in self.edges:
                    for e in elist:
                        e.select = False
                e_set = []
                loop_dir = self.get_loop_dir(self.is_loop, dest_e)
                walker(self.edge, loop_dir, e_set, dest_e)
                for e in e_set:
                    e.select = True
            bpy.data.meshes[context.object.name].update()

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
            self.un_edges = [[], []]
            self.default_dir = 0
            context.window_manager.modal_handler_add(self)
            return {'RUNNING_MODAL'}
        else:
            self.report({'WARNING'}, "No active object, could not finish")
            return {'CANCELLED'}
        
    def get_loop_dir(self, is_loop, dest_e):
        if is_loop:
            return self.default_dir
        if dest_e in self.edges[0]:
            return 1
        else:
            return 0
    
    @classmethod
    def poll(cls, context):
        ob = context.active_object
        return (ob and ob.type == 'MESH' and context.mode == 'EDIT_MESH')
    
    
#util funcs
def get_loop_edges(e):
    e_set1 = []
    e_set2 = []
    is_loop = walker(e, 0, e_set1)
    if is_loop:
        return [e_set1], is_loop
    else:
        walker(e, 1, e_set2) 
    return [e_set1, e_set2], is_loop    
        
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
            s.append(edge)
        if end and edge.index == end.index:
            print('reach end')
            break
        
    return is_loop


def register():
    bpy.utils.register_class(ModalSelectOperator)


def unregister():
    bpy.utils.unregister_class(ModalSelectOperator)


if __name__ == "__main__":
    register()
    #unregister()
    # test call
    #bpy.ops.object.modal_select_operator('INVOKE_DEFAULT')


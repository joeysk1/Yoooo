import bpy
from bpy.props import IntProperty, FloatProperty
import bmesh
import mathutils
import copy


class FoldOperator(bpy.types.Operator):
    """Move an object with the mouse, example"""
    bl_idname = "object.fold_operator"
    bl_label = "Fold Operator"

    #first_mouse_x = IntProperty()
    #first_mouse_y = IntProperty()
    first_valuex = FloatProperty()
    first_valuey = FloatProperty()

    def modal(self, context, event):
        if event.type == 'MOUSEMOVE':
            #deltax = self.first_mouse_x - event.mouse_x
            #deltay = self.first_mouse_y - event.mouse_y
            #context.object.location.x = self.first_valuex + deltax * 0.01
            #context.object.location.y = self.first_valuey + deltay * 0.01
            self.move_sel(context, event, self.vert_sel)
            bpy.data.meshes[self.obj.name].update()

        elif event.type == 'LEFTMOUSE':
            return {'FINISHED'}

        elif event.type in {'RIGHTMOUSE', 'ESC'}:
            #context.object.location.x = self.first_value
            for i in range(len(self.first_pos)):
                self.vert_sel[i].co = self.first_pos[i]
            return {'CANCELLED'}

        return {'RUNNING_MODAL'}

    def invoke(self, context, event):
        #print 'in invoke'
        if context.object:
            self.first_mouse_x = event.mouse_x
            self.first_mouse_y = event.mouse_y
            self.first_value = context.object.location.x
            self.obj = context.active_object
            self.bm = bmesh.from_edit_mesh(context.active_object.data)
            self.vert_sel = [v for v in self.bm.verts if v.select]
            self.first_pos = [v.co for v in self.vert_sel]
            self.first_pos = copy.deepcopy(self.first_pos)

            context.window_manager.modal_handler_add(self)
            return {'RUNNING_MODAL'}
        else:
            self.report({'WARNING'}, "No active object, could not finish")
            return {'CANCELLED'}
        
    @classmethod
    def poll(cls, context):
        # check we are in mesh editmode
        ob = context.active_object
        return(ob and ob.type == 'MESH' and context.mode == 'EDIT_MESH')
    
    def move_sel(self, context, event, vert_sel):
        deltax = self.first_mouse_x - event.mouse_x
        deltay = self.first_mouse_y - event.mouse_y
        for i in range(len(self.vert_sel)):
        #for vert in self.vert_sel:
            self.vert_sel[i].co = self.first_pos[i] + mathutils.Vector((deltax * 0.001, deltay * 0.001, 0.0))


def register():
    bpy.utils.register_class(FoldOperator)


def unregister():
    bpy.utils.unregister_class(ModalOperator)


if __name__ == "__main__":
    register()

    # test call
    bpy.ops.object.fold_operator('INVOKE_DEFAULT')


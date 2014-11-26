import bpy
from bpy.props import IntProperty, FloatProperty
import bmesh


class ModalSelectOperator(bpy.types.Operator):
    """Move an object with the mouse, example"""
    bl_idname = "object.modal_select_operator"
    bl_label = "Simple Modal Select Operator"

    def modal(self, context, event):
        if event.type == 'MOUSEMOVE':
            pass

        elif event.type == 'LEFTMOUSE':
            return {'FINISHED'}

        elif event.type in {'RIGHTMOUSE', 'ESC'}:
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
            self.loop = get_loop_edges(edge)

            context.window_manager.modal_handler_add(self)
            return {'RUNNING_MODAL'}
        else:
            self.report({'WARNING'}, "No active object, could not finish")
            return {'CANCELLED'}
    
    @classmethod
    def poll(cls, context):
        ob = context.active_object
        return (ob and ob.type == 'MESH' and context.mode == 'EDIT_MESH')


def register():
    bpy.utils.register_class(ModalOperator)


def unregister():
    bpy.utils.unregister_class(ModalOperator)


if __name__ == "__main__":
    register()

    # test call
    bpy.ops.object.modal_operator('INVOKE_DEFAULT')


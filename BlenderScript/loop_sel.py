# This example assumes we have a mesh object selected

import bpy
import bmesh

C = bpy.context
obj = C.active_object
bm = bmesh.from_edit_mesh(obj.data)

edges = [e for e in bm.edges if e.select]
e = edges[0]

def loop_sel_test(stae):
    side = stae.link_loops[1].link_loop_next
    side = side.link_loop_radial_next
    next = side.link_loop_next.edge
    next.select = True
    for m in bpy.data.meshes:
        m.update()
        
def walker(loop):
    ori = loop
    dir = 0
    while len(loop.face.edges) == 4:
        side = loop.link_loop_next
        if side.link_loop_radial_next == side:
            if dir < 1:
                dir += 1
                loop = ori
                side = loop.link_loop_next
            else:
                return
        side = side.link_loop_radial_next
        edge = side.link_loop_next.edge
        loop = edge.link_loops[dir]
        yield edge
        
def loop_sel(edge):
    loop1 = edge.link_loops[0]
    loop2 = edge.link_loops[1]
    es = walker(loop1)
    for e in es:
        e.select = True
    es = walker(loop2)
    for e in es:
        e.select = True
    for m in bpy.data.meshes:
        m.update()

#add comment  
loop_sel(e)

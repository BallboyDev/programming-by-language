from point import *
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

def draw():
    #glLineWidth(GLfloat(6.0))
    glBegin(GL_LINES)
    # glColor3fv((1.0, 1.0, 1.0))
    # glColor3fv((0.5, 0.5, 0.5))
    glColor3fv((0.0, 0.0, 0.0))

        # global pulse_color
        # glColor3fv((pulse_color[0], pulse_color[1], pulse_color[2]))
        #
        # global pulse_val
        #
        # if pulse_color[0] > 1:
        #     pulse_val = -0.04
        # elif pulse_color[0] <= 0.0:
        #     pulse_val = 0.04
        #
        # for i in range(3):
        #     pulse_color[i] += pulse_val

    for axis in edge_pieces:
        for piece in axis:
            for edge in cube_edges:
                for vertex in edge:
                    glVertex3fv(piece[vertex])
    for piece in center_pieces:
        for edge in cube_edges:
            for vertex in edge:
                glVertex3fv(piece[vertex])
    for piece in corner_pieces:
        for edge in cube_edges:
            for vertex in edge:
                glVertex3fv(piece[vertex])
    glEnd()

draw()

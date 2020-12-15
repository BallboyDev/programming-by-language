import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *



def Cube():
    verticies = (
        (1, -1, -1),
        (1, 1, -1),
        (-1, 1, -1),
        (-1, -1, -1),
        (1, -1, 1),
        (1, 1, 1),
        (-1, -1, 1),
        (-1, 1, 1)
        )

    edges = (
        (0, 1),
        (0, 3),
        (0, 4),
        (2, 1),
        (2, 3),
        (2, 7),
        (6, 3),
        (6, 4),
        (6, 7),
        (5, 1),
        (5, 4),
        (5, 7)
        )
    glRotatef(89, 1, 0, 0)
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(verticies[vertex])
    glEnd()

def main():
    pygame.init()
    # 라이브러리 초기화를 하지 않을 경우 일부 기능이 정상 작동하지 않을 수 있다.
    
    display = (800, 600)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)
    # 화면 해상도를 800, 600으로 초기화
    # FULLSCREEN : 전체 화면 모드를 사용
    # HWSURGACE : 하드웨어 가속 사용, 전체 화면 모드에서만 가능
    # OPENGL : OpenGL 사용 가능한 디스플레이를 초기화
    # DOUBLEBUF : 더블 버퍼 모드를 사용, HWSURFACE or OPENGL 에서 사용을 추천

    gluPerspective(60, (display[0]/display[1]), 0.1, 50.0)
    # gluPerspective(시야각, 종횡비, 근거리 클리핑 평면 위치, 원거리 클리핑 평면위치)

    glTranslatef(0.0, 0.0, -10)
    # 우리의 시선의 위치(x, y, z)

    glRotatef(90, 1, 0, 0)
    # 순서대로 각도, x, y, z의 값
    # 즉 , (3, 1, 1) 위치를 중심으로 화면의 모든 물체를 1도씩 외전시킨다.

    while True:
        for event in pygame.event.get():
            # 이벤트를 처리하는 부분
            # -> 키보드, 마우스 등의 이벤트 처리 코드가 들어감
            
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.K_SPACE:
                glRotatef(90, 1, 0, 0)

        #glRotatef(5, 0, 0, 0)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        # OpenGL의 모든 버퍼를 비웁니다. 즉 이는 이전에 그렸던 물체들에 대한 정보를 제거하게 됩니다.
        Cube()
        pygame.display.flip()
        pygame.time.wait(10)

main()

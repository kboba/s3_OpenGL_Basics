//#include <GL/glut.h>
#include <stdlib.h>
#include <iostream> 
#include "gl/include/glut.h"
#include "gl/include/glu.h"
#include "gl/include/gl.h"

// wp�rz�dne po�o�enia obserwatora
GLdouble eyex = 0;
GLdouble eyey = 0;
GLdouble eyez = 3;

// wsp�rz�dne punktu w kt�rego kierunku jest zwr�cony obserwator,
GLdouble centerx = 0;
GLdouble centery = 0;
GLdouble centerz = -100;

// k�t obrotu
double angle = 0;

// funkcja generuj�ca scen� 3D
void Display()
{
    // kolor t�a - zawarto�� bufora koloru
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // czyszczenie bufora koloru
    glClear(GL_COLOR_BUFFER_BIT);
    // wyb�r macierzy modelowania
    glMatrixMode(GL_MODELVIEW);
    // macierz modelowania = macierz jednostkowa
    glLoadIdentity();
    // ustawienie obserwatora
    gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, 0, 1, 0);
    // obr�t wok� osi
    glRotatef(angle, 1.0, 1.0, 1.0);

    // pocz�tek definicji kraw�dzi sze�cianu
    glBegin(GL_LINES);
    // kolor kraw�dzi sze�cianu
    glColor3f(0.0, 0.0, 1.0);
    // wsp�lrz�dne kolejnych kraw�dzi sze�cianu
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    // koniec definicji sze�cianu
    glEnd();
    // skierowanie polece� do wykonania
    glFlush();
    // zamiana bufor�w koloru
    glutSwapBuffers();
}

// zmiana wielko�ci okna
void Reshape(int width, int height)
{
    // obszar renderingu - ca�e okno
    glViewport(0, 0, width, height);

    // wyb�r macierzy rzutowania
    glMatrixMode(GL_PROJECTION);

    // macierz rzutowania = macierz jednostkowa
    glLoadIdentity();

    // parametry bry�y obcinania
    glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 5.0);

    // generowanie sceny 3D
    Display();
}

// obs�uga klawiatury
void Keyboard(unsigned char key, int x, int y)
{
    // klawisz +
    if (key == '+')
        eyez -= 0.1;
    else

        // klawisz -
        if (key == '-')
            eyez += 0.1;

        else if (key == 'w')
            eyey -= 0.1; // do stuff
        else if (key == 'a')
            eyex += 0.1; // do other stuff
        else if (key == 's')
            eyey += 0.1;
        else if (key == 'd')
            eyex -= 0.1;

    // odrysowanie okna
    Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obs�uga klawiszy funkcyjnych i klawiszy kursora
void SpecialKeys(int key, int x, int y)
{
    switch (key)
    {
        // kursor w lewo
    case GLUT_KEY_LEFT:
        eyex += 0.1;
        break;

        // kursor w g�r�
    case GLUT_KEY_UP:
        eyey -= 0.1;
        break;

        // kursor w prawo
    case GLUT_KEY_RIGHT:
        eyex -= 0.1;
        break;

        // kursor w d�
    case GLUT_KEY_DOWN:
        eyey += 0.1;
        break;
    }

    // odrysowanie okna
    Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// rotator, kt�ry obraca figure co okre�lony czas
void rotator(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, rotator, 0);
    angle += 0.3;
    if (angle > 360.0)
        angle = angle - 360.0;
}

int main(int argc, char* argv[])
{
    // Inicjalizacja biblioteki glut, kt�ra tworzy okienko z poziomu OpenGL
    // inicjalizacja biblioteki GLUT
    glutInit(&argc, argv);
    // Ustawienie trybu kolor�w RGBA oraz podw�jnego buforowania
    // inicjalizacja bufora ramki
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    // rozmiary g��wnego okna programu
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(400, 200);
    // Stworzenie okna
    // utworzenie g��wnego okna programu
    glutCreateWindow("PO - Lab11 - sze�cian");
    // Zarejestrowanie funkcji zwrotnych
    // do��czenie funkcji generuj�cej scen� 3D
    glutDisplayFunc(Display);
    // glutIdleFunc(Display);            niepotrzebne?
    // do��czenie funkcji wywo�ywanej przy zmianie rozmiaru okna
    glutReshapeFunc(Reshape);
    // do��czenie funkcji obs�ugi klawiatury
    glutKeyboardFunc(Keyboard);
    // do��czenie funkcji obs�ugi klawiszy funkcyjnych i klawiszy kursora
    glutSpecialFunc(SpecialKeys);
    // do��czenie funkcji obracania naszego sze�cianu
    glutTimerFunc(0, rotator, 0);
    //Uruchamianie g��wnej p�tli OpenGL
    // wprowadzenie programu do obs�ugi p�tli komunikat�w
    glutMainLoop();
    return 0;
}

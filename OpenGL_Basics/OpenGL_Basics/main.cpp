//#include <GL/glut.h>
#include <stdlib.h>
#include <iostream> 
#include "gl/include/glut.h"
#include "gl/include/glu.h"
#include "gl/include/gl.h"

// wpó³rzêdne po³o¿enia obserwatora
GLdouble eyex = 0;
GLdouble eyey = 0;
GLdouble eyez = 3;

// wspó³rzêdne punktu w którego kierunku jest zwrócony obserwator,
GLdouble centerx = 0;
GLdouble centery = 0;
GLdouble centerz = -100;

// k¹t obrotu
double angle = 0;

// funkcja generuj¹ca scenê 3D
void Display()
{
    // kolor t³a - zawartoœæ bufora koloru
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // czyszczenie bufora koloru
    glClear(GL_COLOR_BUFFER_BIT);
    // wybór macierzy modelowania
    glMatrixMode(GL_MODELVIEW);
    // macierz modelowania = macierz jednostkowa
    glLoadIdentity();
    // ustawienie obserwatora
    gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, 0, 1, 0);
    // obrót wokó³ osi
    glRotatef(angle, 1.0, 1.0, 1.0);

    // pocz¹tek definicji krawêdzi szeœcianu
    glBegin(GL_LINES);
    // kolor krawêdzi szeœcianu
    glColor3f(0.0, 0.0, 1.0);
    // wspólrzêdne kolejnych krawêdzi szeœcianu
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
    // koniec definicji szeœcianu
    glEnd();
    // skierowanie poleceñ do wykonania
    glFlush();
    // zamiana buforów koloru
    glutSwapBuffers();
}

// zmiana wielkoœci okna
void Reshape(int width, int height)
{
    // obszar renderingu - ca³e okno
    glViewport(0, 0, width, height);

    // wybór macierzy rzutowania
    glMatrixMode(GL_PROJECTION);

    // macierz rzutowania = macierz jednostkowa
    glLoadIdentity();

    // parametry bry³y obcinania
    glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 5.0);

    // generowanie sceny 3D
    Display();
}

// obs³uga klawiatury
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

// obs³uga klawiszy funkcyjnych i klawiszy kursora
void SpecialKeys(int key, int x, int y)
{
    switch (key)
    {
        // kursor w lewo
    case GLUT_KEY_LEFT:
        eyex += 0.1;
        break;

        // kursor w górê
    case GLUT_KEY_UP:
        eyey -= 0.1;
        break;

        // kursor w prawo
    case GLUT_KEY_RIGHT:
        eyex -= 0.1;
        break;

        // kursor w dó³
    case GLUT_KEY_DOWN:
        eyey += 0.1;
        break;
    }

    // odrysowanie okna
    Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// rotator, który obraca figure co okreœlony czas
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
    // Inicjalizacja biblioteki glut, która tworzy okienko z poziomu OpenGL
    // inicjalizacja biblioteki GLUT
    glutInit(&argc, argv);
    // Ustawienie trybu kolorów RGBA oraz podwójnego buforowania
    // inicjalizacja bufora ramki
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    // rozmiary g³ównego okna programu
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(400, 200);
    // Stworzenie okna
    // utworzenie g³ównego okna programu
    glutCreateWindow("PO - Lab11 - szeœcian");
    // Zarejestrowanie funkcji zwrotnych
    // do³¹czenie funkcji generuj¹cej scenê 3D
    glutDisplayFunc(Display);
    // glutIdleFunc(Display);            niepotrzebne?
    // do³¹czenie funkcji wywo³ywanej przy zmianie rozmiaru okna
    glutReshapeFunc(Reshape);
    // do³¹czenie funkcji obs³ugi klawiatury
    glutKeyboardFunc(Keyboard);
    // do³¹czenie funkcji obs³ugi klawiszy funkcyjnych i klawiszy kursora
    glutSpecialFunc(SpecialKeys);
    // do³¹czenie funkcji obracania naszego szeœcianu
    glutTimerFunc(0, rotator, 0);
    //Uruchamianie g³ównej pêtli OpenGL
    // wprowadzenie programu do obs³ugi pêtli komunikatów
    glutMainLoop();
    return 0;
}

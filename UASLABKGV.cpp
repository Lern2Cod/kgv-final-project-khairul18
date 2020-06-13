#include <Windows.h>
#include <glut.h>

int w = 1000, h = 1000, z = -200;
int x1 = 0, y1 = 0, sudut = 0, z1 = 0;

void rumah() {
    glTranslatef(0, 0, 0);
    glPushMatrix();
    glColor3ub(254, 222, 173);  //alas
    glTranslatef(-10, -15, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(5, 5, 0.1);
    glutSolidCube(28);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);  //kabah utama
    glTranslatef(-10, 5, 0);
    glScalef(2, 2, 2);
    glutSolidCube(22.45);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 200, 0); //matahari
    glTranslatef(80, 70, -15);
    glutSolidSphere(8, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(201, 161, 50);  //headband
    glTranslatef(-10, 17, 0);
    glScalef(3, 0.3, 3);
    glutSolidCube(15);
    glPopMatrix();

    glTranslatef(0, 0, 0);
    glPushMatrix();
    glColor3ub(201, 161, 50);  //pintu
    glTranslatef(-23.6, -3, 22.8);
    glScalef(1.9, 3.2, 0);
    glutSolidCube(5);
    glPopMatrix();

   
}







void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(10, 0, z);
    glRotatef(sudut, x1, y1, z1);
    rumah();
    glutSwapBuffers();
}

void resize(int w1, int h1) {
    glViewport(0, 0, w1, h1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myKeyboard(unsigned char key, int x, int y) {
    if (key == '=')
        z += 5;
    else if (key == '-')
        z -= 5;
    else if (key == 'y') {
        x1 = 1;
        y1 = 0;
        z1 = 0;
        sudut += 10;
    }
    else if (key == 't') {
        x1 = 1;
        y1 = 0;
        z1 = 0;
        sudut += -10;
    }
    else if (key == 'x') {
        x1 = 0;
        y1 = 1;
        z1 = 0;
        sudut += -10;
    }
    else if (key == 'c') {
        x1 = 0;
        y1 = 1;
        z1 = 0;
        sudut += 10;
    }
    else if (key == 'z') {
        x1 = 0;
        y1 = 0;
        z1 = 1;
        sudut += -10;
    }
}

void init() {
    glClearColor(180, 100, 100, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("uaskgv");
    gluOrtho2D(-w, w, -h, h);
    glutDisplayFunc(renderScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(myKeyboard);
    glutIdleFunc(idle);
    init();
    glutMainLoop();
}
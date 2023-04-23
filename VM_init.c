#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
extern GLfloat xrot;
extern GLfloat yrot;
GLfloat zscale=-50.0;
GLfloat yscale=0.0;
GLfloat xscale=0.0;

void VM_init(void)
{
    // Effacer le fond d'écran en utilisant glClear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Charger la matrice identité en utilisant glLoadIdentity
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glTranslatef(0,0,zscale);
    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
} 

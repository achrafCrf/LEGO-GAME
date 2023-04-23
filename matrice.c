#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "opmat.h"
#include "math.h"

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

GLvoid Modelisation()
{
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

  glPushMatrix();
  {
    // Ceci, qui n'utilise pas les primitives de calcul d'OpenGL
    GLfloat * rot = rotation_x(M_PI/4.0);
    GLfloat * trans = translation(0.0,1.0,0.0);
    GLfloat * res = mxm(trans, rot);
    glMultMatrixf(res);

    // est identique à 
    /* glTranslatef(0.0,1.0,0.0); */
    /* glRotatef(45.0, 1.0, 0.0, 0.0); */
    // Rotation du cube sur lui-même de x de 45° selon l'axe (PI/4) puis translation de 1.0 selon l'axe des y
    glutSolidCube(0.5);
  }
  glPopMatrix();


  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}

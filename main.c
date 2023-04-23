#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

// #include "init.c"

GLfloat xrot = 0.0f;
GLfloat yrot = 0.0f;
// GLfloat z = -5.0f;
GLfloat rot = 0.0f;
GLfloat angle = 0;
GLfloat anglex = 0;
GLfloat angley = 0;
GLfloat anglez = 0;
GLfloat locx = 0;
GLfloat locy = 0;
GLfloat locz = 0;
GLfloat xLego1 = -30;
GLfloat yLego1 = 3.0;
GLfloat zLego1 = 30;
GLfloat rLego1 = 0;
GLfloat xLego2 = 0.0;
GLfloat yLego2 = 0.0;
GLfloat zLego2 = 0.0;
GLfloat rLego2 = 0.0;
GLfloat articule1 = 0.0;
GLfloat articule2 = 0.0;


extern GLuint textures[1];

void mouvement(){
    static int direction = 1;
    
    articule1 += direction * 5.0f;
    
    if (articule1 >= 45.0f) {
        direction = -3;
    } else if (articule1 <= -45.0f) {
        direction = 3;
    }
}

void mouvement2(){
    static int direction2 = 1;
    
    articule2 += direction2 * 5.0f;
    
    if (articule2 >= 45.0f) {
        direction2 = -1;
    } else if (articule2 <= -45.0f) {
        direction2 = 1;
    }
}



void LEGO(GLint lx, GLint ly, GLint lz, GLint ax, GLint ay, GLint az,GLfloat articule)
{
    glPushMatrix();
    {
        GLfloat pos[] = {1.0, 0., 0., 1.};
        GLfloat pos0[] = {1.0, 0., 0., 0.};

        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glLightfv(GL_LIGHT0, GL_POSITION, pos0);
        GLfloat shininess_or = 51.2;
        glMaterialfv(GL_FRONT, GL_SHININESS, &shininess_or);
        // // Reculer la caméra pour voir le LEGO dans son ensemble
        glTranslatef(lx, ly, lz);
        glRotated(ax, 1, 0, 0);
        glRotated(ay, 0, 1, 0);
        glRotated(az, 0, 0, 1);

        // Dessiner le LEGO en plusieurs parties
        glPushMatrix(); // Matrice pour la tête et le visage
{
    glTranslatef(0.0, 0.7, 0.0);
    // chapeau
    glPushMatrix();
    {
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.0, 0.1, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glutSolidCylinder(0.2, 0.2, 25, 20);
    }
    glPopMatrix();
    // Dessiner la tête cylindrique
    glPushMatrix();
    {
        glColor3f(1.0, 1.0, 1.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glutSolidCylinder(0.4, 0.6, 25, 20);
    }
    glPopMatrix();

    // Dessiner les yeux
    glPushMatrix();
    {
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(-0.2, -0.2, 0.4);
        glutSolidSphere(0.08, 10, 10);
        glTranslatef(0.4, 0.0, 0.0);
        glutSolidSphere(0.08, 10, 10);
    }
    glPopMatrix();

    // Dessiner la bouche souriante
    glPushMatrix();
    {
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.4, 0.5);
        glRotatef(30.0, 1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(-0.1, 0.0, 0.0);
        glVertex3f(0.1, 0.0, 0.0);
        glEnd();
    }
    glPopMatrix();

    glPushMatrix(); // Matrice pour le cou
    {
        // Dessiner le cylindre du cou
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.0, -0.3, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glutSolidCylinder(0.3, 0.4, 20, 20);
    }
    glPopMatrix(); // Fin de la matrice pour le cou
}
glPopMatrix(); // Fin de la matrice pour la tête et le visage

        // Dessiner le corps principal
        glPushMatrix();
        {
            //   glColor3f(1.0, 1.0, 0.0);
            glColor3f(1.0, 1.0, 1.0);
            glTranslatef(0.0, -0.5, 0.0);
            glScalef(1.0, 1.0, 1.0);
            glutSolidCube(1.0);
        }
        glPopMatrix();

        // Dessiner les épaules et les bras
        glPushMatrix();
        {
            glColor3f(0.0, 0.0, 1.0);
            glTranslatef(-0.75, -0.5, 0.0);
            // Épaule gauche
            glPushMatrix();
            {
                glTranslatef(0.0, 0.5, 0.0);
                glScalef(0.5, 0.5, 1.0);
                glutSolidSphere(0.5, 20, 20);
                glRotated(-articule, 1, 0, 0);

                // Bras gauche
                glPushMatrix();
                {
                    glTranslatef(0.0, -1.0, 0.0);
                    glScalef(0.5, 2.0, 0.5);
                    glutSolidCube(1.0);
                }
                glPopMatrix();
            }
            glPopMatrix();

            // Épaule droite
            glPushMatrix();
            {
                glTranslatef(1.5, 0.5, 0.0);
                glScalef(0.5, 0.5, 1.0);
                glutSolidSphere(0.5, 20, 20);
                glRotated(articule, 1, 0, 0);
                // Bras droit
                glPushMatrix();
                {
                    glTranslatef(0.0, -1.0, 0.0);
                    glScalef(0.5, 2.0, 0.5);
                    glutSolidCube(1.0);
                }
                glPopMatrix();
            }
            glPopMatrix();
        }
        glPopMatrix();
        glPushMatrix();
        {
            glColor3f(1.0, 1.0, 1.0);

            // Jambe gauche
            glPushMatrix();
            {
                glTranslatef(-0.3, -1.75, 0.0);
                glRotated(articule, 1, 0, 0);
                glScalef(0.5, 2.0, 1.0);
                glutSolidCube(0.7);

                // Pied gauche
                glPushMatrix();
                {

                    glTranslatef(0.0, -0.3, 0.0);
                    glScalef(0.5, 0.4, 1.0);
                    glutSolidSphere(0.5, 20, 20);
                }
                glPopMatrix();
            }
            glPopMatrix();

            // Jambe droite
            glPushMatrix();
            {
                glTranslatef(0.3, -1.75, 0.0); // modifier la position pour la jambe droite
                glRotated(-articule, 1, 0, 0);

                glScalef(0.5, 2.0, 1.0);
                glutSolidCube(0.7);

                // Pied droit
                glPushMatrix();
                {
                    glTranslatef(0.0, -0.3, 0.0);
                    glScalef(0.5, 0.5, 1.0);
                    glutSolidSphere(0.5, 20, 20);
                }
                glPopMatrix();
            }
            glPopMatrix();
        }
        glPopMatrix();
    }
    glPopMatrix();
}

GLvoid Modelisation()
{

    VM_init();
    mouvement2();
    GLfloat couleurs[] = {0.5, 0.1, 5.1, 5.4};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, couleurs);
    // Positionnement de la caméra
    gluLookAt(0, 20, 65, 0, 0, 0, 0, 1, 0);
  // Affichage du texte en haut du lego
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(-15, 20 , 0);
  char* message = "Appuyez sur Z/Q/S/D ou <-/^/->/v pour bouger";
  for (int i = 0; message[i] != '\0'; i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
  }
    // Couleur du sol : gris
    glColor3f(0.5, 0.5, 0.5);
// printf("%f",xLego1);
// printf("%f",zLego1);
    if (zLego1 == 31 && xLego1 < 30)
    {
        rLego1 = 90;
        if (xLego2 < xLego1 || xLego1 + 0.5 < xLego2 || zLego1 != zLego2)
            xLego1 += 0.25f;
    }
    else if (xLego1 == 30 && zLego1 > -17)
    {
        rLego1 = 180;
        if (zLego2 > zLego1 || zLego1 - 0.5 > zLego2 || xLego1 != xLego2)
            zLego1 -= 0.25f;
    }
    else
    {
        if (zLego1 == -17 && xLego1 > -30)
        {
            rLego1 = 270;
            if (xLego2 > xLego1 || xLego1 - 0.5 > xLego2 || zLego1 != zLego2)
                xLego1 -= 0.25f;
        }
        else if (xLego1 == -30 && zLego1 < 31)
        {
            rLego1 = 0;
            if (zLego2 < zLego1 || zLego1 + 0.2 < zLego2 || xLego1 != xLego2)
                zLego1 += 0.25f;
        }
    }

    LEGO(xLego1, yLego1, zLego1, 0, rLego1, 0,articule2);
    LEGO(xLego2, 3.0, zLego2+7.0, 0, rLego2, 0,articule1);
    glPushMatrix();
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        glTranslated(0, -20, -1.0);
        glScaled(66, 35, 52);
        glBegin(GL_QUADS);
        // Face avant
        glNormal3f(0.0, 0.0, 1.0);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, 0.5f);

        // Face arrière
        glNormal3f(0.0, 0.0, -1.0);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.5f, 0.5f, -0.5f);

        // Face gauche
        glNormal3f(-1.0, 0.0, 0.0);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, -0.5f);

        // Face droite
        glNormal3f(1.0, 0.0, 0.0);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        // Face haut
        glNormal3f(0.0, 1.0, 0.0);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, -0.5f);

        // Face bas
        glNormal3f(0.0, -1.0, 0.0);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
    // axes();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    return notre_init(argc, argv, &Modelisation);
}
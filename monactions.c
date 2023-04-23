#include "monactions.h"
#include <GL/glut.h>

// extern GLfloat zscale;

extern int blend;
extern int light;
extern GLfloat angle;
extern GLfloat xscale;
extern GLfloat yscale;
extern GLfloat zscale;
extern GLint locx;
extern GLint locy;
extern GLint locz;
extern GLfloat xLego2;
extern GLfloat yLego2;
extern GLfloat zLego2;
extern GLfloat rLego2;

void touche_pressee(unsigned char key, int x, int y)
{
  usleep(100);

  switch (key)
  {
  case ESCAPE:

    exit(1);
    break;

  case ESPACE:

    break;

  case TOUCHE_MIN_B:
      // mouvement de saut
    for (int i = 0; i < 3; i++) {
      yLego2 += 3.0;
      mouvement();
      usleep(100000);
    }
    for (int i = 0; i < 3; i++) {
      yLego2 -= 3.0;
      mouvement();
      usleep(100000);
    }
    break;
  case TOUCHE_MAJ_B:
    blend = switch_blend(blend);
    break;

  case TOUCHE_MIN_L:
  case TOUCHE_MAJ_L:
  case TOUCHE_MIN_Z:
    rLego2 = 180;
    if (zLego2 > -17)
    {
      zLego2 -= 0.25f;
    }
    mouvement();
    break;
    break;
  case TOUCHE_MIN_S:
    rLego2 = 0;
    if (zLego2 < 23)
    {
      zLego2 += 0.25f;
    }
    mouvement();
    break;
  case TOUCHE_MIN_Q:
    rLego2 = 270;
    if (xLego2 > -30)
    {
      xLego2 -= 0.25f;
    }
    mouvement();

    break;
  case TOUCHE_MIN_D:
    rLego2 = 90;
    if (xLego2 < 30)
    {
      xLego2 += 0.25f;
    }
    mouvement();

    break;
  }
}
void touche_speciale(int touche, int x, int y)
{
  switch (touche)
  {
  case GLUT_KEY_PAGE_UP:
    --zscale;
    printf("%f",zscale);
    angle += 5.0;
    break;
  case GLUT_KEY_PAGE_DOWN:
    ++zscale;
    break;
  case GLUT_KEY_UP:
    rLego2 = 180;
    if (zLego2 > -23)
    {
      zLego2 -= 0.25f;
    }
    mouvement();
    break;
  case GLUT_KEY_DOWN:
    rLego2 = 0;
    if (zLego2 < 23)
    {
      zLego2 += 0.25f;
    }
    mouvement();
    break;
  case GLUT_KEY_LEFT:
    rLego2 = 270;
    if (xLego2 > -30)
    {
      xLego2 -= 0.25f;
    }
    mouvement();

    break;
  case GLUT_KEY_RIGHT:
    rLego2 = 90;
    if (xLego2 < 30)
    {
      xLego2 +=0.25f;
    }
    mouvement();

    break;
  }
}

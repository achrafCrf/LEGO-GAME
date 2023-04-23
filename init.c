#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "monactions.h"
#include "ppm.h"
GLuint blend = 0;
GLuint light = 0;
GLuint textures[1];

GLvoid Redimensionne(GLsizei Width, GLsizei Height)
{
    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 500.0f);
    glMatrixMode(GL_MODELVIEW);
}
int notre_init(int argc, char **argv, void (*Modelisation)())
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1400, 1400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Notre Fenêtre");
    // Chaque fois l'utilisateur essai de dessiner,OpenGl appel  cette fonction
    glutDisplayFunc(Modelisation);
    // Quand il ya plus d'evenement utilisateurs on attente
    glutIdleFunc(Modelisation);
    // Quand on change la taille de la fenetre du cq OpenGl appelle cette fontion pour redimensionez la scene 3d
    glutReshapeFunc(&Redimensionne);
    // l'utilisateur appuie sur une touche du clavier. Cela permet de capturer les entrées clavier et de les utiliser pour contrôler la scène 3D.
    glutKeyboardFunc(&touche_pressee);
    // La fonction de rappel définie dans glutSpecialFunc est appelée par GLUT lorsque l'utilisateur appuie sur une touche spéciale du clavier.
    glutSpecialFunc(&touche_speciale);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    /* Créer ce qui ne varie pas lors de la modélisation */
    glGenTextures(1, textures);
    TEXTURE_STRUCT *charingane = readPpm("charingane.ppm");
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, charingane->width, charingane->height, 0, GL_RGB, GL_UNSIGNED_BYTE, charingane->data);
    free(charingane->data);
    free(charingane);
    glutMainLoop();

    return 1;
}
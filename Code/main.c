/*
 * GL01Hello.cpp: Test OpenGL/GLUT C/C++ Setup
 * Tested under Eclipse CDT with MinGW/Cygwin and CodeBlocks with MinGW
 * To compile with -lfreeglut -lglu32 -lopengl32
 */
#include <GL/glu.h>
#include <GL/gl.h> 
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "functions.h"

GLfloat b = 0.0f;	// function multiplier
GLfloat aspect = 1.0f;
GLfloat aspecta = 1.0f;
GLfloat n = 1.0f;

void display(){

	glBegin(GL_LINES);
	// draw a semi-infinite center line
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.0f, 10000.0f );
	glVertex2f(0.0f, -10000.0f );

	glVertex2f(10000.0f, 0.0f);
	glVertex2f(-10000.0f, 0.0f);

	// draw the function

	glColor3f(1.0f, 0.0f, 0.0f);

	for(GLfloat a = -100.0f; a < 100.0f; a += 0.01f){
		GLfloat k = lefunccion(a, n);
		glVertex2f(a*aspecta, k*aspecta);
	}
	
	glColor3f(0.0f, 0.0f, 1.0f);
	for(GLfloat a = -100.0f; a < 100.0f; a += 0.01f){
		GLfloat k = lefunction2(a, n);
		glVertex2f(a*aspecta, k*aspecta);
	}

	glColor3f(1.0f, 1.0f, 1.0f);

	glEnd();
	glFlush();

}

void LeKeborde(int key){
	glClear(GL_COLOR_BUFFER_BIT);
	if(key == 119){
		glTranslatef(0.0f, -0.1f, 0.0f);
	}			
	else if(key == 97){
		glTranslatef(0.1f, 0.0f, 0.0f);

	}

	else if(key == 100){
		glTranslatef(-0.1f, 0.0f, 0.0f);
	}

	else if(key == 115){
		glTranslatef(0.0f, 0.1f, 0.0f);
	}

	else if(key == 32){
		b += 0.1f;
	}
	
	else if(key == 43){
		n += 0.1f;
	}

	else if(key == 45){
		n -= 0.1f;
	}
	glEnd();
}

void Timer(int value) {
	glutPostRedisplay();
	glLineWidth(aspect);
   	glutTimerFunc(100, Timer, 0); // next Timer call milliseconds later
}


void trapezoide(int button, int state, int x, int y){
    glClear(GL_COLOR_BUFFER_BIT);
	float mx = x ;
    	float my = y ;
    	GLfloat ox = (mx/500 -1.0);
    	GLfloat oy = -(my/500 -1.0);
	// 3 frente 
	// 4 tras
	if(button == 3){
		if(aspecta > 0){
			aspecta += 0.01;
		}
		aspect += 0.01;
	}
	else if(button == 4){
		if(aspecta > 0){
			aspecta -= 0.01;
		}
		aspect -= 0.01;
	}
	glEnd();

}


/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

   	glutInit(&argc, argv);                 // Initialize GLUTc
   	glutCreateWindow("Graphic Plotting"); // Create a window with the given title
   	glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
   	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   	glutDisplayFunc(display); // Register display callback handler for window re-paint
   	glutKeyboardFunc(LeKeborde);
	glutTimerFunc(0, Timer, 0);
	glutMouseFunc(trapezoide);
	glPointSize(0.2f);
   	glutMainLoop();           // Enter the event-processing loop
   	return 0;
}

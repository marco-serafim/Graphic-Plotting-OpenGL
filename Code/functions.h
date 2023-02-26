#include <stdio.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>

// ATTENTION!: B is a value that is changed by the user during the program.


GLfloat lefunccion(GLfloat x, GLfloat b){
    	GLfloat response = sin(x*b);	// function 1
	return response;
}

GLfloat lefunction2(GLfloat x, GLfloat b){
	GLfloat response = (2*x) * b;	// function 2	
	return response;
}

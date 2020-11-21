#include <stdio.h>
#include <GL/glut.h>


static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;

//------- custom functions starts -------
void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}
void reset()
{
	spin_x = 0;
	spin_y = 1;
	spin_z = 0;
	translate_x = 0.0;
	translate_y = 0.0;
	translate_z = -30.0;
}
//------- custom functions ends -------
void reshape(int w,int h)
{
	glViewport(0,0, (GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spinDisplay(void)
{
	spin=spin+spin_speed;
	if(spin>360.0)
	{
		spin=spin-360.0;
	}
	glutPostRedisplay();
}
void spinDisplayReverse(void)
{
	spin=spin-spin_speed;
	if(spin<360.0)
	{
		spin=spin+360.0;
	}
	glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_MIDDLE_BUTTON:
		if(state==GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(spinDisplayReverse);
		break;
	default:
		break;
	}
}
void keyboard(unsigned char key, int x, int y)
{
	//-------- spin --------
	if(key=='x')
	{
		setSpin(1.0,0.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='y')
	{
		setSpin(0.0,1.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='z')
	{
		setSpin(0.0,0.0,1.0);
		glutPostRedisplay();
	}
	else if(key=='a')
	{
		setSpin(1.0,1.0,1.0);
		glutPostRedisplay();
	}
	//-------- spin --------
	//-------- zoom --------
	else if(key=='i')
	{
		translate_z++;
		glutPostRedisplay();
	}
	else if(key=='o')
	{
		translate_z--;
		glutPostRedisplay();
	}
	//-------- zoom --------
	//-------- reset -------
	else if(key=='r')
	{
		reset();
		glutPostRedisplay();
	}
	else if(key=='l')
	{
		translate_x--;
		glutPostRedisplay();
	}//-------- reset -------
else if(key=='b')
	{
	translate_x++;
		glutPostRedisplay();
	}
else if(key=='u')
	{
	translate_y++;
		glutPostRedisplay();
	}
else if(key=='d')
	{
	translate_y--;
		glutPostRedisplay();
	}
else if(key=='g')
	{
	glColor3f( 0.0, 1.0, 0.0);
		glutPostRedisplay();
	}

}


// assuming work-window width=50unit, height=25unit;
void init()
{
	glClearColor(0,0,0,0);
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
}


void drawFan()
{
	glTranslatef(translate_x, translate_y, translate_z);

	glRotatef(spin,spin_x,spin_y,spin_z);



	glBegin(GL_TRIANGLES);
glEnable( GL_DEPTH_TEST );
	glColor3f( 1, 1, 0); // red
	//glColor3f(0.5, 0.5, 0.0);

	glVertex2i(1, 1);
	glColor3f( 1, 0.5, 0 ); // green
glVertex2i(-15, 15);
glColor3f( 1, 0, 1 ); // blue
	glVertex2i(30, 15);
		glEnd();

		glBegin(GL_TRIANGLES); //up
	glColor3f(1, 1, 0);
	glVertex2i(8,30 );
		glColor3f( 1, 0.5, 0 ); // green
glVertex2i(-5,25);
	glColor3f( 1, 0.5, 0 ); // green
	glVertex2i(30,30);
		glEnd();


		glBegin(GL_TRIANGLES); // down
	glColor3f(1, 1, 0.0);
	glVertex2i(2,2 );
		glColor3f( 1, 0, 1 ); // green
glVertex2i(18, -2);
	glColor3f( 1.0, 0.5, 0 ); // green

	glVertex2i(5, 8);
		glEnd();

		glBegin(GL_TRIANGLES);
	glColor3f(1,  1, 0);
	glVertex2i(30, 7);
		glColor3f( 1, 0, 1 ); // green
   glVertex2i(35,15);
   	glColor3f( 1, 0.5, 0 ); // green
	glVertex2i(30, 25);
		glEnd();



			glBegin(GL_TRIANGLES);
	//glColor3f(0.5, 0.5, 0.0);
		glColor3f( 1, 1, 0 ); // green
	glVertex2i(-16, 16);
		glColor3f( 1, 0.5, 0); // green
glVertex2i(0, 30);
	glColor3f( 1, 0, 1 ); // green
	glVertex2i(30,16);
		glEnd();



		glEnd();

}

void draw()
{

    glBegin(GL_QUADS);
	glColor3f(0.0, 1, 1); //   ll square
	glVertex2i(0, 0);
	glColor3f(0, 1, 1); //   ll square
glVertex2i(0, -300);
glColor3f(0.0, 1, 1); //   ll square
	glVertex2i(-300,0);






glBegin(GL_QUADS);
	glColor3f(0.0, 1, 1);// rigt squre
	glVertex2i(0, 0);
	glColor3f(0.0, 0, 1); //   ll square
glVertex2i(0, -300);
glColor3f(0.0, 1, 1); //   ll square
	glVertex2i(300,0);
	glEnd();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//******************************************//
	//------- custom code starts -------

	drawFan();

draw();
	//------- custom code ends -------
	//******************************************//
	glutSwapBuffers();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard and Mouse Interaction");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
}

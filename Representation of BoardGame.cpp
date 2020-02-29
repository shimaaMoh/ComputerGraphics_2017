#include <windows.h>  
#include <GL/glu.h> 
#include <glut.h>
#include <math.h>
#include <iostream>

using namespace std ;

GLfloat angleCube = 0.0;     
int refreshMills = 15 ;
float angle =0 ;
float  radius=5, xx1 =10 , yy1=0  ,t =0.0;
double move_y = 0; double move_x = 0;  double move_z = 0;
double mv_p = 0 ; 

void specialKeys( int key, int x, int y ) 
{
switch(key){
    case GLUT_KEY_RIGHT : 
        move_x++;  break ;
    case GLUT_KEY_LEFT :  
        move_x--;  break ;
    case GLUT_KEY_UP :
        move_y++;  break ;
    case GLUT_KEY_DOWN :  
        move_y--;  break ;
    case GLUT_KEY_F1 :  
        move_z--;  break ;
    case GLUT_KEY_F2 :  
        move_z ++; break ; 
    case GLUT_KEY_F3 :
    	mv_p +=4 ; break ;
    case GLUT_KEY_F4 :
    	mv_p-=4 ;  break ;  
    case GLUT_KEY_F5 :  
        move_x--;
	    move_z --;
		move_y --;  
        break ;
}
glutPostRedisplay();
}
void Display (void)
{
 //-------------------THE BOARD ---------------//
 glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //clear the buffers
 glMatrixMode(GL_MODELVIEW);                          //to choose "GL_MODELVIEW " as the current Matrix
 glLoadIdentity();                                    // Reset "GL_MODELVIEW " matrix
 glTranslatef(-1.0+move_x,5.0+move_y,-35.0+move_z);   // to move the entire board 
 glBegin(GL_QUADS);                                   // startig to bulid the board quad by quad 
   glColor3f (1.0 , 1.0 , 1.0);
   glVertex3f(5.0,-10.0,5.0);
   glVertex3f(-5.0,-10.0,5.0);
   glVertex3f(-5.0,-10.0,-20.0);
   glVertex3f(5.0,-10.0 ,-20.0); 
 glEnd();
 
 glBegin(GL_QUADS);
   glColor3f(0.16, 0.15, 0.16);
   glVertex3f(-5.0,-10.0,5.0);
   glVertex3f(-15.0,-10.0,5.0);
   glVertex3f(-15.0,-10.0,-20.0);
   glVertex3f(-5.0,-10.0 ,-20.0); 
 glEnd();
  
  
 glBegin(GL_QUADS);
    glColor3f (0.16, 0.15, 0.16);
    glVertex3f(15.0,-10.0,5.0);
    glVertex3f(5.0,-10.0,5.0);
    glVertex3f(5.0,-10.0,-20.0);
    glVertex3f(15.0,-10.0 ,-20.0); 
 glEnd();

 glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0 , 1.0);
    glVertex3f(15.0,-10.0,-20.0);
    glVertex3f(5.0,-10.0,-20.0);
    glVertex3f(5.0,-10.0,-45.0);
    glVertex3f(15.0,-10.0 ,-45.0); 
 glEnd();
 glBegin(GL_QUADS);
    glColor3f (0.16, 0.15, 0.16);
    glVertex3f(5.0,-10.0,-20.0);
    glVertex3f(-5.0,-10.0,-20.0);
    glVertex3f(-5.0,-10.0,-45.0);
    glVertex3f(5.0,-10.0 ,-45.0); 
 glEnd();
 glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0 , 1.0);
    glVertex3f(-5.0,-10.0,-20.0);
    glVertex3f(-15.0,-10.0,-20.0);
    glVertex3f(-15.0,-10.0,-45.0);
    glVertex3f(-5.0,-10.0 ,-45.0); 
 glEnd();
 //--------------------------- solid sphere as peice in the game -------------------------// 
  glColor3f (0.45, 0.2 , 0.29);
  glLoadIdentity();                                      //reset
  glTranslatef(-11.0+move_x,-3.0+move_y,-65.0+move_z);   //to move along with the board  
  glTranslatef(mv_p,0.0,mv_p);                           //to move on the boards separately 
  glutSolidSphere(2,20,20);                               
  
  //----------------------------------1st cube--------------------------------------------//
 glLoadIdentity();                                       //reset
 glTranslatef(5+move_x,10.0+move_y,-55.0+move_z);       //to move along with the board
 glScalef(0.18,0.18,0.18);                             //to resize the cube 
 glRotatef(angleCube, 10.0f, 10.0f, 10.0f);           // to rotate the cube 
 //front  panel         
 glBegin(GL_QUADS);                                   //starting to bulid the cube quad by quad
  // glNormal3f(0.0f, 0.0f, 1.0f);                       
   glColor3f (1.0 , 1.0 , 1.0); 
   glVertex3f(25.0,25.0,25.0);    
   glVertex3f(-25.0,25.0,25.0);
   glVertex3f(-25.0,-25.0,25.0);
   glVertex3f(25.0,-25.0,25.0);
 glEnd();
 
 //right panel
 glBegin(GL_QUADS);                                   
   glColor3f (0.45 , 0.29 , 0.32);
   glNormal3f(1.0f, 0.0f, 0.0f);
   glVertex3f(25.0,25.0 ,-25.0);  
   glVertex3f(25.0,25.0,25.0);
   glVertex3f(25.0,-25.0,25.0);
   glVertex3f(25.0,-25.0,-25.0);
 glEnd();
  //up panel
 glBegin(GL_QUADS);                                
   glColor3f (0.45 , 0.29 , 0.32);
   //glNormal3f(0.0f,1.0f,0.0f);
   glVertex3f(25.0,25.0,-25.0);
   glVertex3f(-25.0,25.0,-25.0);
   glVertex3f(-25.0,25.0,25.0);
   glVertex3f(25.0,25.0 ,25.0);  
 glEnd();
  //left panel
 glBegin(GL_QUADS);                              
   glColor3f (0.45 , 0.29 , 0.32);
   glNormal3f(-1.0f, 0.0f, 0.0f);
   glVertex3f(-25.0,25.0 ,25.0);
   glVertex3f(-25.0,25.0,-25.0);
   glVertex3f(-25.0,-25.0,-25.0);
   glVertex3f(-25.0,-25.0,25.0);
 glEnd();
  //down panel
 glBegin(GL_QUADS);                          
   glColor3f (0.45 , 0.29 , 0.32);
   glNormal3f(0.0f,-1.0f,0.0f);
   glVertex3f(25.0 ,-25.0,25.0);
   glVertex3f(-25.0,-25.0,25.0);
   glVertex3f(-25.0,-25.0 ,-25.0); 
   glVertex3f(25.0,-25.0,-25.0);
 glEnd(); 
 //back panel
 glBegin(GL_QUADS);                         
   glColor3f (1.0 , 1.0 , 1.0);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glVertex3f(25.0,-25.0 ,-25.0);
   glVertex3f(-25.0,-25.0,-25.0);
   glVertex3f(-25.0,25.0,-25.0);
   glVertex3f(25.0,25.0,-25.0);
 glEnd();
 //the circle at the front panel
 glPushMatrix();                                      
   glTranslatef(-10.0,0.0,25.80);
   glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);      //from the lab manual                   
     glVertex2f(xx1, yy1);
     for (angle=0;angle<=360;angle++) 
     {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius ); }
   glEnd();
 glPopMatrix();
  //the first circle at the back
 glPushMatrix();
   glTranslatef(-18.0,0.0,-25.8);       
   glColor3f (0.0 , 0.0 , 0.0);  
   glBegin(GL_TRIANGLE_FAN);
     glVertex2f(xx1, yy1);
     for (angle=0;angle<=360;angle++) 
     { glVertex2f( xx1+sin(angle)*radius, yy1+cos(angle)*radius);}
  glEnd();
 glPopMatrix();
  //the second circle at the back
 glPushMatrix();                      
   glTranslatef(-5.0,0.0,-25.8); 
   glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xx1, yy1);
    for (angle=0;angle<=360;angle++) 
    {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius);}
   glEnd();
   glPopMatrix();
 //------------------------------------------2nd cube---------------------------------------//
 glLoadIdentity();
 glTranslatef(-10.0 +move_x,8.0+move_y,-50.0+move_z);         //SAME AS THE 1ST CUBE 
 glScalef(0.17,0.17,0.17);                                    
 glRotatef(angleCube, 0.0f, -40.0f, 10.0f);
  //front 
  glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0 , 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);    
    glVertex3f(25.0,25.0,25.0);  
    glVertex3f(-25.0,25.0,25.0);
    glVertex3f(-25.0,-25.0,25.0);
    glVertex3f(25.0,-25.0,25.0);
  glEnd();
 
  //top panel
  glBegin(GL_QUADS);
    glColor3f (0.45 , 0.29 , 0.32);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(25.0,25.0,-25.0);
    glVertex3f(-25.0,25.0,-25.0);
    glVertex3f(-25.0,25.0,25.0);
    glVertex3f(25.0,25.0 ,25.0);  
  glEnd();
 //left panel
 glBegin(GL_QUADS);
   glColor3f (0.45 , 0.29 , 0.32);
   glNormal3f(-1.0f, 0.0f, 0.0f);
   glVertex3f(-25.0,25.0 ,25.0); 
   glVertex3f(-25.0,25.0,-25.0);
   glVertex3f(-25.0,-25.0,-25.0);
   glVertex3f(-25.0,-25.0,25.0);
 glEnd();
 //bottom
 glBegin(GL_QUADS);
   glColor3f (0.45 , 0.29 , 0.32);
   glNormal3f(0.0f, -1.0f, 0.0f);
   glVertex3f(25.0,-25.0,25.0);
   glVertex3f(-25.0,-25.0,25.0);
   glVertex3f(-25.0,-25.0 ,-25.0);  
   glVertex3f(25.0,-25.0,-25.0);
 glEnd(); 
 
 glBegin(GL_QUADS);//back
   glColor3f (1.0 , 1.0 , 1.0);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glVertex3f(25.0,-25.0 ,-25.0); 
   glVertex3f(-25.0,-25.0,-25.0);
   glVertex3f(-25.0,25.0,-25.0);
   glVertex3f(25.0,25.0,-25.0);
 glEnd();
 
 //right panel
  glBegin(GL_QUADS);
   glColor3f (0.45 , 0.29 , 0.32);
   glNormal3f(1.0f, 0.0f, 0.0f);
   glVertex3f(25.0,25.0 ,-25.0); 
   glVertex3f(25.0,25.0,25.0);
   glVertex3f(25.0,-25.0,25.0);
   glVertex3f(25.0,-25.0,-25.0);
  glEnd();
  
    //the three circles at the front panel
 glPushMatrix();
   glTranslatef(-15.0,-8.0,25.9);
   glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(xx1, yy1);
   for (angle=0;angle<=360;angle++) 
    {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius );}
   glEnd();
   glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-15.0,13.0,25.9);
 glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(xx1, yy1);
    for (angle=0;angle<=360;angle++) 
    {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius );}
   glEnd();
 glPopMatrix();

 glPushMatrix();
 glTranslatef(2.0,2.0,25.9);
 glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(xx1, yy1);
    for (angle=0;angle<=360;angle++) 
    {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius );}
 glEnd();
 glPopMatrix();
 
   //the four circles at the back
   glTranslatef(-15.0,5.0,-25.8);  
   glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(xx1, yy1);
    for (angle=0;angle<=360;angle++) 
    {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius );}
   glEnd();
   
 
 glPushMatrix();
   glTranslatef(16.0,5.0,0.0); 
   glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(xx1, yy1);
    for (angle=0;angle<=360;angle++) 
    {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius );}
   glEnd();
   glPopMatrix();
 
 glPushMatrix();
   glTranslatef(16.0,-10.0,0.5); 
   glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(xx1, yy1);
    for (angle=0;angle<=360;angle++) 
    {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius ); }
   glEnd();
 glPopMatrix();


 glPushMatrix();
   glTranslatef(0.0,-13.0,0.5); 
   glColor3f (0.0 , 0.0 , 0.0); 
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(xx1, yy1);
    for (angle=0;angle<=360;angle++) 
    {glVertex2f(xx1+sin(angle)*radius, yy1+cos(angle)*radius ); }
   glEnd();
 glPopMatrix(); 

  
  
//------------------------------------------LIGHT---------------------------------------// 
 //Add ambient light
 GLfloat ambientColor[] = {1.0, 1.0, 1.0, 0.0};                //light of the whole scene
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
 
 //Add positioned light
 GLfloat lightColor0[] = {0.55, 0.23, 0.33, 0.0f};                    
 GLfloat lightPos0[] = {-10.0f, 0.0f, 0.0f, 1.0f};              //Positioned at (-10,0,0)
 glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);    
 glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
 
 //Add directed light
 GLfloat lightColor1[] = {0.92, 0.92, 0.92, 0.0f}; 
 //Coming from the direction (0 ,-10 ,0 )
 GLfloat lightPos1[] = {0.0f, -10.0f, 0.0f, 0.0f};
 glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
 glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
 
 glFlush();                                        //to make the drawing appear on the screen
 glutSwapBuffers();                               // becase we're using double buffering
 
 angleCube += 0.15f;
  
}


void timer(int value) {
   glutPostRedisplay();                    // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

void init (void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);     //specify the background color which is black
  glClearDepth(1.0) ;                      
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);           
  glEnable(GL_LIGHTING);                  //Enable lighting
  glEnable(GL_LIGHT0);                    //Enable light 0
  glEnable(GL_LIGHT1);                    //Enable light 1
  glEnable(GL_NORMALIZE);               
  glDepthFunc(GL_LEQUAL);                 
  glShadeModel(GL_SMOOTH);                // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT ,GL_NICEST);  
  
}

 
void reshape(GLsizei width, GLsizei height) {  
    // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height ;
   glViewport(0, 0, width, height);           // Set the viewport to cover the new window
 
   // Set the aspect ratio of the clipping volume to match the viewport
   
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective(45.0f, aspect, 0.1f, 140.0f);
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);        // Initialize GLUT
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1024, 680);
    glutInitWindowPosition (50, 50);
    glutCreateWindow (" BOARD GAME ");
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    init ();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();            // Enter the infinite event-processing loop
return 0;
}

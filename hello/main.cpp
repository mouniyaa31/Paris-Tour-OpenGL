#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <cstdlib>
#include <cmath>
//#include <windows.h>
//
//using namespace std;
//int width=480;
//int height=640;
//
#define PI 3.14159265
#define CTRL_COUNT 100

bool nightLight;
bool sunrise=false;
//int lightColor={0,0,0};
void draw_cylinder(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B);
int ctrlPointsCount;
int ctrlPointsX[CTRL_COUNT], ctrlPointsY[CTRL_COUNT];
int X1[3]= {20,25,20}, Y1[3]= {5,24,38};
int X2[3]= {0,-5,0}, Y2[3]= {1,static_cast<int>(0.5),0};
int X3[3]= {22,0,18}, Y3[3]= {30,38,45};
int X4[3]= {28,50,32}, Y4[3]= {30,38,45};
int X5[3]= {18,25,32}, Y5[3]= {45,60,45};
double var = -6;
double rainX = -6;
double rainY;
bool VelocityUp=false;
bool freeze=false;
double SpeedUp;
double tree[3] = {34, 139, 34};
bool NightRain=false;

void tower(float x,float y, float s){
    
    
    
    glClearColor(0.8f, 0.93f,0.93f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
//    glMatrixMode(GL_PROJECTION);              // setup viewing projection
//    glLoadIdentity();                           // start with identity matrix
//    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
    
    
//    //sky
//    glBegin(GL_POLYGON);
//    glColor3f(0.28f,0.84f,0.82f);
//    glVertex3f(x+10.0*s, y+10.0*s, 0.0);
//    glVertex3f(x+0.0*s, y+10.0*s, 0.0);
//    glColor3f(0.28f,0.84f,1.0f);
//    glVertex3f(x+0.0*s, y+4.0*s, 0.0);
//    glVertex3f(x+10.0*s, y+4.0*s, 0.0);
//    glEnd();
//
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+5*s,y+8.5*s,0);
        glVertex3f(x+5*s,y+9.0*s,0);
    glEnd();
    
    //top
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(x+5.2*s, y+8.5*s, 0.0);
    glVertex3f(x+4.8*s, y+8.5*s, 0.0);
    glVertex3f(x+4.8*s, y+8*s, 0.0);
    glVertex3f(x+5.2*s, y+8*s, 0.0);
    glEnd();
    
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+4.8*s,y+8*s,0);
        glVertex3f(x+4.5*s,y+6*s,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+5.2*s,y+8*s,0);
        glVertex3f(x+5.5*s,y+6*s,0.0);
    glEnd();
    
    //cross
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+4.8*s,y+8*s,0);
        glVertex3f(x+5.5*s,y+6*s,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+5.2*s,y+8*s,0);
        glVertex3f(x+4.5*s,y+6*s,0.0);
    glEnd();
    
    //middle
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(x+5.5*s, y+6*s, 0.0);
    glVertex3f(x+4.5*s, y+6*s, 0.0);
    glVertex3f(x+4.5*s, y+5.5*s, 0.0);
    glVertex3f(x+5.5*s, y+5.5*s, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+4.5*s,y+5.5*s,0);
        glVertex3f(x+4*s,y+3.5*s,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+5.5*s,y+5.5*s,0);
        glVertex3f(x+6*s,y+3.5*s,0.0);
    glEnd();
    
    //center lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+5*s,y+5.5*s,0);
        glVertex3f(x+4.5*s,y+3.5*s,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+5*s,y+5.5*s,0);
        glVertex3f(x+5.5*s,y+3.5*s,0.0);
    glEnd();
    
    //lower
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(x+6.0*s, y+3.5*s, 0.0);
    glVertex3f(x+4.0*s, y+3.5*s, 0.0);
    glVertex3f(x+4.0*s, y+3.0*s, 0.0);
    glVertex3f(x+6.0*s, y+3.0*s, 0.0);
    glEnd();
    
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+4*s,y+3*s,0);
        glVertex3f(x+3.0*s,y+0.5*s,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+3.0*s,y+0.5*s,0);
        glVertex3f(x+4.0*s,y+0.5*s,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+4.0*s,y+0.5*s,0.0);
        glVertex3f(x+4.5*s,y+2.0*s,0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+4.5*s,y+2.0*s,0);
        glVertex3f(x+5.5*s,y+2.0*s,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+5.5*s,y+2.0*s,0.0);
        glVertex3f(x+6.0*s,y+0.5*s,0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+6.0*s,y+0.5*s,0);
        glVertex3f(x+7.0*s,y+0.5*s,0.0);
    glEnd();
    
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x+7.0*s,y+0.5*s,0);
        glVertex3f(x+6*s,y+3*s,0.0);
    glEnd();
    
    
  
    
    glFlush();

    
}
void drawTree()
{
    //Tree
    glColor3ub(tree[0], tree[1], tree[2]);

    glPushMatrix();
    glutSolidSphere(0.25,40,40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15,-0.15,0);
    glutSolidSphere(0.25,40,40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15,-0.15,0);
    glutSolidSphere(0.25,40,40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.3,0);
    glRotatef(90,1,0,0);
    draw_cylinder(0.04,0.7,137, 94, 41);
    glPopMatrix();
}

void draw_cylinder(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R,G,B);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 2*3.1416 )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*3.1416 )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

 int ib;
GLfloat twicePib = 2.0f * PI;
   int triangleAmountb = 20;
//
bool Rain = false;
bool night = false;

//colors  variables
double sky[3] = {19,190,242};
double cloud[3] = {255,255,255};
double sun[3] = {219,230,21};
double bush[3] = {127,162,12};
double water[3] = {152,222,245};


using namespace std;

double rain = 0;

float a=0.0,b=0.0,y=0.0;


void drawCloud()
{
    glutSolidSphere(0.4,40,40);
    glScalef(1,0.4,1);
    glTranslatef(-0.1,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(cloud[0], cloud[1], cloud[2]);
    glutSolidSphere(0.7,40,40);
}



void bezierCoefficients(int n,int *c)
{

    int k,i;
    for(k=0; k<=n; k++)
    {
        c[k]=1;
        for(i=n; i>=k+1; i--)
            c[k]*=i;
        for(i=n-k; i>=2; i--)
            c[k]/=i;
    }

}


void drawEllipse(void)
{
    GLint i;
    GLfloat xradius=3.5;
    GLfloat yradius=2;
    const GLfloat DEG2RAD = 3.14159/180;

    glColor3ub(23,145,62);

    glBegin(GL_POLYGON);
    for (i=0; i < 360; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex2f ( cos (degInRad) *xradius,  sin (degInRad) *yradius);
    }
    glEnd();
}

void drawRedEllipse(void)
{
    GLint i;
    GLfloat xradius=3.5;
    GLfloat yradius=2;
    const GLfloat DEG2RAD = 3.14159/180;

    glColor3ub(242,46,49);

    glBegin(GL_POLYGON);
    for (i=0; i < 360; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex2f ( cos (degInRad) *xradius,  sin (degInRad) *yradius);
    }
    glEnd();
}


void dp(GLint cx,GLint cy)
{

    glColor3ub(237,52,52);
    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    glEnd();

}

void pix(GLint h,GLint k,GLint x,GLint y)
{
    glColor3ub(237,52,52);
    dp(x+h,y+k);
    dp(x+h,-y+k);
    dp(-x+h,-y+k);
    dp(-x+h,y+k);
    dp(y+h,x+k);
    dp(y+h,-x+k);
    dp(-y+h,-x+k);
    dp(-y+h,x+k);

}

void cd(GLint h,GLint k,GLint r)
{
    glColor3ub(237,52,52);
    GLint d=1-r,x=0,y=r;
    while(y>x)
    {
        pix(h,k,x,y);
        if(d<0)
            d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    pix(h,k,x,y);
}


void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    //glColor3ub(23,60,43);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
        glEnd();
}



double setUpSpeed(double z){

    if(freeze==true){

        return 0.0;
    }

    else if(freeze==false){
        
        if(VelocityUp==true){
            double x = 0.2f;
            
            return x;
            
        }
        
        if(VelocityUp==false)
        {
            
            return z;
            
        }
    }
    return 0.0;
}



    void drawRain()
    {
    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,-0.1,0);
        glVertex3f(rainX,-0.2,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,-0.4,0);
        glVertex3f(rainX,-0.5,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,-0.7,0);
        glVertex3f(rainX,-0.8,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,-1,0);
        glVertex3f(rainX,-1.1,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,-1.3,0);
        glVertex3f(rainX,-1.4,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,-1.6,0);
        glVertex3f(rainX,-1.7,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,-1.9,0);
        glVertex3f(rainX,-2,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,0.1,0);
        glVertex3f(rainX,0.2,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,0.4,0);
        glVertex3f(rainX,0.5,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,0.7,0);
        glVertex3f(rainX,0.8,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,1,0);
        glVertex3f(rainX,1.1,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,1.3,0);
        glVertex3f(rainX,1.4,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,1.6,0);
        glVertex3f(rainX,1.7,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0; i<100; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(rainX,1.9,0);
        glVertex3f(rainX,2,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;
}


void drawBird()
{
    glPushMatrix();
    int i;

    GLfloat mm=0.182f;
    GLfloat nn=.801f;
    GLfloat radiusmm =.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mm, nn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
            nn + (radiusmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
    /////2nd bird////
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

    GLfloat mmm=0.062f;
    GLfloat nnn=.801f;
    GLfloat radiusmmm =.01f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmm, nnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
            nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    /////3rd bird/////
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

    GLfloat mmmm=-0.638f;
    GLfloat nnnn=.801f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmmm,nnnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
            nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    ////4th bird////
    GLfloat mmmmm=-0.518f;
    GLfloat nnnnn=.801f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmmmm, nnnnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
            nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();
    glPopMatrix();

}

void drawBird2()
{
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(0,0,0);
    glVertex3f(1, 0.5, 0);
    glVertex3f(1, 0.5, 0);
    glVertex3f(0, 1, 0);
    glEnd();
    glPopMatrix();
}



//Initializes 3D rendering
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}






float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

//Draws the 3D scene
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

   // glClearColor(<#GLclampf red#>, <#GLclampf green#>, <#GLclampf blue#>, <#GLclampf alpha#>)
    
    tower(-3,-2.5,0.6);

    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(-7,-3.2,0);
    drawTree();
    glPopMatrix();

    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(-6,-2.2,0);
    drawTree();
    glPopMatrix();

    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(-5,-1.2,0);
    drawTree();
    glPopMatrix();


    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(-4,-0.2,0);
    drawTree();
    glPopMatrix();



    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(-3,1.2,0);
    drawTree();
    glPopMatrix();




    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(-1.8,1.2,0);
    drawTree();
    glPopMatrix();


//    //tree
//    glPushMatrix();
//    glScalef(0.7,0.7,1);
//    glTranslatef(-0.6,1.2,0);
//    drawTree();
//    glPopMatrix();

//    //tree
//    glPushMatrix();
//    glScalef(0.7,0.7,1);
//    glTranslatef(0.6,1.2,0);
//    drawTree();
//    glPopMatrix();



      //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(1.8,1.2,0);
    drawTree();
    glPopMatrix();
      //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(3,1.2,0);
    drawTree();
    glPopMatrix();
      //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(4,-0.2,0);
    drawTree();
    glPopMatrix();



    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(5,-1.2,0);
    drawTree();
    glPopMatrix();

    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(6,-2.2,0);
    drawTree();
    glPopMatrix();

    //tree
    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(7,-3.2,0);
    drawTree();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0.18,2);
    glPopMatrix();
    //drawLight();
   // if(nightLight==true){
    //nightLightFun();

    glPopMatrix();

    //Sky
    glPushMatrix();
    glScalef(7,3,2);
    glTranslatef(0,1.21,0);
    glColor3ub(sky[0], sky[1], sky[2]);
    glBegin(GL_QUADS);
    glVertex3f(-1.0, -1.1, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.1, 0.0);
    glEnd();
    glPopMatrix();

     //SUN

    glPushMatrix();
    glTranslatef(0,-_angle,0);
    glTranslatef(4,3,0);
    glScalef(1,1,0.1);
    glColor3ub(sun[0], sun[1], sun[2]);
    glutSolidSphere(0.4,40,40);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(_angle,0,0);


    glPopMatrix();
    glTranslatef(0,0,0.1);


    glPopMatrix();



//starts
if(NightRain==false){
    if(nightLight==true){
    glPushMatrix();
    glTranslatef(4.5,2.2,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.0,2.4,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,2.4,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.4,2.2,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(2.8,2.6,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(0.8,2.8,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-4.0,2.6,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-2.9,2.6,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.9,2.6,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4,2.1,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2,2.1,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2,2.6,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2,2.1,0);
     glScalef(.5,.5,0);
    //drawStars();
    glPopMatrix();
    }
}
//////////////end

    if(Rain && !night)
    {
        //rain
        glPushMatrix();
        glTranslatef(0,-rain,3);
        glRotatef(10,0,0,1);
        drawRain();
        glPopMatrix();

        //rainbow
        glPushMatrix();
        glTranslatef(-3,1,0);
        glScalef(4,1.5,1);
    //    drawRainbow();
        glPopMatrix();
    }

    if(Rain && night)
    {
        //rain
        glPushMatrix();
        glTranslatef(0,-rain,3);
        glRotatef(10,0,0,1);
        drawRain();
        glPopMatrix();

    }

    glPushMatrix();
    //glTranslatef(ship, 0, 0);
    glTranslatef(0, 2, 0);
if(night!=true){
    //draw Bird
    glPushMatrix();
    glScalef(3, 1, 1);
    drawBird();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glScalef(3, 0.7, 1);
    drawBird();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glTranslatef(-0.1, 0, 1);
    glScalef(0.05, 0.05, 1);
    //drawBird2();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glTranslatef(-0.1, 0.1, 1);
    glScalef(0.05, 0.05, 1);
    //drawBird2();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glTranslatef(-0.1, -0.1, 1);
    glScalef(0.05, 0.05, 1);
    //drawBird2();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glTranslatef(-0.2, -0.1, 1);
    glScalef(0.05, 0.05, 1);
    //drawBird2();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glTranslatef(-0.2, -0.2, 1);
    glScalef(0.05, 0.05, 1);
    //drawBird2();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glTranslatef(-0.2, 0, 1);
    glScalef(0.05, 0.05, 1);
    //drawBird2();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glTranslatef(-0.2, 0.1, 1);
    glScalef(0.05, 0.05, 1);
    //drawBird2();
    glPopMatrix();

    //draw Bird
    glPushMatrix();
    glTranslatef(-0.2, 0.2, 1);
    glScalef(0.05, 0.05, 1);
    //drawBird2();
    glPopMatrix();
}
    glPopMatrix();

    glutSwapBuffers();

}

void update(int value)
{

    if(freeze==true){
    _angle+=0.0f;
    }
    else if(sunrise==true){

    if(VelocityUp==true){
    _angle-=0.01f;
   }
    else{
         _angle-=0.001f;
    }

    if(_angle<0.0f){

       sunrise=false;
    }
 }
else if(VelocityUp==false){
    _angle+=0.001f;

}
else if(VelocityUp==true){
    _angle+=0.01f;
}



 if(_angle>2.27f){
    sunrise=true;


 }



    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);
}




////////////////*****************************end

void rainAnimation(int value)
{
    double z= setUpSpeed(0.02);
    rain+=z;
   // rain += 0.02f;
    if(rain>0.1f)
    {
        //move=true;
        rain = -0.1f;
    }
    glutPostRedisplay();

    glutTimerFunc(25, rainAnimation, 0);
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'v':
        VelocityUp= true;

        break;


    case 'w' :
    VelocityUp=false;
    freeze=false;
    break;

    case 'f' :
        freeze=true;
        break;
        //end

    case 'r':
        nightLight = false;
        NightRain=true;
        Rain = true;
        if(!night)
        {
            sky[0] = 128;
            sky[1] = 137;
            sky[2] = 140;
            cloud[0] = 87;
            cloud[1] = 98;
            cloud[2] = 102;
            sun[0] = 128;
            sun[1] = 137;
            sun[2] = 140;
            //PlaySound(TEXT("rain.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        }

        if(night && Rain)
        {
            sun[0] = 77;
            sun[1] = 77;
            sun[2] = 77;
            //PlaySound(TEXT("rain.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        }
        break;

    case 's':
        Rain = false;
        NightRain=false;
        if(!night)
        {
            sky[0] = 19;
            sky[1] = 190;
            sky[2] = 242;
            cloud[0] = 255;
            cloud[1] = 255;
            cloud[2] = 255;
            sun[0] = 219;
            sun[1] = 230;
            sun[2] = 21;
            tree[0] = 34;
            tree[1] = 139;
            tree[2] = 34;

            //PlaySound(TEXT("sun.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        }
        if(!Rain && night)
        {
            sun[0] = 255;
            sun[1] = 255;
            sun[2] = 255;
            //PlaySound(TEXT("night.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        }
        break;

    case 'n':
        night = true;
        nightLight = true;

        if(night && !Rain)
        {
            NightRain=false;
            sky[0] = 77;
            sky[1] = 77;
            sky[2] = 77;
            sun[0] = 255;
            sun[1] = 255;
            sun[2] = 255;
            tree[0] = 125;
            tree[1] = 125;
            tree[2] = 125;

            //PlaySound(TEXT("night.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        }
        else if(night && Rain)
        {
            sky[0] = 77;
            sky[1] = 77;
            sky[2] = 77;
            sun[0] = 77;
            sun[1] = 77;
            sun[2] = 77;
            tree[0] = 125;
            tree[1] = 125;
            tree[2] = 125;
            glBegin(GL_TRIANGLES);
            glColor3ub(255, 255, 0);
            glVertex2f(-2.9f,-0.6f);
            glVertex2f(-2.7f,-0.6f);
            glVertex2f(-2.8f,-0.2f);
            glEnd();

        }

        break;

    case 'd':
        night = false;
        nightLight = false;
        if(!Rain)
        {
            sky[0] = 19;
            sky[1] = 190;
            sky[2] = 242;
            sun[0] = 219;
            sun[1] = 230;
            sun[2] = 21;
            tree[0] = 34;
            tree[1] = 139;
            tree[2] = 34;


            //PlaySound(TEXT("sun.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        }
        if(Rain && !night)
        {
            sky[0] = 128;
            sky[1] = 137;
            sky[2] = 140;
            sun[0] = 128;
            sun[1] = 137;
            sun[2] = 140;
            tree[0] = 34;
            tree[1] = 139;
            tree[2] = 34;

            //PlaySound(TEXT("rain.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        }
        break;
    }
}
//--------------Main--------------------//


void init()
{
    glClearColor(0.5f, 0.0f, 0.0f,0.0);
    glMatrixMode(GLUT_SINGLE|GLUT_RGB);
    glLoadIdentity();
    glOrtho(-90.0,100.0,-15.0,100.0,0.0,1.0);
}

void renderbitmapscale(float x,float y,void *font,char *string)
{
    char *c;
    glRasterPos2f(x,y);

//    float scale = 36 / 100.0f; // adjust scale based on desired font size
    glScalef(0.005,0.005,1);

    for(c=string; *c!='\0'; c++)
    {
        glutBitmapCharacter(font,*c);
    }
}

void renderbitmap(float x,float y,void *font,char *string)
{
    char *c;
    glRasterPos2f(x,y);

//    float scale = fontSize / 100.0f; // adjust scale based on desired font size
//    glScalef(scale, scale, 1.0f);

    for(c=string; *c!='\0'; c++)
    {
        glutBitmapCharacter(font,*c);
    }
}

//------------- Display Text------------------ //
void displaytext(float x1, float y1,char *text){
    char buf[100]= {0};
    snprintf(buf,100,text);
    renderbitmap(x1,y1,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}

//----------------Road lines-----------------//
void roadlines(float x, float x1, float y, float y1){
    while(x<x1){

        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(x,(y1+y)/2);
            glVertex2f(x+0.4, (y1+y)/2);
        glEnd();
        x+=0.8;
    }
}





//human//
// create circle for sun
void sunFunc(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    //GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<=360;i++)
    {
        angle = i*PI /180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

float humany=2;
void timerhuman(int value){
    humany += 0.02f;
    glutPostRedisplay();
    if(humany<5.5){
        glutTimerFunc(1, timerhuman, 0);
    }
    glFlush();
    glEnd();
}

void humanFunc(float humanx)
{
//MAN LEFT
//man head
    float s=0.05;
       glColor3f(1, 0.76, 0.41);
    sunFunc(1.5*s,1.5*s,humanx-80.0*s,humany-20.5*s);

//main hair
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25*s,humany-19.25*s);
    glVertex2f(humanx-81.25*s,humany-18*s);
    glVertex2f(humanx-78.75*s,humany-18*s);
    glVertex2f(humanx-78.75*s,humany-19.25*s);
    glEnd();

//man eyes
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75*s,humany-20*s);
    glVertex2f(humanx-79.25*s,humany-20*s);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75*s,humany-21.5*s);
    glVertex2f(humanx-79.25*s,humany-21.5*s);
    glEnd();

//man chest
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-83.0*s,humany-22.0*s,0);
    glVertex3f(humanx-77.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-77.0*s,humany-28.0*s,0);
    glVertex3f(humanx-83.0*s,humany-28.0*s,0.0);
    glEnd();
//man t-shirt
    glColor3f(0.3f, 0.5f, 0.0f); //red
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0*s,humany-22.0*s,0);
    glVertex3f(humanx-78.0*s,humany-22.0*s,0.0);
    glColor3f(0.3f, 0.6f, 0.0f);
    glVertex3f(humanx-78.0*s,humany-28.0*s,0);
    glVertex3f(humanx-82.0*s,humany-28.0*s,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-83.0*s,humany-22.0*s,0);
    glVertex3f(humanx-82.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-82.0*s,humany-24.0*s,0);
    glVertex3f(humanx-83.0*s,humany-24.0*s,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-77.0*s,humany-22.0*s,0);
    glVertex3f(humanx-78.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-78.0*s,humany-24.0*s,0);
    glVertex3f(humanx-77.0*s,humany-24.0*s,0.0);
    glEnd();

//man pant
    glBegin(GL_QUADS);
       glColor3f(0.5, 0.7, 0.92);
    glVertex3f(humanx-82.0*s,humany-28.0*s,0);
    glVertex3f(humanx-78.0*s,humany-28.0*s,0.0);
    glVertex3f(humanx-78.0*s,humany-35.0*s,0);
    glVertex3f(humanx-82.0*s,humany-35.0*s,0.0);
    glEnd();
//man legs
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-81.5*s,humany-35.0*s,0);
    glVertex3f(humanx-78.5*s,humany-35.0*s,0.0);
    glVertex3f(humanx-78.5*s,humany-38.0*s,0);
    glVertex3f(humanx-81.5*s,humany-38.0*s,0.0);
    glEnd();
//man leg divider
    glBegin(GL_LINES);
       glColor3f(0.0, 0.0, 0);
    glVertex3f(humanx-80.0*s,humany-32.0*s,0);
    glVertex3f(humanx-80.0*s,humany-38.0*s,0.0);
    glEnd();
}


void humanFuncf(float humanx, float humany)
{
//MAN LEFT
//man head
    float s=0.05;
       glColor3f(1, 0.76, 0.41);
    sunFunc(1.5*s,1.5*s,humanx-80.0*s,humany-20.5*s);

//main hair
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25*s,humany-19.25*s);
    glVertex2f(humanx-81.25*s,humany-18*s);
    glVertex2f(humanx-78.75*s,humany-18*s);
    glVertex2f(humanx-78.75*s,humany-19.25*s);
    glEnd();

//man eyes
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75*s,humany-20*s);
    glVertex2f(humanx-79.25*s,humany-20*s);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75*s,humany-21.5*s);
    glVertex2f(humanx-79.25*s,humany-21.5*s);
    glEnd();

//man chest
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-83.0*s,humany-22.0*s,0);
    glVertex3f(humanx-77.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-77.0*s,humany-28.0*s,0);
    glVertex3f(humanx-83.0*s,humany-28.0*s,0.0);
    glEnd();
//man t-shirt
    glColor3f(0.3f, 0.5f, 0.0f); //red
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0*s,humany-22.0*s,0);
    glVertex3f(humanx-78.0*s,humany-22.0*s,0.0);
    glColor3f(0.3f, 0.6f, 0.0f);
    glVertex3f(humanx-78.0*s,humany-28.0*s,0);
    glVertex3f(humanx-82.0*s,humany-28.0*s,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-83.0*s,humany-22.0*s,0);
    glVertex3f(humanx-82.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-82.0*s,humany-24.0*s,0);
    glVertex3f(humanx-83.0*s,humany-24.0*s,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-77.0*s,humany-22.0*s,0);
    glVertex3f(humanx-78.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-78.0*s,humany-24.0*s,0);
    glVertex3f(humanx-77.0*s,humany-24.0*s,0.0);
    glEnd();

//man pant
    glBegin(GL_QUADS);
       glColor3f(0.5, 0.7, 0.92);
    glVertex3f(humanx-82.0*s,humany-28.0*s,0);
    glVertex3f(humanx-78.0*s,humany-28.0*s,0.0);
    glVertex3f(humanx-78.0*s,humany-35.0*s,0);
    glVertex3f(humanx-82.0*s,humany-35.0*s,0.0);
    glEnd();
//man legs
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-81.5*s,humany-35.0*s,0);
    glVertex3f(humanx-78.5*s,humany-35.0*s,0.0);
    glVertex3f(humanx-78.5*s,humany-38.0*s,0);
    glVertex3f(humanx-81.5*s,humany-38.0*s,0.0);
    glEnd();
//man leg divider
    glBegin(GL_LINES);
       glColor3f(0.0, 0.0, 0);
    glVertex3f(humanx-80.0*s,humany-32.0*s,0);
    glVertex3f(humanx-80.0*s,humany-38.0*s,0.0);
    glEnd();
}

void humanFunct(float humanx, float humany)
{
//MAN LEFT
//man head
    float s=0.1;
       glColor3f(1, 0.76, 0.41);
    sunFunc(1.5*s,1.5*s,humanx-80.0*s,humany-20.5*s);

//main hair
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25*s,humany-19.25*s);
    glVertex2f(humanx-81.25*s,humany-18*s);
    glVertex2f(humanx-78.75*s,humany-18*s);
    glVertex2f(humanx-78.75*s,humany-19.25*s);
    glEnd();

//man eyes
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75*s,humany-20*s);
    glVertex2f(humanx-79.25*s,humany-20*s);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75*s,humany-21.5*s);
    glVertex2f(humanx-79.25*s,humany-21.5*s);
    glEnd();

//man chest
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-83.0*s,humany-22.0*s,0);
    glVertex3f(humanx-77.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-77.0*s,humany-28.0*s,0);
    glVertex3f(humanx-83.0*s,humany-28.0*s,0.0);
    glEnd();
//man t-shirt
    glColor3f(0.3f, 0.5f, 0.0f); //red
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0*s,humany-22.0*s,0);
    glVertex3f(humanx-78.0*s,humany-22.0*s,0.0);
    glColor3f(0.3f, 0.6f, 0.0f);
    glVertex3f(humanx-78.0*s,humany-28.0*s,0);
    glVertex3f(humanx-82.0*s,humany-28.0*s,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-83.0*s,humany-22.0*s,0);
    glVertex3f(humanx-82.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-82.0*s,humany-24.0*s,0);
    glVertex3f(humanx-83.0*s,humany-24.0*s,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-77.0*s,humany-22.0*s,0);
    glVertex3f(humanx-78.0*s,humany-22.0*s,0.0);
    glVertex3f(humanx-78.0*s,humany-24.0*s,0);
    glVertex3f(humanx-77.0*s,humany-24.0*s,0.0);
    glEnd();

////man pant
//    glBegin(GL_QUADS);
//    glColor3f(0.3f, 0.5f, 0.0f);
//    glVertex3f(humanx-82.0*s,humany-28.0*s,0);
//    glVertex3f(humanx-78.0*s,humany-28.0*s,0.0);
//    glVertex3f(humanx-78.0*s,humany-35.0*s,0);
//    glVertex3f(humanx-82.0*s,humany-35.0*s,0.0);
//    glEnd();
////man legs
//    glBegin(GL_QUADS);
//       glColor3f(1, 0.76, 0.41);
//    glVertex3f(humanx-81.5*s,humany-35.0*s,0);
//    glVertex3f(humanx-78.5*s,humany-35.0*s,0.0);
//    glVertex3f(humanx-78.5*s,humany-38.0*s,0);
//    glVertex3f(humanx-81.5*s,humany-38.0*s,0.0);
//    glEnd();
////man leg divider
//    glBegin(GL_LINES);
//       glColor3f(0.0, 0.0, 0);
//    glVertex3f(humanx-80.0*s,humany-32.0*s,0);
//    glVertex3f(humanx-80.0*s,humany-38.0*s,0.0);
//    glEnd();
}



int flag = 0;
//-------------------Tree-----------------------//



//---------------first Screen---------------//
void introscreen()
{
    glutFullScreen();
    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.f,1.f,1.f);
    char buf[100]= {0};

    snprintf(buf,100,"Paris Tour");
    renderbitmap(3,90,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"A Mouniyaa");
    renderbitmap(-40,70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"4NM20CS001");
    renderbitmap(35,70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"A Ramya Shree");
    renderbitmap(-40,55,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100," 4NM20CS002");
    renderbitmap(35,55,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"Guided BY:");
    renderbitmap(4,40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"Dr. Pradeep Kanchan");
    renderbitmap(-40,35,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"Assistant Professor Gd-III");
    renderbitmap(-40,30,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"Mr. Puneeth R P");
    renderbitmap(35,35,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"Assistant Professor Gd-II");
    renderbitmap(35,30,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    glColor3d(171,148,97);
    glPushMatrix();

    glRectf(5,20,22,12);
    glColor3f(1.0f, 0.0f, 0.0f);
    //glRasterPos2i(250 + 25, 350 + 20);
    renderbitmap(10,15,GLUT_BITMAP_TIMES_ROMAN_24,"Next");
    //PlaySound("kitchen.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}


void display(void)
{
    glutFullScreen();
    //glutKeyboardFunc(keyboardguide);
    char buf[100]= {0};

    glColor3f(1.0, 0.0, 0.0);
    snprintf(buf,100,"Eiffel Tower");
    renderbitmap(4,3.5,GLUT_BITMAP_TIMES_ROMAN_24,buf);

    glColor3f(1.0, 0.0, 0.0);
    snprintf(buf,100,"Museum");
    renderbitmap(8,7,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    glClear( GL_COLOR_BUFFER_BIT);

    //river
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.6, 0.9);
    glVertex3f(1.0, 15.0, 0.0);
    glVertex3f(2.0, 15.0, 0.0);
    glVertex3f(2.0, 0.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();

    // center long road
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 5.0, 0.0);
    glVertex3f(12.0, 5.0, 0.0);
    glVertex3f(12.0, 4.25, 0.0);
    glVertex3f(-2.0, 4.25, 0.0);
    glEnd();

    roadlines(-2.0, 12.0, 5.0, 4.25);

    //museum
    glColor3d(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(8.0, 10.5, 0.0);
    glVertex3f(12.0, 10.5, 0.0);
    glColor3d(0.0f, 0.3f, 0.0f);
    glVertex3f(12.0, 7.5, 0.0);
    glVertex3f(8.0, 7.5, 0.0);
    glEnd();


    //tower
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(4.0, 6.0, 0.0);
    glVertex3f(6.0, 6.0, 0.0);
    glColor3d(0.0f, 0.3f, 0.0f);
    glVertex3f(6.0, 3.5, 0.0);
    glVertex3f(4.0, 3.5, 0.0);
    glEnd();
    
    //garden
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(4.0, 3.0, 0.0);
    glVertex3f(6.0, 3.0, 0.0);
    glColor3d(0.0f, 0.3f, 0.0f);
    glVertex3f(6.0, 0.5, 0.0);
    glVertex3f(4.0, 0.5, 0.0);
    glEnd();

    //cross
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(4.0, 1.575, 0.0);
    glVertex3f(6.0, 1.575, 0.0);
    glColor3f(0.5, 0.6, 0.5);
    glVertex3f(6.0, 1.875, 0.0);
    glVertex3f(4.0, 1.875, 0.0);
    glEnd();
    
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(4.875, 3.0, 0.0);
    glVertex3f(5.125, 3.0, 0.0);
    glColor3f(0.5, 0.6, 0.5);
    glVertex3f(5.125, 0.5, 0.0);
    glVertex3f(4.875, 0.5, 0.0);
    glEnd();

    //convo
    glColor3d(0.5f, 0.5f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex3f(4.8, 9.0, 0.0);
    glVertex3f(7.5, 9.0, 0.0);
    glColor3d(0.5f, 0.5f, 0.5f);
    glVertex3f(7.5f, 8.3, 0.0);
    glVertex3f(4.8, 8.3, 0.0);
    glEnd();
    
    glColor3d(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex3f(4.8, 9.0, 0.0);
    glVertex3f(4.8, 8.7, 0.0);
    glVertex3f(4.6, 8.8, 0.0);
    glEnd();


    //vertical long road
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 15.0, 0.0);
    glVertex3f(3.0, 15.0, 0.0);
    glVertex3f(3.0, -15.0, 0.0);
    glVertex3f(2.5, -15.0, 0.0);
    glEnd();

    float y = -15;
    while(y<15){

        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(2.75,y);
            glVertex2f(2.75,y+0.4);
        glEnd();
        y+=0.8;
    }


    // upper half road
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(8.0, 15.0, 0.0);
    glVertex3f(8.5, 15.0, 0.0);
    glVertex3f(8.5, 5, 0.0);
    glVertex3f(8.0, 5, 0.0);
    glEnd();

    y=5;
    while(y<15){

        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(8.25,y);
            glVertex2f(8.25,y+0.4);
        glEnd();
        y+=0.8;
    }


    displaytext(4.5,4.7,"Eiffel Tower");
    displaytext(8.6, 8.7, "Musée du Louvre");
    displaytext(1.05,6,"River Seine");
    displaytext(5, 8.5, "Bonjour!! Bienvenue a Paris");
    
//    humany=9.8;
    humanFuncf(8.3,9.8);
    
    glColor3d(0.0f, 0.5f, 0.0f);
    sunFunc(0.25, 0.35, 5, 1.75);
    
    glEnd();
    glFlush();
}



void newdisp()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1,0,0);
     glFlush();
}


float doorL=4.5,doorR=5.0;

void timer(int value)
{
    doorL -= 0.05f;
    doorR += 0.05f;
    glutPostRedisplay();
    if(doorL>4.2 && doorR<5.3){
    glutTimerFunc(1, timer, 0);
    }
    glFlush();
    glEnd();
}


void EiffelMain(){
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(1300, 700);
//    //Create the window
//    glutCreateWindow("Ciy_View_2D");
//    initRendering();
//    //Set handler functions
//    glutDisplayFunc(drawScene);
//    glutReshapeFunc(handleResize);
//    glutTimerFunc(250, update, 0); //Add a timer
//    glutKeyboardFunc(keyboard);
//    glutMainLoop();
}

void MonaLisa()
{
    char buf[1000]= {0};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(256,253,208);
    snprintf(buf,100,"Considered an archetypal masterpie");
    renderbitmap(-0.875,0.70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"ce of the Italian Renaissance it has");
    renderbitmap(-0.875,0.55,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"been described as the best known, the");
    renderbitmap(-0.875,0.40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"most visited, the most written about, the");
    renderbitmap(-0.875,0.25,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"most sung about, the most parodied work");
    renderbitmap(-0.875,0.10,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    displaytext(-0.875,-0.05, "of art in the world.The painting's");
    displaytext(-0.875,-0.20, "novel qualities include the subject's");
    displaytext(-0.875,-0.35, "enigmatic expression monumentality");

//    glRectf(-0.3,-0.7,0.3,-0.5);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    // glRasterPos2i(250 + 25, 350 + 20);
//    renderbitmap(-0.1,-0.65,GLUT_BITMAP_TIMES_ROMAN_24,"Visit");
//    glutMouseFunc(visit_Museum);
    glFlush();
}
void des(int button, int state, int x, int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        
        if(x >= 600 && x <= 800 && y >= 400 && y <= 1000) {
            glutInitWindowSize(450,400);
            glutCreateWindow("MonaLisa");
            glutDisplayFunc(MonaLisa);
        }
    }
}

void Museum_Interior(){
    
    char buf[1000]= {0};
    
    glClearColor(0.8f, 0.93f,0.93f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.96f, 0.89f);
    glVertex3f(2.0, 8.0, 0.0);
    glVertex3f(8.0, 8.0, 0.0);
    //glColor3f(0.8f,0.56f,0.06f);
    glVertex3f(8.0, 3.0, 0.0);
    glVertex3f(2.0, 3.0, 0.0);
    glEnd();
    
    //up trapezium
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.6, 0.6);
    glVertex3f(2.0, 8.0, 0.0);
    glVertex3f(8.0, 8.0, 0.0);
    glColor3f(0.4, 0.6, 0.7);
    glVertex3f(10.0, 10.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.4, 0.6, 0.7);
        glVertex3f(10,10,0.0);
        glVertex3f(8,8,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.4, 0.8, 0.7);
        glVertex3f(0.0,10.0,0.0);
        glVertex3f(2,8,0.0);
    glEnd();
    
    
    //photo
    glBegin(GL_POLYGON);
    glColor3d(0.4, 0.8, 0.7);
    glVertex3f(4.0, 7.0, 0.0);
    glVertex3f(6.0, 7.0, 0.0);
    //glColor3f(0.8f,0.56f,0.06f);
    glVertex3f(6.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    
    //down trapezium
    glBegin(GL_POLYGON);
    glColor3f(0.8f,0.56f,0.06f);
    glVertex3f(8.0, 3.0, 0.0);
    glVertex3f(2.0, 3.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glEnd();
    
    
    glBegin(GL_LINES);
    glColor3f(0.5, 0.26, 0.02);
        glVertex3f(3.5,3,0.0);
        glVertex3f(2.5,0,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.5, 0.26, 0.02);
        glVertex3f(5.0,3.0,0.0);
        glVertex3f(5.0,0,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.5, 0.26, 0.02);
        glVertex3f(6.5,3,0.0);
        glVertex3f(7.5,0,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.5, 0.26, 0.02);
        glVertex3f(1.5,2,0.0);
        glVertex3f(8.5,2,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.5, 0.26, 0.02);
        glVertex3f(0.75,1,0.0);
        glVertex3f(9.25,1,0.0);
    glEnd();
    
    snprintf(buf,100,"Mona Lisa");
    renderbitmap(-0.875,0.70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    humanFunct(13,7.4);
    
    
    glEnd();
    glFlush();
}

void mymouse(int button, int state, int x, int y){
    if(button == GLUT_RIGHT_BUTTON){
        glutTimerFunc(0, timer, 0);
    }

    if(button == GLUT_RIGHT_BUTTON){
        glutTimerFunc(0, timerhuman, 0);
    }
    
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        
        if(x >= 600 && x <= 800 && y >= 400 && y <= 1000) {
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3d(0,0,256);
            glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
            glutCreateWindow("Museum Interior");
            glutInitWindowSize(1000, 1000);
            glClearColor(0.4, 0.8, 1.0, 0.0);         // black background
            glMatrixMode(GL_PROJECTION);              // setup viewing projection
            glLoadIdentity();
            glutMouseFunc(des);// start with identity matrix
            glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
            glutDisplayFunc(Museum_Interior);
            glutMainLoop();
            
            
        }
    }
}


void visit_Eiffel(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){

        if(x >= -1000 && x <= 1000 && y >= -1000 && y <= 1000) {
//            glClear(GL_COLOR_BUFFER_BIT);
//            glColor3d(0,0,256);
//            glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//            glutCreateWindow ("Eiffel Tower");
//            glClearColor(0.4, 0.8, 1.0, 0.0);         // black background
//            glMatrixMode(GL_PROJECTION);              // setup viewing projection
//            glLoadIdentity();                           // start with identity matrix
//            glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
//            glutMouseFunc(mymouse);
//            glutDisplayFunc(EiffelMain);
//            glutMainLoop();
            
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
            //Create the window
            glutCreateWindow("Tower");
           // glutFullScreen();
            glutInitWindowSize(1000, 1000);
            initRendering();
            //Set handler functions
            glutDisplayFunc(drawScene);
            glutReshapeFunc(handleResize);
            glutTimerFunc(250, update, 0); //Add a timer
            glutKeyboardFunc(keyboard);
            glutMainLoop();
        }
    }
}

void pyramid() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    glLoadIdentity();                  // Reset the model-view matrix

    glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0f, 4.0f, 4.0f);
    glVertex3f(3.5f, 4.0f, 4.0f);
    glVertex3f(3.5f, 6.5f, 6.5f);
    glVertex3f(2.0f, 6.5f, 6.5f);
    glEnd();

    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
    // Front
    //glColor3d(102,178,255);     // light blue
    glColor3f(1.0,0.9,0.2);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(1.0,0.9,0.2);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(1.0,0.9,0.2);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right
    //glColor3d(0,128,255);
    glColor3f(1.0,0.7,0.2);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0,0.7,0.2);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(1.0,0.7,0.2);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back
    glColor3d(0,128,255);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3d(0,128,255);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3d(0,128,255);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left
    glColor3d(0,128,255);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3d(0,128,255);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glColor3d(0,128,255);
    glVertex3f(-1.0f,-1.0f, 1.0f);

    glEnd();   // Done drawing the pyramid


    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}



void mykey(char key, int x, int y){
    if(key=='m' || key=='M')
        glutTimerFunc(0, timerhuman, 0);
}



void MuseumMain(){
    //glutFullScreen();
    glClearColor(0.8f, 0.93f,0.93f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    //sky
    glBegin(GL_POLYGON);
    glColor3f(0.28f,0.84f,0.82f);
    glVertex3f(10.0, 10.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glColor3f(0.28f,0.84f,1.0f);
    glVertex3f(0.0, 4.0, 0.0);
    glVertex3f(10.0, 4.0, 0.0);
    glEnd();

    //ground
    glBegin(GL_POLYGON);
    glColor3f(0.68f,0.7f,0.72f);
    glVertex3f(-10.0, -15.0, 0.0);
    glVertex3f(-10.0, 4.0, 0.0);
    glVertex3f(10.0, 4.0, 0.0);
    glVertex3f(10.0, -15.0, 0.0);
    glEnd();

    //main
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.8f,0.2f);
    glVertex3f(1.0, 7.0, 0.0);
    glVertex3f(9.0, 7.0, 0.0);
    glColor3f(0.8f,0.56f,0.06f);
    glVertex3f(9.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glEnd();

    //left kombo
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.26, 0.02);
    glVertex3f(1.0, 7.0, 0.0);
    glVertex3f(2.0, 7.0, 0.0);
    glColor3f(0.8f,0.56f,0.06f);
    glVertex3f(1.8, 8.0, 0.0);
    glVertex3f(1.2, 8.0, 0.0);
    glEnd();

    //right kombo
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.26, 0.02);
    glVertex3f(9.0, 7.0, 0.0);
    glVertex3f(8.0, 7.0, 0.0);
    glColor3f(0.8f,0.56f,0.06f);
    glVertex3f(8.2, 8.0, 0.0);
    glVertex3f(8.8, 8.0, 0.0);
    glEnd();

    //middle kombo
    glBegin(GL_POLYGON);
    glColor3f(0.8f,0.56f,0.06f);
    glVertex3f(4.5, 8.0, 0.0);
    glVertex3f(5.5, 8.0, 0.0);
    glColor3f(0.5, 0.26, 0.02);
    glVertex3f(5.7, 7.0, 0.0);
    glVertex3f(4.3, 7.0, 0.0);
    glEnd();


    //up line
    glBegin(GL_LINES);
    glColor3f(0.5, 0.26, 0.02);
        glVertex3f(1.0,6.5,0.0);
        glVertex3f(9.0,6.5,0.0);
    glEnd();

    //down line
    glBegin(GL_LINES);
    glColor3f(0.5, 0.26, 0.02);
        glVertex3f(1.0,5.5,0.0);
        glVertex3f(9.0,5.5,0.0);
    glEnd();

   // door
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(4.5, 5.2, 0.0);
    glVertex3f(5.5, 5.2, 0.0);
    glVertex3f(5.5, 4.0, 0.0);
    glVertex3f(4.5, 4.0, 0.0);
    glEnd();

    //left door
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.26, 0.02);
     glVertex3f(doorL, 5.2, 0.0);
     glVertex3f(doorL+0.5, 5.2, 0.0);
     glVertex3f(doorL+0.5, 4.0, 0.0);
    //glColor3f(0.8, 0.26, 0.02);
     glVertex3f(doorL, 4.0, 0.0);
    glEnd();
    
   


    //right door
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.26, 0.02);
      glVertex3f(doorR, 5.2, 0.0);
      glVertex3f(doorR+0.5, 5.2, 0.0);
      glVertex3f(doorR+0.5, 4.0, 0.0);
    //glColor3f(0.8, 0.26, 0.02);
      glVertex3f(doorR, 4.0, 0.0);
    glEnd();

    float winx = 1.5;
    //window down
    for(int i=0;i<3;i++){
        glBegin(GL_POLYGON);
        glColor3f(0.5, 0.26, 0.02);
        glVertex3f(winx, 5.2, 0.0);
        glVertex3f(winx+0.3, 5.2, 0.0);
        //glColor3f(0.8f,0.56f,0.06f);
        glVertex3f(winx+0.3, 4.2, 0.0);
        glVertex3f(winx, 4.2, 0.0);
        glEnd();

        winx+=1.0;
    }

    winx = 6.0;
    //window down
    for(int i=0;i<3;i++){
        glBegin(GL_POLYGON);
        glColor3f(0.5, 0.26, 0.02);
        glVertex3f(winx, 5.2, 0.0);
        glVertex3f(winx+0.3, 5.2, 0.0);
        //glColor3f(0.8f,0.56f,0.06f);
        glVertex3f(winx+0.3, 4.2, 0.0);
        glVertex3f(winx, 4.2, 0.0);
        glEnd();

        winx+=1.0;
    }


    winx = 1.5;
    //window down
    for(int i=0;i<10;i++){
        glBegin(GL_POLYGON);
        glColor3f(0.5, 0.26, 0.02);
        glVertex3f(winx, 6.4, 0.0);
        glVertex3f(winx+0.2, 6.4, 0.0);
        glColor3f(0.8f,0.56f,0.06f);
        glVertex3f(winx+0.2, 6.9, 0.0);
        glVertex3f(winx, 4.2, 6.9);
        glEnd();

        winx+=0.7;
    }
    sunFunc(0.3, 0.5, 2, 9);

    humanFunc(10);


    glEnd();
    glFlush();
}


void visit_Museum(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){

        if(x >= -1000 && x <= 1000 && y >= -1000 && y <= 1000) {
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3d(0,0,256);
            glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
            glutCreateWindow ("Museum");
            glutInitWindowSize(1000, 1000);
            glClearColor(0.4, 0.8, 1.0, 0.0);         // black background
            glMatrixMode(GL_PROJECTION);              // setup viewing projection
            glLoadIdentity();                           // start with identity matrix
            glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
            glutMouseFunc(mymouse);
            //glutKeyboardFunc(mykey);
            glutDisplayFunc(MuseumMain);
            glutMainLoop();
        }
    }
}

void BridgeMain(){
    
    
    
    glClearColor(0.8f, 0.93f,0.93f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();                           // start with identity matrix
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
    
    
    //sky
    glBegin(GL_POLYGON);
    glColor3f(0.28f,0.84f,0.82f);
    glVertex3f(10.0, 10.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glColor3f(0.28f,0.84f,1.0f);
    glVertex3f(0.0, 4.0, 0.0);
    glVertex3f(10.0, 4.0, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(5,8.5,0);
        glVertex3f(5,9,0.0);
    glEnd();
    
    //top
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(5.2, 8.5, 0.0);
    glVertex3f(4.8, 8.5, 0.0);
    glVertex3f(4.8, 8, 0.0);
    glVertex3f(5.2, 8, 0.0);
    glEnd();
    
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(4.8,8,0);
        glVertex3f(4.5,6,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(5.2,8,0);
        glVertex3f(5.5,6,0.0);
    glEnd();
    
    //cross
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(4.8,8,0);
        glVertex3f(5.5,6,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(5.2,8,0);
        glVertex3f(4.5,6,0.0);
    glEnd();
    
    //middle
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(5.5, 6, 0.0);
    glVertex3f(4.5, 6, 0.0);
    glVertex3f(4.5, 5.5, 0.0);
    glVertex3f(5.5, 5.5, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(4.5,5.5,0);
        glVertex3f(4,3.5,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(5.5,5.5,0);
        glVertex3f(6,3.5,0.0);
    glEnd();
    
    //center lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(5,5.5,0);
        glVertex3f(4.5,3.5,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(5,5.5,0);
        glVertex3f(5.5,3.5,0.0);
    glEnd();
    
    //lower
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(6.0, 3.5, 0.0);
    glVertex3f(4.0, 3.5, 0.0);
    glVertex3f(4.0, 3.0, 0.0);
    glVertex3f(6.0, 3.0, 0.0);
    glEnd();
    
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(4,3,0);
        glVertex3f(3.0,0.5,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(3.0,0.5,0);
        glVertex3f(4.0,0.5,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(4.0,0.5,0.0);
        glVertex3f(4.5,2.0,0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(4.5,2.0,0);
        glVertex3f(5.5,2.0,0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(5.5,2.0,0.0);
        glVertex3f(6.0,0.5,0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(6.0,0.5,0);
        glVertex3f(7.0,0.5,0.0);
    glEnd();
    
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
        glVertex3f(7.0,0.5,0);
        glVertex3f(6,3,0.0);
    glEnd();
    
    
  
    
    glFlush();

    
}

void river(){
    //river
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3f(0,117,170);
        glVertex2f(-10,-100);
        glVertex2f(0,-70);
        glVertex2f(15,-66);
        glVertex2f(10,-100);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0,-70);
        glVertex2f(-8,-35);
        glVertex2f(3,-37);
        glVertex2f(15,-66);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(2,-2.3);
        glVertex2f(7,-2.5);
        glVertex2f(3,-37);
        glVertex2f(-8,-35);
        glEnd();
        glFlush();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
}


void visit_Brigde(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){

        if(x >= -1000 && x <= 1000 && y >= -1000 && y <= 1000) {
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3d(0,0,256);
            glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
            glutCreateWindow ("Eiffel Tower");
            glClearColor(0.4, 0.8, 1.0, 0.0);         // black background
            glMatrixMode(GL_PROJECTION);              // setup viewing projection
            glLoadIdentity();                           // start with identity matrix
            //glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
            glOrtho(0.0, 50.0, 0.0, 50.0, -1.0, 1.0);// setup a 10x10x2 viewing world
            //glutMouseFunc(mymouse);
            //glutDisplayFunc(BridgeMain);
            glutDisplayFunc(river);
            glutMainLoop();
        }
    }
}


void Eiffel_Tower()
{
    char buf[1000]= {0};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(256,253,208);
    snprintf(buf,100,"The Eiffel Tower is a wrought-iron lattice");
    renderbitmap(-0.875,0.70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"lattice tower on the Champ de Mars in");
    renderbitmap(-0.875,0.55,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"Paris,France.It is named after the");
    renderbitmap(-0.875,0.40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"engineer Gustave Eiffel, whose company");
    renderbitmap(-0.875,0.25,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"designed and built the tower.Locally");
    renderbitmap(-0.875,0.10,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    displaytext(-0.875,-0.05, "nicknamed La dame de fer.It was");
    displaytext(-0.875,-0.20, "Constructed from 1887 to 1889 other ");
    displaytext(-0.875,-0.35, "objects from ancient civilizations.");

    glRectf(-0.3,-0.7,0.3,-0.5);
    glColor3f(1.0f, 0.0f, 0.0f);
    // glRasterPos2i(250 + 25, 350 + 20);
    renderbitmap(-0.1,-0.65,GLUT_BITMAP_TIMES_ROMAN_24,"Visit");

    glutMouseFunc(visit_Eiffel);
    glFlush();
}


void Bridge()
{

    char buf[1000]= {0};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(256,253,208);
    snprintf(buf,100,"Seine River, river of France, after");
    renderbitmap(-0.875,0.70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"the Loire its longest. It rises 18");
    renderbitmap(-0.875,0.55,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"milesFrance northwest of Dijon and");
    renderbitmap(-0.875,0.40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"flows in a northwesterly direction");
    renderbitmap(-0.875,0.25,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"through Paris before emptying into");
    renderbitmap(-0.875,0.10,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    displaytext(-0.875,-0.05, "the English Channel at Le Havre its ");
    displaytext(-0.875,-0.20, "drainage network carries most of");
    displaytext(-0.875,-0.35, "the French inland waterway traffic");


//    glRectf(-0.3,-0.7,0.3,-0.5);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    // glRasterPos2i(250 + 25, 350 + 20);
//    renderbitmap(-0.1,-0.65,GLUT_BITMAP_TIMES_ROMAN_24,"Visit");
//    glutMouseFunc(visit_Brigde);
    glFlush();
}

void Museum()
{
    char buf[1000]= {0};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(256,253,208);
    snprintf(buf,100,"Louvre is the world's most-visited");
    renderbitmap(-0.875,0.70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"and a historic landmark in Paris,France");
    renderbitmap(-0.875,0.55,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"Paris,France.It is named after the");
    renderbitmap(-0.875,0.40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"It is the home of some of the best-known");
    renderbitmap(-0.875,0.25,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    snprintf(buf,100,"works of art, including the Mona Lisa");
    renderbitmap(-0.875,0.10,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    displaytext(-0.875,-0.05, "and the Venus de Milo.The museum also");
    displaytext(-0.875,-0.20, "has a vast collection of sculptures and");
    displaytext(-0.875,-0.35, "other objects from ancient civilizations.");

    glRectf(-0.3,-0.7,0.3,-0.5);
    glColor3f(1.0f, 0.0f, 0.0f);
    // glRasterPos2i(250 + 25, 350 + 20);
    renderbitmap(-0.1,-0.65,GLUT_BITMAP_TIMES_ROMAN_24,"Visit");
    glutMouseFunc(visit_Museum);
    glFlush();
}

void description(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){

        if(x >= 600 && x <= 800 && y >= 400 && y <= 1000) {
            glutInitWindowSize(450,400);
            glutCreateWindow("Eiffel Tower");
            glutDisplayFunc(Eiffel_Tower);
        }

        if(x >= 200 && x <= 500 && y >= 100 && y <= 1000) {
            glutInitWindowSize(400,400);
            glutCreateWindow("River seine");
            glutDisplayFunc(Bridge);
        }

        if(x >= 1000 && x <= 1500 && y >= 100 && y <= 1000) {
            glutInitWindowSize(450,400);
            glutCreateWindow("Museum");
            glutDisplayFunc(Museum);

        }
        glutPostRedisplay();
    }
    
    if(button==GLUT_RIGHT_BUTTON){
        flag = 1;
    }
}

void mouse(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){

        if(x >= 600 && x <= 845 && y >= 500 && y <= 700) {

            glClear(GL_COLOR_BUFFER_BIT);
            glColor3d(256,253,208);
            //sprintf_s(buf,"Welcome to Paris");
            //renderbitmap(0,0,GLUT_BITMAP_TIMES_ROMAN_24,buf);
            glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
            glutCreateWindow ("Paris");
            glClearColor(0.0, 0.0, 0.0, 0.0);         // black background
            glMatrixMode(GL_PROJECTION);              // setup viewing projection
            glLoadIdentity();                           // start with identity matrix
            glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
            glutMouseFunc(description);
            glutDisplayFunc(display);
            //glutMouseFunc(description);
            glutMainLoop();
        }
        glutPostRedisplay();
    }
}



void indisplay()
{
    introscreen();
    glutPostRedisplay();
    glEnd();
    glFlush();
}





int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1200,800);
    glutCreateWindow("MOUSE EVENT");
    init();
    glutDisplayFunc(indisplay);
    glutMouseFunc(mouse);
    //glutMouseFunc(paris);
    glutMainLoop();
}



//#include <fstream>
//#include <iostream>
//#include <stdlib.h>
//#include <GLUT/GLUT.h>
//using namespace std;
//int width=480;
//int height=640;
//
//void initGL() {
//   glClearColor(0.2, 0.7,0.86, 0.0);
//   glOrtho(-100,100,-100,100,-100,100); // Set background color to black and opaque
//   glClearDepth(1.0f);                   // Set background depth to farthest
//   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
//   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
//   glShadeModel(GL_SMOOTH);   // Enable smooth shading
//   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
//}
//
//
//void init()
//{
//    glClearColor(0.5f, 0.0f, 0.0f,0.0);
//    glMatrixMode(GLUT_SINGLE|GLUT_RGB);
//    glLoadIdentity();
//    glOrtho(-90.0,100.0,-15.0,100.0,0.0,1.0);
//}
//void renderbitmap(float x,float y,void *font,char *string)
//{
//    char *c;
//    glRasterPos2f(x,y);
//    for(c=string; *c!='\0'; c++)
//    {
//        glutBitmapCharacter(font,*c);
//    }
//}
//
//void introscreen()
//{
//    glColor3f(1.f,1.f,1.f);
//    char buf[100]= {0};
//
//    snprintf(buf,100,"Paris Tour");
//
//    snprintf(buf,100,"Paris Tour");
//    renderbitmap(-5,90,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"A Mouniyaa");
//    renderbitmap(-40,70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"4NM20CS001");
//    renderbitmap(35,70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"A Ramya Shree");
//    renderbitmap(-40,55,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100," 4NM20CS002");
//    renderbitmap(35,55,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"Guided BY:");
//    renderbitmap(-60,40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"Dr. Pradeep Kanchan");
//    renderbitmap(-40,40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"Mr. Puneeth R P");
//    renderbitmap(35,40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    glColor3d(171,148,97);
//    glPushMatrix();
//
//
//
//       glRectf(-5,25,15,15);
//       glColor3f(1.0f, 0.0f, 0.0f);
//   // glRasterPos2i(250 + 25, 350 + 20);
//    renderbitmap(2,19,GLUT_BITMAP_TIMES_ROMAN_24,"Next");
//}
//
//void Eiffel_Tower()
//{
//     char buf[1000]= {0};
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3d(256,253,208);
//    snprintf(buf,100,"The Eiffel Tower is a wrought-iron lattice");
//     renderbitmap(-1,0.70,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"tower on the Champ de Mars in Paris, France. ");
//     renderbitmap(-1,0.60,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"It is named after the engineer Gustave Eiffel,");
//     renderbitmap(-1,0.50,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"whose company designed and built the tower. ");
//     renderbitmap(-1,0.40,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    snprintf(buf,100,"Locally nicknamed La dame de fer.");
//     renderbitmap(-1,0.30,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//     glFlush();
//}
//
//void Bridge()
//{
//     char buf[500]= {0};
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3d(256,253,208);
//    snprintf(buf,100,"Welcome to Paris");
//     renderbitmap(0,0,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//     glFlush();
//}
//
//
//void Museum()
//{
//     char buf[500]= {0};
//     glClear(GL_COLOR_BUFFER_BIT);
//     pyramid();
//     glColor3d(256,253,208);
//    snprintf(buf,100,"Welcome to Paris");
//     renderbitmap(0,0,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//     glFlush();
//}
//
//
//
//void description(int button,int state,int x,int y){
//    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
//    //std::cout << x << std::endl;
//    //std::cout << y << std::endl;
//    if(x >= 600 && x <= 800 && y >= 400 && y <= 1000) {
//        glutInitWindowSize(450,400);
//        glutCreateWindow("Welcome to Paris");
//        glutDisplayFunc(Eiffel_Tower);
//    }
//
//    if(x >= 200 && x <= 500 && y >= 100 && y <= 1000) {
//        glutInitWindowSize(400,400);
//        glutCreateWindow("Welcome to Paris");
//        glutDisplayFunc(Bridge);
//    }
//
//    if(x >= 1000 && x <= 1500 && y >= 100 && y <= 1000) {
//        glutInitWindowSize(400,400);
//        glutCreateWindow("Welcome to Paris");
//        glutDisplayFunc(Museum);
//
//    }
//    glutPostRedisplay();
//    }
//}
//
//void display(void)
//{
//    char buf[100]= {0};
//
//    glColor3f(1.0, 0.0, 0.0);
//    snprintf(buf,100,"Eiffel Tower");
//    renderbitmap(4,3.5,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//
//    glColor3f(1.0, 0.0, 0.0);
//    snprintf(buf,100,"Museum");
//    renderbitmap(8,7,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    glClear( GL_COLOR_BUFFER_BIT);
//
//    glBegin(GL_POLYGON);
//    glColor3f(0.1, 0.6, 0.9);
//    glVertex3f(1.0, 15.0, 0.0);
//    glColor3f(0.23, 0.48, 0.62);
//    glVertex3f(2.0, 15.0, 0.0);
//    glVertex3f(2.0, 0.0, 0.0);
//    glVertex3f(1.0, 0.0, 0.0);
//    glEnd();
//
//
//    //museum
//    glColor3f(0.6, 0.8, 0.6);
//    glBegin(GL_POLYGON);
//    glVertex3f(8.0, 10.5, 0.0);
//    glVertex3f(12.0, 10.5, 0.0);
//    glVertex3f(12.0, 7.5, 0.0);
//    glVertex3f(8.0, 7.5, 0.0);
//    glEnd();
//
//
//    //square
//    glColor3f(0.6, 0.8, 0.6);
//    glBegin(GL_POLYGON);
//    glVertex3f(4.0, 6.0, 0.0);
//    glVertex3f(6.0, 6.0, 0.0);
//    glVertex3f(6.0, 3.5, 0.0);
//    glVertex3f(4.0, 3.5, 0.0);
//    glEnd();
//
//
//
//    //vertical long road
//    glColor3f(0.5, 0.5, 0.5);
//    glBegin(GL_POLYGON);
//    glVertex3f(2.75, 15.0, 0.0);
//    glVertex3f(3.0, 15.0, 0.0);
//    glVertex3f(3.0, -15.0, 0.0);
//    glVertex3f(2.75, -15.0, 0.0);
//    glEnd();
//
//    // upper half road
//    glColor3f(0.5, 0.5, 0.5);
//    glBegin(GL_POLYGON);
//    glVertex3f(8.0, 15.0, 0.0);
//    glVertex3f(8.25, 15.0, 0.0);
//    glVertex3f(8.25, 5, 0.0);
//    glVertex3f(8.0, 5, 0.0);
//    glEnd();
//
//    // first half of the road
//    glColor3f(0.5, 0.5, 0.5);
//    glBegin(GL_POLYGON);
//    glVertex3f(-2.0, 5.0, 0.0);
//    glVertex3f(4.0, 5.0, 0.0);
//    glVertex3f(4.0, 4.5, 0.0);
//    glVertex3f(-2.0, 4.5, 0.0);
//    glEnd();
//
//    //second half of the road
//    glColor3f(0.5, 0.5, 0.5);
//    glBegin(GL_POLYGON);
//    glVertex3f(6.0, 5.0, 0.0);
//    glVertex3f(12.0, 5.0, 0.0);
//    glVertex3f(12.0, 4.5, 0.0);
//    glVertex3f(6.0, 4.5, 0.0);
//
//    //river
//    //wave(1,1,1,1);
//    glEnd();
//
//
//
//    glFlush();
//}
//
//
//void newdisp()
//{
//    char buf[100]= {0};
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3d(256,253,208);
//    //sprintf_s(buf,"Welcome to Paris");
//    //renderbitmap(0,0,GLUT_BITMAP_TIMES_ROMAN_24,buf);
//    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//
//    glutInitWindowPosition(100,100);
//    glutInitWindowSize(300,300);
//    glutCreateWindow ("Paris");
//
//    glClearColor(0.0, 0.0, 0.0, 0.0);         // black background
//    glMatrixMode(GL_PROJECTION);              // setup viewing projection
//    glLoadIdentity();                           // start with identity matrix
//    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
//
//    glutDisplayFunc(display);
//    glutMouseFunc(description);
//    glutMainLoop();
//    //glBegin(GL_POLYGON);
//    //display();
//    //glutMouseFunc(description);
//     //glFlush();
//}
//
//
//void mouse(int button,int state,int x,int y){
//    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
//
//        if(x >= 600 && x <= 845 && y >= 500 && y <= 700) {
//            glutCreateWindow("Welcome to Paris");
//            glutDisplayFunc(newdisp);
//        }
//        glutPostRedisplay();
//    }
//}
//
//void indisplay()
//{
//    introscreen();
//    glEnd();
//    glFlush();
//
//    glutPostRedisplay();
//}
//
//
//
//
//
//int main(int argc,char **argv)
//{
//    glutInit(&argc,argv);
//    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
//    glutInitWindowPosition(10,10);
//    glutInitWindowSize(1200,800);
//    glutCreateWindow("MOUSE EVENT");
//    init();
//    glutDisplayFunc(indisplay);
//    glutMouseFunc(mouse);
//    glutMainLoop();
//}



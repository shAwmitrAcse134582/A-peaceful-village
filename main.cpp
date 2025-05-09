#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>
#define SPEED 30.0

// Function prototypes
void drawCube(float size);
void drawHouse(float x, float y, float z);
void drawTree(float x, float y, float z);
void drawWindmill(float x, float y, float z);
void draw_object();
void drawBush(float x, float y, float z);
void drawRiver();

// Camera position and rotation
float cameraX = 0.0f;
float cameraY = 5.0f;
float cameraZ = 15.0f;
float cameraRotX = 0.0f;
float cameraRotY = 0.0f;

// Animation variables
float sunAngle = 0.0f;
float windmillRotation = 0.0f;
float doorAngle = 0.0f;
float windowAngle = 0.0f;
bool doorOpening = false;
bool windowOpening = false;

// Lighting
GLfloat lightPosition[] = {5.0f, 5.0f, 5.0f, 1.0f};
GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat diffuseLight[] = {1.0f, 1.0f, 1.0f, 1.0f};

int posx=0,posy=0,posz=0;
int day = 1;        //1 for day ,0 for night

float meghX = 0;
float meghY = 0;
int meghStatus = 0;

float x_rot = 0;
float y_inc = 0;
float y_dec =0;

float x3_rot = 0;
float dy_inc = 0;
float dy_dec =0;
float x_dec =0;

float hill2X = 1;
float hill2Y = 1;

//hill1
float hill11= 0;
float hill112 =0;
float hill12 =0;
float hill122 =0;
float hill13 =0;

//hill2
float hill21= 0;
float hill212 =0;
float hill22 =0;
float hill222 =0;
float hill23 =0;


#define PI 3.1416

//GLint i, j, k,x=0,y=0,speed=0,alt=0,n1=1000,n2=1100,s1=0,s2=1,s3=1;
GLfloat sun_spin=0, sun_x=0, sun_y=0,reduce=10;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;

// Add these variables at the top with other global variables
float cloudPositions[3] = {-15.0f, 0.0f, 0.0f};  // Array to store cloud positions
float cloudSpeed = 0.05f;  // Speed of cloud movement

// Add these variables at the top with other global variables
float birdPositions[3][3] = {
    {-15.0f, 7.0f, -8.0f},  // First bird position
    {-12.0f, 8.0f, -10.0f}, // Second bird position
    {-10.0f, 6.0f, -9.0f}   // Third bird position
};
float birdSpeed = 0.1f;
float wingAngle = 0.0f;
bool wingUp = true;

// Add these variables at the top with other global variables
float treeSwayAngle = 0.0f;
bool swayRight = true;

// Add these variables at the top with other global variables
bool bushesBloom = false;
float bushBloomAngle = 0.0f;

// Add these variables at the top with other global variables
float windmillX = 0.0f;
float windmillY = 0.0f;
float windmillSpeedX = 0.02f;
float windmillSpeedY = 0.01f;
bool windmillMovingRight = true;
bool windmillMovingUp = true;

// Add these variables at the top with other global variables
float fanX = 0.0f;
float fanY = 0.0f;
float fanSpeed = 0.02f;
bool fanMovingRight = true;
bool fanMovingUp = true;

// Add these variables at the top with other global variables
float riverFlow = 0.0f;
float riverSpeed = 0.02f;

// Add these global variables at the top with other animation variables
float boatX = -18.0f;
float boatSpeed = 0.01f;

void DrawCircle(float cx, float cy, float r, int num_segments){

		 glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < num_segments; i++)
		{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

		}
		glEnd();
	}



void megh(int x){

	glColor3f(1.0, 1.0, 1.0);
	DrawCircle(100, 1000, 60, 2000);//1
	DrawCircle(200,1000, 80, 2000);//2
	DrawCircle(300, 1000, 55, 2000);//3


	DrawCircle(800, 1000, 60, 1000);//1
	DrawCircle(900,1000, 80, 1000);//2
	DrawCircle(1000, 1000, 55, 1000);//3

	DrawCircle(500, 900, 60, 2000);//1
	DrawCircle(600,900, 80, 2000);//2
	DrawCircle(700, 900, 55, 2000);//3

	DrawCircle(500, 1100, 60, 2000);//1
	DrawCircle(600,1100, 80, 2000);//2
	DrawCircle(700, 1100, 55, 2000);//3


	}


void movemegh()
	{
		//if (meghStatus == 1)
		//{
		//	meghX +=.5;
		//}
		//if (meghX>2000)
		//{
		//	meghX = -200;
		//}
		glPushMatrix();
		glTranslatef(meghX, meghY, 0);
		megh(1);
		glPopMatrix();


	}





///tree

void tree()
{
///tree1
    glColor3f(0.6156863,0,0);

    glBegin(GL_POLYGON);

        glVertex3i(50, 350, 0);
        glVertex3i(70, 350, 0);


        glVertex3i(70, 500, 0);
        glVertex3i(50, 500, 0);

    glEnd();

  glColor3f(0.0, 0.5, 0.0);

glBegin(GL_POLYGON);

    glVertex3i(10, 500, 0);
    glVertex3i(110, 500, 0);


    glVertex3i(60, 600, 0);

glEnd();
glBegin(GL_POLYGON);


    glVertex3i(15, 550, 0);
    glVertex3i(105, 550, 0);


    glVertex3i(60, 650, 0);



glEnd();

///tree2
glColor3f(0.6156863,0,0);

glBegin(GL_POLYGON);


    glVertex3i(50+100, 350, 0);
    glVertex3i(70+100, 350, 0);


    glVertex3i(70+100, 500, 0);
    glVertex3i(50+100, 500, 0);


glEnd();

  glColor3f(0.0, 0.5, 0.0);

glBegin(GL_POLYGON);


    glVertex3i(10+100, 500, 0);
    glVertex3i(110+100, 500, 0);


    glVertex3i(60+100, 600, 0);



glEnd();
glBegin(GL_POLYGON);


    glVertex3i(15+100, 550, 0);
    glVertex3i(105+100, 550, 0);


    glVertex3i(60+100, 650, 0);



glEnd();
///tree3
glColor3f(0.6156863,0,0);

glBegin(GL_POLYGON);


    glVertex3i(50+1000, 350+100, 0);
    glVertex3i(70+1000, 350+100, 0);


    glVertex3i(70+1000, 500+100, 0);
    glVertex3i(50+1000, 500+100, 0);


glEnd();

  glColor3f(0.0, 0.5, 0.0);

glBegin(GL_POLYGON);


    glVertex3i(10+1000, 500+100, 0);
    glVertex3i(110+1000, 500+100, 0);


    glVertex3i(60+1000, 600+100, 0);



glEnd();
glBegin(GL_POLYGON);


    glVertex3i(15+1000, 550+100, 0);
    glVertex3i(105+1000, 550+100, 0);


    glVertex3i(60+1000, 650+100, 0);



glEnd();
///tree4
glColor3f(0.6156863,0,0);

glBegin(GL_POLYGON);


    glVertex3i(50+1100, 350+200, 0);
    glVertex3i(70+1100, 350+200, 0);


    glVertex3i(70+1100, 500+200, 0);
    glVertex3i(50+1100, 500+200, 0);


glEnd();

  glColor3f(0.0, 0.5, 0.0);

glBegin(GL_POLYGON);


    glVertex3i(10+1100, 500+200, 0);
    glVertex3i(110+1100, 500+200, 0);


    glVertex3i(60+1100, 600+200, 0);



glEnd();
glBegin(GL_POLYGON);


    glVertex3i(15+1100, 550+200, 0);
    glVertex3i(105+1100, 550+200, 0);


    glVertex3i(60+1100, 650+200, 0);



glEnd();
///tree5
glColor3f(0.6156863,0,0);

glBegin(GL_POLYGON);


    glVertex3i(50+900, 350+200, 0);
    glVertex3i(70+900, 350+200, 0);


    glVertex3i(70+900, 500+200, 0);
    glVertex3i(50+900, 500+200, 0);


glEnd();

  glColor3f(0.0, 0.5, 0.0);

glBegin(GL_POLYGON);


    glVertex3i(10+900, 500+200, 0);
    glVertex3i(110+900, 500+200, 0);


    glVertex3i(60+900, 600+200, 0);



glEnd();
glBegin(GL_POLYGON);


    glVertex3i(15+900, 550+200, 0);
    glVertex3i(105+900, 550+200, 0);


    glVertex3i(60+900, 650+200, 0);

glEnd();


}



///river
void river()
{
    //glColor3f(0.0352941176470588, 0.5098039215686275, 0.9568627450980392);

    glColor3f(0.0, 0.8, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(0, 0, 0);
    glVertex3i(1200, 0, 0);
    glVertex3i(1200, 300, 0);
    glVertex3i(0, 300, 0);


glEnd();



}
//land
void land()
{
    glColor3f(0.5 ,1.0 ,0.5);
    glBegin(GL_POLYGON);

    glVertex3i(0, 300, 0);
    glVertex3i(1200, 300, 0);
    glVertex3i(1200, 600, 0);
    glVertex3i(0, 600, 0);


glEnd();

}
///hill
void hill()
{

  //  glColor3f(0.50196, 0.25098, 0.0);
  //  glBegin(GL_POLYGON);

   // glVertex3i(600, 600, 0);
   // glVertex3i(800, 900, 0);
   // glVertex3i(900, 650, 0);
    //glVertex3i(600, 600, 0);

    glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);

    //glVertex3i(600, 600, 0);
    glVertex3i(900, 600, 0);
    glVertex3i(1000, 800, 0);
    glVertex3i(1100, 600, 0);

     glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(1050, 600, 0);
    glVertex3i(1200, 800, 0);
    glVertex3i(1200, 600, 0);
    //glVertex3i(1100, 620, 0);




glEnd();

}

void hill1()
{

    glColor3f(0.128, 0.128, 0.128);
    glBegin(GL_POLYGON);

    glVertex3i(700+hill11, 600+hill112, 0);
    glVertex3i(900+hill12, 600+hill122, 0);
    glVertex3i(800, 950+hill13, 0);
    //glVertex3i(600, 600, 0);

glEnd();

}

void hill2()
{

    glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(800+hill2X, 600+hill2Y, 0);
    glVertex3i(900+hill2X, 900+hill2Y, 0);
    glVertex3i(1000+hill2X, 600+hill2Y, 0);
    //glVertex3i(600, 600, 0);

glEnd();

}





///house

void house()
{

///house1
glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

glBegin(GL_POLYGON);

    glVertex3i(220, 350, 0);
    glVertex3i(380, 350, 0);
    glVertex3i(380, 450, 0);
    glVertex3i(220, 450, 0);


glEnd();

glColor3f(0, 0, 1);
glBegin(GL_POLYGON);

    glVertex3i(200, 450, 0);
    glVertex3i(400, 450, 0);
    glVertex3i(300, 650, 0);



glEnd();


glColor3f(1,1,1);
glBegin(GL_POLYGON);

    glVertex3i(280, 350, 0);
    glVertex3i(320, 350, 0);
    glVertex3i(320, 450, 0);
    glVertex3i(280, 450, 0);


glEnd();
///house2
glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

glBegin(GL_POLYGON);

   // glVertex3i(420, 400, 0);
  // glVertex3i(580, 400, 0);
  //  glVertex3i(580, 500, 0);
  //  glVertex3i(420, 500, 0);


    glVertex3i(420, 400, 0);
   glVertex3i(480, 400, 0);
    glVertex3i(480, 500, 0);
    glVertex3i(420, 500, 0);





glEnd();



glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);
glBegin(GL_POLYGON);


     glVertex3i(520, 400, 0);
     glVertex3i(580, 400, 0);
     glVertex3i(580, 500, 0);
     glVertex3i(520, 500, 0);

glEnd();




glColor3f(1.444, .5, 0);
glBegin(GL_POLYGON);

    glVertex3i(200+200, 450+50, 0);
    glVertex3i(400+200, 450+50, 0);
    glVertex3i(300+200, 650+50, 0);



glEnd();

glColor3f(1,1,1);
glBegin(GL_POLYGON);

    glVertex3i(280+200, 350+50, 0);
    glVertex3i(320+200, 350+50, 0);
    glVertex3i(320+200, 450+50, 0);
    glVertex3i(280+200, 450+50, 0);


glEnd();
/*

glColor3f(1,1,0);
glBegin(GL_POLYGON);

    glVertex3i(280+200, 350+50, 0);
    glVertex3i(320+200, 350+50, 0);
    glVertex3i(320+200, 450+50, 0);
    glVertex3i(280+200, 450+50, 0);


glEnd();
*/
}


///////////////////////////////////////////////////////////////////////////////

void house3d(){


	glBegin(GL_POLYGON); //House rec
	glColor3f(0.5, 0.2, 0.1);
	glVertex2i(100, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 250);
	glVertex2i(100, 250);
	glEnd();




	glBegin(GL_POLYGON); //House rec border
	glColor3f(1.0, 0.3, 0.2);
	glVertex2i(90, 80);
	glVertex2i(355, 80);
	glVertex2i(350, 100);
	glVertex2i(100, 100);
	glEnd();

	glBegin(GL_POLYGON); //House door
	glColor3f(1, 1, 1);
	glVertex2i(200, 100);
	glVertex2i(250, 100);
	glVertex2i(250, 200);
	glVertex2i(200, 200);
	glEnd();


	glBegin(GL_POLYGON); //House tin
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(100, 250);
	glVertex2i(350, 250);
	glVertex2i(300, 400);
	glVertex2i(50, 400);
	glEnd();



	glBegin(GL_POLYGON); //House tri
	glColor3f(0.6, 0.3, 0.1);
	glVertex2i(25, 275);
	glVertex2i(100, 250);
	glVertex2i(50, 400);

	glEnd();




	glBegin(GL_POLYGON); //House tri down rec
	glColor3f(0.9, 0.2, 0.16);
	glVertex2i(25, 150);
	glVertex2i(100, 100);
	glVertex2i(100, 250);
	glVertex2i(25, 275);
	glEnd();




	glBegin(GL_POLYGON); //House tri down rec bor
	glColor3f(0.3, 0.3, 0.1);
	glVertex2i(20, 130);
	glVertex2i(90,80 );
	glVertex2i(100, 100);
	glVertex2i(25, 150);
	glEnd();



	glBegin(GL_POLYGON); //House tri down rec ven
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(50, 210);
	glVertex2i(75, 200);
	glVertex2i(75, 240);
	glVertex2i(50, 250);
	glEnd();




	glBegin(GL_POLYGON); //House vender
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(125, 200);
	glVertex2i(150, 200);
	glVertex2i(150, 240);
	glVertex2i(125, 240);
	glEnd();

	glBegin(GL_POLYGON); //House vender
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(300, 200);
	glVertex2i(325, 200);
	glVertex2i(325, 240);
	glVertex2i(300, 240);
	glEnd();
	 glBegin(GL_POLYGON); //Grass
	glColor3f(0.0, 0.6, 0.3);
	glVertex2i(495, 110);
	glVertex2i(480, 130);
	glVertex2i(470, 140);
	glVertex2i(490, 130);
	glVertex2i(480, 160);
	glVertex2i(500, 130);
	glVertex2i(505, 180);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(510, 140);
	glVertex2i(530, 160);
	glVertex2i(520, 130);
	glVertex2i(540, 140);
	glVertex2i(530, 130);
	glVertex2i(515, 110);
	glEnd();

	glBegin(GL_POLYGON); //Grass
	glColor3f(0.0, 0.6, 0.1);
	glVertex2i(635, 100);
	glVertex2i(620, 120);
	glVertex2i(610, 130);
	glVertex2i(630, 120);
	glVertex2i(620, 150);
	glVertex2i(640, 130);
	glVertex2i(645, 170);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(650, 130);
	glVertex2i(670, 150);
	glVertex2i(660, 120);
	glVertex2i(680, 130);
	glVertex2i(670, 120);
	glVertex2i(655, 100);
	glEnd();
	}


	void door3()
	{
        glBegin(GL_POLYGON); //House door
        glColor3f(0.2, 0.2, 0.1);
        glVertex3f(200, 100,0);
        glVertex3f(250, 100+y_inc,x_rot);
        glVertex3f(250, 200+y_dec,x_rot);
        glVertex3f(200, 200,0);
        glEnd();
	}

void door1()
{
     glColor3f(0.2, 0.2, 0.1);
//glColor3f(1,1,0);
glBegin(GL_POLYGON);

    glVertex3i(280, 350, 0);
    glVertex3i(320, 350+y_inc, x_rot);
    glVertex3i(320, 450+y_dec, x_rot);
    glVertex3i(280, 450, 0);


glEnd();
}

/////////////////////////////////////////////////////////////////////////////////

void door()
{
     glColor3f(0.2, 0.2, 0.1);
  //  glColor3f(1,1,0);
glBegin(GL_POLYGON);

    glVertex3i(275+200, 350+50, 0);
    glVertex3i(320+200, 350+50+y_inc, x_rot);
    glVertex3i(320+200, 450+50+y_dec, x_rot);
    glVertex3i(275+200, 450+50, 0);


glEnd();
}


void circle(GLdouble rad)
{
   glBegin(GL_POLYGON);
    {
      	for(int i=0;i<50;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/50;
            float r=rad;
            float x = r * cos(A);

            float y = r * sin(A);
            glVertex2f(x,y );
        }
    }
    glEnd();
}




/////////////////////////////////////////////////

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model(){

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///*** Windmill_Final_Model ***///
void Windmill(){



        ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
   glColor3ub(208, 211, 212);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3ub(208, 211, 212);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();




}


void move_right(){

   // sun_move();

    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(cx>1000){
            cx= -400;

    }
    if(dx>1000){
            dx= -500;

    }


    glutPostRedisplay();
}
///////////////////////////////////////////////////////





int rad,x,y,a,b,h;
bool SE,E;



///clouds
void draw_object()
{
    // Draw ground
    glColor3f(0.5f, 0.8f, 0.5f);
    glBegin(GL_QUADS);
    glVertex3f(-20.0f, 0.0f, -20.0f);
    glVertex3f(-20.0f, 0.0f, 20.0f);
    glVertex3f(20.0f, 0.0f, 20.0f);
    glVertex3f(20.0f, 0.0f, -20.0f);
    glEnd();

    // Draw river with gap in front of houses
    drawRiver();

    // Draw houses according to original positions
    drawHouse(-8.0f, 0.0f, -5.0f);
    drawBush(-9.5f, 0.0f, -4.0f);
    drawBush(-6.5f, 0.0f, -4.0f);
    drawHouse(-4.0f, 0.0f, -5.0f);
    drawBush(-5.5f, 0.0f, -4.0f);
    drawBush(-2.5f, 0.0f, -4.0f);
    drawHouse(0.0f, 0.0f, -5.0f);
    drawBush(-1.5f, 0.0f, -4.0f);
    drawBush(1.5f, 0.0f, -4.0f);

    // Draw trees according to original positions
    drawTree(-10.0f, 0.0f, -8.0f);
    drawTree(-6.0f, 0.0f, -8.0f);
    drawTree(2.0f, 0.0f, -8.0f);
    drawTree(6.0f, 0.0f, -8.0f);
    drawTree(10.0f, 0.0f, -8.0f);

    // Draw windmills
    drawWindmill(-8.0f, 0.0f, -8.0f);  // Left windmill
    drawWindmill(0.0f, 0.0f, -8.0f);   // Center windmill

    // Draw triangular hills in the background
    // First row of hills (closest)
    glPushMatrix();
    glTranslatef(-5.0f, 0.0f, -15.0f);
    glColor3f(0.2f, 0.6f, 0.2f);  // Dark green
    glBegin(GL_TRIANGLES);
    glVertex3f(-3.0f, 0.0f, -3.0f);
    glVertex3f(3.0f, 0.0f, -3.0f);
    glVertex3f(0.0f, 4.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.0f, 0.0f, -15.0f);
    glColor3f(0.3f, 0.7f, 0.3f);  // Medium green
    glBegin(GL_TRIANGLES);
    glVertex3f(-3.0f, 0.0f, -3.0f);
    glVertex3f(3.0f, 0.0f, -3.0f);
    glVertex3f(0.0f, 4.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // Second row of hills (middle)
    glPushMatrix();
    glTranslatef(-8.0f, 0.0f, -18.0f);
    glColor3f(0.25f, 0.65f, 0.25f);  // Medium-dark green
    glBegin(GL_TRIANGLES);
    glVertex3f(-4.0f, 0.0f, -4.0f);
    glVertex3f(4.0f, 0.0f, -4.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -18.0f);
    glColor3f(0.35f, 0.75f, 0.35f);  // Lighter green
    glBegin(GL_TRIANGLES);
    glVertex3f(-4.5f, 0.0f, -4.5f);
    glVertex3f(4.5f, 0.0f, -4.5f);
    glVertex3f(0.0f, 5.5f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8.0f, 0.0f, -18.0f);
    glColor3f(0.3f, 0.7f, 0.3f);  // Medium green
    glBegin(GL_TRIANGLES);
    glVertex3f(-4.0f, 0.0f, -4.0f);
    glVertex3f(4.0f, 0.0f, -4.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // Third row of hills (furthest)
    glPushMatrix();
    glTranslatef(-12.0f, 0.0f, -22.0f);
    glColor3f(0.2f, 0.6f, 0.2f);  // Dark green
    glBegin(GL_TRIANGLES);
    glVertex3f(-5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, -5.0f);
    glVertex3f(0.0f, 6.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, -22.0f);
    glColor3f(0.25f, 0.65f, 0.25f);  // Medium-dark green
    glBegin(GL_TRIANGLES);
    glVertex3f(-5.5f, 0.0f, -5.5f);
    glVertex3f(5.5f, 0.0f, -5.5f);
    glVertex3f(0.0f, 6.5f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0f, 0.0f, -22.0f);
    glColor3f(0.3f, 0.7f, 0.3f);  // Medium green
    glBegin(GL_TRIANGLES);
    glVertex3f(-5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, -5.0f);
    glVertex3f(0.0f, 6.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12.0f, 0.0f, -22.0f);
    glColor3f(0.35f, 0.75f, 0.35f);  // Lighter green
    glBegin(GL_TRIANGLES);
    glVertex3f(-5.5f, 0.0f, -5.5f);
    glVertex3f(5.5f, 0.0f, -5.5f);
    glVertex3f(0.0f, 6.5f, 0.0f);
    glEnd();
    glPopMatrix();
}

// Add this function to draw a single cloud
void drawCloud(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Draw cloud using multiple spheres
    glColor3f(1.0f, 1.0f, 1.0f);  // White color for clouds
    
    // Main cloud body (increased size from 0.5 to 1.0)
    glutSolidSphere(1.0f, 16, 16);
    
    // Cloud puffs (increased size from 0.4 to 0.8 and adjusted positions)
    glPushMatrix();
    glTranslatef(0.6f, 0.0f, 0.0f);
    glutSolidSphere(0.8f, 16, 16);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.6f, 0.0f, 0.0f);
    glutSolidSphere(0.8f, 16, 16);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glutSolidSphere(0.8f, 16, 16);
    glPopMatrix();
    
    // Additional puffs for more volume
    glPushMatrix();
    glTranslatef(0.3f, 0.3f, 0.0f);
    glutSolidSphere(0.7f, 16, 16);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.3f, 0.3f, 0.0f);
    glutSolidSphere(0.7f, 16, 16);
    glPopMatrix();
    
    glPopMatrix();
}

// Add this function to draw the sun
void drawSun(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Draw main sun sphere (reduced size from 2.0 to 1.0)
    glColor3f(1.0f, 0.5f, 0.0f);  // Orange color for sun
    glutSolidSphere(1.0f, 32, 32);  // Smaller, smoother sphere for sun
    
    // Add sun rays (reduced length from 3.0 to 1.5)
    glColor3f(1.0f, 0.7f, 0.0f);  // Lighter orange for rays
    for(int i = 0; i < 8; i++) {
        glPushMatrix();
        glRotatef(45.0f * i, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(1.5f, 0.3f, 0.0f);  // Reduced ray width and length
        glVertex3f(1.5f, -0.3f, 0.0f);
        glEnd();
        glPopMatrix();
    }
    
    glPopMatrix();
}

// Add this function to draw a single bird
void drawBird(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Bird body
    glColor3f(0.2f, 0.2f, 0.2f);  // Dark gray color for bird
    glPushMatrix();
    glScalef(0.3f, 0.2f, 0.2f);  // Elongated body
    glutSolidSphere(1.0f, 16, 16);
    glPopMatrix();
    
    // Bird head
    glPushMatrix();
    glTranslatef(0.2f, 0.1f, 0.0f);
    glutSolidSphere(0.15f, 16, 16);
    glPopMatrix();
    
    // Bird wings
    glColor3f(0.3f, 0.3f, 0.3f);  // Slightly lighter gray for wings
    
    // Left wing
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(wingAngle, 1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.3f, 0.2f, 0.0f);
    glVertex3f(0.0f, 0.4f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // Right wing
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(-wingAngle, 1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.3f, -0.2f, 0.0f);
    glVertex3f(0.0f, -0.4f, 0.0f);
    glEnd();
    glPopMatrix();
    
    glPopMatrix();
}

// Update the display function to include birds
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Set up camera
    gluLookAt(cameraX, cameraY, cameraZ,
              cameraX + sin(cameraRotY), cameraY + sin(cameraRotX), cameraZ - cos(cameraRotY),
              0.0f, 1.0f, 0.0f);
    
    // Draw sky with a more natural sky blue color
    glColor3f(0.529f, 0.808f, 0.922f);  // Sky blue color
    glBegin(GL_QUADS);
    glVertex3f(-20.0f, 15.0f, -20.0f);
    glVertex3f(20.0f, 15.0f, -20.0f);
    glVertex3f(20.0f, 15.0f, 20.0f);
    glVertex3f(-20.0f, 15.0f, 20.0f);
    glEnd();
    
    // Draw sun at the highest position
    drawSun(0.0f, 12.0f, -15.0f);
    
    // Draw birds
    for (int i = 0; i < 3; i++) {
        drawBird(birdPositions[i][0], birdPositions[i][1], birdPositions[i][2]);
    }
    
    // Draw clouds
    drawCloud(cloudPositions[0], 9.0f, -10.0f);
    drawCloud(cloudPositions[1], 8.0f, -5.0f);
    drawCloud(cloudPositions[2], 10.0f, -15.0f);
    
    // Draw ground
    glColor3f(0.5f, 0.8f, 0.5f);
    glBegin(GL_QUADS);
    glVertex3f(-20.0f, 0.0f, -20.0f);
    glVertex3f(-20.0f, 0.0f, 20.0f);
    glVertex3f(20.0f, 0.0f, 20.0f);
    glVertex3f(20.0f, 0.0f, -20.0f);
    glEnd();
    
    // Draw scene objects
    draw_object();
    
    glutSwapBuffers();
}

void keyboardFunc(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Camera movement
        case 'w':
            cameraZ -= 0.5f;
            break;
        case 's':
            cameraZ += 0.5f;
            break;
        case 'a':
            cameraX -= 0.5f;
            break;
        case 'd':
            cameraX += 0.5f;
            break;
        case 'q':
            cameraY += 0.5f;
            break;
        case 'e':
            cameraY -= 0.5f;
            break;
            
        // Camera rotation
        case 'j':
            cameraRotY -= 0.1f;
            break;
        case 'l':
            cameraRotY += 0.1f;
            break;
        case 'i':
            cameraRotX -= 0.1f;
            break;
        case 'k':
            cameraRotX += 0.1f;
            break;
            
        // Door and window controls
        case 'o':
            doorOpening = !doorOpening;
            break;
        case 'p':
            windowOpening = !windowOpening;
            break;
            
        // Day/Night cycle
        case 'n':
            day = 0;
            break;
        case 'm':
            day = 1;
            break;
            
        // Bush blooming control
        case 'b':
            bushesBloom = !bushesBloom;
            break;
            
        // Exit
        case 27: // ESC key
            exit(0);
            break;
    }
    
    glutPostRedisplay();
}
void update(int value) {


    if(posx>=1200)
    {
        posx=0;
    }
    else{
        posx++;
    }
    glutPostRedisplay();
	glutTimerFunc(10, update, 0);
}


void updateD(int value) {


    if(posy>=50)
    {
        posy=0;
    }
    else{
        posy++;
    }
    glutPostRedisplay();
	glutTimerFunc(40, updateD, 0);
}
void updateDoor(int value) {


    if(y_inc>=40)
    {
        x_rot=0;
        y_inc=0;
        y_dec=0;
    }
    else{
        x_rot-=0.5;
        y_inc+=5;
        y_dec-=5;
    }
    glutPostRedisplay();
	glutTimerFunc(200, updateDoor, 0);
}
void init(void)
{
    glClearColor(0.6196078431372549, 0.9333333333333333, 0.996078431372549, 1.0);
    
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    
    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    
    // Set up light properties
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    
    // Set up perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Update the idle function to restore cloud and bird animations
void idle()
{
    // Existing animations
    if (doorOpening) {
        doorAngle += 2.0f;
        if (doorAngle >= 90.0f) {
            doorAngle = 90.0f;
        }
    } else {
        doorAngle -= 2.0f;
        if (doorAngle <= 0.0f) {
            doorAngle = 0.0f;
        }
    }
    
    if (windowOpening) {
        windowAngle += 2.0f;
        if (windowAngle >= 90.0f) {
            windowAngle = 90.0f;
        }
    } else {
        windowAngle -= 2.0f;
        if (windowAngle <= 0.0f) {
            windowAngle = 0.0f;
        }
    }
    
    // Update windmill rotation
    windmillRotation += 0.5f;
    if (windmillRotation >= 360.0f) {
        windmillRotation = 0.0f;
    }
    
    // Update cloud positions
    for (int i = 0; i < 3; i++) {
        cloudPositions[i] += cloudSpeed;
        if (cloudPositions[i] > 20.0f) {
            cloudPositions[i] = -20.0f;
        }
    }
    
    // Update bird positions and wing animation
    for (int i = 0; i < 3; i++) {
        birdPositions[i][0] += birdSpeed;
        if (birdPositions[i][0] > 20.0f) {
            birdPositions[i][0] = -20.0f;
        }
    }
    
    // Wing flapping animation
    if (wingUp) {
        wingAngle += 5.0f;
        if (wingAngle >= 30.0f) {
            wingUp = false;
        }
    } else {
        wingAngle -= 5.0f;
        if (wingAngle <= -30.0f) {
            wingUp = true;
        }
    }
    
    // Tree swaying animation
    if (swayRight) {
        treeSwayAngle += 0.2f;  // Slower swaying motion
        if (treeSwayAngle >= 5.0f) {  // Reduced maximum sway angle
            swayRight = false;
        }
    } else {
        treeSwayAngle -= 0.2f;
        if (treeSwayAngle <= -5.0f) {
            swayRight = true;
        }
    }
    
    // Bush blooming animation
    if (bushesBloom) {
        bushBloomAngle += 0.5f;
        if (bushBloomAngle >= 360.0f) {
            bushBloomAngle = 0.0f;
        }
    }
    
    // Update river flow
    riverFlow += riverSpeed;
    if (riverFlow >= 360.0f) {
        riverFlow = 0.0f;
    }
    
    // Update boat position
    boatX += boatSpeed;
    if (boatX > 18.0f) boatX = -18.0f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Village Scene");
    
    init();
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardFunc);
    glutIdleFunc(idle);
    
    glutMainLoop();
    return 0;
}

// Function to draw a 3D cube
void drawCube(float size) {
    float half = size / 2.0f;
    
    glBegin(GL_QUADS);
    // Front face
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-half, -half, half);
    glVertex3f(half, -half, half);
    glVertex3f(half, half, half);
    glVertex3f(-half, half, half);
    
    // Back face
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-half, -half, -half);
    glVertex3f(-half, half, -half);
    glVertex3f(half, half, -half);
    glVertex3f(half, -half, -half);
    
    // Top face
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-half, half, -half);
    glVertex3f(-half, half, half);
    glVertex3f(half, half, half);
    glVertex3f(half, half, -half);
    
    // Bottom face
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-half, -half, -half);
    glVertex3f(half, -half, -half);
    glVertex3f(half, -half, half);
    glVertex3f(-half, -half, half);
    
    // Right face
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(half, -half, -half);
    glVertex3f(half, half, -half);
    glVertex3f(half, half, half);
    glVertex3f(half, -half, half);
    
    // Left face
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(-half, -half, -half);
    glVertex3f(-half, -half, half);
    glVertex3f(-half, half, half);
    glVertex3f(-half, half, -half);
    glEnd();
}

// Function to draw a 3D house
void drawHouse(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Main house body
    drawCube(2.0f);
    
    // Roof
    glColor3f(0.5f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.2f, 1.0f, -1.2f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(1.2f, 1.0f, -1.2f);
    
    glVertex3f(1.2f, 1.0f, -1.2f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(1.2f, 1.0f, 1.2f);
    
    glVertex3f(1.2f, 1.0f, 1.2f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(-1.2f, 1.0f, 1.2f);
    
    glVertex3f(-1.2f, 1.0f, 1.2f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(-1.2f, 1.0f, -1.2f);
    glEnd();
    
    // Windows - Front (moved higher)
    // Left window
    glPushMatrix();
    glTranslatef(-0.6f, 0.4f, 1.01f);  // Moved window higher (y from 0.2 to 0.4)
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f);
    glColor3f(0.2f, 0.4f, 0.8f);  // Blue color for window
    glBegin(GL_QUADS);
    glVertex3f(-0.2f, -0.2f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.0f);
    glVertex3f(0.2f, 0.2f, 0.0f);
    glVertex3f(-0.2f, 0.2f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // Right window
    glPushMatrix();
    glTranslatef(0.6f, 0.4f, 1.01f);  // Moved window higher (y from 0.2 to 0.4)
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f);
    glColor3f(0.2f, 0.4f, 0.8f);  // Blue color for window
    glBegin(GL_QUADS);
    glVertex3f(-0.2f, -0.2f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.0f);
    glVertex3f(0.2f, 0.2f, 0.0f);
    glVertex3f(-0.2f, 0.2f, 0.0f);
    glEnd();
    glPopMatrix();
    
    // Door (centered between windows)
    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 1.01f);  // Moved door up slightly (y from -0.5 to -0.3)
    glRotatef(doorAngle, 0.0f, 1.0f, 0.0f);
    glColor3f(0.6f, 0.3f, 0.1f);  // Brown color for door
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, -0.5f, 0.0f);
    glVertex3f(0.3f, -0.5f, 0.0f);
    glVertex3f(0.3f, 0.5f, 0.0f);
    glVertex3f(-0.3f, 0.5f, 0.0f);
    glEnd();
    glPopMatrix();
    
    glPopMatrix();
}

// Function to draw a 3D tree
void drawTree(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Tree trunk (brownish-red)
    glColor3f(0.6156863, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1f, 0.0f, 0.0f);
    glVertex3f(0.1f, 0.0f, 0.0f);
    glVertex3f(0.1f, 1.5f, 0.0f);
    glVertex3f(-0.1f, 1.5f, 0.0f);
    glEnd();

    // Tree leaves (green)
    glColor3f(0.0, 0.5, 0.0);
    
    // First triangle
    glBegin(GL_POLYGON);
    glVertex3f(-0.5f, 1.5f, 0.0f);
    glVertex3f(0.5f, 1.5f, 0.0f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();

    // Second triangle
    glBegin(GL_POLYGON);
    glVertex3f(-0.45f, 1.8f, 0.0f);
    glVertex3f(0.45f, 1.8f, 0.0f);
    glVertex3f(0.0f, 2.8f, 0.0f);
    glEnd();

    glPopMatrix();
}

// Function to draw a 3D windmill
void drawWindmill(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Windmill stand (made longer)
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex3f(-0.05f, 0.0f, 0.0f);
    glVertex3f(0.05f, 0.0f, 0.0f);
    glVertex3f(0.05f, 2.5f, 0.0f);  // Increased height from 1.4 to 2.5
    glVertex3f(-0.05f, 2.5f, 0.0f);
    glEnd();

    // Windmill motor (moved up with the stand)
    glColor3ub(208, 211, 212);
    glPushMatrix();
    glTranslatef(0.0f, 2.5f, 0.0f);  // Moved up to match new stand height
    glutSolidSphere(0.15f, 16, 16);  // Made motor slightly bigger
    glPopMatrix();

    // Windmill blades (made bigger)
    glColor3ub(208, 211, 212);
    glPushMatrix();
    glTranslatef(0.0f, 2.5f, 0.0f);  // Moved up to match new stand height
    glRotatef(windmillRotation, 0.0f, 0.0f, 1.0f);
    
    // Blade One (scaled up)
    glBegin(GL_POLYGON);
    glVertex3f(-0.08f, 0.0f, 0.0f);
    glVertex3f(-1.5f, -0.6f, 0.0f);  // Increased size
    glVertex3f(-1.45f, -0.62f, 0.0f);
    glVertex3f(-0.05f, -0.1f, 0.0f);
    glEnd();

    // Blade Two (scaled up)
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 0.08f, 0.0f);
    glVertex3f(0.8f, 1.2f, 0.0f);    // Increased size
    glVertex3f(0.85f, 1.25f, 0.0f);
    glVertex3f(0.08f, 0.0f, 0.0f);
    glEnd();

    // Blade Three (scaled up)
    glBegin(GL_POLYGON);
    glVertex3f(1.2f, -1.3f, 0.0f);   // Increased size
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.08f, 0.08f, 0.0f);
    glVertex3f(1.25f, -1.28f, 0.0f);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}

// Add this function to draw a bush
void drawBush(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Bush base (green)
    glColor3f(0.0f, 0.5f, 0.0f);  // Dark green
    glPushMatrix();
    glScalef(0.8f, 0.6f, 0.8f);
    glutSolidSphere(0.5f, 16, 16);
    glPopMatrix();
    
    // If blooming, add flowers
    if (bushesBloom) {
        // Red flowers
        glColor3f(1.0f, 0.0f, 0.0f);  // Red
        for (int i = 0; i < 5; i++) {
            glPushMatrix();
            float angle = i * 72.0f;  // Distribute flowers evenly
            glRotatef(angle, 0.0f, 1.0f, 0.0f);
            glTranslatef(0.3f, 0.2f, 0.0f);
            glutSolidSphere(0.1f, 8, 8);
            glPopMatrix();
        }
        
        // Yellow flowers
        glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
        for (int i = 0; i < 4; i++) {
            glPushMatrix();
            float angle = i * 90.0f + 36.0f;  // Offset from red flowers
            glRotatef(angle, 0.0f, 1.0f, 0.0f);
            glTranslatef(0.25f, 0.15f, 0.0f);
            glutSolidSphere(0.08f, 8, 8);
            glPopMatrix();
        }
    }
    
    glPopMatrix();
}

// Function to draw a simple boat
void drawBoat(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    // Boat base (brown)
    glColor3f(0.5f, 0.2f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, 0.0f, -0.4f);
    glVertex3f(1.0f, 0.0f, -0.4f);
    glVertex3f(0.7f, 0.2f, 0.0f);
    glVertex3f(-0.7f, 0.2f, 0.0f);
    glEnd();
    // Boat top (white)
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.4f, 0.0f);
    glVertex3f(-0.4f, 0.4f, 0.0f);
    glEnd();
    glPopMatrix();
}

// Update drawRiver to draw the boat
void drawRiver() {
    glPushMatrix();
    glTranslatef(0.0f, 0.01f, 2.0f);  // River in front of houses
    // River base - sky blue, wide
    glColor3f(0.53f, 0.81f, 0.98f);  // Sky blue color
    glBegin(GL_QUADS);
    glVertex3f(-20.0f, 0.0f, -2.5f);
    glVertex3f(20.0f, 0.0f, -2.5f);
    glVertex3f(20.0f, 0.0f, 2.5f);
    glVertex3f(-20.0f, 0.0f, 2.5f);
    glEnd();
    // Animated water wave overlay
    glColor3f(0.4f, 0.7f, 1.0f);  // Slightly lighter blue for wave
    glBegin(GL_QUAD_STRIP);
    for (float x = -20.0f; x <= 20.0f; x += 0.2f) {
        float wave = 0.15f * sinf(2.0f * x + riverFlow * 1.5f);
        glVertex3f(x, 0.02f + wave, -2.5f);
        glVertex3f(x, 0.02f + wave, 2.5f);
    }
    glEnd();
    // Draw the boat (centered in z)
    drawBoat(boatX, 0.18f, 0.0f);
    glPopMatrix();
}

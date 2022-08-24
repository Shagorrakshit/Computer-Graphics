#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

static float tp3 =  0;
static float pm=  300.0;
static float bm=  350.0;
static float tm=  500.0;
static float sm=  50.0;
static float gm=  350.0;
static float bym= 400.0;
static float gm2= 300.0;
static float cm=  500.0;
static float cm2= 500.0;
float _rain = 1000.0;
float _nt = 0.0;
float _sn = 0.0;
float spin = 0.0;
float sun = true;
bool night = false;
bool rainday = false;

///////function///////
void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0;i<=360; i++){
    rad = i*(3.1416/180);
    glVertex2f(x+rx*cos(rad),y+ry*sin(rad));

    }
    glEnd();
}
void triangle(int x, int y, int x1, int x2,int y1)
{
    glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x1,y);

        glVertex2d(x1,y);
        glVertex2d(x2,y1);

        glVertex2d(x2,y1);
        glVertex2d(x,y);
        glEnd();
}

void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
        glVertex2d(x1,y1);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
        glVertex2d(x2,y2);
        glEnd();
}
void rectangle(int x, int y, int x1, int y1)
{
    glBegin(GL_QUADS);
        glVertex2d(x,y);
        glVertex2d(x,y1);
        glVertex2d(x1,y1);
        glVertex2d(x1,y);


    glEnd();
}

void Sun(){
if (sun){
    glPushMatrix();
    glTranslated(130,260,0);
    glColor3f(1.0, 0.76, 0.3);
    circle(20,30,0,0);
    glPopMatrix();
}
}

void Night(int value){

if(night){
    glClearColor(0.0,0.0,0.0,0.0);
	glutPostRedisplay();
    glutTimerFunc(5, Night, 0);
    glFlush();
}



}
void make_cloud(int x, int y)
{

    glColor3f(1.0, 1.0, 1.0);
    circle(10,10,x,y);
    circle(10,10,x+10,y);
    circle(10,10,x+30,y);
    circle(10,10,x+5,y-10);
    circle(10,10,x+20,y-10);
    circle(10,10,x+5,y+10);
    circle(10,10,x+20,y+10);
}

void cloud_move_right(GLfloat t){
    tp3=tp3+t;
    if(tp3>600)
        tp3 = -300;
    glutPostRedisplay();
}


void cloud()
{
    glPushMatrix();
    glTranslatef(tp3,0,0);
    make_cloud(-300,280);
    make_cloud(-500,280);
    make_cloud(-200,250);
    make_cloud(-400,250);
    make_cloud(200,250);
    make_cloud(-100,250);
    make_cloud(-350,230);
    glPopMatrix();
    cloud_move_right(.1);

    glEnd();
}



void hill()
{
    glColor3f(0.627, 0.322, 0.176);
    triangle(-200,-10,100,-50,200);
    glColor3f(0.545, 0.271, 0.075);
    triangle(-250,-60,100,-100,200);
    glColor3f(0.502, 0.502, 0.000);
    triangle(-590,-60,100,-210,190);
    glColor3f(0.333, 0.420, 0.184);
    triangle(-590,-60,100,-290,190);
}
void soil()
{
    glColor3f(0.604, 0.804, 0.196);
    rectangle(60,-10,300,130);
      //  glColor3f(	0.196, 0.804, 0.196);
     triangle(-70,-50,60,60,130);
     triangle(-60,-100,-360,150,130);
}

void river()
{
 glColor3f(0.251, 0.878, 0.816);
    rectangle(-300,-10,200,130);

}
void ground()
{
     glColor3f(0.722, 0.525, 0.043);
     rectangle(-300,-300,300,-10);

}
void road()
{
        //Road Area
        glColor3f(0.3, 0.3, 0.3);
        rectangle(-300,-140,300,-30);
        //road side broader up
        glColor3f(0.0, 0.0, 0.0);
       // rectangle(-300,-30,300,-33);
        //road side broader down
        glColor3f(0.0, 0.0, 0.0);
        //rectangle(-300,-143,300,-140);

        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-80,-230,-86);
        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-80,-200,-86);
        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(-150,-80,0,-86);
        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(50,-80,150,-86);
        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(200,-80,290,-86);

}

/////////////Shuvo rahman////////////
void decoration()
{
    //traffic light
     glColor3f(	0.412, 0.412, 0.412);
     rectangle(45,63,42,-10);
     glColor3f(0.184, 0.310, 0.310);
     rectangle(49,60,39,100);
     glColor3f(1.000, 0.000, 0.000);
     circle(3,4,44,90);
     glColor3f(0.196, 0.804, 0.196);
     circle(3,4,44,80);
     glColor3f(	1.000, 0.549, 0.000);
     circle(3,4,44,70);

     //piller
     glColor3f(	1.000, 0.843, 0.000);
     rectangle(-230,30,-235,-20);
     rectangle(-200,30,-205,-20);
     rectangle(-170,30,-175,-20);
     rectangle(-140,30,-145,-20);
     rectangle(-110,30,-115,-20);

     glColor3f(	0.000, 0.000, 0.000);
     rectangle(-230,25,-235,20);
     rectangle(-200,25,-205,20);
     rectangle(-170,25,-175,20);
     rectangle(-140,25,-145,20);
     rectangle(-110,25,-115,20);
     rectangle(-230,-20,-235,-15);
     rectangle(-200,-20,-205,-15);
     rectangle(-170,-20,-175,-15);
     rectangle(-140,-20,-145,-15);
     rectangle(-110,-20,-115,-15);



}
void tree(int a,int b,int c,int d, int e,int f,int g, int h , int i)
{
   glColor3f(0.502, 0.000, 0.000);
   rectangle(a,b,c,d);
   glColor3f(0.133, 0.545, 0.133);
   triangle(e,f,g,h,i);

}
void tree1()
{
    tree(0,130,2,140,-5,140,7,1,170);
    tree(30,130,32,140,25,140,37,31,170);
    tree(60,130,62,140,55,140,67,61,170);
    tree(90,130,92,140,85,140,97,91,170);
    tree(120,130,122,140,115,140,127,121,170);
    tree(150,130,152,140,145,140,157,151,170);
    tree(180,130,182,140,175,140,187,181,170);
    tree(210,130,212,140,205,140,217,211,170);
    tree(240,130,242,140,235,140,247,241,170);
    tree(270,130,272,140,265,140,277,271,170);
    tree(300,130,302,140,295,140,307,301,170);
    tree(330,130,332,140,325,140,337,331,170);
}

void make_tree2()
{
    glColor3f(0.000, 0.392, 0.000);
    circle(20,30,0,0);
    circle(20,30,20,0);
    circle(20,30,40,0);
    circle(20,30,30,30);
    circle(20,30,10,30);
    circle(20,30,10,-30);
    circle(20,30,30,-30);

    circle(10,20,50,-70);
    circle(10,20,60,-60);
    circle(10,20,60,-80);


    glColor3f(	0.804, 0.522, 0.247);
    rectangle1(10,-130,30,-130,10,-30,30,-30);
    rectangle1(10,-30,17,-30,5,0,5,0);
    rectangle1(17,-30,22,-30,19,0,19,0);
    rectangle1(22,-30,30,-30,35,0,35,0);
    rectangle1(30,-90,30,-100,55,-70,55,-75);
}
void tree2()
{
    glPushMatrix();
    glTranslated(-320,120,0);
    make_tree2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(270,120,0);
    make_tree2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(100,120,0);
    make_tree2();
    glPopMatrix();

}
void house()
{
    glColor3f(	0.184, 0.310, 0.310);
    rectangle1(200,-9,350,-9,200,80,350,80);
    rectangle1(200,80,250,80,200,120,250,120);
    glColor3f(0.373, 0.620, 0.627);
    triangle(195,120,255,225,150);

    glColor3f(1.000, 1.000, 0.000);
    rectangle1(215,95,235,95,215,115,235,115);

    glColor3f(	0.941, 0.902, 0.549);
    rectangle1(220,-9,250,-9,220,40,250,40);


}

//////..........//////
void make_plane()
{
    glColor3f(	0.282, 0.239, 0.545);
    circle(20,15,0,0);
    rectangle(0,-15,70,15);
    glColor3f(1.000, 0.000, 0.000);
    rectangle1(70,-15,90,35,70,15,90,40);
    glColor3f(1.0, 0.0, 0.0);
    rectangle1(30,15,50,15,60,35,55,30);

glColor3f(1.0, 1.0, 1.0);
circle(5,5,10,0);
circle(5,5,30,0);
circle(5,5,50,0);
circle(5,5,65,0);
rectangle(-5,-5,0,10);


}
void planeMove(){
pm=pm-.5;
    if(pm<-500)
        pm = 300;
        glutPostRedisplay();
}

void plane()
{
    planeMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(pm,250,0);
     make_plane();
     glPopMatrix();

    }
}

///car part////
void makeprivatecar(){
    glColor3f(0.902, 0.902, 0.980);
    circle(8,14,2,1);
    rectangle(0,-10,60,15);
    rectangle1(60,-10,80,-10,60,15,80,5);

    glColor3f(0, 0, 0);
    triangle(5,15,20,20,40);
    glColor3f(0.184, 0.310, 0.310);
    triangle(40,15,60,40,40);
    glColor3f(0, 0, 0);
    rectangle(20,15,40,40);


    glColor3f(0, 0, 0);
    circle(7,14,10,-10);
    circle(7,14,60,-10);

    glColor3f(1.000, 0.973, 0.863);
    circle(5,10,10,-10);
    circle(5,10,60,-10);
//car2
    glColor3f(1.000, 0.627, 0.478);
    rectangle(-220,-10,-150,15);

    glColor3f(0, 0, 0);
    glColor3f(0.184, 0.310, 0.310);
    triangle(-190,15,-150,-170,40);
    glColor3f(0, 0, 0);
    rectangle(-190,15,-170,40);


    glColor3f(0, 0, 0);
    circle(7,14,-170,-10);
    circle(7,14,-205,-10);

    glColor3f(1.000, 0.973, 0.863);
    circle(5,10,-170,-10);
    circle(5,10,-205,-10);
}
void privatecarMove(){
cm=cm+.9;
    if(cm>500)
        cm = -500;
        glutPostRedisplay();
}

void privatecar()
{
    privatecarMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(cm,-50,0);
     makeprivatecar();
     glPopMatrix();

    }
}
void makeprivatecar2(){
    glColor3f(0.780, 0.082, 0.522);

    rectangle(0,-10,60,15);
    rectangle1(-15,-10,0,-10,-15,10,0,15);

    glColor3f(0.098, 0.098, 0.439);
    triangle(5,15,20,20,40);
    glColor3f(0, 0, 0);
    triangle(55,15,60,55,40);
    glColor3f(0, 0, 0);
    rectangle(20,15,55,40);

    glColor3f(0, 0, 0);
    circle(7,14,0,-10);
    circle(7,14,45,-10);

    glColor3f(1.000, 0.973, 0.863);
    circle(5,10,0,-10);
    circle(5,10,45,-10);


//car2
    glColor3f(1.000, 0.000, 0.000);
    rectangle(-220,-10,-150,15);
    circle(6,12,-218,2);


    glColor3f(	0.294, 0.000, 0.510);
    triangle(-190,15,-150,-170,40);
    triangle(-190,15,-200,-190,40);
    glColor3f(0, 0, 0);
    rectangle(-190,15,-170,40);



    glColor3f(0, 0, 0);
    circle(7,14,-170,-10);
    circle(7,14,-205,-10);

    glColor3f(1.000, 0.973, 0.863);
    circle(5,10,-170,-10);
    circle(5,10,-205,-10);
}
void privatecarMove2(){
cm2=cm2-.9;
    if(cm2<-500)
        cm2 = 500;
        glutPostRedisplay();
}

void privatecar2()
{
    privatecarMove2();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(cm2,-115,0);
     makeprivatecar2();
     glPopMatrix();

    }
}


//////men part///
void makeman()
{
    //boy
    //head
    glColor3f(1.000, 0.855, 0.725);
    rectangle(63,50,67,60);
    rectangle(61,60,68,75);
    glColor3f(0.000, 0.000, 0.000);
    rectangle(67,62,68,75);
    rectangle(60,62,61,75);
    rectangle(61,70,68,75);

    rectangle(61,68,63,66);
    rectangle(65,68,67,66);

    //body
    glColor3f(0.698, 0.133, 0.133);
    rectangle(60,20,70,50);
    circle(8,8,65,50);

    //leg
    glColor3f(	0.902, 0.902, 0.980);
    rectangle(61,20,64,-5);
    rectangle(66,20,69,-5);
    glColor3f(0.000, 0.000, 0.000);
    rectangle(60,-5,64,-8);
    rectangle(65,-5,69,-8);

   //lefthand
    glColor3f(	0.698, 0.133, 0.133);
    rectangle(70,50,73,40);
    glColor3f( 1.000, 0.855, 0.725);
    rectangle(70,45,73,28);
     //righthand
    glColor3f(0.698, 0.133, 0.133);
    rectangle(60,50,57,40);
    glColor3f(1.000, 0.855, 0.725);
    rectangle(60,45,57,28);
}

void makeboy()
{
    //boy
    //head
    glColor3f(1.000, 0.855, 0.725);
    rectangle(63,50,67,60);
    rectangle(61,60,68,75);
    glColor3f(0.000, 0.000, 0.000);
    rectangle(66,62,68,75);
    rectangle(61,70,68,75);

    rectangle(61,68,63,66);

    //body
    glColor3f(	0.502, 0.502, 0.000);
    rectangle(60,20,70,50);
    circle(5,7,65,50);

    //leg
    glColor3f(0.098, 0.098, 0.439);
    rectangle(61,20,64,-5);
    rectangle(66,20,69,-5);
    glColor3f(1.000, 1.000, 0.000);
    rectangle(60,-5,64,-8);
    rectangle(65,-5,69,-8);

   //lefthand
    glColor3f(0.098, 0.098, 0.439);
    rectangle(64,50,67,25);
    glColor3f( 1.000, 0.855, 0.725);
    rectangle(64,25,67,28);
}
void boyMove(){
bym=bym-.4;
    if(bym<-400)
        bym = 400;
        glutPostRedisplay();
}

void boy()
{
    boyMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(bym,-160,0);
     makeboy();
     glPopMatrix();

    }
}

void makegirl(){
 /////////girl////////
     //head
    glColor3f(1.000, 0.855,0.725);
    rectangle(33,50,37,60);
    rectangle(32,60,39,75);
    glColor3f(0.000, 0.000, 0.000);
    rectangle(30,70,40,75);
    rectangle(36,68,38,66);
   //leg
    glColor3f(1.000, 0.855, 0.725);
    rectangle(31,20,34,-5);
    rectangle(36,20,39,-5);
    glColor3f(0.545, 0.000, 0.000);
    rectangle(30,-5,35,-8);
    rectangle(36,-5,41,-8);
    //body

    glColor3f(1.000, 0.000, 1.000);
    rectangle(30,20,39,50);
    circle(5,7,35,50);
    circle(5,6,37,48);
    glColor3f(0.416, 0.353, 0.804);
    rectangle1(39,35,30,35,44,15,26,15);
   //hair layer
    glColor3f(0.000, 0.000, 0.000);
    rectangle(30,50,33,75);



   //lefthand
    glColor3f(0.098, 0.098, 0.439);
    rectangle(34,50,37,25);
    glColor3f( 1.000, 0.855, 0.725);
    rectangle(34,25,37,28);

}
void girlMove1(){
gm=gm+.4;
    if(gm>350)
        gm = -350;
        glutPostRedisplay();
}

void girl1()
{
    girlMove1();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(gm,-170,0);
     makegirl();
     glPopMatrix();

    }
}
void girlMove2(){
gm2=gm2+.6;
    if(gm2>350)
        gm2 = -350;
        glutPostRedisplay();
}

void girl2()
{
    girlMove2();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(gm2,-170,0);
     makegirl();
     glPopMatrix();

    }
}


/////ship part////
void shipstation(){

     glColor3f(0.627, 0.322, 0.176);
     rectangle1(-80,30,-40,30,-10,80,30,80);
     rectangle1(-105,40,-30,40,-90,50,-30,50);
     rectangle1(-65,65,-10,65,-50,75,-10,75);

     glColor3f(0.545, 0.271, 0.075);
     rectangle(-98,25,-95,40);
     rectangle(-75,10,-70,30);
     rectangle(-45,10,-40,30);
     rectangle(25,80,20,60);
     rectangle(-56,55,-53,65);


}


void makeship(){

    glColor3f(0.184, 0.310, 0.310);
    rectangle(-190,30,-110,50);
    triangle(-190,50,-210,-190,30);
    triangle(-110,50,-105,-110,30);

     glColor3f(1.000, 1.000, 0.000);
     rectangle(-180,50,-115,70);
     triangle(-180,50,-200,-180,70);
     triangle(-115,50,-110,-115,70);

     glColor3f(0.184, 0.310, 0.310);
     rectangle(-160,70,-120,90);
     triangle(-120,70,-115,-120,90);
     triangle(-160,70,-175,-160,90);

     glColor3f(0.753, 0.753, 0.753);
     rectangle(-165,77,-140,84);
     triangle(-165,77,-169,-165,85);

     glColor3f(0.0, 0.0, 0.0);
     rectangle(-135,90,-125,110);
     rectangle(-155,90,-145,110);

     rectangle(-160,77,-161,84);
     rectangle(-150,77,-151,84);
     rectangle(-140,77,-141,84);

     glColor3f(0.0, 0.0, 0.0);
       circle(3,4,-180,60);
       circle(3,4,-170,60);
       circle(3,4,-160,60);
       circle(3,4,-150,60);
       circle(3,4,-140,60);
       circle(3,4,-130,60);
       circle(3,4,-120,60);
}

void shipMove(){
sm=sm-.08;
    if(sm<-200)
        sm = 50;
     glutPostRedisplay();
}

void ship()
{
   shipMove();
   for(int i=0;i<1;i++)
     {
     glPushMatrix();
     glTranslatef(sm,35,0);
     makeship();
     glPopMatrix();
    }
}

void street()
{
        //Road Area
        glColor3f(0.753, 0.753, 0.753);
        rectangle(-300,-185,300,-150);
        glColor3f(0.663, 0.663, 0.663);
        rectangle(-300,-210,300,-185);
        //road side broader down
        glColor3f(0.412, 0.412, 0.412);
        //rectangle(-300,-150,300,-148);
        //road side broader up
        glColor3f(0.412, 0.412, 0.412);
     //   rectangle(-300,-185,300,-187);
        //road side broader down
        glColor3f(0.412, 0.412, 0.412);
        //rectangle(-300,-210,300,-212);

        //divider
        glColor3f(0.412, 0.412, 0.412);
        rectangle(-290,-210,-291,-185);
        rectangle(-245,-210,-246,-185);
        rectangle(-200,-210,-201,-185);
        rectangle(-155,-210,-156,-185);
        rectangle(-110,-210,-111,-185);
        rectangle(-65,-210,-66,-185);
        rectangle(-20,-210,-21,-185);
        rectangle(25,-210,26,-185);
        rectangle(70,-210,71,-185);
        rectangle(115,-210,116,-185);
        rectangle(160,-210,161,-185);
        rectangle(205,-210,206,-185);
        rectangle(250,-210,251,-185);
        rectangle(295,-210,296,-185);
        int i = 0;

        glColor3f(	0.827, 0.827, 0.827);
        glBegin(GL_QUADS);
        for(i=-300;i<=300;i=i+45){

        glVertex2d(i+8,-185);
        glVertex2d(i+9,-185);
        glVertex2d(i+25,-150);
        glVertex2d(i+26,-150);

    }
      glEnd();
}
/////train part/////
void railline()
{
    glColor3f(0,0,0);
    rectangle(-300,-235,300,-240);
    rectangle(-300,-260,300,-265);
    int i = 0;

    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    for(i=-305;i<=300;i=i+30){

        glVertex2d(i,-270);
        glVertex2d(i+5,-270);
        glVertex2d(i+20,-230);
        glVertex2d(i+25,-230);

    }
    glEnd();

}

void maketrain()
{
    glColor3f(0, 0, 0);
    circle(8,15,-70,-2);
    circle(8,15,-53,-2);

    circle(8,15,-20,-2);
    circle(8,15,-3,-2);

    circle(8,15,30,-2);
    circle(8,15,47,-2);

    circle(8,15,75,-2);
    circle(8,15,93,-2);

    circle(8,15,125,-2);
    circle(8,15,142,-2);

    circle(8,15,170,-2);
    circle(8,15,188,-2);

    rectangle(-70,0,-70,2);

    glColor3f(	0.902, 0.902, 0.980);
    rectangle(-70,0,12,60);
    rectangle(15,0,110,60);
    rectangle(113,0,200,60);

    glColor3f(	0.482, 0.408, 0.933);
    rectangle1(-110,0,-70,0,-110,20,-70,60);
    glColor3f(0.482, 0.408, 0.933);
    circle(10,10,-107,10);
    glColor3f(0.098, 0.098, 0.439);
    triangle(-70,20,-110,-70,60);

    glColor3f(0.647, 0.165, 0.165);
    rectangle(-60,10,-50,50);
    rectangle(-45,30,-35,50);
    rectangle(-30,30,-20,50);
    rectangle(-15,30,-5,50);
    rectangle(-0,30,10,50);

    rectangle(30,30,40,50);
    rectangle(45,30,55,50);
    rectangle(60,10,70,50);
    rectangle(75,30,85,50);
    rectangle(90,30,99,50);
    rectangle(120,30,130,50);
    rectangle(135,30,145,50);
    rectangle(150,10,160,50);
    rectangle(165,30,175,50);
    rectangle(180,30,190,50);

}

void trainmove()
{
tm=tm-1.2;
    if(tm<-500)
        tm = 500;
        glutPostRedisplay();
}
void rail()
{
    //trainmove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(tm,-245,0);
     maketrain();
     glPopMatrix();

    }

}

void Rain(int value){

if(rainday){

    _rain += 1.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=5000; y%=500;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(1, Rain,10);

    glFlush();

    }
}

void spinDisplay_left()
{
   spin = spin - .3;

  glutPostRedisplay();
}
void fan()
{
    glColor3f(1, 1, 1);
rectangle1(-3,0,0,-30,0,30,3,0);
}
void windmil()
{
    glColor3f(0.502, 0.502, 0.502);
    rectangle1(-6,-90,6,-90,-3,4,3,4);
    spinDisplay_left();
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 10.0);
    fan();
    glPopMatrix();
}

void windmail()
{
    glPushMatrix();
    glTranslated(60,190,0);
    windmil();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-20,190,0);
    windmil();
    glPopMatrix();

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Sun();
    cloud();
    hill();
    river();
    soil();
    ground();
    road();
    ship();
    tree1();
    makeman();
    windmail();
    tree2();
    shipstation();
    house();
    plane();
    street();
    railline();
    rail();
    decoration();
    privatecar();
    privatecar2();
    boy();
    girl1();
    girl2();
    glFlush();

}

void init()
{
glClearColor(0.3, .65, 1, 1.0);
glOrtho(-300,300,-300,300,-150,500);
}

void my_keyboard(unsigned char key, int x, int y)
{

switch (key) {

case 'r':
rainday = true;
Rain(_rain);
break;

case 'e':
rainday = false;
break;

case 't':
glutIdleFunc(trainmove);
break;

case 'n':
night = true;
Night(_nt);
sun=false;
break;

case 'd':
sun=true;
night = false;
glClearColor(0.3, .65, 1, 1.0);

break;

default:

break;
}
}
int main()
{
    cout << "**********Welcome to our beautiful FENI***********" << endl;
    cout << "press 'T' FOR TRAIN " << endl;
    cout << "press 'N' FOR NIGHT " << endl;
    cout << "press 'D' FOR DAY " << endl;
    cout << "press 'R' FOR RAIN " << endl;
    cout << "press 'E' FOR STOPRAIN " << endl;
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1200,600);
    glutInitWindowPosition(400,150);
    glutCreateWindow("Beautiful Feni City view");
    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}

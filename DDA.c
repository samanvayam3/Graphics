#include<graphics.h>
#include<conio.h>

int a0,a1,b0,b1;
float m;
char A[15],B[15],slope[15];

void plot(int x0,int y0,int x1,int y1)
{ int i;
  float x,y,dx,dy,steps;
  a0=x0;
  b0=y0;
  a1=x1;
  b1=y1;
  dx=(float)(x1-x0);
  dy=(float)(y1-y0);
  m=dy/dx;
  if(dx>=dy)
  { steps=dx; }
  else
  { steps=dy; }
  dx=dx/steps;
  dy=dy/steps;
  x=x0;
  y=y0;
  for(i=0;i<=steps;i++)
  { putpixel(x,y,15);
    x=x+dx;
    y=y+dy;
    delay(25);
  }
}

void main()
{ int gd=DETECT,gm,i;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  for(i=0;i<640;i=i+160)
  { line(i,0,i,getmaxy()); }
  line(getmaxx(),0,getmaxx(),getmaxy());
  for(i=0;i<480;i=i+240)
  { line(0,i,getmaxx(),i); }
  line(0,getmaxy(),getmaxx(),getmaxy());

  //Block(1,1):-
  delay(1000);
  outtextxy(38,20,"-: CGMT :-");
  delay(1000);
  outtextxy(10,50,"# Program - 4 :-");
  delay(1000);
  outtextxy(10,80,"Aim : To execute");
  outtextxy(60,95,"DDA line");
  outtextxy(60,110,"drawing");
  outtextxy(60,125,"algorithm.");
  delay(1000);
  outtextxy(50,155,"Ashish Singla");
  outtextxy(65,165,"00520902719");
  delay(1000);
  outtextxy(12,200,"Lines drawn using");
  outtextxy(12,215,"DDA Algorithm --->");

  //Block(1,2):-
  delay(1000);
  outtextxy(170,15,"* CASE - 1 :-");
  delay(800);
  outtextxy(170,40,"=> x0=y0=x1=y1");
  delay(800);
  plot(200,200,200,200);
  setcolor(4);
  circle(200,200,1);
  setcolor(15);
  delay(800);
  circle(200,200,20);
  delay(800);
  sprintf(A,"A(%d,%d)",a0,b0);
  outtextxy(200,120,A);
  delay(800);
  sprintf(B,"B(%d,%d)",a1,b1);
  outtextxy(200,140,B);

  //Block(1,3):-
  delay(800);
  outtextxy(330,15,"* CASE - 2 :-");
  delay(800);
  outtextxy(330,40,"=> x0=x1");
  delay(800);
  outtextxy(330,55,"=> y0!=y1");
  setcolor(4);
  circle(350,125,1);
  circle(350,185,1);
  setcolor(15);
  plot(350,125,350,185);
  delay(800);
  sprintf(A,"A(%d,%d)",a0,b0);
  outtextxy(340,110,A);
  delay(800);
  sprintf(slope,"Slope = %.2f",m);
  outtextxy(360,150,slope);
  delay(800);
  sprintf(B,"B(%d,%d)",a1,b1);
  outtextxy(340,195,B);

  //Block(1,4):-
  delay(800);
  outtextxy(490,15,"* CASE - 3 :-");
  delay(800);
  outtextxy(490,40,"=> x0!=x1");
  delay(800);
  outtextxy(490,55,"=> y0=y1");
  setcolor(4);
  circle(500,155,1);
  circle(600,155,1);
  setcolor(15);
  plot(500,155,600,155);
  delay(800);
  sprintf(slope,"Slope = %.2f",m);
  outtextxy(520,110,slope);
  delay(800);
  sprintf(A,"A(%d,%d)",a0,b0);
  outtextxy(490,140,A);
  delay(800);
  sprintf(B,"B(%d,%d)",a1,b1);
  outtextxy(550,165,B);

  //Block(2,1):-
  delay(800);
  outtextxy(10,260,"* CASE - 4 :-");
  delay(800);
  outtextxy(10,285,"=> Slope +ve");
  delay(800);
  outtextxy(10,300,"=> Slope > 1");
  setcolor(4);
  circle(20,350,1);
  circle(80,450,1);
  setcolor(15);
  plot(20,350,80,450);
  delay(800);
  sprintf(A,"A(%d,%d)",a0,b0);
  outtextxy(10,335,A);
  delay(800);
  sprintf(slope,"Slope = %.2f",m);
  outtextxy(((a0+a1)/2)+5,((b0+b1)/2)-15,slope);
  delay(800);
  sprintf(B,"B(%d,%d)",a1,b1);
  outtextxy(70,460,B);

  //Block(2,2):-
  delay(800);
  outtextxy(170,260,"* CASE - 5 :-");
  delay(800);
  outtextxy(170,285,"=> Slope -ve");
  delay(800);
  outtextxy(170,300,"=> Slope > -1");
  setcolor(4);
  circle(310,350,1);
  circle(190,450,1);
  setcolor(15);
  plot(310,350,190,450);
  delay(800);
  sprintf(A,"A(%d,%d)",a0,b0);
  outtextxy(240,335,A);
  delay(800);
  sprintf(slope,"Slope = %.2f",m);
  outtextxy(((a0+a1)/2)-80,((b0+b1)/2)-35,slope);
  delay(800);
  sprintf(B,"B(%d,%d)",a1,b1);
  outtextxy(170,460,B);

  //Block(2,3):-
  delay(800);
  outtextxy(330,260,"* CASE - 6 :-");
  delay(800);
  outtextxy(330,285,"=> Slope +ve");
  delay(800);
  outtextxy(330,300,"=> Slope < 1");
  setcolor(4);
  circle(330,350,1);
  circle(465,450,1);
  setcolor(15);
  plot(330,350,465,450);
  delay(800);
  sprintf(A,"A(%d,%d)",a0,b0);
  outtextxy(330,335,A);
  delay(800);
  sprintf(slope,"Slope = %.2f",m);
  outtextxy(((a0+a1)/2)-20,((b0+b1)/2)-35,slope);
  delay(800);
  sprintf(B,"B(%d,%d)",a1,b1);
  outtextxy(400,460,B);

  //Block(2,4):-
  delay(800);
  outtextxy(490,260,"* CASE - 7 :-");
  delay(800);
  outtextxy(490,285,"=> Slope -ve");
  delay(800);
  outtextxy(490,300,"=> Slope < -1");
  setcolor(4);
  circle(620,350,1);
  circle(550,450,1);
  setcolor(15);
  plot(620,350,550,450);
  delay(800);
  sprintf(A,"A(%d,%d)",a0,b0);
  outtextxy(560,335,A);
  delay(800);
  sprintf(slope,"Slope = %.2f",m);
  outtextxy(((a0+a1)/2)-90,((b0+b1)/2)-35,slope);
  delay(800);
  sprintf(B,"B(%d,%d)",a1,b1);
  outtextxy(490,460,B);

  getch();
  closegraph();
}

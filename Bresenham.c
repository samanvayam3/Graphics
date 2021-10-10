#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

int i,x,y,dx,dy,a0,a1,b0,b1;
float m;
char A[15],B[15],slope[15];

void slope0p1(int x0,int y0,int x1,int y1)
{ int p;
  x=x0;
  y=y0;
  dx=x1-x0;
  dy=y1-y0;
  p=2*dy-dx;
  while(x!=x1+1)
  { putpixel(x,y,2);
    delay(25);
    if(p<=0)
    { p=p+2*dy; }
    else
    { y=y+1;
      p=p+2*dy-2*dx;
    }
    x++;
  }
}

void slope1pinf(int x0,int y0,int x1,int y1)
{ int p;
  x=x0;
  y=y0;
  dx=x1-x0;
  dy=y1-y0;
  p=2*dx-dy;
  while(y!=y1+1)
  { putpixel(x,y,3);
    delay(25);
    if(p<=0)
    { p=p+2*dx; }
    else
    { x=x+1;
      p=p+2*dx-2*dy;
    }
    y++;
  }
}

void slope0n1(int x0,int y0,int x1,int y1)
{ int p;
  x=x0;
  y=y0;
  dy=y1-y0;
  x1=2*x0-x1;
  dx=x1-x0;
  p=2*dy-dx;
  while(x!=x1+1)
  { putpixel(2*x0-x,y,4);
    delay(25);
    if(p<=0)
    { p=p+2*dy; }
    else
    { y=y+1;
      p=p+2*dy-2*dx;
    }
    x++;
  }
}

void slopen1ninf(int x0,int y0,int x1,int y1)
{ int p;
  y=y0;
  x1=2*x0-x1;
  dx=x1-x0;
  x=dx;
  dy=y1-y0;
  m=0-(float)dy/dx;
  p=2*dx-dy;
  while(y!=y1+1)
  { putpixel(x1-x,y,3);
    delay(25);
    if(p<=0)
    { p=p+2*dx; }
    else
    { x=x+1;
      p=p+2*dx-2*dy;
    }
    y++;
  }
}

void bresenham(int x0,int y0,int x1,int y1)
{ a0=x0;
  b0=y0;
  a1=x1;
  b1=y1;
  dx=x1-x0;
  dy=y1-y0;
  if(dx==0&&dy==0)
  { m=100; }
  else
  { m=(float)dy/dx; }
  if(m<-1)
  { slopen1ninf(x0,y0,x1,y1); }
  else if(m>=-1&&m<0)
  { slope0n1(x0,y0,x1,y1); }
  else if(m>=0&&m<1)
  { slope0p1(x0,y0,x1,y1); }
  else if(m>=1)
  { slope1pinf(x0,y0,x1,y1); }
  else
  { slope0p1(x0,y0,x1,y1); }
}

void frame()
{ for(i=0;i<640;i=i+160)
  { line(i,0,i,getmaxy()); }
  line(getmaxx(),0,getmaxx(),getmaxy());
  for(i=0;i<480;i=i+240)
  { line(0,i,getmaxx(),i); }
  line(0,getmaxy(),getmaxx(),getmaxy());
}

void main()
{ int gd=DETECT,gm,i;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  //Block(1,1):-
  delay(1000);
  outtextxy(38,20,"-: CGMT :-");
  delay(1000);
  outtextxy(10,50,"# Program - 5 :-");
  delay(1000);
  outtextxy(10,80,"Aim : To execute");
  outtextxy(60,95,"Bresenham's");
  outtextxy(50,110,"line drawing");
  outtextxy(60,125,"algorithm.");
  delay(1000);
  outtextxy(50,155,"Ashish Singla");
  outtextxy(65,165,"00520902719");
  delay(1000);
  outtextxy(8,200,"Lines drawn using");
  outtextxy(8,215,"Bresenham's Algo ->");



  bresenham(620,350,550,450);



  getch();
  closegraph();
}

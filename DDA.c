#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

int i=0;

void frame()
{ line(0,0,getmaxx(),0);
  line(0,0,0,getmaxy());
  line(0,getmaxy(),getmaxx(),getmaxy());
  line(getmaxx(),0,getmaxx(),getmaxy());
  line(0,30,getmaxx(),30);
}

void pause()
{ outtextxy(10,450,"Press any key to contine ...");
  getch();
}

void slide1()
{ frame();
  delay(250);
  outtextxy(270,12,"-: Line :-");
  delay(500);
  outtextxy(10,40,"* (x1,y1) : (100,250)");
  delay(500);
  outtextxy(10,50,"* (x2,y2) : (250,100)");
  delay(500);
  line(100,250,250,100);
  delay(500);
  outtextxy(10,60,"* Translation : dx = 88");
  outtextxy(10,70,"              : dy = 88");
  delay(1000);
  for(i=0;i<89;i++)
  { frame();
    outtextxy(270,12,"-: Line :-");
    outtextxy(10,40,"* (x1,y1) : (100,250)");
    outtextxy(10,50,"* (x2,y2) : (250,100)");
    outtextxy(10,60,"* Translating : dx = 88");
    outtextxy(10,70,"              : dy = 88");
    line(100+i,250+i,250+i,100+i);
    delay(23);
    cleardevice();
  }
  frame();
  outtextxy(270,12,"-: Line :-");
  outtextxy(15,50,"* (x1,y1) : (100,250)");
  outtextxy(15,65,"* (x2,y2) : (250,100)");
  outtextxy(15,80,"* Translated : dx = 88");
  outtextxy(15,95,"             : dy = 88");
  outtextxy(15,110,"* Scaling : 1.5x");
  line(187,337,337,187);
  delay(1000);
  line(100*1.5,250*1.5,250*1.5,100*1.5);
  delay(1000);
  for(i=0;i<151;i++)
  { frame();
    outtextxy(270,12,"-: Line :-");
    outtextxy(15,50,"* (x1,y1) : (100,250)");
    outtextxy(15,65,"* (x2,y2) : (250,100)");
    outtextxy(15,80,"* Translated : dx = 88");
    outtextxy(15,95,"             : dy = 88");
    outtextxy(15,110,"* Scaled : 1.5x");
    outtextxy(15,125,"* Translating : dx = 150");
    outtextxy(15,140,"              : dy = 0");
    line(150+i,375,375+i,150);
    delay(20);
    cleardevice();
  }
  frame();
  outtextxy(270,12,"-: Line :-");
  outtextxy(15,50,"* (x1,y1) : (100,250)");
  outtextxy(15,65,"* (x2,y2) : (250,100)");
  outtextxy(15,80,"* Translated : dx = 88");
  outtextxy(15,95,"             : dy = 88");
  outtextxy(15,110,"* Scaled : 1.5x");
  outtextxy(15,125,"* Translated : dx = 150");
  outtextxy(15,140,"             : dy = 0");
  line(150+i,375,375+i,150);
}

void slide2()
{ outtextxy(265,12,"-: Circle :-");
  outtextxy(15,50,"* Center : (350,457)");
  outtextxy(15,65,"* Radius : 87");

  for(i=350;i<401;i++)
  { frame();
    outtextxy(265,12,"-: Circle :-");
    outtextxy(15,50,"* Center : (350,457)");
    outtextxy(15,65,"* Radius : 87");
    outtextxy(15,80,"* Translating to : (400,250)");
    outtextxy(15,95,"* Scaling to : 2x");
    putpixel(i,(-i*i)/500+330,15);
    circle(i,(-i*i)/500+330,i%300);
    delay(50);
    cleardevice();
  }
  frame();
  outtextxy(265,12,"-: Circle :-");
  outtextxy(15,50,"* Center : (350,457)");
  outtextxy(15,65,"* Radius : 87");
  outtextxy(15,80,"* Translated to : (400,250)");
  outtextxy(15,95,"* Scaled to : 2x");
  putpixel(i,(-i*i)/400+330,15);
  circle(i,(-i*i)/400+330,10+i/4);
}

void slide3()
{ float i;
  int j,pts[]={230,140,270,130,285,160,250,170,210,165,230,140};
  frame();
  outtextxy(264,12,"-: Polygon :-");
  delay(500);
  drawpoly(6,pts);
  delay(500);
  for(i=100;i<113;i++)
  { frame();
    outtextxy(264,12,"-: Polygon :-");
    outtextxy(15,50,"* Vertices : {(230,140),(270,130),285,160),(250,170),(210,165)");
    outtextxy(15,65,"* Scaled to : 1.12x");
    for(j=0;j<12;j++)
    { pts[j]=pts[j]*i/100; }
    drawpoly(6,pts);
    delay(150);
    cleardevice();
  }
  frame();
  outtextxy(264,12,"-: Polygon :-");
  outtextxy(15,50,"* Vertices : {(230,140),(270,130),285,160),(250,170),(210,165)");
  outtextxy(15,65,"* Scaled to : 1.12x");
  drawpoly(6,pts);
  delay(500);
  for(i=1;i<16;i++)
  { frame();
    outtextxy(264,12,"-: Polygon :-");
    outtextxy(15,50,"* Vertices : {(230,140),(270,130),285,160),(250,170),(210,165)");
    outtextxy(15,65,"* Scaled to : 1.12x");
    outtextxy(15,80,"* Translated to : dx=50");
    outtextxy(15,95,"                : dy=50");
    for(j=0;j<12;j++)
    { pts[j]=pts[j]-i; }
    drawpoly(6,pts);
    delay(150);
    cleardevice();
  }
  frame();
  outtextxy(264,12,"-: Polygon :-");
  outtextxy(15,50,"* Vertices : {(230,140),(270,130),285,160),(250,170),(210,165)");
  outtextxy(15,65,"* Scaled to : 1.12x");
  outtextxy(15,80,"* Translated to : dx=50");
  outtextxy(15,95,"                : dy=50");
  drawpoly(6,pts);
}

void main()
{ int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  slide1();
  pause();
  slide2();
  pause();
  cleardevice();
  slide3();
  outtextxy(10,450,"Press any key to EXIT ...");
  getch();
  closegraph();
}

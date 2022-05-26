#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void namae(int x,int y,int i=0)
{
	setfillstyle(1,0);
	int p[10]={x+105+i,100,x+120+i,100,x+120+i,y+100,x+105+i,y+100,x+105+i,100};
	fillpoly(5,p);
}

int main()
{
	clrscr();
	int gd=DETECT,gm,x=630,y=470;
	int bk[10]={0,0,x,0,x,y,0,y,0,0};
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setfillstyle(1,15);
	fillpoly(5,bk);
	setlinestyle(0,0,3);
	setcolor(0);
	line(205,100,295,100);
	line(205,250,295,250);
	line(330,100,420,100);
	line(330,250,420,250);
	line(455,100,507,100);
	line(105,100,170,100);
	//top glitch
	line(105,75,540,75);
	line(90,75,95,75);
	line(72,75,82,75);
	line(550,75,560,75);
	line(568,75,573,75);
	//connected glitch
	line(142,130,142,180);
	line(156,250,156,300);
	line(419,250,419,320);
	line(493,250,493,330);
	line(506,250,506,300);
	//bottom glitch
	line(15,350,22,350);
	line(27,350,30,350);
	line(35,350,90,350);
	line(560,350,567,350);
	line(548,350,551,350);
	line(485,350,540,350);
	line(265,380,272,380);
	line(277,380,277,380);
	line(285,380,340,380);
	namae(0,150);
	namae(50,150);
	namae(100,150);
	namae(175,150);
	namae(225,150);
	namae(300,30);
	namae(350,30);
	namae(387,150);
	namae(426,30);
	delay(2000);
	cleardevice();
	closegraph();

	for(int i=0;i<=100;i+=10)
	{
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int c[10]={131+i,100,143+i,100,143+i,130,131+i,130,131+i,100};
	setfillstyle(1,15);
	fillpoly(5,bk);
	fillpoly(5,c);
	namae(0,150,i);
	namae(50,150,i);
	namae(100,150,i);
	namae(175,150,i);
	namae(225,150,i);
	namae(300,30,i);
	c[0]=405+i;
	c[1]=220;
	c[2]=420+i;
	c[3]=220;
	c[4]=420+i;
	c[5]=250;
	c[6]=405+i;
	c[7]=250;
	c[8]=405+i;
	c[9]=220;
	fillpoly(5,c);
	namae(350,30,i);
	namae(387,150,i);
	namae(426,30,i);
	delay(10);
	cleardevice();
	closegraph();
	}

	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setfillstyle(1,15);
	fillpoly(5,bk);
	setlinestyle(0,0,3);
	setcolor(0);
	line(205,100,295,100);
	line(205,250,295,250);
	line(330,100,420,100);
	line(330,250,420,250);
	line(455,100,507,100);
	line(105,100,170,100);
	//top glitch
	line(105,75,540,75);
	line(90,75,95,75);
	line(72,75,82,75);
	line(550,75,560,75);
	line(568,75,573,75);
	//connected glitch
	line(142,130,142,180);
	line(156,250,156,300);
	line(419,250,419,320);
	line(493,250,493,330);
	line(506,250,506,300);
	//bottom glitch
	line(15,350,22,350);
	line(27,350,30,350);
	line(35,350,90,350);
	line(560,350,567,350);
	line(548,350,551,350);
	line(485,350,540,350);
	line(265,380,272,380);
	line(277,380,277,380);
	line(285,380,340,380);
	namae(0,150);
	namae(50,150);
	namae(100,150);
	namae(175,150);
	namae(225,150);
	namae(300,30);
	namae(350,30);
	namae(387,150);
	namae(426,30);
	delay(1000);
	cleardevice();
	closegraph();

	for(i=0;i>-100;i-=10)
	{
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int b[10]={131+i,100,143+i,100,143+i,130,131+i,130,131+i,100};
	setfillstyle(1,15);
	fillpoly(5,bk);
	fillpoly(5,b);
	namae(0,150,i);
	namae(50,150,i);
	namae(100,150,i);
	namae(175,150,i);
	namae(225,150,i);
	namae(300,30,i);
	b[0]=405+i;
	b[1]=220;
	b[2]=420+i;
	b[3]=220;
	b[4]=420+i;
	b[5]=250;
	b[6]=405+i;
	b[7]=250;
	b[8]=405+i;
	b[9]=220;
	fillpoly(5,b);
	namae(350,30,i);
	namae(387,150,i);
	namae(426,30,i);
	delay(10);
	cleardevice();
	closegraph();
	}

	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setfillstyle(1,15);
	fillpoly(5,bk);
	setlinestyle(0,0,3);
	setcolor(0);
	line(205,100,295,100);
	line(205,250,295,250);
	line(330,100,420,100);
	line(330,250,420,250);
	line(455,100,507,100);
	line(105,100,170,100);
	//top glitch
	line(105,75,540,75);
	line(90,75,95,75);
	line(72,75,82,75);
	line(550,75,560,75);
	line(568,75,573,75);
	//connected glitch
	line(142,130,142,180);
	line(156,250,156,300);
	line(419,250,419,320);
	line(493,250,493,330);
	line(506,250,506,300);
	//bottom glitch
	line(15,350,22,350);
	line(27,350,30,350);
	line(35,350,90,350);
	line(560,350,567,350);
	line(548,350,551,350);
	line(485,350,540,350);
	line(265,380,272,380);
	line(277,380,277,380);
	line(285,380,340,380);
	namae(0,150); //m
	int d[10]={131,100,143,100,143,130,131,130,131,100};
	fillpoly(5,d);   //m
	namae(50,150);      //m
	namae(100,150);       //o
	namae(175,150);        //o
	namae(225,150);        //c
	namae(300,30);           //c
	d[0]=405;
	d[1]=220;
	d[2]=420;
	d[3]=220;
	d[4]=420;
	d[5]=250;
	d[6]=405;
	d[7]=250;
	d[8]=405;
	d[9]=220;
	fillpoly(5,d);        //c
	namae(350,30);           //t
	namae(387,150);             //t
	namae(426,30);
	getch();
	cleardevice();
	closegraph();
	return 0;
}

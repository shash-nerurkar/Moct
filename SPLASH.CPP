#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void namae(int x,int y)
{
	setfillstyle(1,0);
	int p[10]={x+105,100,x+120,100,x+120,y+100,x+105,y+100,x+105,100};
	fillpoly(5,p);
}

int main()
{
	clrscr();
	int gd=DETECT,gm,x=630,y=470;
	int bk[10]={0,0,x,0,x,y,0,y,0,0};
	int c[10]={131,100,143,100,143,130,131,130,131,100};
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setfillstyle(9,15);
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
	fillpoly(5,c);   //m
	namae(50,150);      //m
	namae(100,150);       //o
	namae(175,150);        //o
	namae(225,150);        //c
	namae(300,30);           //c
	c[0]=405;
	c[1]=220;
	c[2]=420;
	c[3]=220;
	c[4]=420;
	c[5]=250;
	c[6]=405;
	c[7]=250;
	c[8]=405;
	c[9]=220;
	fillpoly(5,c);        //c
	namae(350,30);           //t
	namae(387,150);             //t
	namae(426,30);               //t
	getch();
	cleardevice();
	closegraph();
	return 0;
}

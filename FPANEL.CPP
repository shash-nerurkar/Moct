#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void box(int x,int y)
{
	int poly[18]={x,y,x+100,y,x+120,y+20,x+120,y+100,x+100,y+120,x,y+120,x-20,y+100,x-20,y+20,x,y};
	fillpoly(9,poly);
}

void infobox(int num,char comment[30])
{
	cout<<comment;
}

int main()
{
	int gd=DETECT,gm,dum=190,x,y,a;
	float change,hp=500;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setfillstyle(1,4);
	box(39,39);
	setfillstyle(1,2);
	box(199,39);
	setfillstyle(1,9);
	box(39,179);
	setfillstyle(1,8);
	box(199,179);
	setcolor(0);
	settextstyle(0,0,2);
	outtextxy(43,99,"ATTACK");
	outtextxy(210,99,"PARRY");
	outtextxy(55,239,"MEND");
	outtextxy(225,239,"RUN");
	setlinestyle(0,0,3);
	int poly[10]={0,377,350,377,350,427,0,427,0,377};
	drawpoly(5,poly);
	moveto(39,39);
	setcolor(14);
	line(getx()+20,gety()-10,getx(),gety()-10);
	line(getx(),gety()-10,getx()-30,gety()+20);
	line(getx()-30,gety()+20,getx()-30,gety()+40);
	line(getx()+80,gety()-10,getx()+100,gety()-10);
	line(getx()+100,gety()-10,getx()+130,gety()+20);
	line(getx()+130,gety()+20,getx()+130,gety()+40);
	line(getx()+80,gety()+130,getx()+100,gety()+130);
	line(getx()+100,gety()+130,getx()+130,gety()+100);
	line(getx()+130,gety()+100,getx()+130,gety()+80);
	line(getx()+20,gety()+130,getx(),gety()+130);
	line(getx(),gety()+130,getx()-30,gety()+100);
	line(getx()-30,gety()+100,getx()-30,gety()+80);
	do
	{
		a=getch();
		x=getx();
		y=gety();
		switch(a)
		{
			case 'w':
				if(y==179)
					moverel(0,-140);
				break;
			case 'a':
				if(x==199)
					moverel(-160,0);
				break;
			case 's':
				if(y==39)
					moverel(0,140);
				break;
			case 'd':
				if(x==39)
					moverel(160,0);
				break;
			case 'e':
				continue;
			default:
				break;
		}
		setcolor(0);
		line(x+20,y-10,x,y-10);
		line(x,y-10,x-30,y+20);
		line(x-30,y+20,x-30,y+40);
		line(x+80,y-10,x+100,y-10);
		line(x+100,y-10,x+130,y+20);
		line(x+130,y+20,x+130,y+40);
		line(x+80,y+130,x+100,y+130);
		line(x+100,y+130,x+130,y+100);
		line(x+130,y+100,x+130,y+80);
		line(x+20,y+130,x,y+130);
		line(x,y+130,x-30,y+100);
		line(x-30,y+100,x-30,y+80);
		setcolor(14);
		line(getx()+20,gety()-10,getx(),gety()-10);
		line(getx(),gety()-10,getx()-30,gety()+20);
		line(getx()-30,gety()+20,getx()-30,gety()+40);
		line(getx()+80,gety()-10,getx()+100,gety()-10);
		line(getx()+100,gety()-10,getx()+130,gety()+20);
		line(getx()+130,gety()+20,getx()+130,gety()+40);
		line(getx()+80,gety()+130,getx()+100,gety()+130);
		line(getx()+100,gety()+130,getx()+130,gety()+100);
		line(getx()+130,gety()+100,getx()+130,gety()+80);
		line(getx()+20,gety()+130,getx(),gety()+130);
		line(getx(),gety()+130,getx()-30,gety()+100);
		line(getx()-30,gety()+100,getx()-30,gety()+80);

	}while(a!='e');
       /*	for(int i=0;i<5;i++)
	{
		setcolor(15);
		line(400-i,160-i,600+i,160-i);
		line(400-i,160-i,400-i,185+i);
		line(600+i,160-i,600+i,185+i);
		line(400-i,185+i,600+i,185+i);
	}
	for(i=0;i<191;i++)
	{
		setcolor(4);
		line(405+i,165,405+i,180);
	}

	for(i=0;i<5;i++)
	{
		setcolor(15);
		line(400-i,90-i,600+i,90-i);
		line(400-i,90-i,400-i,115+i);
		line(600+i,90-i,600+i,115+i);
		line(400-i,115+i,600+i,115+i);
	}
	for(i=0;i<191;i++)
	{
		setcolor(2);
		line(405+i,95,405+i,110);
	}



	while(i>0)
	{
		cout<<"ENTER HEALTH:";
		cin>>hp;
		if(hp<0)
			hp=-hp;
		change=hp/500;
		while(i>=dum-190*change)
		{
			if(i>=0)
			{
				setcolor(0);
				delay(5);
				line(405+i,95,405+i,110);
				i--;
			}
			else
				break;
		}
		dum=i;
		if(i<380/3&&i>190/3)
		{
			while(i>=0)
			{
				setcolor(12);
				line(405+i,95,405+i,110);
				i--;
			}
		}
		if(i<190/3)
		{
			while(i>=0)
			{
				setcolor(4);
				line(405+i,95,405+i,110);
				i--;
			}
		}
		i=dum;
	} */
	getch();
	cleardevice();
	closegraph();
	return 0;
}
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>


class characters
{
	int dpt;
	int ddpt;
	int hp;
	int dhp;
	int sp;
	int dsp;
	float dr;
public:
	~characters(){}
	void altan(char &predict,char &astate,char move);
	void boss1(char &state);
	void boss2(char &state);
	void finalboss(char &predict,char &state);
	friend void mian1(characters &,characters &,char &);
	friend void mian2(characters &,characters &,char &);
	friend void mian3(characters &,characters &,char &);
	void constructor(int,int,int);
};

int critical()
{
	randomize();
	int a=random(20);
	if(a==11)
		return 2.5;
	else
		return 1;
}

void characters::constructor(int x,int y,int z)
{
	hp=x;
	dhp=x;
	dpt=y;
	ddpt=y;
	sp=z;
	dsp=z;
}

void characters::altan(char &predict,char &astate,char move)
{
	int dum,r,i;
	char a=move;
	randomize();
	do
	{
		astate=a;
		dum=0;
		switch(a)
		{
		case 'a':
			r=random(5);
			for(i=0;i<5;i++)
			{
				if(r==i)
					dpt=50+i;
			}
			predict=a;
			break;
		case 'p':
			dr=0.4;
			predict=a;
			break;
		case 'm':
			if(hp<dhp)
			{
				hp=hp+80;
				if(hp>dhp)
					hp=dhp;
				predict=a;
			}
			else
			{
				cout<<"YOUR HEALTH IS FULL!"<<endl;
				getch();
				dum=1;
			}
			break;
		case 'r':
			cout<<"YOU RAN!"<<endl;
		}
	}while(dum==1);
}

void characters::boss1(char &state)
{
	static char a='a';
	int r,i;
	randomize();
	switch(a)
	{
		case 'a':
			r=random(5);
			for(i=0;i<5;i++)
			{
				if(r==i)
					dpt=dpt+i;
			}
			state=a;
			a='m';
			break;
		case 'm':
			hp=hp+25;
			state=a;
			a='p';
			break;
		case 'p':
			dr=0.4;
			state=a;
			a='a';
	}
}

void characters::boss2(char &state)
{
	static char a='a';
	int counter=0,r,i;
	randomize();
	if(counter==5)
	{

		switch(a)
		{
			case 'a':
				r=random(5);
				for(i=0;i<5;i++)
				{
					if(r==i)
						dpt=dpt+i;
				}
				state=a;
				a='m';
				break;
			case 'm':
				hp=hp+25;
				state=a;
				a='p';
				break;
			case 'p':
				dr=0.4;
				state=a;
				a='a';
		}
	}
	else
	{
		switch(a)
		{
		case 'a':
			r=random(5);
			for(i=0;i<5;i++)
			{
				if(r==i)
					dpt=dpt+i;
			}
			state=a;
			a='m';
			counter++;
			break;
		case 'm':
			hp=hp+25;
			state=a;
			a='p';
			counter++;
			break;
		case 'p':
			dr=0.4;
			state=a;
			counter++;
			a='m';
			if(counter==5)
				a='a';
		}
	}
}


void characters::finalboss(char &predict,char &state)
{
	static char a='a',b='a';
	int r,i;
	static int dsp=sp,dum=0;
	sp=dsp;
	dum+=1;
	randomize();
	if(dum<3)
	{
		switch(b)
		{
			case 'a':
				r=random(5);
				for(i=0;i<5;i++)
				{
					if(r==i)
						dpt=dpt+i;
				}
				state=b;
				b='b';
				break;
			case 'b':
				if(predict=='a')
				{
					state='p';
					dr=0.4;
				}
				else
				{
					state='m';
					hp=hp+25;
				}
		}
	}
	else
	{
		switch(a)
		{
			case 'a':
				r=random(5);
				for(i=0;i<5;i++)
				{
					if(r==i)
						dpt=dpt+i;
				}
				state=a;
				a='m';
				break;
			case 'm':
				hp=hp+25;
				state=a;
				a='p';
				break;
			case 'p':
				dr=0.4;
				state=a;
				a='a';
		}
	}
}

void printhealth(int hp,int dpt,int ehp,int edpt)
{
	static int adum=190,edum=190;
	int i=190;
	float change;
	cout<<"YOU DEALT :"<<dpt<<"  ";
	change=(float)edpt/ehp;
	while(i>=adum-190*change)
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
	adum=i;
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
	i=190;
	cout<<"ENEMY DEALT :"<<edpt<<endl;
	change=(float)dpt/hp;
	while(i>=edum-190*change)
	{
		if(i>=0)
		{
			setcolor(0);
			delay(5);
			line(405+i,165,405+i,180);
			i--;
		}
		else
			break;
	}
	edum=i;
	if(i<380/3&&i>190/3)
	{
		while(i>=0)
		{
			setcolor(12);
			line(405+i,165,405+i,180);
			i--;
		}
	}
	if(i<190/3)
	{
		while(i>=0)
		{
			setcolor(4);
			line(405+i,165,405+i,180);
			i--;
		}
	}
}

void box(int x,int y)
{
	int poly[18]={x,y,x+100,y,x+120,y+20,x+120,y+100,x+100,y+120,x,y+120,x-20,y+100,x-20,y+20,x,y};
	fillpoly(9,poly);
}

char keys()
{
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
	char a;
	int x,y,x1,y1;
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
	moveto(39,39);
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
				x1=getx();
				y1=gety();
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
	switch(x1+y1)
	{
		case 78:
			return 'a';
		case 238:
			return 'p';
		case 218:
			return 'm';
		case 378:
			return 'r';
	}
}

void mian1(characters &hero,characters &villain,char &result)
{
	char state,astate,predict,move;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int vcrit,hcrit,p,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	for(int i=0;i<5;i++)
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
	randomize();
	while(hero.hp>0&&villain.hp>0)
	{
		hero.sp=hero.dsp;
		hcrit=critical();
		vcrit=critical();
		villain.sp=villain.dsp;
		move=keys();
		hero.altan(predict,astate,move);
		villain.boss1(state);
		if(hero.sp>villain.sp)
		{
			for(i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero.dpt*hcrit;
			hero.hp=hero.hp-hero.dr*villain.dpt*vcrit;
		}
		if(hero.sp<villain.sp)
		{
			for(i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero.hp=hero.hp-hero.dr*villain.dpt*vcrit;
			villain.hp=villain.hp-villain.dr*hero.dpt*hcrit;
		}
		if(state=='p')
		{
			p=random(50);
			while(p<10)
			{
				p=random(50);
			}
			villain.sp=villain.sp+p;
		}
		if(astate=='p')
		{
			p=random(50);
			while(p<10)
			{
				p=random(50);
			}
			hero.sp=hero.sp+p;
		}
		hero.dr=1;
		villain.dr=1;
		if(state=='a')
			cout<<endl<<"ENEMY ATTACKED!"<<endl;
		if(state=='p')
			cout<<endl<<"ENEMY PARRIED!"<<endl;
		if(state=='m')
			cout<<endl<<"ENEMY MENDED ITS WOUNDS!"<<endl;
		if(hero.hp<0)
			hero.hp=0;
		if(villain.hp<0)
			villain.hp=0;
		printhealth(hero.hp,hero.dpt,villain.hp,villain.dpt);
		getch();
		hero.dpt=villain.dpt=0;
		if(astate=='r')
			exit(1);
	}
	if(hero.hp==0)
	{
		cout<<"YOU LOST!";
		result='l';
	}
	if(villain.hp==0)
	{
		cout<<"YOU WIN!";
		result='w';
	}
	getch();
}

void mian2(characters &hero,characters &villain,char &result)
{
	char state,astate,predict,move;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int vcrit,hcrit,p,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	cout<<"TO ATTACK, ENTER a."<<endl;
	cout<<"TO PARRY, ENTER p."<<endl;
	cout<<"TO MEND, ENTER m."<<endl;
	for(int i=0;i<5;i++)
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
	while(hero.hp>0&&villain.hp>0)
	{
		hero.sp=hero.dsp;
		hcrit=critical();
		vcrit=critical();
		villain.sp=villain.dsp;
		move=keys();
		hero.altan(predict,astate,move);
		villain.boss2(state);
		if(hero.sp>villain.sp)
		{
			for(i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero.dpt*hcrit;
			hero.hp=hero.hp-hero.dr*villain.dpt*vcrit;
		}
		if(hero.sp<villain.sp)
		{
			for(i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero.hp=hero.hp-hero.dr*villain.dpt*vcrit;
			villain.hp=villain.hp-villain.dr*hero.dpt*hcrit;
		}
		if(state=='p')
		{
			p=random(50);
			while(p<10)
			{
				p=random(50);
			}
			villain.sp=villain.sp+p;
		}
		if(astate=='p')
		{
			p=random(50);
			while(p<10)
			{
				p=random(50);
			}
			hero.sp=hero.sp+p;
		}
		hero.dr=1;
		villain.dr=1;
		if(state=='a')
			cout<<endl<<"ENEMY ATTACKED!"<<endl;
		if(state=='p')
			cout<<endl<<"ENEMY PARRIED!"<<endl;
		if(state=='m')
			cout<<endl<<"ENEMY MENDED ITS WOUNDS!"<<endl;
		printhealth(hero.hp,hero.dpt,villain.hp,villain.dpt);
		hero.dpt=villain.dpt=0;
	}
	if(hero.hp==0)
	{
		cout<<"YOU LOST!";
		result='l';
	}
	if(villain.hp==0)
	{
		cout<<"YOU WIN!";
		result='w';
	}
	getch();
}


void mian3(characters &hero,characters &villain,char &result)
{
	char state,astate,predict,move;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int vcrit,hcrit,p,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	cout<<"TO ATTACK, ENTER a."<<endl;
	cout<<"TO PARRY, ENTER p."<<endl;
	cout<<"TO MEND, ENTER m."<<endl;
	for(int i=0;i<5;i++)
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
	while(hero.hp>0&&villain.hp>0)
	{
		hero.sp=hero.dsp;
		villain.sp=villain.dsp;
		hcrit=critical();
		vcrit=critical();
		move=keys();
		hero.altan(predict,astate,move);
		villain.finalboss(predict,state);
		if(hero.sp>villain.sp)
		{
			for(i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero.dpt*hcrit;
			hero.hp=hero.hp-hero.dr*villain.dpt*vcrit;
		}
		if(hero.sp<villain.sp)
		{
			for(i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero.hp=hero.hp-hero.dr*villain.dpt*vcrit;
			villain.hp=villain.hp-villain.dr*hero.dpt*hcrit;
		}
		if(state=='p')
		{
			p=random(50);
			while(p<10)
			{
				p=random(50);
			}
			villain.sp=villain.sp+p;
		}
		if(astate=='p')
		{
			p=random(50);
			while(p<10)
			{
				p=random(50);
			}
			hero.sp=hero.sp+p;
		}
		hero.dr=1;
		villain.dr=1;
		if(state=='a')
			cout<<endl<<"ENEMY ATTACKED!"<<endl;
		if(state=='p')
			cout<<endl<<"ENEMY PARRIED!"<<endl;
		if(state=='m')
			cout<<endl<<"ENEMY MENDED ITS WOUNDS!"<<endl;
		if(hero.hp<0)
			hero.hp=0;
		if(villain.hp<0)
			villain.hp=0;
		printhealth(hero.hp,hero.dpt,villain.hp,villain.dpt);
		hero.dpt=villain.dpt=0;
	}
	if(hero.hp==0)
	{
		cout<<"YOU LOST!";
		result='l';
	}
	if(villain.hp==0)
	{
		cout<<"YOU WIN!";
		result='w';
	}
	hero.hp=hero.dhp;
	hero.dpt=hero.ddpt;
	villain.hp=villain.dhp;
	villain.dpt=villain.ddpt;
	getch();
}


int main()
{
	clrscr();
	char result;
	characters altan,boss1,boss2,finalboss;
	altan.constructor(100,30,75);
	boss1.constructor(210,55,45);
	//boss2.constructor(320,85,100);
	//finalboss.constructor(400,120,150);
	mian1(altan,boss1,result);
      /*	do
	{
		mian1(altan,boss1,result);
		if(result=='l')
		{
			cout<<"TRY AGAIN!";
			getch();
			clrscr();
		}
	}while(result=='l');
	cleardevice();
	closegraph();
	clrscr();
	altan.constructor(170,50,75);
	do
	{
		cout<<"SECOND BOSS.";
		mian2(altan,boss2,result);
		if(result=='l')
		{
			cout<<"TRY AGAIN!";
			getch();
			clrscr();
		}
	}while(result=='l');
	cleardevice();
	closegraph();
	clrscr();
	altan.constructor(250,95,75);
	do
	{
		cout<<"FINAL BOSS.";
		mian3(altan,finalboss,result);
		if(result=='l')
		{
			cout<<"TRY AGAIN!";
			getch();
			clrscr();
		}
	}while(result=='l'); */
	getch();
	closegraph();
	cleardevice();
	return 0;
}
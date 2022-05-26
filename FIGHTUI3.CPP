#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

char keys();

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
	void altan(char &predict,char &astate);
	void boss1(char &state);
	void boss2(char &state);
	void finalboss(char &predict,char &state);
	friend void mian1(characters &,characters &,char &);
	friend void mian2(characters &,characters &,char &);
	friend void mian3(characters &,characters &,char &);
	void constructor(int,int,int);
};

void characters::constructor(int x,int y,int z)
{
	hp=x;
	dhp=x;
	dpt=y;
	ddpt=y;
	sp=z;
	dsp=z;
}

void characters::altan(char &predict,char &astate)
{
	int dum,r;
	int diabox[]={395,350,675,350,675,479,395,479,395,350};
	char a;
	randomize();
	do
	{
		dum=0;
		setcolor(15);
		setfillstyle(1,15);
		fillpoly(5,diabox);
		a=keys();
		astate=a;
		switch(a)
		{
		case 'a':
			r=random(5);
			dpt=ddpt+r;
			predict=a;
			break;
		case 'p':
			dr=0.4;
			predict=a;
			break;
		case 'm':
			if(hp<dhp)
			{
				hp=hp+30;
				if(hp>dhp)
					hp=dhp;
				predict=a;
			}
			else
			{
				setcolor(0);
				outtextxy(410,385,"YOUR HEALTH IS FULL!");
				getch();
				dum=1;
			}
			break;
		case 'r':
			setcolor(0);
			outtextxy(410,385,"YOU RAN!");
		}
	}while(dum==1);
}

void characters::boss1(char &state)
{
	static char a='a';
	int r,x;
	randomize();
	do
    {
        switch(a)
        {
            case 'a':
                r=random(5);
                dpt=ddpt+r;
                state=a;
		x=0;
                a='m';
                break;
            case 'm':
                if(hp<=185)
                {
                    hp=hp+25;
                    state=a;
                    a='p';
                    x=0;
                }
                else
                {
                    x=1;
                    a='a';
                }
                break;
            case 'p':
                dr=0.4;
                state=a;
                a='a';
                x=0;
        }
    }while(x!=0);
}

void characters::boss2(char &state)
{
	static char a='a';
	int counter=0,r,i,x;
	randomize();
	if(counter==5)
	{
        do
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
				x=0;
				break;
			case 'm':
			    if(hp<=185)
                {
                    hp=hp+25;
                    state=a;
                    a='p';
                    x=0;
                }
                else
                {
                    x=1;
                    a='a';
                }
				break;
			case 'p':
				dr=0.4;
				state=a;
				a='a';
				x=0;
            }
        }while(x!=0);
	}
	else
	{
	    do
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
                x=0;
                break;
            case 'm':
                if(hp<=185)
                {
                    hp=hp+25;
                    state=a;
                    a='p';
                    counter++;
                    x=0;
                }
                else
                {
                    x=1;
                    a='a';
                }
                break;
            case 'p':
                dr=0.4;
                state=a;
                counter++;
                a='m';
                if(counter==5)
                    a='a';
                x=0;
            }
        }while(x!=0);
	}
}

void characters::finalboss(char &predict,char &state)
{
	static char a='a',b='a';
	int r,i,x;
	static int dsp=sp,dum=0;
	sp=dsp;
	dum+=1;
	randomize();
	if(dum<3)
	{
	    do
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
                    x=0;
                    b='b';
                    break;
                case 'b':
                    if(predict=='a')
                    {
                        state='p';
                        x=0;
                        dr=0.4;
                    }
                    else
                    {
                        if(hp<=185)
                        {
                            state='m';
                            hp=hp+25;
                            x=0;
                        }
                        else
                        {
                            x=1;
			    b='a';
                        }
                    }
            }
	}while(x!=0);
	}
	else
	{
	    do
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
                    x=0;
                    break;
                case 'm':
                    if(hp<=185)
                    {
                        hp=hp+25;
                        state=a;
                        a='p';
                        x=0;
                    }
                    else
                    {
                        x=1;
                        a='a';
                    }
                    break;
		case 'p':
		    dr=0.4;
		    state=a;
		    a='a';
		    x=0;
	    }
	}while(x!=0);
	}
}

void printhealth(int dpt,int edpt,int dhp,int dehp,char state,char astate)
{
    static int i=190;
    float f=190/dhp,change;
    if(state=='a')
    {
	change=i-(edpt*f);
	while(i!=change)
	{
	    setcolor(0);
	    delay(7);
	    line(405+i,95,405+i,110);
	    i--;
	}
    }
    if(astate=='m')
    {
	change=i+(25*f);
	while(i!=change)
	{
	    setcolor(15);
	    delay(7);
	    line(405+i,95,405+i,110);
	    i++;
	}
    }
    static int j=190;
    float ef=190/dehp,echange;
    if(astate=='a')
    {
	echange=j-(dpt*ef);
	while(j!=echange)
	{
	    setcolor(0);
	    delay(7);
	    line(405+j,165,405+j,180);
	    j--;
	}
    }
    if(state=='m')
    {
	echange=j+(25*ef);
	while(j!=echange)
	{
	    setcolor(15);
	    delay(7);
	    line(405+j,165,405+j,180);
	    j++;
	}
    }
}

/*
void printhealth(int hp,int dpt,int ehp,int edpt,int dhp,int dehp)
{
	static int i=190,adum=190,mhp=dhp;
	float change;
	change=(float)edpt/dhp;
	if(mhp>=hp)
	{
		if(i>=0)
		{
			setcolor(0);
			while(i>adum-change*190)
			{
				delay(7);
				line(405+i,95,405+i,110);
				i--;
			}
		}
	}
	else
	{
		change=float(hp-mhp/dhp);
		while(i>adum+change*190)
		{
			setcolor(2);
			delay(7);
			line(405+i,95,405+i,110);
		}
	}
	adum=i;
	mhp=hp;
	int static edum=190,mehp=dehp;
	i=190;
	change=(float)dpt/dehp;
	if(mehp>=ehp)
	{
		if(i>=0)
		{
			setcolor(0);
			while(i>edum-change*190)
			{
				delay(7);
				line(405+i,165,405+i,180);
				i--;
			}
		}
	}
	else
	{
		change=float(ehp-mehp/dehp);
		while(i>edum+change*190)
		{
			setcolor(2);
			delay(7);
			line(405+i,165,405+i,180);
		}
	}
	edum=i;
	mehp=ehp;
}
*/
void box(int x,int y)
{
	int poly[18]={x,y,x+100,y,x+120,y+20,x+120,y+100,x+100,y+120,x,y+120,x-20,y+100,x-20,y+20,x,y};
	fillpoly(9,poly);
}

char keys()
{
	int a;
	static int x,y,x1=39,y1=39;
	setfillstyle(1,4);
	setcolor(15);
	setlinestyle(0,0,1);
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
	settextstyle(0,0,1);
	setlinestyle(0,0,3);
	setcolor(15);
	int poly[10]={0,377,350,377,350,427,0,427,0,377};
	drawpoly(5,poly);
	moveto(x1,y1);
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
		x=getx();
		y=gety();
		int bb[]={3,380,347,380,347,424,3,424,3,380};
		setcolor(0);
		setfillstyle(1,0);
		fillpoly(5,bb);
		setcolor(15);
		switch(x+y)
		{
			case 378:
				outtextxy(10,402,"THE TEAM MAY ESCAPE. ONLY WORKS ON GOONS.");
				break;
			case 218:
				outtextxy(10,402,"ALTAN MENDS HIS WOUNDS, HEALING HIMSELF.");
				break;
			case 238:
				outtextxy(10,402,"ALTAN DEFENDS, REDUCING DAMAGE DEALT.");
				break;
			case 78:
				outtextxy(10,402,"ALTAN SLICES AT THE ENEMY, DEALING DAMAGE.");
		}
		a=getch();
		switch(a)
		{
			case 119:
				if(y==179)
					moverel(0,-140);
				break;
			case 97:
				if(x==199)
					moverel(-160,0);
				break;
			case 115:
				if(y==39)
					moverel(0,140);
				break;
			case 100:
				if(x==39)
					moverel(160,0);
				break;
			case 13:
				x1=getx();
				y1=gety();
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
	}while(a!=13);
	switch(x1+y1)
	{
		case 78:
			return 'a';
		case 238:
			return 'p';
		case 218:
			return 'm';
		default:
			return 'r';
	}
}

void mian1(characters &hero,characters &villain,char &result)
{
	char state,astate,predict;
	int p,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int diabox[]={395,350,675,350,675,479,395,479,395,350};
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
	do
	{
		hero.sp=hero.dsp;
		villain.sp=villain.dsp;
		hero.altan(predict,astate);
		villain.boss1(state);
		if(hero.sp<villain.sp)
		{
			setcolor(2);
			outtextxy(410,370,"ENEMY PLAYED FIRST!");
			hero.hp=hero.hp-hero.dr*villain.dpt;
			villain.hp=villain.hp-villain.dr*hero.dpt;
		}
		else
		{
			setcolor(1);
			outtextxy(410,370,"YOU PLAYED FIRST!");
			villain.hp=villain.hp-villain.dr*hero.dpt;
			hero.hp=hero.hp-hero.dr*villain.dpt;
		}
		hero.dr=1;
		villain.dr=1;
		setcolor(0);
		settextstyle(0,0,1);
		switch(astate)
		{
			case 'a':
				outtextxy(410,385,"ALTAN ATTACKED!");
				break;
			case 'p':
				outtextxy(410,385,"ALTAN PARRIED!");
				p=random(25);
				while(p<10)
				{
					p=random(25);
				}
				hero.sp=hero.sp+p;
				break;
			case 'm':
				outtextxy(410,385,"ALTAN MENDED HIS WOUNDS!");
				break;
			case 'r':
				getch();
				cleardevice();
				exit(1);
		}
		switch(state)
		{
			case 'a':
				outtextxy(410,430,"ENEMY ATTACKED!");
				break;
			case 'p':
				outtextxy(410,430,"ENEMY PARRIED!");
				p=random(25);
				while(p<10)
				{
					p=random(25);
				}
				villain.sp=villain.sp+p;
				break;
			case 'm':
				outtextxy(410,430,"ENEMY MENDED ITS WOUNDS!");
		}
		if(hero.hp<0)
			hero.hp=0;
		if(villain.hp<0)
			villain.hp=0;
		printhealth(hero.dpt,villain.dpt,hero.dhp,villain.dhp,state,astate);
		hero.dpt=0;
		villain.dpt=0;
		cout<<hero.hp<<" "<<villain.hp<<"  ";
		getch();
	}while(hero.hp>0&&villain.hp>0);
	setfillstyle(1,15);
	fillpoly(5,diabox);
	settextstyle(1,0,2);
	if(hero.hp==0)
	{
		setcolor(4);
		outtextxy(410,400,"YOU LOST!");
		result='l';
	}
	if(villain.hp==0)
	{
		setcolor(2);
		outtextxy(410,400,"YOU WON!");
		result='w';
	}
}
/*
void mian2(characters &hero,characters &villain,char &result)
{
	char state,astate,predict;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int p,gd=DETECT,gm;
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
	do
	{
		hero.sp=hero.dsp;
		villain.sp=villain.dsp;
		hero.altan(predict,astate);
		villain.boss2(state);
		if(hero.sp>villain.sp)
		{
			for(i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero.dpt;
			hero.hp=hero.hp-hero.dr*villain.dpt;
		}
		if(hero.sp<villain.sp)
		{
			for(i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero.hp=hero.hp-hero.dr*villain.dpt;
			villain.hp=villain.hp-villain.dr*hero.dpt;
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
	}while(hero.hp>0&&villain.hp>0);
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
	char state,astate,predict;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int p,gd=DETECT,gm;
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
	do
	{
		hero.sp=hero.dsp;
		villain.sp=villain.dsp;
		hero.altan(predict,astate);
		villain.finalboss(predict,state);
		if(hero.sp>villain.sp)
		{
			for(i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero.dpt;
			hero.hp=hero.hp-hero.dr*villain.dpt;
		}
		if(hero.sp<villain.sp)
		{
			for(i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero.hp=hero.hp-hero.dr*villain.dpt;
			villain.hp=villain.hp-villain.dr*hero.dpt;
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
	}while(hero.hp>0&&villain.hp>0);
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
*/
int main()
{
	clrscr();
	char result;
	characters altan,boss1,boss2,finalboss;
	altan.constructor(150,30,65);
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
	cleardevice();
	closegraph();
	return 0;
}

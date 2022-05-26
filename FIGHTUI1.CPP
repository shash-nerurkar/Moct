#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

void printhealths(int &hp,int dpt,int &ehp,int edpt)
{
	static int adum=190;
	static int edum=190;
	static int mhp=hp,mehp=ehp;
	static int thp=hp,tehp=ehp;
	int i=190;
	float change;
       //	if(mhp>=hp)
	{
		change=(float)edpt/thp;
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
	}
       /*	else
	{
		change=(float)(thp-hp)/thp;
		while(i<=adum+190*change)
		{
			if(i<=190)
			{
				setcolor(2);
				delay(5);
				line(405+i,95,405+i,110);
				i++;
			}
			else
				break;
		}
	}*/
	adum=i;
	mhp=hp;
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
	change=(float)dpt/tehp;
	//if(mehp>=ehp)
	{
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
	}
	/*else
	{
		change=(float)(tehp-ehp)/tehp;
		while(i<=edum+190*change)
		{
			if(i<=190)
			{
				setcolor(2);
				delay(5);
				line(405+i,95,405+i,110);
				i++;
			}
			else
				break;
		}
	} */
	edum=i;
	mehp=ehp;
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
	dhp=z;
	dpt=y;
	ddpt=y;
	sp=z;
	dsp=z;
}

void characters::altan(char &predict,char &astate)
{
	int dum,r,i;
	char a;
	randomize();
	do
	{
		a=getch();
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
				clrscr();
				dum=1;
			}
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
	int dum,i=190;
	float change;
	cout<<"YOU DEALT :"<<dpt<<"  ";
	while(i>0)
	{
		change=(float)dpt/hp;
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
	}
	i=190;
	cout<<"ENEMY DEALT :"<<edpt<<endl;
	while(i>0)
	{
		change=(float)edpt/ehp;
		while(i>=dum-190*change)
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
		dum=i;
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
		i=dum;
	}
}

void mian1(characters &hero,characters &villain,char &result)
{
	char state,astate,predict;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int crit=critical(),p,gd=DETECT,gm;
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
	randomize();
	while(hero.hp>0&&villain.hp>0)
	{
		hero.sp=hero.dsp;
		villain.sp=villain.dsp;
		hero.altan(predict,astate);
		villain.boss1(state);
		if(hero.sp>villain.sp)
		{
			for(i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero.dpt*crit;
			hero.hp=hero.hp-hero.dr*villain.dpt*crit;
		}
		if(hero.sp<villain.sp)
		{
			for(i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero.hp=hero.hp-hero.dr*villain.dpt*crit;
			villain.hp=villain.hp-villain.dr*hero.dpt*crit;
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
	char state,astate,predict;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int crit=critical(),p,gd=DETECT,gm;
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
		hero.altan(predict,astate);
		villain.boss2(state);
		if(hero.sp>villain.sp)
		{
			for(i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero.dpt*crit;
			hero.hp=hero.hp-hero.dr*villain.dpt*crit;
		}
		if(hero.sp<villain.sp)
		{
			for(i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero.hp=hero.hp-hero.dr*villain.dpt*crit;
			villain.hp=villain.hp-villain.dr*hero.dpt*crit;
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
	char state,astate,predict;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int crit=critical(),p,gd=DETECT,gm;
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
		hero.altan(predict,astate);
		villain.finalboss(predict,	state);
		if(hero.sp>villain.sp)
		{
			for(i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero.dpt*crit;
			hero.hp=hero.hp-hero.dr*villain.dpt*crit;
		}
		if(hero.sp<villain.sp)
		{
			for(i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero.hp=hero.hp-hero.dr*villain.dpt*crit;
			villain.hp=villain.hp-villain.dr*hero.dpt*crit;
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
	boss2.constructor(320,85,100);
	finalboss.constructor(400,120,150);
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
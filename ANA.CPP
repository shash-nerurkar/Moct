#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

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
	void ana(char &astate);
	void boss1(char &state);
	void boss2(char &state);
	void finalboss(char &predict,char &state);
	friend void mian1(characters &,characters &,characters &,char &);
	friend void mian2(characters &,characters &,characters &,char &);
	friend void mian3(characters &,characters &,characters &,char &);
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
	int dum,num=0,r,i,p;
	char a;
	num+=1;
	randomize();
	do
	{
		cout<<"\tROUND "<<num<<endl<<endl;
		cout<<"WHAT SHOULD ALTAN DO?"<<endl;
		cout<<"TO ATTACK, ENTER a."<<endl;
		cout<<"TO PARRY, ENTER p."<<endl;
		cout<<"TO MEND, ENTER m."<<endl;
		cin>>a;
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
			p=random(50);
			for(i=10;i<51;i++)
			{
				if(p==i)
					sp=sp+i;
			}
			predict=a;
			break;
		case 'm':
			if(hp<290)
			{
				hp=hp+80;
				if(hp>290)
					hp=290;
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

void characters::ana(char &astate)
{
	int dum,r,i,p;
	char a;
	randomize();
	do
	{
		cout<<"WHAT SHOULD ANA DO?"<<endl;
		cout<<"TO HEAL, ENTER a."<<endl;
		cout<<"TO BLOCK, ENTER p."<<endl;
		cout<<"TO MEND, ENTER m."<<endl;
		cin>>a;
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
			break;
		case 'p':
			dr=0.4;
			p=random(50);
			for(i=10;i<51;i++)
			{
				if(p==i)
					sp=sp+i;
			}
			break;
		case 'm':
			if(hp<290)
			{
				hp=hp+80;
				if(hp>290)
					hp=290;
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
	int r,i,p;
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
			p=random(50);
			for(i=10;i<51;i++)
			{
				if(p==i)
					sp=sp+i;
			}
			state=a;
			a='a';
	}
}

void characters::boss2(char &state)
{
	static char a='a';
	int counter=0,r,i,p;
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
				p=random(50);
				for(i=10;i<51;i++)
				{
					if(p==i)
						sp=sp+i;
				}
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
			p=random(50);
			for(i=10;i<51;i++)
			{
				if(p==i)
					sp=sp+i;
			}
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
	int r,i,p;
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
					p=random(50);
					for(i=10;i<51;i++)
					{
						if(p==i)
							sp=sp+i;
					}
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
				p=random(50);
				for(i=10;i<51;i++)
				{
					if(p==i)
						sp=sp+i;
				}
				a='a';
		}
	}
}

void mian1(characters &hero1,characters &hero2,characters &villain,char &result)
{
	char state,astate,predict;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	int crit=critical();
	while(hero1.hp!=0&&villain.hp!=0)
	{
		hero1.sp=hero1.dsp;
		villain.sp=villain.dsp;
		hero1.altan(predict,astate);
		hero2.ana(astate);
		villain.boss1(state);
		if(hero1.sp>villain.sp)
		{
			for(int i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero1.dpt*crit;
			hero1.hp=hero1.hp-hero1.dr*villain.dpt*crit+hero2.dpt;
		}
		if(hero1.sp<villain.sp)
		{
			for(int i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero1.hp=hero1.hp-hero1.dr*villain.dpt*crit+hero2.dpt;
			villain.hp=villain.hp-villain.dr*hero1.dpt*crit;
		}
		if(state=='p')
			villain.sp++;
		if(astate=='p')
			hero1.sp++;
		hero1.dr=1;
		villain.dr=1;
	}
	getch();
	clrscr();
	if(hero1.hp==0)
	{
		cout<<"YOU LOST!";
		result='l';
	{
	if(villain.hp==0)
	{
		cout<<"YOU WIN!";
		result='w';
	}
	hero1.hp=hero1.dhp;
	hero1.dpt=hero1.ddpt;
	villain.hp=villain.dhp;
	villain.dpt=villain.ddpt;
	getch();
}

void mian2(characters &hero1,characters &hero2,characters &villain,char &result)
{
	char state,astate,predict;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	while(hero1.hp!=0&&villain.hp!=0)
	{
		hero1.sp=hero1.dsp;
		villain.sp=villain.dsp;
		hero1.altan(predict,astate);
		hero2.ana(astate);
		villain.boss2(state);
		if(hero1.sp>villain.sp)
		{
			for(int i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero1.dpt*crit;
			hero1.hp=hero1.hp-hero1.dr*villain.dpt*crit+hero2.dpt;
		}
		if(hero1.sp<villain.sp)
		{
			for(int i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero1.hp=hero1.hp-hero1.dr*villain.dpt*crit+hero2.dpt;
			villain.hp=villain.hp-villain.dr*hero1.dpt*crit;
		}
		if(state=='p')
			villain.sp++;
		if(astate=='p')
			hero.sp++;
		hero.dr=1;
		villain.dr=1;
	}
	getch();
	clrscr();
	if(hero1.hp==0)
	{
		cout<<"YOU LOST!";
		result='l';
	{
	if(villain.hp==0)
	{
		cout<<"YOU WIN!";
		result='w';
	}
	hero1.hp=hero1.dhp;
	hero1.dpt=hero1.ddpt;
	villain.hp=villain.dhp;
	villain.dpt=villain.ddpt;
	getch();
}


void mian3(characters &hero1,characters &hero2,characters &villain,char &result)
{
	char state,astate,predict;
	char first[20]="YOU PLAYED FIRST!";
	char second[25]="THE ENEMY PLAYED FIRST!";
	while(hero.hp!=0&&villain.hp!=0)
	{
		hero1.sp=hero1.dsp;
		villain.sp=villain.dsp;
		hero1.altan(predict,astate);
		hero2.ana(astate);
		villain.finalboss(state);
		if(hero1.sp>villain.sp)
		{
			for(int i=0;i<20;i++)
			{
				cout<<first[i];
				delay(90);
			}
			villain.hp=villain.hp-villain.dr*hero1.dpt*crit;
			hero1.hp=hero1.hp-hero1.dr*villain.dpt*crit+hero2.dpt;
		}
		if(hero1.sp<villain.sp)
		{
			for(int i=0;i<25;i++)
			{
				cout<<second[i];
				delay(90);
			}
			hero1.hp=hero1.hp-hero1.dr*villain.dpt*crit+hero2.dpt;
			villain.hp=villain.hp-villain.dr*hero1.dpt*crit;
		}
		if(state=='p')
			villain.sp++;
		if(astate=='p')
			hero.sp++;
		hero.dr=1;
		villain.dr=1;
	}
	getch();
	clrscr();
	if(hero1.hp==0)
	{
		cout<<"YOU LOST!";
		result='l';
	{
	if(villain.hp==0)
	{
		cout<<"YOU WIN!";
		result='w';
	}
	hero1.hp=hero1.dhp;
	hero1.dpt=hero1.ddpt;
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
	ana.constructor(15,40,75);
	boss1.constructor(210,55,45);
	boss2.constructor(320,85,100);
	finalboss.constructor(400,120,150);
	do
	{
		mian1(altan,boss1,result);
		if(result=='l')
		{
			cout<<"TRY AGAIN!";
			getch();
			clrscr();
		}
	}while(result=='l');
	altan.constructor(170,50,75);
	ana.constructor(35,70,75);
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
	altan.constructor(250,95,75);
	ana.constructor(60,95,75);
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
	}while(result=='l');
	return 0;
}
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
void altan(int &dpt,int &hp,float &dr)
{
	int dum;
	char a;
	do
	{
		cout<<"\tYOUR TURN."<<endl;
		cout<<"TO ATTACK, ENTER a."<<endl;
		cout<<"TO PARRY, ENTER p."<<endl;
		cout<<"TO MEND, ENTER m."<<endl;
		cin>>a;
		dum=0;
		switch(a)
		{
		case 'a':
			randomize();
			int r=random(5);
			for(int i=0;i<5;i++)
			{
				if(r==i)
					dpt=25+i;
			}
			break;
		case 'p':
			dr=0.4;
			break;
		case 'm':
			if(hp<100)
			{
				hp=hp+10;
				if(hp>100)
					hp=100;
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

void enemy(int &edpt,int &ehp,float &edr)
{
	int a,b,c,dum;
	randomize();
	do
	{
		a=random(100);
		b=random(a);
		if(b%2==0)
			c=0;
		else if(b%3==0)
			c=1;
		else if(b%5==0)
			c=2;
		dum=0;
		switch(c)
		{
		case 0:
			cout<<"ENEMY ATTACKED!"<<endl;
			randomize();
			int r=random(15);
			for(int i=0;i<15;i++)
			{
				if(r==i)
					edpt=15+i;
			}
			break;
		case 1:
			cout<<"ENEMY PARRIED!"<<endl;
			edr=0.4;
			break;
		case 2:
			if(ehp<55)
			{
				cout<<"ENEMY MENDED HIS WOUNDS!"<<endl;
				ehp=ehp+25;
			}
			else
				dum=1;
		}
	}while(dum==1);

}

int main()
{
	clrscr();
	int dpt=0,edpt=0,hp=100,ehp=90;
	float edr=1.0,dr=1.0;
	while(hp>0&&ehp>0)
	{
		altan(dpt,hp,dr);
		enemy(edpt,ehp,edr);
		ehp=ehp-edr*dpt;
		hp=hp-dr*edpt;
		cout<<"YOU DEALT:"<<dpt<<endl;
		cout<<"ENEMY DEALT:"<<edpt<<endl;
		dr=1.0;
		edr=1.0;
		dpt=0;
		edpt=0;
		if(hp<0)
			hp=0;
		if(ehp<0)
			ehp=0;
		cout<<"YOUR HEALTH REMAINING:"<<hp<<endl<<"ENEMY'S HEALTH REMAINING:"<<ehp<<endl;
		getch();
		clrscr();
	      }
	if(hp==0)
		cout<<"YOU LOST.";
	else
		cout<<"YOU WON!";
	getch();
	return 0;
}
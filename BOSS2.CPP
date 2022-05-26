#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
void altan(int &dpt,int &hp,float &dr,int &sp)
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
					dpt=95+i;
			}
			break;
		case 'p':
			dr=0.4;
			sp+=1;
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
int attack()
{
	return 70;
}
void mend(int &ehp)
{
	ehp=ehp+95;
}
int parry()
{
	return 0.4;
}
void enemy(int &edpt,int &ehp,float &edr,int &esp,char &state)
{
	static char a='a';
	int counter=0;
	if(counter==5)
	{

		switch(a)
		{
			case 'a':
				edpt=attack();
				state=a;
				a='m';
				break;
			case 'm':
				mend(ehp);
				state=a;
				a='p';
				break;
			case 'p':
				edr=parry();
				esp+=1;
				state=a;
				a='a';
		}
	}
	else
	{
		switch(a)
		{
		case 'a':
			edpt=attack();
			state=a;
			a='m';
			counter++;
			break;
		case 'm':
			mend(ehp);
			state=a;
			a='p';
			counter++;
			break;
		case 'p':
			edr=parry();
			state=a;
			esp+=1;
			counter++;
			a='m';
			if(counter==5)
				a='a';
		}
	}
}

int main()
{
	clrscr();
	int dpt=0,edpt=0,hp=280,ehp=390,sp=2,esp=1;
	int dsp=sp,desp=esp;
	char state;
	float edr=1.0,dr=1.0;
	while(hp>0&&ehp>0)
	{
			altan(dpt,hp,dr,sp);
			enemy(edpt,ehp,edr,esp,state);
		if(sp>esp)
		{
			cout<<"YOU PLAYED FIRST!"<<endl;
			ehp=ehp-edr*dpt;
			hp=hp-dr*edpt;
			if(state=='a')
				cout<<"THE ENEMY ATTACKED!"<<endl;
			else if(state=='p')
				cout<<"THE ENEMY PARRIED!"<<endl;
			else if(state=='m')
				cout<<"THE ENEMY MENDED HIS WOUNDS!"<<endl;
		}
		else
		{
			cout<<"ENEMY PLAYED FIRST!"<<endl;
			hp=hp-dr*edpt;
			ehp=ehp-edr*dpt;
		}
		cout<<"YOU DEALT:"<<dpt<<endl;
		cout<<"ENEMY DEALT:"<<edpt<<endl;
		sp=dsp;
		esp=desp;
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
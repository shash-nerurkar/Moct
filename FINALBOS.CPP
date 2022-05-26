#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
void altan(int &dpt,int &hp,float &dr,int &sp,char &predict)
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
		static int dsp=sp;
		sp=dsp;
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
			predict=a;
			break;
		case 'p':
			dr=0.4;
			sp+=1;
			predict=a;
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
			predict=a;
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
void enemy(int &edpt,int &ehp,float &edr,int &esp,char &predict)
{
	static char a='a',b='a';
	static int desp=esp,dum=0;
	esp=desp;
	dum+=1;
	if(dum<3)
	{
		switch(b)
		{
			case 'a':
				cout<<"THE ENEMY ATTACKED!";
				edpt=attack();
				b='b';
				break;
			case 'b':
				if(predict=='a')
				{
					cout<<"THE ENEMY PARRIED!";
					edr=parry();
				}
				else
				{
					cout<<"THE ENEMY MENDED HIS WOUNDS!";
					mend(ehp);
				}
		}
	else
	{
		switch(a)
		{
			case 'a':
				cout<<"THE ENEMY ATTACKED!";
				edpt=attack();
				a='m';
				break;
			case 'm':
				cout<<"THE ENEMY MENDED HIS WOUNDS!";
				mend(ehp);
				a='p';
				break;
			case 'p':
				cout<<"THE ENEMY PARRIED!";
				edr=parry();
				esp+=1;
				a='a';
		}
	}
}

int main()
{
	clrscr();
	int dpt=0,edpt=0,hp=280,ehp=390,sp=2,esp=1;
	char predict;
	float edr=1.0,dr=1.0;
	while(hp>0&&ehp>0)
	{

		cout<<endl<<endl;
		if(sp>esp)
		{
			altan(dpt,hp,dr,sp,predict);
			enemy(edpt,ehp,edr,esp,predict);
		}
		else
		{
			altan(dpt,hp,dr,sp,predict);
			enemy(edpt,ehp,edr,esp,predict);
		}
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
	      }
	if(hp==0)
		cout<<"YOU LOST.";
	else
		cout<<"YOU WON!";
	getch();
	return 0;
}
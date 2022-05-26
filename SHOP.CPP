#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

//void boxex()
//{
//	int x[]={0,258,639,258,639,298,0,298,0,258};
//}

void indibox3(int y, int col=15)
{
	int b[]={0,y,639,y,639,y+40,0,y+40,0,y};
	setcolor(col);
	line(132,y,132,y+40);
	line(195,y,195,y+40);
	drawpoly(5,b);
}


void indibox2(int y, int col=15,int adj=0)
{
	int b[]={0,y,639,y,639,y+40+adj,0,y+40+adj,0,y};
	setcolor(col);
	line(132,y,132,y+40+adj);
	line(195,y,195,y+40+adj);
	drawpoly(5,b);
}

void indibox(int y,int col=15)
{
	int b[]={0,y,639,y,639,y+40,0,y+40,0,y};
	setcolor(col);
	line(95,y,95,y+40);
	line(163,y,163,y+40);
	drawpoly(5,b);
}

int main()
{
	_setcursortype(_NOCURSOR);
	int gd=DETECT,gm,mpx;
	char dum;
	char duff;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	settextstyle(1,0,5);
	delay(100);
	mpx=getmaxx()/2-155;
	outtextxy(mpx,15,"THE SHACK");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t(i)FOR MELEE USER, ENTER m,"<<endl<<endl<<"\t\t\t\t\t(ii)FOR SUPPORT CHARACTER, ENTER s."<<endl<<endl<<"\t\t\t\t\t(iii)FOR TANK CHARACTER, ENTER t";
	dum=getch();
	clrscr();
	cleardevice();
	do
	{
		switch(dum)
		{
			case 'm':
				settextstyle(3,0,5);
				setcolor(9);
				outtextxy(100,50,"ALTAN'S SHOP");
				setcolor(15);
				settextstyle(0,0,1);
				outtextxy(10,165,"PITCHFORK     -      Your trusty ol' fork.");
				outtextxy(10,205,"BATTLE AXE  35000    Clean executes lead to more meat salvaged.");
				outtextxy(10,245,"KATANA      50000    Every third move does percentage current health damage.");
				outtextxy(10,283,"GODSTAFF    100000   Can call angels,boosting critical hit ratio");
				outtextxy(170,297," damage per second.");
				setlinestyle(0,0,3);
				for(int i=150;i<271;i+=40)
				{
					indibox(i);
				}
				int a,y1;
				moveto(0,150);
				indibox(150,9);
				do
				{
					a=getch();
					y1=gety();
					switch(a)
					{
						case 115:
							if(y1<=230)
								moverel(0,40);
							break;
						case 119:
							if(y1>=190)
								moverel(0,-40);
							break;
						case 13:
							continue;
						default:
							continue;
						}
						indibox(y1);
						indibox(gety(),9);
					}while(a!=13);
				break;
			case 's':
				settextstyle(3,0,5);
				setcolor(5);
				outtextxy(100,50,"ANA'S SHOP");
				settextstyle(0,0,1);
				setcolor(15);
				outtextxy(10,165,"BOAR-SKIN ARMOR  35000   Tough protective cover. That little bulk you need to");
				outtextxy(210,179,"serve the prince.");
				outtextxy(10,205,"CANE OF          50000   Heals everyone for %missing health.");
				outtextxy(10,219,"REDEMPTION");
				outtextxy(10,245,"THE RESURRECTOR 100000   Lays a curse upon self to bring a member of the party");
				outtextxy(205,259,"back to life, fully restoring...(press m for more)");
				setlinestyle(0,0,3);
				for(int j=150; j<231; j+=40)
				{
					i==230?indibox2(j,15,60):indibox2(j);
				}
				moveto(0,150);
				indibox2(150,5);
				do
				{
					a=getch();
					y1=gety();
					switch(a)
					{
						case 115:
							if(y1<=190)
								moverel(0,40);
							break;
						case 119:
							if(y1>=190)
								moverel(0,-40);
							break;
						case 109:
							if(y1==230)
							{
							setcolor(15);
							outtextxy(210,245,"Lays a curse upon self to bring a member of the party");
							outtextxy(210,259,"back to life, fully restoring primary status and some");
							outtextxy(210,273,"health.The curse deals a fourth of your health every");
							outtextxy(210,287,"turn.");
							setcolor(5);
							}
							break;
						case 13:
							continue;
						default:
							continue;
						}
						if(gety()==230)
						{
							indibox2(y1);
							indibox2(gety(),5,60);
						}
						if(y1==230)
						{
							indibox2(y1,0,60);
							indibox(gety(),5);
						}
					}while(a!=13);
				break;
			case 't':
				settextstyle(3,0,5);
				setcolor(2);
				outtextxy(100,50,"MOTOG'S SHOP");
				settextstyle(0,0,1);
				setcolor(15);
				outtextxy(10,165,"BOAR-SKIN ARMOR  35000   Tough protective cover. That little bulk you need to");
				outtextxy(210,179,"serve the prince.");
				outtextxy(10,205,"HARDENED         50000   Regenerates %health per second. This breaks if the");
				outtextxy(210,219,"tank is hit in the last 3 turns.");
				outtextxy(10,219,"ACCUMETAL GUARD");
				outtextxy(10,245,"THE BULWARK OF   100000  All reduced damage is converted into energy.");
				outtextxy(210,259,"This energy can be released...(press m for more)");
				outtextxy(10,259,"RAHLDEN");
				setlinestyle(0,0,3);
				for(int k=150; k<259; k+=40)
				{
					indibox3(k);
				}
				moveto(0,150);
				indibox3(150,2);
				do
				{
					a=getch();
					y1=gety();
					switch(a)
					{
						case 115:
							if(y1<=190)
								moverel(0,40);
							break;
						case 119:
							if(y1>=190)
								moverel(0,-40);
							break;
						case 109:
							if(y1>=190)
							{
							setcolor(0);
							outtextxy(210,259,"This energy can be released...(press m for more)");
							setcolor(15);
							outtextxy(210,259,"This energy can be released to deal true damage.");
							outtextxy(210,273,"Foreseeing an attack, the knight blocks it, and gains");
							outtextxy(210,287,"extra damage reduction.");
							setcolor(2);
							}
							break;
						case 13:
							continue;
						default:
							continue;
						}
						indibox3(y1);
						indibox3(gety(),2);
					}while(a!=13);
				break;
			case 'e':
				exit(1);
			default:
				continue;
		}
	}while(dum!='m'&&dum!='s'&&dum!='t');
	cleardevice();
	closegraph();
	return 0;
}
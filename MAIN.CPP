#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>

void changewpn();
void subtrans();
void giveup(int&);
void database();
void loading();

void map()
{
	 _setcursortype(_NOCURSOR);
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	int mpx;
	settextstyle(3,0,5);
	delay(100);
	mpx=getmaxx()/2-155;
	outtextxy(mpx,150,"GUHA FOREST");
	delay(1000);
	cleardevice();
	closegraph();
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	for(int i=0;i<36;i++)
	{
		setcolor(10);
		circle(525,380,i);
	}
	cout	<<endl<<endl<<endl<<endl
		<<endl<<endl<<endl<<endl
		<<endl<<endl<<endl<<endl
		<<endl<<endl<<endl<<endl<<endl
		<<endl<<endl<<endl<<endl<<endl
		<<endl<<"\t\t\t\t\t\t\t      PRAEREN";
	setcolor(15);
	line(600,440,460,440);//AB
	line(460,300,610,300);//CD
	line(460,300,460,253);//CE
	line(460,253,340,253);//EF
	line(340,253,340,440);//FG
	line(340,440,260,440);//GH
	line(250,150,150,150);//KL
	line(150,150,150,38); //LM
	line(50,150,50,300);  //NO
	line(50,300,145,300); //OP
	line(145,300,145,375);//PQ
	line(400,150,400,38); //RS
	line(400,150,600,150);//RT
	line(600,150,600,38); //TU

	line(600,460,440,460);//A1B1
	line(440,460,440,273);//B1E1
	line(440,273,360,273);//E1F1
	line(360,273,360,460);//F1G1
	line(360,460,240,460);//G1H1
	line(240,378,240,170);//I2K1
	line(240,170,70,170); //K1N1
	line(70,170,70,280);  //N1O1
	line(70,280,165,280); //O1P1
	line(165,280,165,375);//P1Q1
	line(260,170,620,170);//K2T1
	line(620,170,620,38); //T1U1

	//intersections
	line(460,320,610,320);//C1D1
	line(460,440,460,320);//BC1
	line(240,378,175,378);//I2J
	line(240,398,175,398);//I1J1
	line(50,150,130,150); //NL1
	line(130,150,130,38); //L1M1
	line(150,150,380,150);//LR1
	line(380,150,380,38); //R1S1
	line(260,440,260,170);//HK2
	line(240,460,240,398);//H1I1
	for(i=0;i<16;i++)  //starting point
	{
		setcolor(8);
		line(614-i,450-i,614+i,450-i);
		line(614-i,450+i,614-i,450-i);
		line(614-i,450+i,614+i,450+i);
		line(614+i,450-i,614+i,450+i);

	}
	for(i=0;i<6;i++)
	{
		setcolor(15);
		line(599,435-i,629,435-i);
		line(599-i,435,599-i,465);
		line(599,465+i,629,465+i);
		line(629+i,465,629+i,435);
	}
	for(i=0;i<16;i++)        //boss1
	{
		if(i>12)
			setcolor(1);
		else
			setcolor(9);
		line(450-i,450-i,450+i,450-i);
		line(450-i,450+i,450-i,450-i);
		line(450-i,450+i,450+i,450+i);
		line(450+i,450-i,450+i,450+i);
	}
	for(i=0;i<16;i++)            //optionalboss1
	{
		if(i>12)
			setcolor(1);
		else
			setcolor(9);
		line(600-i,310-i,600+i,310-i);
		line(600-i,310+i,600-i,310-i);
		line(600-i,310+i,600+i,310+i);
		line(600+i,310-i,600+i,310+i);
	}
	for(i=0;i<16;i++)           //boss2
	{
		if(i>12)
			setcolor(1);
		else
			setcolor(9);
		line(450-i,263-i,450+i,263-i);
		line(450-i,263+i,450-i,263-i);
		line(450-i,263+i,450+i,263+i);
		line(450+i,263-i,450+i,263+i);
	}
	for(i=0;i<16;i++)            //boss3
	{
		if(i>12)
			setcolor(1);
		else
			setcolor(9);
		line(350-i,450-i,350+i,450-i);
		line(350-i,450+i,350-i,450-i);
		line(350-i,450+i,350+i,450+i);
		line(350+i,450-i,350+i,450+i);
	}
	for(i=0;i<16;i++)         //boss4
	{
		if(i>12)
			setcolor(1);
		else
			setcolor(9);
		line(250-i,160-i,250+i,160-i);
		line(250-i,160+i,250-i,160-i);
		line(250-i,160+i,250+i,160+i);
		line(250+i,160-i,250+i,160+i);
	}
	for(i=0;i<16;i++)        //leftboss5
	{
		if(i>12)
			setcolor(1);
		else
			setcolor(9);
		line(60-i,290-i,60+i,290-i);
		line(60-i,290+i,60-i,290-i);
		line(60-i,290+i,60+i,290+i);
		line(60+i,290-i,60+i,290+i);
	}
	for(i=0;i<31;i++)       //strongboss
	{
		if(i>26)
			setcolor(4);
		else
			setcolor(12);
		line(170-i,374-i,170+i,374-i);
		line(170-i,374+i,170-i,374-i);
		line(170-i,374+i,170+i,374+i);
		line(170+i,374-i,170+i,374+i);
	}
	for(i=0;i<16;i++)        //optionalbossleft
	{
		if(i>12)
			setcolor(1);
		else
			setcolor(9);
		line(140-i,50-i,140+i,50-i);
		line(140-i,50+i,140-i,50-i);
		line(140-i,50+i,140+i,50+i);
		line(140+i,50-i,140+i,50+i);
	}
	for(i=0;i<16;i++)        //optionalbossright
	{
		if(i>12)
			setcolor(1);
		else
			setcolor(9);
		line(390-i,50-i,390+i,50-i);
		line(390-i,50+i,390-i,50-i);
		line(390-i,50+i,390+i,50+i);
		line(390+i,50-i,390+i,50+i);
	}
	for(i=0;i<31;i++)      //finalboss
	{
		if(i>26)
			setcolor(4);
		else
			setcolor(12);
		line(610-i,50-i,610+i,50-i);
		line(610-i,50+i,610-i,50-i);
		line(610-i,50+i,610+i,50+i);
		line(610+i,50-i,610+i,50+i);
	}
	for(i=35;i<50;i++)     //praeren
	{
		setcolor(10);
		circle(525,380,i);
	}
getch();
cleardevice();
closegraph();
clrscr();
subtrans();
}

void transition()
{
	 _setcursortype(_NOCURSOR);
	textcolor(LIGHTBLUE+BLINK);
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cprintf("                              PRESS ANY KEY TO CONTINUE");
	textcolor(7);
	getch();
}

char dim[3],twpname[15],swpname[15],mwpname[15]="Pitchfork";
int twpncost,swpncost,mwpncost;
int mwpndpt,twpndpt;

void box(int x,int y,int col=15)
{
	int b1[]={x,y,x+70,y,x+70,y+35,x,y+35,x,y};
	setlinestyle(0,0,3);
	setcolor(col);
	drawpoly(5,b1);
}

class inventory
{
	int meat;
public:
	int money;
	inventory()
	{
	  money=5000;
	  meat=20;
	}
	void accessinv();
};

void inventory::accessinv()
{
	int gd=DETECT,gm,mpx;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	settextstyle(1,0,5);
	mpx=getmaxx()/2-155;
	outtextxy(mpx,15,"INVENTORY");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<endl<<"CURRENT BALANCE: "<<5000<<" coins"<<endl<<endl;
	cout<<endl<<"MEAT AVAILABLE: "<<2000<<" steaks"<<endl<<endl;
	cout<<endl<<"VITO:ARMS IN-HAND: "<<"bserb"<<endl<<endl;
	cout<<endl<<"ANA:ARMS IN-HAND: "<<"frgbsetbd"<<endl<<endl;
	cout<<endl<<"MOTOG:ARMS IN-HAND: "<<"sragserbbwargregfdrgd"<<endl<<endl;
	settextstyle(0,0,2);
	outtextxy(400,100,"CHANGE WEAPONS?:");
	box(420,145);
	box(515,145);
	outtextxy(430,155,"YES");
	outtextxy(535,155,"NO");
	moveto(420,155);
	box(420,145,14);
	int a,x1;
	do
	{
		a=getch();
		x1=getx();
		switch(a)
		{
			case 97:
				if(x1==515)
					moverel(-95,0);
				break;
			case 100:
				if(x1==420)
					moverel(95,0);
				break;
			case 13:
				continue;
			default:
				continue;
		}
		box(x1,145);
		box(getx(),145,14);
	}while(a!=13);
	settextstyle(0,0,1);
	if(x1==515)
	{
		outtextxy(200,400,"PRESS ANY KEY TO CONTINUE");
		getch();
	}
	else
	{
		clrscr();
		changewpn();
	}
	cleardevice();
	closegraph();
	subtrans();
}
inventory player;

void changemel(char a)
{
	 _setcursortype(_NOCURSOR);
	int moneh,decoh;
	char decoy[15];
	do
	{
		switch(a)
		{
			case 'p':
				strcpy(decoy,mwpname);
				strcpy(mwpname,"PITCHFORK");
				mwpncost=0;
				decoh=mwpndpt;
				mwpndpt=0;
				break;
			case 'b':
				strcpy(decoy,mwpname);
				strcpy(mwpname,"BATTLE AXE");
				mwpncost=35000;
				decoh=mwpndpt;
				mwpndpt=0;
				break;

			case 'k':
				strcpy(decoy,mwpname);
				strcpy(mwpname,"KATANA");
				mwpncost=100000;
				decoh=mwpndpt;
				mwpndpt=0;
				break;
			case 'g':
				strcpy(decoy,mwpname);
				strcpy(mwpname,"GODSTAFF");
				mwpncost=100000;
				decoh=mwpndpt;
				mwpndpt=0;
				break;
			case 'z':
				cleardevice();
				player.accessinv();
				break;
			default:
				cleardevice();
				player.accessinv();
				cin>>dim[0];
		}
		a=dim[0];
	}while(a!='p'&&a!='b'&&a!='k'&&a!='g');
	char dum;
	cout<<"ARE YOU SURE YOU WANT TO BUY"<<mwpname<<"?(y/n)";
	cin>>dum;
	if(dum=='n')
	{
		strcpy(mwpname,decoy);
		mwpndpt=decoh;
		player.money=moneh;
	}
	moneh=player.money;
	player.money=player.money-mwpncost;
	if(player.money<0)
	{
		cout<<"NOT ENOUGH COINS.";
		player.money=moneh;
		strcpy(mwpname,decoy);
		mwpndpt=decoh;
	}
}

void changesupp(char b)
{
	 _setcursortype(_NOCURSOR);
	int moneh;
	char decoy[15];
	do
	{
		switch(b)
		{
			case 'b':
				strcpy(decoy,swpname);
				strcpy(swpname,"BOAR-SKIN ARMOR");
				swpncost=35000;
				break;
			case 'c':
				strcpy(decoy,swpname);
				strcpy(swpname,"CANE OF REDEMPTION");
				swpncost=50000;
				break;
			case 'r':
				strcpy(decoy,swpname);
				strcpy(swpname,"THE RESURRECTOR");
				swpncost=100000;
				break;
			case 'z':
				cleardevice();
				player.accessinv();
				break;
			default:
				cleardevice();
				player.accessinv();
				cin>>dim[1];
		}
		b=dim[1];
	}while(b!='b'&&b!='c'&&b!='r');
	char dum;
	cout<<"ARE YOU SURE YOU WANT TO BUY"<<swpname<<"?(y/n)";
	cin>>dum;
	if(dum=='n')
	{
		strcpy(swpname,decoy);
		player.money=moneh;
	}
	moneh=player.money;
	player.money=player.money-swpncost;
	if(player.money<0)
	{
		cout<<"NOT ENOUGH COINS.";
		player.money=moneh;
		strcpy(swpname,decoy);
	}
}

void changetank(char c)
{
	 _setcursortype(_NOCURSOR);
	int moneh;
	char decoy[15];
	do
	{
		switch(c)
		{
			case 'b':
				strcpy(decoy,swpname);
				strcpy(swpname,"BOAR-SKIN ARMOR");
				swpncost=35000;
				break;
			case 'g':
				strcpy(decoy,swpname);
				strcpy(swpname,"HARDENED METAL GUARD");
				swpncost=50000;
				break;
			case 'r':
				strcpy(decoy,swpname);
				strcpy(swpname,"THE BULWARK OF RAHLDEN");
				swpncost=100000;
				break;
			case 'z':
				cleardevice();
				player.accessinv();
				break;
			default:
				cleardevice();
				player.accessinv();
				cin>>dim[2];
		}
		c=dim[2];
	}while(c!='b'&&c!='g'&&c!='r');
	char dum;
	cout<<"ARE YOU SURE YOU WANT TO BUY"<<twpname<<"?(y/n)";
	cin>>dum;
	if(dum=='n')
	{
		strcpy(swpname,decoy);
		player.money=moneh;
	}
	moneh=player.money;
	player.money=player.money-swpncost;
	if(player.money<0)
	{
		cout<<"NOT ENOUGH COINS.";
		player.money=moneh;
		strcpy(swpname,decoy);
	}
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

void changewpn()
{
	_setcursortype(_NOCURSOR);
	int gd=DETECT,gm,mpx,y1;
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
				outtextxy(200,165,"EXIT");
				outtextxy(10,205,"PITCHFORK     -      Your trusty ol' fork.");
				outtextxy(10,245,"BATTLE AXE  35000    Clean executes lead to more meat salvaged.");
				outtextxy(10,285,"KATANA      50000    Every third move does percentage current health damage.");
				outtextxy(10,325,"GODSTAFF    100000   Can call angels,boosting critical hit ratio");
				outtextxy(170,337," damage per second.");
				setlinestyle(0,0,3);
				for(int i=150;i<=310;i+=40)
				{
					indibox(i);
				}
				int a;
				moveto(0,150);
				indibox(150,9);
				do
				{
					a=getch();
					y1=gety();
					switch(a)
					{
						case 115:
							if(y1<=270)
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
				outtextxy(250,165,	"EXIT");
				outtextxy(10,205,"BOAR-SKIN ARMOR  35000   Tough protective cover. That little bulk you need to");
				outtextxy(210,219,"serve the prince.");
				outtextxy(10,245,"CANE OF          50000   Heals everyone for %missing health.");
				outtextxy(10,259,"REDEMPTION");
				outtextxy(10,285,"THE RESURRECTOR 100000   Lays a curse upon self to bring a member of the party");
				outtextxy(210,299,"back to life, fully restoring primary status and some");
				outtextxy(210,313,"health.The curse deals a fourth of your health every");
				outtextxy(210,327,"turn.");
				setlinestyle(0,0,3);
				for(int j=150;j<=270;j+=40)
				{
					j==270?indibox2(j,15,60):indibox2(j);
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
							if(y1<=230)
								moverel(0,40);
							else
								continue;
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
					if(y1==270)
					{
						indibox2(y1,15,60);
						indibox2(gety(),5);
					}
					else if(gety()==270)
					{
						indibox2(y1);
						indibox2(gety(),5,60);
					}
					else
					{
						indibox2(y1);
						indibox2(gety(),5);
					}
				}while(a!=13);
				break;
			case 't':
				settextstyle(3,0,5);
				setcolor(2);
				outtextxy(100,50,"MOTOG'S SHOP");
				settextstyle(0,0,1);
				setcolor(15);
				outtextxy(250,165,"EXIT");
				outtextxy(10,205,"BOAR-SKIN ARMOR  35000   Tough protective cover. That little bulk you need to");
				outtextxy(210,219,"serve the prince.");
				outtextxy(10,245,"HARDENED         50000   Regenerates %health per second. This breaks if the");
				outtextxy(210,259,"tank is hit in the last 3 turns.");
				outtextxy(10,259,"ACCUMETAL GUARD");
				outtextxy(10,285,"THE BULWARK OF   100000  All reduced damage is converted into energy.");
				outtextxy(210,299,"This energy can be released to deal true damage.");
				outtextxy(210,313,"Foreseeing an attack, the knight blocks it, and gains");
				outtextxy(210,327,"extra damage reduction.");
				outtextxy(10,299,"RAHLDEN");
				setlinestyle(0,0,3);
				for(int k=150; k<=270; k+=40)
				{
					k==270?indibox2(k,15,60):indibox2(k);
				}
				moveto(0,150);
				indibox2(150,2);
				do
				{
					a=getch();
					y1=gety();
					switch(a)
					{
						case 115:
							if(y1<=230)
								moverel(0,40);
							else
								continue;
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
					if(y1==270)
					{
						indibox2(y1,15,60);
						indibox2(gety(),2);
					}
					else if(gety()==270)
					{
						indibox2(y1);
						indibox2(gety(),2,60);
					}
					else
					{
						indibox2(y1);
						indibox2(gety(),2);
					}
				     }while(a!=13);
				break;
			case 'e':
				exit(1);
			default:
				continue;
		}
	}while(dum!='m'&&dum!='s'&&dum!='t');
	switch(dum)
	{
		case 'm':
			switch(y1)
			{
				case 150:
					changemel('z');
				case 190:
					changemel('p');
				case 230:
					changemel('b');
				case 270:
					changemel('k');
				case 310:
					changemel('g');
			}
		case 's':
			switch(y1)
			{
				case 150:
					changesupp('z');
				case 190:
					changesupp('b');
				case 230:
					changesupp('c');
				case 270:
					changesupp('r');
			}
		case 't':
			switch(y1)
			{
				case 150:
					changetank('z');
				case 190:
					changetank('b');
				case 230:
					changetank('g');
				case 270:
					changetank('r');
			}
	}
cleardevice();
closegraph();
}

void trap(int x,int y,int col=0)
{
	int trape[]={x,y,40+x,y,30+x,30+y,10+x,30+y,x,y};
	setfillstyle(1,col);
	setcolor(col);
	fillpoly(5,trape);
}

char mainscr()
{
	settextstyle(0,0,2);
	outtextxy(295,150,"MAP");
	outtextxy(250,200,"INVENTORY");
	outtextxy(260,250,"DATABASE");
	outtextxy(265,300,"GIVE UP");
	int x1,y1,a;
	moveto(240,140);
	trap(getx()-45,gety(),15);
	trap(getx()+175,gety(),15);
	setcolor(10);
	line(getx()-45,gety(),getx()+215,gety());
	line(getx()-35,gety()+30,getx()+205,gety()+30);
	do
	{
		a=getch();
		x1=getx();
		y1=gety();
		switch(a)
		{
			case 119:
				if(gety()>=190)
					moverel(0,-50);
				break;
			case 115:
				if(gety()<=240)
				moverel(0,50);
				    break;
			case 13:
				continue;
			default:
				continue;
		}
		trap(x1-45,y1);
		trap(x1+175,y1);
		setcolor(0);
		line(x1-45,y1,x1+215,y1);
		line(x1-35,y1+30,x1+205,y1+30);
		trap(getx()-45,gety(),15);
		trap(getx()+175,gety(),15);
		switch(getx()+gety())
		{
		case 380:
			setcolor(10);
			break;
		case 430:
			setcolor(9);
			break;
		case 480:
			setcolor(11);
			break;
		case 530:
			setcolor(12);
		}
		line(getx()-45,gety(),getx()+215,gety());
		line(getx()-35,gety()+30,getx()+205,gety()+30);
	}while(a!=13);
	switch(getcolor())
	{
		case 9:
			return 'i';
		case 10:
			return 'm';
		case 11:
			return 'd';
		case 12:
			return 'p';
	}
	return '-';
}

void subtrans()
{
	loading();
	_setcursortype(_NOCURSOR);
	char dum;
	int gd=DETECT,gm;
	int mpx;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	settextstyle(3,0,6);
	delay(100);
	mpx=getmaxx()/2-155;
	outtextxy(mpx+95,20,"M0CT");
	dum=mainscr();
	switch(dum)
	{
	cleardevice();
	closegraph();
	clrscr();
		case 'm':
			map();
		case 'i':
			player.accessinv();
		case 'd':
			database();
		case 'p':
			exit(1);
	}
}

void namae(int x,int y,int i=0)
{
	setfillstyle(1,0);
	int p[10]={x+105+i,100,x+120+i,100,x+120+i,y+100,x+105+i,y+100,x+105+i,100};
	fillpoly(5,p);
}

void header()
{
	 _setcursortype(_NOCURSOR);
	int gd=DETECT,gm,x=630,y=470;
	int bk[10]={0,0,x,0,x,y,0,y,0,0};
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setfillstyle(1,15);
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
	namae(0,150);
	namae(50,150);
	namae(100,150);
	namae(175,150);
	namae(225,150);
	namae(300,30);
	namae(350,30);
	namae(387,150);
	namae(426,30);
	delay(2000);
	cleardevice();
	closegraph();

	for(int i=0;i<=100;i+=10)
	{
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int c[10]={131+i,100,143+i,100,143+i,130,131+i,130,131+i,100};
	setfillstyle(1,15);
	fillpoly(5,bk);
	fillpoly(5,c);
	namae(0,150,i);
	namae(50,150,i);
	namae(100,150,i);
	namae(175,150,i);
	namae(225,150,i);
	namae(300,30,i);
	c[0]=405+i;
	c[1]=220;
	c[2]=420+i;
	c[3]=220;
	c[4]=420+i;
	c[5]=250;
	c[6]=405+i;
	c[7]=250;
	c[8]=405+i;
	c[9]=220;
	fillpoly(5,c);
	namae(350,30,i);
	namae(387,150,i);
	namae(426,30,i);
	delay(10);
	cleardevice();
	closegraph();
	}

	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setfillstyle(1,15);
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
	namae(0,150);
	namae(50,150);
	namae(100,150);
	namae(175,150);
	namae(225,150);
	namae(300,30);
	namae(350,30);
	namae(387,150);
	namae(426,30);
	delay(1000);
	cleardevice();
	closegraph();

	for(i=0;i>-100;i-=10)
	{
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int b[10]={131+i,100,143+i,100,143+i,130,131+i,130,131+i,100};
	setfillstyle(1,15);
	fillpoly(5,bk);
	fillpoly(5,b);
	namae(0,150,i);
	namae(50,150,i);
	namae(100,150,i);
	namae(175,150,i);
	namae(225,150,i);
	namae(300,30,i);
	b[0]=405+i;
	b[1]=220;
	b[2]=420+i;
	b[3]=220;
	b[4]=420+i;
	b[5]=250;
	b[6]=405+i;
	b[7]=250;
	b[8]=405+i;
	b[9]=220;
	fillpoly(5,b);
	namae(350,30,i);
	namae(387,150,i);
	namae(426,30,i);
	delay(10);
	cleardevice();
	closegraph();
	}

	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setfillstyle(1,15);
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
	int d[10]={131,100,143,100,143,130,131,130,131,100};
	fillpoly(5,d);   //m
	namae(50,150);      //m
	namae(100,150);       //o
	namae(175,150);        //o
	namae(225,150);        //c
	namae(300,30);           //c
	d[0]=405;
	d[1]=220;
	d[2]=420;
	d[3]=220;
	d[4]=420;
	d[5]=250;
	d[6]=405;
	d[7]=250;
	d[8]=405;
	d[9]=220;
	fillpoly(5,d);        //c
	namae(350,30);           //t
	namae(387,150);             //t
	namae(426,30);
	delay(2000);
	outtextxy(200,450,"PRESS ANY KEY TO CONTINUE");
	getch();
	cleardevice();
	closegraph();

}

void giveup(int &givup)
{
	givup=1;
}

void makebox()
{
	setlinestyle(0,0,3);
	int lop[]={270,140,400,140,400,160,270,160,270,140};
	drawpoly(5,lop);
	setlinestyle(0,0,1);
}

void database()
{
      _setcursortype(_NOCURSOR);
     char dum;
     do
      {

		int gd=DETECT,gm,mpx;
		initgraph(&gd,&gm,"c:\\turboc3\\BGI");
		settextstyle(1,0,5);
		delay(100);
		mpx=getmaxx()/2-155;
		outtextxy(mpx+30,15,"DATABASE");

		settextstyle(0,0,1);
		makebox();
		outtextxy(mpx+100,150,"GENERAL INFO");
		outtextxy(mpx+100,190,"ADVANCE INFO");
		outtextxy(mpx+100,230,"EXIT DATABASE");
		dum=getch();
		switch (dum)
		{
				case 'g':
					cleardevice();
					closegraph();
					clrscr();
					 _setcursortype(_NOCURSOR);
					cout<<endl<<"(i)THE TOWN OF PRAEREN LIES TO THE WEST OF GUHA FOREST. PRAEREN IS A BEAUTIFUL PLACE WITH SOULFUL RESIDENTS.IT IS UNDER THE TYRANNICAL RULE OF KING VLAD.";
					cout<<endl<<"(ii)VITO,YOUR MAIN CHARACTER IS A FARMER.A VEHEMENT UNDERPERFORMER,HE IS A STRONG-WILLED HUMAN.";
					cout<<endl<<"(iii)FERNANDINO IS A LITERALLY CHEESE BALL.HE IS TRUSTWORTHY AND WISE.A GOOD COMRADE.";
					cout<<endl<<"(iv)ANASTASIA IS A FORAGER.SHE AND VITO ARE CHILDHOOD FRIENDS.THEY ARE INSEPERABLE.";
					cout<<endl<<"(v)MOTOG IS A DRUNK GOOD-FOR-NOTHING.HE IS GOOD NATURED AND PEOPLE TEND TO TAKE ADVANTAGE OF HIM.THE ONLY PERSON HE TRUSTS FULLY IS VITO.";
					cout<<endl<<"(vi)VLADIMIR PUTOUT IS CURRENTLY THE RULER OF PRAEREN.HE CLAIMS THAT HE IS FROM THE BARREN WASTELANDS OF SOVIET RUSSIA.A STRONG SPEAKER,HE COMMANDS THE ENTIRE FOOD FORCE OF THE TOWN.";
					cout<<endl<<"(vii)VITO, ANA AND MOTOG FORM A CLAN.THEY HAVE SET OUT TO FOIL THE ANARCHIC RULE OF VLAD.";
					cout<<endl<<"(viii)HP STANDS FOR HEALTH POINTS.IT REPRESENTS THE NUMBER OF HITS YOUR CHARACTER CAN TAKE.";
					cout<<endl<<"(ix)MEAT IS USED TO REPLENISH THE HP OF YOUR PARTY. SOME OF IT IS USED TO BRIBE FERNANDINO. IT CAN BE OBTAINED THROUGH BATTLING AND THE SHAKE SHACK.";           case 'm':
					cout<<endl<<endl<<"ENTER ANY KEY TO GO BACK TO DATABASE";
					getch();
					database();
					break;
				case 'a':
					cleardevice();
					closegraph();
					clrscr();
					 _setcursortype(_NOCURSOR);
					cout<<endl<<"PERCENTAGE MISSING HEALTH:PRETTY SELF EXPLANATORY. x %MISSING HP= x*MISSING HEALTH/100.";
					cout<<endl<<"x %CURRENT HEALTH DAMAGE= x*REMAINING HEALTH/100.";
					cout<<endl<<"A CURSE IS A STATUS EFFECT WHICH DEPLETES A FOURTH OF YOUR HEALTH EVERY TURN";
					cout<<endl<<"DPT STANDS FOR DAMAGE DEALT PER TURN";
					cout<<endl<<endl<<"ENTER ANY KEY TO GO BACK TO DATABASE";
					getch();
					database();
					break;
				case 'e':
					cleardevice();
					closegraph();
					subtrans();
					break;
				default:
					cleardevice();
					closegraph();
					clrscr();
					cout<<"ENTER VALID KEY: ";

		}
      }while(dum!='a'&&dum!='g'&&dum!='e');

}

void tips()
{
	 _setcursortype(_NOCURSOR);
	randomize();
	int a=random(10);
	cout<<"\t    ";
	if(a==0)
		cout<<"THE ENEMY CAN BE A SINGLE POWERHOUSE OR AN INVOKER. CHOOSE YOUR WEAPONS WISELY.";
	else if(a==1)
		cout<<"A GOOD BALANCE IN OFFENSE AND DEFENSE IS REQUIRED FOR A WIN.";
	else if(a==2)
		cout<<"THE TOMAHAWK IS A HIGH RISK HIGH REWARD SETUP TYPE. IF YOU CAN WITHSTAND THE ENEMY FOR LONG ENOUGH IT CAN GET A CLEANSWEEP.";
	else if(a==3)
		cout<<"%MISSING HP ATTACKS ARE ONLY USEFUL WHEN THE ENEMY IS LOW ON HEALTH. TRY TO TIME IT THAT WAY.";
	else if(a==4)
		cout<<"\"SOMETIMES YOU MUST LOSE A BATTLE TO WIN THE WAR.\"";
	else if(a==5)
		cout<<"IF YOU HIT A WALL, KEEP TRYING! THOSE WHO HAVE NEVER FAILED HAVE NEVER TRIED.";
	else if(a==6)
		cout<<"REMEMBER, YOU CONTROL THE FIELD, NOT THE OTHER WAY AROUND.";
	else if(a==7)
		cout<<"MEAT IS SCARCE IN THE FOREST. USE YOUR SUBSTANCES JUDICIOUSLY.";
	else if(a==8)
		cout<<"THE GOAL IS NOT TO SURVIVE, BUT TO PLANT FEAR INTO THE HEARTS OF THOSE WHO THINK ILL OF YOU AND YOUR VILLAGE.";
	else if(a==9)
		cout<<"\"THE MORE YOU KNOW, THE LESS SURE YOU ARE.\"";
}

void loading()
{
	 _setcursortype(_NOCURSOR);
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int x=getmaxx()/2-100,y=getmaxy()/2-80;
	line(x,y,x+180,y);
	line(x,y,x,y+32);
	line(x,y+32,x+180,y+32);
	line(x+180,y+32,x+180,y);
	line(x+5,y+5,x+175,y+5);
	line(x+5,y+5,x+5,y+27);
	line(x+5,y+27,x+175,y+27);
	line(x+175,y+27,x+175,y+5);
	line(x,y,x+5,y+5);
	line(x+175,y+27,x+180,y+32);
	line(x+5,y+27,x,y+32);
	line(x+175,y+5,x+180,y);
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t   LOADING..."<<endl<<endl<<endl<<endl<<endl;
	tips();
	for(int i=0;i<171;i++)
	{
		randomize;
		int a=random(3);
		if(a==0)
			delay(5);
		if(a==1)
			delay(20);
		if(a==2)
			delay(75);
		line(x+5+i,y+5,x+5+i,y+27);
	}
	cout<<endl<<endl<<endl<<"\t\t\t   PRESS ANY KEY TO CONTINUE";
	getch();
	cleardevice();
	closegraph();
}

int main()
{
	 _setcursortype(_NOCURSOR);
	char intro[]="Hello, summoner.";// Welcome to The Jurassic 
			//Pot.In the midst of King Vlad's oppressive rule,
			//three townfolks Vito, Ana and Motog come together
			// to form a clan and embark on a journey to abolish
			//the anarchy. Vlad's forces are stationed in the Guha
			//forest to ambush the newly formed clan.";
	clrscr();
	header();
	loading();
	textcolor(7);
	int i=0;
	char *clan=new char[10];
	cout<<endl;
	_setcursortype(_NOCURSOR);
	cprintf("ENTER YOUR CLAN NAME: ");
	cin>>clan;
	cout<<endl;
	 _setcursortype(_NOCURSOR);
	while(intro[i]!='\0')
	{

		cout<<intro[i];
		if(intro[i]=='.')
			delay(1000);
		else
			delay(100);
		i++;
	}
	transition();
	subtrans();
	return 0;
}

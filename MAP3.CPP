#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>



void b1eye(int x,int y)
{
	int i[]={x,y,x+2,y,x+2,y+2,x,y+2,x,y};
	setfillstyle(1,11);
	setcolor(11);
	fillpoly(5,i);
}

void main()
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
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\t\t      PRAEREN";
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

	for(i=35;i<50;i++)     //praeren
	{
		setcolor(10);
		circle(525,380,i);
	}
	setfillstyle(1,12);
	setcolor(12);
	fillellipse(250,160,25,25);
	int b1head[]={260,175,235,175,238,145,260,145,260,175};
	setcolor(2);
	setfillstyle(1,2);
	fillpoly(5,b1head);
	int b1hood[]={260,175,260,148,257,145,237,145,237,143,261,143,265,147,265,175,260,175};
	setcolor(0);
	setfillstyle(1,0);
	fillpoly(9,b1hood);
	b1eye(245,152);
	b1eye(243,157);
	b1eye(247,157);
	b1eye(241,162);
	b1eye(245,162);
	b1eye(249,162);
	setcolor(12);
	setfillstyle(1,12);
	fillellipse(170,374,25,25);
	int b2cane[]={155,360,151,364,183,388,187,384,155,360};
	setfillstyle(1,0);
	setcolor(0);
	fillpoly(5,b2cane);
	int canediatop[]={157,366,157,360,151,360,151,366,157,366};
	int canediabot[]={181,382,187,382,187,388,181,388,181,382};
	setcolor(2);
	setfillstyle(1,6);
	fillpoly(5,canediatop);
	fillpoly(5,canediabot);
	setfillstyle(1,4);
	setcolor(12);
	setfillstyle(1,12);
	fillellipse(610,50,25,25);
	int hatbot[]={630,60,590,60,590,50,595,50,595,55,625,55,625,50,630,50,630,225,60,630,60};
	setcolor(0);
	setfillstyle(1,0);
	fillpoly(8,hatbot);
	int hattop[]={620,55,600,55,600,30,620,30,620,55};
	setcolor(0);
	setfillstyle(1,0);
	fillpoly(5,hattop);
	int hatstrap[]={620,55,600,55,600,52,620,52,620,55};
	setcolor(4);
	setfillstyle(1,4);
	fillpoly(5,hatstrap);
	setcolor(1);
	setfillstyle(1,9);



getch();
cleardevice();
closegraph();
clrscr();
}

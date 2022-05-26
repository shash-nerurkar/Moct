#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main()
{
	clrscr();
	int gd=DETECT,gm;
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
	for(i=35;i<50;i++)
	{
		setcolor(10);
		circle(525,380,i);
	}
       /*	for(int i=0;i<144;i+=12)
	{
		delay(69);
		setcolor(9);
		circle(590-i,455,4);//vito
		if(i==143)
		{
			cleardevice();
			closegraph();
		}
	}
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	line(600,440,460,440);//AB
	line(460,300,610,300);//CD
	line(460,300,460,253);//CE
	line(460,253,340,253);//EF
	line(340,253,340,440);//FG
	line(340,440,260,440);//GH
	line(250,150,150,150);//KL
	line(150,150,150,38); //LM
	line(40,150,40,300);  //NO
	line(40,300,175,300); //OP
	line(175,300,175,375);//PQ
	line(400,150,400,38); //RS
	line(400,150,600,150);//RT
	line(600,150,600,38); //TU

	line(600,460,440,460);//A1B1
	line(440,460,440,273);//B1E1
	line(440,273,360,273);//E1F1
	line(360,273,360,460);//F1G1
	line(360,460,240,460);//G1H1
	line(240,413,240,170);//I1K1
	line(240,170,70,170); //K1N1
	line(70,170,70,280);  //N1O1
	line(70,280,195,280); //O1P1
	line(195,280,195,375);//P1Q1
	line(260,170,620,170);//K2T1
	line(620,170,620,38); //T1U1

	//intersections
	line(460,320,610,320);//C1D1
	line(460,440,460,320);//BC1
	line(240,413,200,413);//I2J
	line(240,433,200,433);//I1J1
	line(40,150,130,150); //NL1
	line(130,150,130,38); //L1M1
	line(150,150,380,150);//LR1
	line(380,150,380,38); //R1S1
	line(260,440,260,170);//HK2
	line(240,460,240,433);//H1I1
	for(int j=0;j<15;j++)
	{
		setcolor(9);
		circle(590-i,450,4);
		delay(300);
		setcolor(0);
		circle(590-i,450,4);
		delay(300);
	}*/
	getch();
	cleardevice();
	closegraph();
	return 0;
}

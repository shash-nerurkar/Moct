#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main()
{
	int gd=DETECT,gm,dum=190;
	float change,hp=500;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");

	for(int i=0;i<5;i++)
	{
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



	while(i>0)
	{
		cout<<"ENTER HEALTH:";
		cin>>hp;
		if(hp<0)
			hp=-hp;
		change=hp/500;
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
	getch();
	cleardevice();
	closegraph();
	return 0;
}

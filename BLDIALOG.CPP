#include<iostream.h>
#include<graphics.h>
#include<conio.h>

int main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	setlinestyle(0,0,3);
	int poly[10]={0,377,350,377,350,427,0,427,0,377};
	drawpoly(5,poly);
	outtextxy(10,402,"THE TEAM MAY ESCAPE. ONLY WORKS ON GOONS.");
	//"ALTAN MENDS HIS WOUNDS, HEALING HIMSELF.");
	//"ALTAN DEFENDS, REDUCING DAMAGE DEALT.");
	//"ALTAN SLICES AT THE ENEMY, DEALING DAMAGE.");
	getch();
	cleardevice();
	closegraph();
	return 0;
}
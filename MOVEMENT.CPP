#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

int main()
{
	int gd=DETECT,gm;
	int x=0,y=0;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	circle(300+x,300+y,10);
	clrscr();
	char a;
	cout<<"ENTER w,a,s AND d TO GO UP, LEFT, DOWN AND RIGHT RESPECTIVELY.";
	do
	{

		cin>>a;
		cout<<endl;
		switch(a)
		{
			case 'w':
				y--;
				break;
			case 'a':
				x--;
				break;
			case 's':
				y++;
				break;
			case 'd':
				x++;
				break;
			case 'e':
				break;
			default:
				clrscr();
				cout<<"ENTER W,A,S AND D TO GO UP, LEFT, DOWN AND RIGHT RESPECTIVELY.";
		 }
		 circle(300+x,300+y,10);
		 x=y=0;
		 getch();
	}while(a!='e');
	getch();
	return 0;
}
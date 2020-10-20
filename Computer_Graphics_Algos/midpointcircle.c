#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
void pixel(int xc,int yc,int x,int y)
{
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(xc+y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc-y,yc+x,WHITE);
	putpixel(xc-y,yc-x,WHITE);
}
void midptcircle(int xc,int yc,int r){
	int x=0;
	int y=r;
	int p=1-r;
	pixel(xc,yc,x,y);

	while(x<y)
	{
		if(p<0)
		{
			x++;
			p=p+2*x+1;
		}
		else
		{
			x++;
			y--;
			p=p+2*(x-y)+1;
		}
		pixel(xc,yc,x,y);
	}


}


int main()
{
	int gd,gm,xc,yc,r;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	printf("Enter the center of the circle :");
	scanf("%d%d",&xc,&yc);
	printf("Enter the radius of the circle :");
	scanf("%d",&r);
	midptcircle(xc,yc,r);
	getch();
	closegraph();
	return 0;
}

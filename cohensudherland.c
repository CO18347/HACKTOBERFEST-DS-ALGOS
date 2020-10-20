#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xl,yl,xh,yh;

int get(int x,int y){
	int code = 0;
	%Perform Bitwise OR to get outcode
	if(y > yh) code |=TOP; % to the Top of rectangle 
	if(y < yl) code |=BOTTOM; % to the Bottom of rectangle 
	if(x < xl) code |=LEFT; % to the left of rectangle 
	if(x > xh) code |=RIGHT; % to the Right of rectangle 
	return code;
}

void main()
{
	int gdriver = DETECT,gmode,x1,y1,x2,y2,flag = 0,out1,out2; 
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	setcolor(WHITE);
	printf("Enter bottom left and top right co-ordinates of window: ");
	scanf("%d %d %d %d",&xl,&yl,&xh,&yh);
	rectangle(xl,yl,xh,yh);
	printf("Enter the endpoints of the line: ");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	line(x1,y1,x2,y2);
	getch();

	out1=get(x1,y1);
	out2=get(x2,y2);
	while(1){
		float m =(float)(y2-y1)/(x2-x1);
		%Both points inside. flag line
		if(out1==0 && out2==0){ 
			flag = 1;
			break;
		}
		%AND of both codes != 0.Line is outside. Reject line
		else if((out1 & out2)!=0){
			break;
		}else{
			int x,y;
			int temp;
			%Decide if point1 is inside, if not, calculate intersection
			if(out1==0) 
				temp = out2;
			else 
				temp = out1;
			%Line clips top edge
			if(temp & TOP){
				x = x1+ (yh-y1)/m;
				y = yh;
			}
			else if(temp & BOTTOM){ 	%Line clips bottom edge
				x = x1+ (yl-y1)/m;
				y = yl;
			}else if(temp & LEFT){ 	%Line clips left edge
				x = xl;
				y = y1+ m*(xl-x1);
			}else if(temp & RIGHT){ 	%Line clips right edge
				x = xh;
				y = y1+ m*(xh-x1);
			}
			%Check which point we had selected earlier as temp, and replace its co-ordinates
			if(temp == out1){ 
				x1 = x;
				y1 = y;
				out1 = get(x1,y1);
			}else{
				x2 = x;
				y2 = y;
				out2 = get(x2,y2);
			}
		}
	}
	setcolor(YELLOW);
	% Here the user can add code to display the rectangle along with the accepted (portion of) lines 
	printf("After clipping:");
	if(flag)
		line(x1,y1,x2,y2);
	getch();
	closegraph();
}

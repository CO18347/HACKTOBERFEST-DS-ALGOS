#include <stdio.h>
#include <dos.h>
#include <graphics.h>
// function to draw all other 7 pixels 
// present at symmetric position 
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, BLUE);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, GREEN);
    putpixel(xc-x, yc-y, YELLOW);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}

void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {

        x++;
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0)
        {                                       //if d > 0, then (x+1, y-1) is to be chosen 
                                                //as the next pixel as it will be closer to the arc.
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
        
    }
}

int main()

{   //initgraph initializes the graphics system by loading a graphics driver from disk.
    //graphicmode is Graphics mode which is a computer display mode that generates image using pixels
    // DETECT is a macro defined in "graphics.h" header file.
    int xc,yc,r;
    int gd=DETECT,gm;
    printf("Enter the coordinates of center of the circle");
    scanf("%d%d",&xc,&yc);
    printf("Enter the length of radius");
    scanf("%d",&r);
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    circleBres(xc, yc, r); // function call 
    getch();
    closegraph();
    return 0;
}

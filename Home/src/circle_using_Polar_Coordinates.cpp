#include <graphics.h>  
#include <stdlib.h>  
#define color 10  
void eightWaySymmetricPlot(int xc,int yc,int x,int y)  
{  
    putpixel(x+xc,y+yc,color);  
    putpixel(x+xc,-y+yc,color);  
    putpixel(-x+xc,-y+yc,color);  
    putpixel(-x+xc,y+yc,color);  
    putpixel(y+xc,x+yc,color);  
    putpixel(y+xc,-x+yc,color);  
    putpixel(-y+xc,-x+yc,color);  
    putpixel(-y+xc,x+yc,color);  
}  
void PolarCircle(int xc,int yc,int r)  
{  
    int x,y,d;  
    x=0;  
    y=r;  
    d=3-2*r;  
    eightWaySymmetricPlot(xc,yc,x,y);  
    while(x<=y)  
    {  
        if(d<=0)  
        {  
            d=d+4*x+6;  
        }  
        else  
        {  
            d=d+4*x-4*y+10;  
            y=y-1;  
        }  
        x=x+1;  
        eightWaySymmetricPlot(xc,yc,x,y);  
    }  
}  
int main(void)  
{  
    int gdriver = DETECT, gmode, errorcode;  
    int xc,yc,r;  
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");  
errorcode = graphresult();  
if (errorcode != grOk)    
    {  
        printf("Graphics error: %s\n", grapherrormsg(errorcode));  
        printf("Press any key to halt:");  
        getch();  
        exit(1);               
    }  
printf("Enter the values of xc and yc ,that is center points of circle : ");  
    scanf("%d%d",&xc,&yc);  
    printf("Enter the radius of circle : ");  
    scanf("%d",&r);  

    // Enter the values of xc and yc ,that is center points of circle : 250 300
    // Enter the radius of circle : 80

    PolarCircle(xc,yc,r);  
    getch();  
    closegraph();  
    return 0;  
}  
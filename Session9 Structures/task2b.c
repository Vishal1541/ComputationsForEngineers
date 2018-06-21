#include<stdio.h>
#include <sys/ioctl.h>
#define clrscr() printf("\033[H\033[J")
float n;
void getWinSize(int *width,int *length )
{
	struct winsize w;
	ioctl( 0 , TIOCGWINSZ, &w) ;
	*length=w.ws_col;
	*width=w.ws_row;
}
typedef struct s1
{
    int x,y;
}point;
typedef struct s2
{
    point d1,d2;
}rectangle;
void change_dim(int len,int wid,rectangle rect)
{
	while((rect.d1.x>=wid)||(rect.d2.x>=wid)||(rect.d1.y>=len)||(rect.d1.y>=len))
	{
		rect.d1.x/=2;
		rect.d2.x/=2;
		rect.d1.y/=2;
		rect.d2.y/=2;
	}
}
void draw_rect(int fill,rectangle rect)
{
	int i,j;
	for(i=1;i<rect.d1.y;i++)
		printf(" \n");
	for(i=1;i<rect.d1.x;i++)
		printf(" ");
	printf("+");
	for(i=rect.d1.x+1;i<rect.d2.x;i++)
		printf("-");
	printf("+\n");
	for(i=rect.d1.y+1;i<rect.d2.y;i++)
	{
		for(j=1;j<rect.d1.x;j++)
			printf(" ");
		printf("|");
		if(fill)
			for(j=rect.d1.x+1;j<rect.d2.x;j++)
				printf("-");
		else
			for(j=rect.d1.x+1;j<rect.d2.x;j++)
				printf(" ");
		printf("|\n");
	}
	for(i=1;i<rect.d1.x;i++)
		printf(" ");
	printf("+");
	for(i=rect.d1.x+1;i<rect.d2.x;i++)
		printf("-");
	printf("+\n");
}
void intersect_area(rectangle rect[],int fill)
{
	rectangle final_rect=rect[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(rect[i].d1.x>final_rect.d1.x)
			final_rect.d1.x=rect[i].d1.x;
		if(rect[i].d2.x<final_rect.d2.x)
			final_rect.d2.x=rect[i].d2.x;
		if(rect[i].d1.y>final_rect.d1.y)
			final_rect.d1.y=rect[i].d1.y;
		if(rect[i].d2.y<final_rect.d2.y)
			final_rect.d2.y=rect[i].d2.y;
	}
	draw_rect(fill,final_rect);
}
int main()
{
    clrscr();
    int val=0,filled=0,length,width;
    getWinSize(&length,&width);
	printf("Please enter the number of rectangles you wish to make:");
	val=scanf("%f",&n);
	rectangle rect[(int)n];
    char dump;
	while(val!=1)
    {
        printf("Please enter a valid input...!!!\n");
        val=scanf("%c %f",&dump,&n)-1;
    }
    int i=0;
    for(i=0;i<(int)n;i++)
    {
    	printf("Please enter the coordinates of any two diagonally opposite points of the rectangle:\n");
    	val=scanf("%d%d%d%d",&rect[i].d1.x,&rect[i].d1.y,&rect[i].d2.x,&rect[i].d2.y);
		while(val!=4)
    	{
        	printf("Please enter a valid input...!!!\n");
        	val=scanf("%c %d%d%d%d",&dump,&rect[i].d1.x,&rect[i].d1.y,&rect[i].d2.x,&rect[i].d2.y)-1;
    	}
    	if(rect[i].d1.x>rect[i].d2.x)
    	{
        	int temp=rect[i].d1.x;
        	rect[i].d1.x=rect[i].d2.x;
        	rect[i].d2.x=temp;
    	}
    	if(rect[i].d1.y>rect[i].d2.y)
    	{
        	int temp=rect[i].d1.y;
        	rect[i].d1.y=rect[i].d2.y;
        	rect[i].d2.y=temp;
    	}
    	change_dim(length,width,rect[i]);
    }
    printf("Enter 0 if the rectangle has to be empty, and 1 if you want it to be filled:");
    val=scanf("%d",&filled);
    while((val!=1)||(filled<0)||(filled>1))
    {
        printf("Please enter a valid input...!!!\n");
        val=scanf("%c %d",&dump,&filled)-1;
    }
    intersect_area(rect,filled);
    return 0;
}

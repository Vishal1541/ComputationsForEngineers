#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct point{
	float x;
	float y;
}PointType;

typedef struct rect{
	PointType p1;
	PointType p2;
}RectType;

int main(){
	printf("Enter the type of rectangle:\n");
	printf("1. Filled\n");
	printf("2. Unfilled\n");
	int n;
	scanf("%d",&n);
	assert(n==1 || n==2);
	RectType rect[2];
	printf("Enter the co-ordinate of 1st rect:\n");
	printf("x1 = ");
	scanf("%f",&rect[0].p1.x);
	printf("y1 = ");
	scanf("%f",&rect[0].p1.y);
	printf("x2 = ");
	scanf("%f",&rect[0].p2.x);
	printf("y2 = ");
	scanf("%f",&rect[0].p2.y);
	printf("Enter the co-ordinate of 2nd rect:\n");
	printf("x1 = ");
	scanf("%f",&rect[1].p1.x);
	printf("y1 = ");
	scanf("%f",&rect[1].p1.y);
	printf("x2 = ");
	scanf("%f",&rect[1].p2.x);
	printf("y2 = ");
	scanf("%f",&rect[1].p2.y);
	if(n==1){
		//Rect1
		printf("\n\nRect1:\n\n\t\t\t");
		printf("+");
		for(int j=0;j<=abs(rect[0].p2.x-rect[0].p1.x);j++)
			printf("-");
		printf("+\n\t\t\t");
		for(int i=0;i<(abs(rect[0].p2.y-rect[0].p1.y))/1.2;i++){
			printf("|");
			for(int j=0;j<=abs(rect[0].p2.x-rect[0].p1.x);j++)
				printf("-");
			printf("|\n\t\t\t");			
		}
		printf("+");
		for(int j=0;j<=abs(rect[0].p2.x-rect[0].p1.x);j++)
			printf("-");
		printf("+");
		
		//Rect2
		printf("\n\nRect2:\n\n\t\t\t");
		printf("+");
		for(int j=0;j<=abs(rect[1].p2.x-rect[1].p1.x);j++)
			printf("-");
		printf("+\n\t\t\t");
		for(int i=0;i<(abs(rect[1].p2.y-rect[1].p1.y))/1.2;i++){
			printf("|");
			for(int j=0;j<=abs(rect[1].p2.x-rect[1].p1.x);j++)
				printf("-");
			printf("|\n\t\t\t");			
		}
		printf("+");
		for(int j=0;j<=abs(rect[1].p2.x-rect[1].p1.x);j++)
			printf("-");
		printf("+\n");
	}
	else{
		//Rect1
		printf("\n\nRect1:\n\n\t\t\t");
		printf("+");
		for(int j=0;j<=abs(rect[0].p2.x-rect[0].p1.x);j++)
			printf("-");
		printf("+\n\t\t\t");
		for(int i=0;i<(abs(rect[0].p2.y-rect[0].p1.y))/1.2;i++){
			printf("|");
			for(int j=0;j<=abs(rect[0].p2.x-rect[0].p1.x);j++)
				printf(" ");
			printf("|\n\t\t\t");			
		}
		printf("+");
		for(int j=0;j<=abs(rect[0].p2.x-rect[0].p1.x);j++)
			printf("-");
		printf("+");
		
		//Rect2
		printf("\n\nRect2:\n\n\t\t\t");
		printf("+");
		for(int j=0;j<=abs(rect[1].p2.x-rect[1].p1.x);j++)
			printf("-");
		printf("+\n\t\t\t");
		for(int i=0;i<(abs(rect[1].p2.y-rect[1].p1.y))/1.2;i++){
			printf("|");
			for(int j=0;j<=abs(rect[1].p2.x-rect[1].p1.x);j++)
				printf(" ");
			printf("|\n\t\t\t");			
		}
		printf("+");
		for(int j=0;j<=abs(rect[1].p2.x-rect[1].p1.x);j++)
			printf("-");
		printf("+\n");
	}
	return 0;
}










	

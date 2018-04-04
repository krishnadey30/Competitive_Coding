#include <stdio.h>
int main()
{
	int t,p;
	scanf("%d",&t);
	for(p=0;p<t;p++)
	{
		int x,y,x1,y1,x2,y2,x3,y3;
		scanf("%d,%d,%d,%d",&x,&y,&x1,&y1);
		scanf("%d,%d,%d,%d",&x2,&y2,&x3,&y3);
		if(x==x2 && y==y2)
		{
			printf("yes\n");
		}
		else if(x1==x2 && y1==y2)
		{
			printf("yes\n");
		}
		else if(x1==x3 && y1==y3)
		{
			printf("yes\n");
		}
		else if(x==x3 && y==y3)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
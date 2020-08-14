#include<stdio.h>
//#include<conio.h>
void swap(int*,int*);
int main()
{
	int a,b;
	printf("enter any two value\n");
	scanf("%d%d",&a,&b);
	swap(&a,&b);
	printf("\na=%d\nb=%d\n",a,b);
	return 0;
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

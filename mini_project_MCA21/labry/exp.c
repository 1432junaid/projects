#include<stdio.h>
void exit1(void);

int main(){
	exit1();
	return 0;
}

void exit1(){
	printf("Would you like to exit\t:");
	char a;
	scanf("%c",&a);
	if(a=='y' || a=='Y'){
		printf("\nyou are in exit now!\n");
	}else{
	printf("you are in else :\n");
	}
}


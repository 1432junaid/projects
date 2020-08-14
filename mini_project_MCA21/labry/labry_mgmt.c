#include<stdio.h>
#include<string.h>
//#include<stdlib.c>


void pwd(void);
void add_book(void);
void menu(void);
void exit1(void);




int main(){
//	system("clear");
//	pwd();
//	add_book();
//	menu();
	exit1();
	return 0;
}




void pwd(){				//This is password function

	char pwd[10];
	char name[10];
	printf("\t\t\t\t\n\n*********************LIBRARY MANAGEMENT*************************\n\n");
	printf("\n\n\n\t\tEnter user name\t:");
	scanf("%s",&name);
	printf("\n\n\t\tEnter password\t:");
	scanf("%s",&pwd);
	int r = strcmp(name,"admin");
	int t = strcmp(pwd,"123456");
	if(r==0 && t==0){
		system("clear");
		menu();
	}else{
	printf("\t\t\t\twrong passward\n\n\n\n");
	}
//	system("clear");

}


void add_book(){			//this is add  book function
	char b_name[20],a_name[20];
	int b_number;
	printf("\t\t\t\tEnter Book Name				:");
	scanf("%s",&b_name);
	printf("\t\t\t\tEnter Author Name			:");
	scanf("%s",&a_name);
	printf("\t\t\t\tEnter Book Number			:");
	scanf("%d",&b_number);
	printf("\n\n\n\n\n\n\n\n\nNOTE:[ Enter only 4 digits number to add book number ]\n\n\n");
}


void menu(){				//this is menu function
	printf("\t\t\t##################################### MENU #################################################\n\n\n\n\n\n");
	printf("\t\t\t 1:ADD BOOK\n");
	printf("\t\t\t 2:REMOVE BOOK\n");
	printf("\t\t\t 3:FIND BOOK\n");
	printf("\t\t\t 4:ISSUE BOOK\n");
	printf("\t\t\t 5:RETURN BOOK\n");
	printf("\t\t\t 6:LIST BOOK\n");
	printf("\t\t\t 7:EXIT\n\n\n\n\n");

	int x;
	printf("Select option\t");
	scanf("%d",&x);
	switch(x){

	case 1:
	add_book();
	break;

	case 2:
	printf("this is case 2\n");
	break;

	case 3:
	printf("This is case 3\n");
	break;

	case 4:
	printf("This is case 4\n");
	break;

	case 5:
	printf("this is case 5\n");
	break;

	case 6:
	printf("this is case 6\n");
	break;

	case 7:
	exit1();
	break;


	default:
	printf("Enter a valid option\n");

	}

}


void exit1(){
	printf("\n\n\n\n\t\t\t");
	printf("Enter y to exit\t:");
	char a;
	scanf("%c",&a);
	if(a=='y' || a=='Y'){
		system("clear");
		printf("\n\n\n\t\t\t\tbye bye\n\n\n!");
//		system("clear");
	}else{
		menu();
	}
}

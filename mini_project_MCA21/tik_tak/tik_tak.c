#include<stdio.h>
#include<stdlib.h>
//this is test branch
void display(char [][3]);
void play(char [][3]);
void test(char [][3]);
void update(char [][3],int,char);
int win_draw(char [][3]);

//this is feature 1 branch

int main(){
	char box[3][3] = { 	{'1','2','3'},
				{'4','5','6'},
				{'7','8','9'}
			 };
	int result;
	printf("\n\n");
	while(1){
		int x;
		printf("1. play game !!\n");
		printf("2. quit game :(\n\n");
//		printf("3. test case\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				system("clear");
				printf("Welcom !!\n\n\n");
				display(box);
				play(box);
				result = win_draw(box);
				if(result == 111)printf("\n\nwinner is player 2\n\n");
				if(result == 120)printf("\n\nwinner is player 1\n\n");
				if(result == 0)printf("\n\n :) Draw\n\n");
			break;
			case 2:
				printf("\n\t\tbye ! bye !\n\n");
				return 0;
//			break;
			case 3:
				display(box);
				test(box);
//				printf("result:\t%d\n\n",result);
		}
	}
	return 0 ;
}

void display(char box[3][3]){
	for(int i = 0; i <3;i++){
		for(int j = 0; j<3; j++){
			printf("%c ",box[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void play(char box[3][3]){
	int p1,p2,result;
	printf("player 1 = x\n");
	printf("player 2 = o\n\n\n");
	for(int i = 1; i<=9; i++){
		if(i%2 == 0){
			printf("player 2  :");
			scanf("%d",&p2);
			update(box,p2,'o');
		}
		if(i%2 != 0){
			printf("player 1  :");
			scanf("%d",&p1);
			update(box,p1,'x');
		}
//		if(i >=3){
//			result = win_draw(box);
//			if(result == 111)printf("\n\nwinner is player 2\n\n");
//			if(result == 120)printf("\n\nwinner is player 1\n\n");
//			if(result == 0)printf("\n\n :) Draw\n\n");
//		}
	}
}

void update(char box[3][3],int val,char ch){
	switch(val){
		case 1:
			box[0][0] = ch;
			system("clear");
			display(box);
		break;
		case 2:
			box[0][1] = ch;
			system("clear");
			display(box);
		break;
		case 3:
			box[0][2] = ch;
			system("clear");
			display(box);
		break;
		case 4:
			box[1][0] = ch;
			system("clear");
			display(box);
		break;
		case 5:
			box[1][1] = ch;
			system("clear");
			display(box);
		break;
		case 6:
			box[1][2] = ch;
			system("clear");
			display(box);
		break;
		case 7:
			box[2][0] = ch;
			system("clear");
			display(box);
		break;
		case 8:
			box[2][1] = ch;
			system("clear");
			display(box);
		break;
		case 9:
			box[2][2] = ch;
			system("clear");
			display(box);
		break;
		default:
			printf("wrrong position");
			exit(1);
	}
}

int win_draw(char box [3][3]){
	if(box [0][0] == box [0][1] && box[0][2]  == box[0][1]){			//1
		return box[0][0];
	}else if(box [1][0] == box [1][1] && box[1][2]  == box[1][1]){			//2
		return box[1][0];
	}else if(box [2][0] == box [2][1] && box[2][2]  == box[2][1]){			//3
		return box[2][1];
	}else if(box [0][0] == box [1][0] && box[2][0]  == box[1][0]){			//4
		return box[0][0];
	}else if(box [0][1] == box [1][1] && box[2][1]  == box[1][1]){			//5
		return box[2][1];
	}else if(box [0][2] == box [1][2] && box[2][2]  == box[1][2]){			//6
		return box[1][2];
	}else if(box [0][0] == box [1][1] && box[2][2]  == box[1][1]){			//7	//diagonol
		return box[1][1];
	}else if(box [0][2] == box [1][1] && box[2][0]  == box[1][1]){			//8	//diagonol
		return box[1][1];
	}else{
		return 0;
	}
}

void test(char box[3][3]){
	int p1,p2;
	printf("player 1 = x\n");
	printf("player 2 = o\n\n\n");
	printf("player 1  :");
	scanf("%d",&p1);
	update(box,p1,'o');
	printf("player 2  :");
	scanf("%d",&p2);
	update(box,p2,'x');
	printf("player 1  :");
	scanf("%d",&p1);
	update(box,p1,'o');

}

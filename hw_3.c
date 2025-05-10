#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define row 9  
#define col 9
	char seat[row][col];
int main(){
	int a,password,i,correct;
	const int real_password=2025;

//personal style screen
	for(i=0;i<=20;i++){
		printf("*****           *****\n");
	}

//Password verification
	for(a=1;a<=3;a++){
		printf("Enter password:");
		scanf("%d",&password);		
		if(password==real_password){
			printf("Password is correct!\n");
			correct=1;
			break;
		}
		else{
			correct=0;
			printf("Wrong password!\n");
		}
}
if(correct==0){
		printf("Wrong password three times!\n");
		return 0;
	}
	clearscreen();
    menu();
    initializeSeats();
    
    return 0;
}
//Main menu
void menu(){
	printf("----------[Booking System]----------\n");
    printf("| a. Available seats                |\n");
    printf("| b. Arrange for you                |\n");
    printf("| c. Choose by yourself             |\n");
    printf("| d. Exit                           |\n");
    printf("------------------------------------\n");
}
void clearscreen(){
	system("cls");
}
void initializeSeats(){
    int i,j,r,c;
    for (i=0;i<row;i++) {
        for (j=0;j<col;j++) {
            seat[i][j]='-';
        }
    }
    srand(time(0));
    for (i=0;i<10;i++) {
        r=rand()%row;
        c=rand()%col;
        seat[r][c]='*';
    }
    displaySeats();
}
void displaySeats(){
    int i,j;
    printf("123456789\n");
    for (i=0;i<row;i++) {
        printf("%d",row-i);
        for (j=0;j<col;j++) {
            printf("%c",seat[i][j]);
        }
        printf("\n");
    }
}


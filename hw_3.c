#include<stdlib.h>
#include<stdio.h>
int main(){
	int a,password,i,correct;
	const int real_password=2025;

//�ӤH����e�� 
	for(i=0;i<=20;i++){
		printf("*****           *****\n");
	}

//�K�X���� 
	for(a=1;a<=3;a++){
		printf("��J�K�X:");
		scanf("%d",&password);		
		if(password==real_password){
			printf("�K�X���T!\n");
			correct=1;
			break;
		}
		else{
			correct=0;
			printf("�K�X���~!\n");
		}
}
if(correct==0){
		printf("�K�X���~�T��!\n");
		return 0;
	}
	clearscreen();
    menu();
    
    return 0;
}

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

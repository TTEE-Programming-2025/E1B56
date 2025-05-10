#include<stdlib.h>
#include<stdio.h>
int main(){
	int a,password,i,correct;
	const int real_password=2025;

//個人風格畫面 
	for(i=0;i<=20;i++){
		printf("*****           *****\n");
	}

//密碼驗證 
	for(a=1;a<=3;a++){
		printf("輸入密碼:");
		scanf("%d",&password);		
		if(password==real_password){
			printf("密碼正確!\n");
			correct=1;
			break;
		}
		else{
			correct=0;
			printf("密碼錯誤!\n");
		}
}
if(correct==0){
		printf("密碼錯誤三次!\n");
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

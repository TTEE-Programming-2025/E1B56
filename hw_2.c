#include<stdlib.h>
#include<stdio.h>
#include<conio.h>//getch()
void clearscreen(){
	system("cls");
}
int main(){
	int option,password,correct=0,i,a;
	const int real_password=2025;
	
	//個人風格畫面 
	for(i=0;i<=20;i++){
		printf("*****           *****\n");
	}
	printf("密碼預設:2025\n");
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
			printf("密碼錯誤!");
		}
}
	if(correct==0){
		printf("密碼錯誤三次!\n");
		return 0;
	}
	
		menu();
		clearscreen();
		triangle();
		
	system("pause");
	return 0;
}
//主畫面 
void menu(){
	printf("------------------------\n");
	printf("| a.畫出直角三角形   	|\n");
	printf("| b.顯示乘法表       	|\n");
	printf("| c.結束             	|\n");
	printf("------------------------\n");
}
//直角三角形 
void triangle(){
	char ch,i,j;
	while(1){
		printf("輸入'a'到'n'的字元:");
		scanf(" %c",&ch);
		
		if(ch>='a'&&ch<='n'){
			clearscreen();
			for(i='a';i<=ch;i++){
				for(j='a';j<=i;j++){
					printf("%c",j);
				}
				printf("\n");
			}
			printf("\n按任意鍵回主畫面");
			getch();
			clearscreen();
			menu();
			break;
		} else{
			printf("輸入錯誤");
		}
	}
}

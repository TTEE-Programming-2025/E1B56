#include<stdlib.h>
#include<stdio.h>
void clearscreen(){
	system("cls");
}
int main(){
	int password,correct=0,i,a;
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
	
	clearscreen();
	printf("------------------------\n");
	printf("| a.畫出直角三角形   	|\n");
	printf("| b.顯示乘法表       	|\n");
	printf("| c.結束             	|\n");
	printf("------------------------");
	
	system("pause");
	return 0;
}

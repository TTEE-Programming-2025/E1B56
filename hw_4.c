#include<stdlib.h>
#include<stdio.h>
#define password 2025
int main(){
	int input_password,a=0,i;
	// 個人風格畫面
    for(i=0;i<20;i++)
        printf("***** 歡迎使用 *****\n");
    while(a<3){
    	printf("輸入密碼:");
    	scanf("%d",&input_password);
    	if(input_password==password){
    		printf("歡迎使用!");
    		break;
		}
		else{
			printf("密碼錯誤!\n"); 
			a++;
		}
	}
	if(a==3){
		printf("密碼錯誤三次，結束!");
		return 0; 
	}
	
	return 0;
}

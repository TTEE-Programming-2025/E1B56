#include<stdlib.h>
#include<stdio.h>
#define password 2025

//學生結構定義
typedef struct{
	char name[20];//姓名 
	int id;//學號 
	int math;//數學 
	int phy;//物理 
	int english;//英文 
	float avg;//平均 
}student; 

student stu[10];  // 放在主程式外作為全域變數
int n;  // 學生人數

// 輸入學生資料
void entergrades() {
	int i;
    clearscreen();
    printf("輸入學生人數（5~10):");
    scanf("%d",&n);
    while(n<5||n>10){
    	printf("錯誤!輸入學生人數（5~10):");
    	scanf("%d",&n);
	}
	for(i=0;i<n;i++){
		printf("第%d位學生資料",i+1);
		printf("姓名:");
		scanf("%s",&stu[i].name);
		printf("學號(6位數):");
		scanf("%d",&stu[i].id); 
		while(stu[i].id<100000||stu[i].id>999999){
			printf("錯誤!學號(6位數):");
			scanf("%d",&stu[i].id);
		}
		printf("數學(0-100):");
		scanf("%d",&stu[i].math);
		while(stu[i].math<0||stu[i].math>100){
			printf("錯誤!數學(0-100):");
			scanf("%d",&stu[i].math);
		}
		printf("物理(0-100):");
		scanf("%d",&stu[i].phy);
		while(stu[i].phy<0||stu[i].phy>100){
			printf("錯誤!物理(0-100):");
			scanf("%d",&stu[i].phy);
		}
		printf("英文(0-100):");
		scanf("%d",&stu[i].english);
		while(stu[i].english<0||stu[i].english>100){
			printf("錯誤!英文(0-100):");
			scanf("%d",&stu[i].english);
		}
	stu[i].avg=stu[i].math+stu[i].phy+stu[i].english/3.0;
	}
	clearscreen();
}
//清除螢幕
void clearscreen(){
	system("cls");
} 
// 主選單
void menu(){
    printf("------------[Grade System]----------\n");
    printf("|  a. Enter student grades         |\n");
    printf("|  b. Display student grades       |\n");
    printf("|  c. Search for student grades    |\n");
    printf("|  d. Grade ranking                |\n");
    printf("|  e. Exit system                  |\n");
    printf("------------------------------------\n");
    printf("請選擇功能:");
}

int main(){
	int input_password,a=0,i;
	// 個人風格畫面
    for(i=0;i<20;i++)
        printf("***** 歡迎使用 *****\n");
    //密碼驗證 
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
	clearscreen();
	menu();
	
	return 0;
}

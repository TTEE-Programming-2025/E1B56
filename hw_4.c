#include<stdlib.h>
#include<stdio.h>
#define password 2025

//�M���ù�
void clearscreen(){
	system("cls");
} 
// �D���
void menu(){
    printf("------------[Grade System]----------\n");
    printf("|  a. Enter student grades         |\n");
    printf("|  b. Display student grades       |\n");
    printf("|  c. Search for student grades    |\n");
    printf("|  d. Grade ranking                |\n");
    printf("|  e. Exit system                  |\n");
    printf("------------------------------------\n");
    printf("�п�ܥ\��:");
}

int main(){
	int input_password,a=0,i;
	// �ӤH����e��
    for(i=0;i<20;i++)
        printf("***** �w��ϥ� *****\n");
    //�K�X���� 
    while(a<3){
    	printf("��J�K�X:");
    	scanf("%d",&input_password);
    	if(input_password==password){
    		printf("�w��ϥ�!");
    		break;
		}
		else{
			printf("�K�X���~!\n"); 
			a++;
		}
	}
	if(a==3){
		printf("�K�X���~�T���A����!");
		return 0; 
	}
	clearscreen();
	menu();
	
	return 0;
}

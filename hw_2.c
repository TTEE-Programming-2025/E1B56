#include<stdlib.h>
#include<stdio.h>
void clearscreen(){
	system("cls");
}
int main(){
	int password,correct=0,i,a;
	const int real_password=2025;
	
	//�ӤH����e�� 
	for(i=0;i<=20;i++){
		printf("*****           *****\n");
	}
	printf("�K�X�w�]:2025\n");
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
			printf("�K�X���~!");
		}
}
	if(correct==0){
		printf("�K�X���~�T��!\n");
		return 0;
	}
	
	clearscreen();
	printf("------------------------\n");
	printf("| a.�e�X�����T����   	|\n");
	printf("| b.��ܭ��k��       	|\n");
	printf("| c.����             	|\n");
	printf("------------------------");
	
	system("pause");
	return 0;
}

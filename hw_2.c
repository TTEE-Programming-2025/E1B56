#include<stdlib.h>
#include<stdio.h>
#include<conio.h>//getch()
void clearscreen(){
	system("cls");
}
int main(){
	int option,password,correct=0,i,a;
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
	
		menu();
		clearscreen();
		triangle();
		
	system("pause");
	return 0;
}
//�D�e�� 
void menu(){
	printf("------------------------\n");
	printf("| a.�e�X�����T����   	|\n");
	printf("| b.��ܭ��k��       	|\n");
	printf("| c.����             	|\n");
	printf("------------------------\n");
}
//�����T���� 
void triangle(){
	char ch,i,j;
	while(1){
		printf("��J'a'��'n'���r��:");
		scanf(" %c",&ch);
		
		if(ch>='a'&&ch<='n'){
			clearscreen();
			for(i='a';i<=ch;i++){
				for(j='a';j<=i;j++){
					printf("%c",j);
				}
				printf("\n");
			}
			printf("\n�����N��^�D�e��");
			getch();
			clearscreen();
			menu();
			break;
		} else{
			printf("��J���~");
		}
	}
}

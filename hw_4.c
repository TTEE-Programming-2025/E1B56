#include<stdlib.h>
#include<stdio.h>
#define password 2025
int main(){
	int input_password,a=0,i;
	// �ӤH����e��
    for(i=0;i<20;i++)
        printf("***** �w��ϥ� *****\n");
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
	
	return 0;
}

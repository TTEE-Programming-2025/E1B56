#include<stdlib.h>
#include<stdio.h>
#define password 2025

//�ǥ͵��c�w�q
typedef struct{
	char name[20];//�m�W 
	int id;//�Ǹ� 
	int math;//�ƾ� 
	int phy;//���z 
	int english;//�^�� 
	float avg;//���� 
}student; 

student stu[10];  // ��b�D�{���~�@�������ܼ�
int n;  // �ǥͤH��

// ��J�ǥ͸��
void entergrades() {
	int i;
    clearscreen();
    printf("��J�ǥͤH�ơ]5~10):");
    scanf("%d",&n);
    while(n<5||n>10){
    	printf("���~!��J�ǥͤH�ơ]5~10):");
    	scanf("%d",&n);
	}
	for(i=0;i<n;i++){
		printf("��%d��ǥ͸��",i+1);
		printf("�m�W:");
		scanf("%s",&stu[i].name);
		printf("�Ǹ�(6���):");
		scanf("%d",&stu[i].id); 
		while(stu[i].id<100000||stu[i].id>999999){
			printf("���~!�Ǹ�(6���):");
			scanf("%d",&stu[i].id);
		}
		printf("�ƾ�(0-100):");
		scanf("%d",&stu[i].math);
		while(stu[i].math<0||stu[i].math>100){
			printf("���~!�ƾ�(0-100):");
			scanf("%d",&stu[i].math);
		}
		printf("���z(0-100):");
		scanf("%d",&stu[i].phy);
		while(stu[i].phy<0||stu[i].phy>100){
			printf("���~!���z(0-100):");
			scanf("%d",&stu[i].phy);
		}
		printf("�^��(0-100):");
		scanf("%d",&stu[i].english);
		while(stu[i].english<0||stu[i].english>100){
			printf("���~!�^��(0-100):");
			scanf("%d",&stu[i].english);
		}
	stu[i].avg=stu[i].math+stu[i].phy+stu[i].english/3.0;
	}
	clearscreen();
}
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

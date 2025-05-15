#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define password 2025

void clearscreen();
void pause();

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
		scanf("%s",stu[i].name);//�r�ꥻ���O��}�A���Υ[ &
		
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
		
	stu[i].avg=(stu[i].math+stu[i].phy+stu[i].english)/3.0;
	}
	clearscreen();
}

// ��ܩҦ��ǥ͸��
void displaygrades(){
	int i;
    clearscreen();
    printf("�m�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t����\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",stu[i].name,stu[i].id,stu[i].math,stu[i].phy,stu[i].english,stu[i].avg);
    }
    pause();
    clearscreen();
}

//�j�M�ǥ͸��
void searchstudent(){
	int i,find=0;
	char target[20];
	clearscreen();
	printf("��J�j�M�ǥͩm�W:");
	scanf("%s",target);
	for(i=0;i<n;i++){
		if(strcmp(stu[i].name,target)==0){
		printf("�m�W: %s\n�Ǹ�: %d\n�ƾ�: %d\n���z: %d\n�^��: %d\n����: %.1f\n",stu[i].name,stu[i].id,stu[i].math,stu[i].phy,stu[i].english,stu[i].avg);
		find=1;
		break;	
		}
	}
	if(!find)
		printf("��Ƥ��s�b�C\n");
	pause();
    clearscreen();
} 

// ���Z�ƦW
void graderanking(){
    clearscreen();
    student temp;
    int i,j;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (stu[i].avg<stu[j].avg){
                temp=stu[i];
                stu[i]=stu[j];
                stu[j]=temp;
            }
        }
    }

    printf("�m�W\t�Ǹ�\t����\n");
    for (i=0;i<n;i++){
        printf("%s\t%d\t%.1f\n", stu[i].name,stu[i].id,stu[i].avg);
    }
    pause();
    clearscreen();
}

void pause(){
    printf("\n�Ы����N���~��...");
    getch();
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
	char option;
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
// �D�{���y�{
    do {
        menu();
        scanf(" %c",&option);
        switch (option) {
            case 'a':
            case 'A':
                entergrades();
                break;
            case 'b':
            case 'B':
                displaygrades();
                break;
            case 'c':
            case 'C':
                searchstudent();
                break;
            case 'd':
            case 'D':
                graderanking();
                break;
            case 'e':
            case 'E': {
                char confirm;
                do {
                    printf("�T�w���}�H(y/n): ");
                    scanf(" %c",&confirm);
                    if (confirm=='y'||confirm=='Y') {
                        printf("�P�¨ϥΡA�A���I\n");
                        return 0;
                    } else if (confirm=='n'||confirm=='N'){
                        break;
                    } else {
                        printf("�п�J���T���ﶵ (y/n)�I\n");
                    }
                } while (1);
                break;
            }
            default:
                printf("�L�Ī��ﶵ�A�Э��s��ܡI\n");
        }
    } while (1);

	
	return 0;
}

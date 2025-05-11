#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define row 9  
#define col 9
	char seat[row][col];
int main(){
	int a,password,i,correct;
	const int real_password=2025;

//personal style screen
	for(i=0;i<=20;i++){
		printf("*****           *****\n");
	}

//Password verification
	for(a=1;a<=3;a++){
		printf("Enter password:");
		scanf("%d",&password);		
		if(password==real_password){
			printf("Password is correct!\n");
			correct=1;
			break;
		}
		else{
			correct=0;
			printf("Wrong password!\n");
		}
}
if(correct==0){
		printf("Wrong password three times!\n");
		return 0;
	}
	clearscreen();
    menu();
    initializeSeats();
    arrangeSeats();
    
    return 0;
}
//Main menu
void menu(){
	printf("----------[Booking System]----------\n");
    printf("| a. Available seats                |\n");
    printf("| b. Arrange for you                |\n");
    printf("| c. Choose by yourself             |\n");
    printf("| d. Exit                           |\n");
    printf("------------------------------------\n");
}
void clearscreen(){
	system("cls");
}
void initializeSeats(){
    int i,j,r,c;
    for (i=0;i<row;i++) {
        for (j=0;j<col;j++) {
            seat[i][j]='-';
        }
    }
    srand(time(0));
    for (i=0;i<10;i++) {
        r=rand()%row;
        c=rand()%col;
        seat[r][c]='*';
    }
    displaySeats();
}
void displaySeats(){
    int i,j;
    printf("123456789\n");
    for (i=0;i<row;i++) {
        printf("%d",row-i);
        for (j=0;j<col;j++) {
            printf("%c",seat[i][j]);
        }
        printf("\n");
    }
}
void arrangeSeats(){
    int numSeats;
    printf("How many seats do you need?(1~4):");
    scanf("%d",&numSeats);

    if (numSeats < 1 || numSeats > 4) {
        printf("Please enter a valid number of seats(1~4)!\n");
        return;
    }

    int i,j,r,c,k,found = 0;
    if (numSeats <= 3) {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col - numSeats + 1; j++) {
                int canArrange = 1;
                for (k = 0; k < numSeats; k++) {
                    if (seat[i][j + k] != '-') {
                        canArrange = 0;
                        break;
                    }
                }
                if (canArrange) {
                    for (k = 0; k < numSeats; k++) {
                        seat[i][j + k] = '@';
                    }
                    found = 1;
                    displaySeats();
                    break;
                }
            }
            if (found) break;
        }
    } else if (numSeats == 4) {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col - 3; j++) {
                int canArrange = 1,k;
                for (k = 0; k < 4; k++) {
                    if (seat[i][j + k] != '-') {
                        canArrange = 0;
                        break;
                    }
                }
                if (canArrange) {
            
                    for (k = 0; k < 4; k++) {
                        seat[i][j + k] = '@';
                    }
                    found = 1;
                    displaySeats();
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            for (i = 0; i < row - 1; i++) {
                for (j = 0; j < col; j++) {
                    if (seat[i][j] == '-' && seat[i + 1][j] == '-') {
                        seat[i][j] = '@';
                        seat[i + 1][j] = '@';
                        found = 1;
                        displaySeats();
                        break;
                    }
                }
                if (found) break;
            }
        }
    }

    if (!found) {
        printf("The requested seats cannot be allocated. Please select a new number of seats.\n");
    }

    char choice;
    printf("Are you satisfied with the seat arrangement? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (seat[i][j] == '@') {
                    seat[i][j] = '*';
                }
            }
        }
    }
}

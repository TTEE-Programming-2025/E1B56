#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2024 

void showIntroScreen() {
    printf("******************************************\n");
    printf("*          Welcome to My Program         *\n");
    printf("*          Designed by [Your Name]       *\n");
    printf("******************************************\n");
    int i = 0;
    for( i = 0; i < 16; i++) {
        printf("*                                        *\n");
    }
    printf("******************************************\n");
    system("PAUSE");
    system("CLS");
}
int verifyPassword() {
    int inputPassword;
    printf("�п�J 4 �ӼƦr���K�X: ");
    scanf("%d", &inputPassword);
    
    if(inputPassword == PASSWORD) {
        printf("�K�X���T�A�w��i�J�t�ΡI\n");
        system("PAUSE");
        return 1;
    } else {
        printf("�K�X���~�I\n");
        printf("%c", '\a'); 
        return 0;
    }
}

void showMenu() {
    system("CLS");
    printf("-------------------------------\n");
    printf("|  'A'...'Z' : Uppercase       |\n");
    printf("|  'a'...'z' : Lowercase       |\n");
    printf("|  '0'...'9' : Digit           |\n");
    printf("|  Otherwise : Your Name       |\n");
    printf("-------------------------------\n");
}

void processUserInput() {
    char inputChar;
    printf("�п�J�@�Ӧr��: ");
    fflush(stdin);
    scanf("%c", &inputChar);
    
    if (inputChar >= 'A' && inputChar <= 'Z') {
        printf("Uppercase\n");
    } else if (inputChar >= 'a' && inputChar <= 'z') {
        printf("Lowercase\n");
    } else if (inputChar >= '0' && inputChar <= '9') {
        printf("Digit\n");
    } else {
        printf("�A���Z�Ůy���Ωm�W\n");
    }
    
    system("PAUSE");
}

int main() {
    showIntroScreen();
    
    if (!verifyPassword()) {
        return 0; 
    }
    
    showMenu();
    processUserInput();
    
    return 0;
}


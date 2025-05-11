#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define row 9  
#define col 9
char seat[row][col];

// Declare functions before use
void clearscreen();
void menu();
void initializeSeats();
void displaySeats();
void arrangeSeats();
int isValidSeat(int rowNum, int colNum);
void chooseSeats();

// Clear the screen
void clearscreen() {
    system("cls");
}

// Display the menu
void menu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats                |\n");
    printf("| b. Arrange for you                |\n");
    printf("| c. Choose by yourself             |\n");
    printf("| d. Exit                           |\n");
    printf("------------------------------------\n");
}

// Initialize seats
void initializeSeats() {
    int i, j, r, c;
    // Initialize seat table with '-'
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            seat[i][j] = '-';
        }
    }

    // Randomly generate 10 booked seats
    srand(time(0));
    for (i = 0; i < 10; i++) {
        r = rand() % row;
        c = rand() % col;
        seat[r][c] = '*';  // Mark as booked seat
    }

    displaySeats();
}

// Display seats
void displaySeats() {
    int i, j;
    printf("123456789\n");
    for (i = 0; i < row; i++) {
        printf("%d", row - i);  // Display row number
        for (j = 0; j < col; j++) {
            printf("%c", seat[i][j]);
        }
        printf("\n");
    }
}

// Check if the seat is valid
int isValidSeat(int rowNum, int colNum) {
    // Check if the seat is within bounds and available
    return (rowNum >= 1 && rowNum <= row && colNum >= 1 && colNum <= col && seat[rowNum - 1][colNum - 1] == '-');
}

// Arrange seats
void arrangeSeats() {
    int numSeats;
    printf("How many seats do you need? (1~4): ");
    scanf("%d", &numSeats);

    if (numSeats < 1 || numSeats > 4) {
        printf("Please enter a valid number of seats (1~4)!\n");
        return;
    }

    int i, j, k, found = 0;
    if (numSeats <= 3) {
        // Find 1-3 consecutive seats
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
        // Find 4 consecutive seats in a row
        for (i = 0; i < row; i++) {
            for (j = 0; j < col - 3; j++) {
                int canArrange = 1;
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

        // If no row found, try two consecutive rows
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

    // Ask if the user is satisfied with the arrangement
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

// Choose seats
void chooseSeats() {
    int rowNum, colNum;
    char choice;
    int invalidCount = 0;

    // Store selected seats
    int selectedSeats[10][2];
    int selectedCount = 0;

    while (1) {
        printf("Please enter your preferred seat (format: row-column, e.g. 1-2): ");
        scanf("%d-%d", &rowNum, &colNum);

        if (isValidSeat(rowNum, colNum)) {
            selectedSeats[selectedCount][0] = rowNum;
            selectedSeats[selectedCount][1] = colNum;
            selectedCount++;

            printf("Selected seats:\n");
            int i;
            for ( i = 0; i < selectedCount; i++) {
                printf("Seat %d-%d\n", selectedSeats[i][0], selectedSeats[i][1]);
            }
        } else {
            printf("The selected seat is invalid, please select again!\n");
            invalidCount++;
        }

        // Check if there are still invalid selections
        if (invalidCount >= 3) {
            printf("Multiple invalid inputs, returning to the main menu.\n");
            return;
        }

        // Ask if the user wants to continue selecting
        printf("Do you want to continue selecting other seats? (y/n): ");
        scanf(" %c", &choice);  // Handle the newline character

        if (choice == 'n' || choice == 'N') {
            break;  // Exit the loop, proceed to confirm the selection
        }
    }

    // Display the selected seats and confirm
    printf("You have selected the following seats:\n");
    int i;
    for ( i = 0; i < selectedCount; i++) {
        printf("Seat %d-%d\n", selectedSeats[i][0], selectedSeats[i][1]);
    }

    // Ask if the user confirms the selection
    printf("Are you satisfied with the selected seats? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Update the selected seats to be reserved (*)
        int i;
        for ( i = 0; i < selectedCount; i++) {
            seat[selectedSeats[i][0] - 1][selectedSeats[i][1] - 1] = '*';
        }
        printf("The seat has been booked successfully!\n");
    } else {
        printf("You have canceled your selection. Returning to the main menu.\n");
    }
}

// Main function to control the flow of the program
int main() {
    int a, password, i, correct = 0;
    const int real_password = 2025;

    // Display personal style screen
    for (i = 0; i <= 20; i++) {
        printf("*****           *****\n");
    }

    // Password verification
    for (a = 1; a <= 3; a++) {
        printf("Enter password: ");
        scanf("%d", &password);

        if (password == real_password) {
            printf("Password is correct!\n");
            correct = 1;
            break;
        } else {
            correct = 0;
            printf("Wrong password!\n");
        }
    }

    if (correct == 0) {
        printf("Wrong password three times!\n");
        return 0;  // Exit the program if password is wrong 3 times
    }

    clearscreen();  // Clear the screen
    menu();  // Display the main menu

    // Display available options and handle user selection
    char choice;
    while (1) {
        printf("Choose an option: ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            displaySeats();  // Show the current available seats
        } else if (choice == 'b') {
            arrangeSeats();  // Let the user arrange seats
        } else if (choice == 'c') {
            chooseSeats();  // Let the user choose specific seats
        } else if (choice == 'd') {
            printf("Exiting the program...\n");
            break;  // Exit the program
        } else {
            printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}


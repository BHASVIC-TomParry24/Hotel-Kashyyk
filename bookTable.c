#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"

int validateTableBooking() {
  int valid = 0;
  char rooms[6][15] = {"..\\room1.txt", "..\\room2.txt", "..\\room3.txt", "..\\room4.txt", "..\\room5.txt", "..\\room6.txt"};
  char bookingID[30];
  char* board = "\0";
  int numberOfPeople;

  fflush(stdin);
  printf("Enter booking ID: ");
  scanf("%s", &bookingID);


  for (int i = 0; i <= 5; i++) {
    if (strcmp(bookingID, read(rooms[i], 9)) == 0) {
      board = read(rooms[i], 6);
      if (strcmp(board, "F") == 0 || strcmp(board, "H") == 0) {
        valid = 1;
      }
      break;
    }
  }

  return valid;
}

void displayAvailableTables() {
    char* tableNames[3] = {"Ednoor  ", "Naboo   ", "Tatooine"};
    char* tablesAvailable[3][2];
    tablesAvailable[0][0] = read("..\\tableData.txt", 1);
    tablesAvailable[0][1] = read("..\\tableData.txt", 2);
    tablesAvailable[1][0] = read("..\\tableData.txt", 3);
    tablesAvailable[1][1] = read("..\\tableData.txt", 4);
    tablesAvailable[2][0] = read("..\\tableData.txt", 5);
    tablesAvailable[2][1] = read("..\\tableData.txt", 6);

    int noTablesAvailable = 1;

    printf("Available bookings:\n");
    for (int i = 0; i < 3; i++) {
        if (strcmp(tablesAvailable[i][0], "T") == 0 || strcmp(tablesAvailable[i][1], "T") == 0) {
            printf("%s | 7pm - %s, 9pm - %s\n", tableNames[i], tablesAvailable[i][0], tablesAvailable[i][1]);
            noTablesAvailable = 0;
        }
    }

    if (noTablesAvailable) {
        printf("No options available\n");
    }
}

int chooseTableBooking() {
    char* tableNames[3] = {"Ednoor", "Naboo", "Tatooine"};
    int choiceTable;
    int choiceTime;
    printf("Which table would you like to book (enter 1 for Ednoor, 2 for Naboo, and 3 for Tatooine)? ");
    fflush(stdin);
    scanf("%d", &choiceTable);
    printf("Which time would you like to book (7 or 9 pm)? ");
    fflush(stdin);
    scanf("%d", &choiceTime);

    int lineNumber;
    if (choiceTable >= 1 && choiceTable <= 3) {
        lineNumber = 2*(choiceTable-1);
    } else {
        printf("Booking was unsuccessful - invalid table choice\n");
        return -1;
    }

    if (choiceTime == 7) {
        lineNumber = lineNumber + 1;
    } else if (choiceTime == 9) {
        lineNumber = lineNumber + 2;
    } else {
        printf("Booking was unsuccessful - invalid time\n");
        return -1;
    }

    if (strcmp(read("..\\tableData.txt", lineNumber), "T") == 0) {
        writeFile("..\\tableData.txt", lineNumber, "F\n");
        printf("Booking succesful! You have booked the %s table at %d pm.\n", tableNames[choiceTable-1], choiceTime);
        return 0;
    }

    printf("Booking was unsuccessful - table already booked\n");
    return -1;
}

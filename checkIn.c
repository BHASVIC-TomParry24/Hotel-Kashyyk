#include <stdio.h>
#include "project.h"
#include <stdlib.h>
#include <string.h>

void checkIn() {
    const int fullBoardRate = 20;
    const int halfBoardRate = 15;
    const int BandBRate = 5;
    char firstName[30];
    char lastName[30];
    int lastNameLength = 0;
    int numberOfAdults;
    int numberOfChildren;
    char boardType;
    int lengthOfStay;
    char newspaper;
    char bookingId[30];
    int randomNumber;
    char randomNumberList[4];
    int age;
    char rooms[6][10] = {"room1.txt", "room2.txt", "room3.txt", "room4.txt", "room5.txt", "room6.txt"};
    char tables[3][10] = {"Endor", "Naboo", "Tatooine"};
    char* nullString = "NULL";

    for (int i = 0; i < 30; i++) {
        lastName[i] = 0;
    }

    printf("Enter your first name: ");
    scanf("%s",firstName);
    fflush(stdin);
    printf("Enter your last name: ");
    scanf("%s",lastName);
    fflush(stdin);
    printf("Enter number of adults: ");
    scanf("%d",&numberOfAdults);
    fflush(stdin);
    printf("Enter number of children: ");
    scanf("%d",&numberOfChildren);
    fflush(stdin);
    printf("Enter the length of your stay in days: ");
    scanf("%d",&lengthOfStay);
    fflush(stdin);
    printf("Enter the board you want: Full(F), Half(H) or Bed and Breakfast(B)");
    scanf("%c",&boardType);
    fflush(stdin);
    printf("Would you like a newspaper? (T for yes, F for no): ");
    scanf("%c",&newspaper);
    fflush(stdin);
    printf("Enter your age: ");
    scanf("%d",&age);
    fflush(stdin);

    randomNumber = rand() % (9999 - 1000 + 1) + 1000;
    sprintf(randomNumberList,"%d",randomNumber);
    for (int i = 0; i < 30; i++) {
        if (lastName[i] != 0) {
            bookingId[i] = lastName[i];
            lastNameLength++;
        }
    }

    for (int i = 0; i <= 4; i++) {
        bookingId[i + lastNameLength] = randomNumberList[0];
    }

    printf("Available Rooms: \n");
    for(int i = 1; i <= 6; i++) {
        char roomFileName[10];
        sprintf(roomFileName, "room%d.txt", i);
        if (strcmp(read(roomFileName, 10), nullString) == 1) {
            printf("Room Number %s (£%s)", read(roomFileName, 1), read(roomFileName, 11));
        }
    }
}
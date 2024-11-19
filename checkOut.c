#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"

void checkOut(){
  int bookingIdFound = 0;
  char bookingId[30];
  char roomFileName[10];
  int roomNumber;
  char* currentBookingId;
  int totalRoomCost;

  printf("Enter booking ID: ");
  scanf("%s", bookingId);

  for(int i = 1; i <= 6; i++) {
    sprintf(roomFileName, "room%d.txt", i);
    currentBookingId = read(roomFileName, 10);
    currentBookingId[strlen(currentBookingId) - 1] = '\0';

    if (strcmp(currentBookingId, bookingId) == 0) {
      roomNumber = i;
      bookingIdFound = 1;
      break;
    };
  }
  if (bookingIdFound == 0) {
    printf("Your booking ID could not be found in our system");
  }

  char* roomCostString = read(roomFileName, 11);
  printf("%s\n", roomCostString);
  sscanf(roomCostString, "%d", &totalRoomCost);
  printf("%d\n", totalRoomCost);
}

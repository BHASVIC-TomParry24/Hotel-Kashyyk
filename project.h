#pragma once
void writeFile(char fileName[256], int line, char text[256]);
void checkIn();
char * read(char file[15], int line, char buffer[100]);
void checkOut();
void resetFile(char fileName[100]);
int removeOldBookings();
int validateTableBooking();
int displayAvailableTables();
int chooseTableBooking();
void bookTable();

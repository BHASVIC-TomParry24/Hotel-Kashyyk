#include<stdio.h>

void read(char file[15], int line) {
  FILE *ftpr = fopen(file, "r");
  if (ftpr == NULL) {
    printf("Error: Could not open file %s\n", file);
    return;
  }

  char buffer[256];
  int currentLine = 1;


  while (fgets(buffer, sizeof(buffer), ftpr) != NULL) {
    if (currentLine == line) {
      printf("Line %d: %s", line, buffer);
      fclose(ftpr);
      return;
    }
    currentLine++;
  }


  printf("Error: Line %d not found in file %s\n", line, file);
  fclose(ftpr);
}










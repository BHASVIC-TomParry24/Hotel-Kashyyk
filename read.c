#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* read(char fileName[32], int line) {
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s\n", fileName);
    exit(0);
  }

  char buffer[256];
  int currentLine = 0;


  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    currentLine++;
    if (currentLine == line) {
      // removes '\n' at the end of each line
      char *ptr = strchr(buffer, '\n');
      if (ptr) {
        *ptr = '\0';
      }
      char *string = buffer;
      fclose(file);
      return(string);
    }
  }


  printf("Error: Line %d not found in file %s\n", line, fileName);
  fclose(file);
  exit(0);
}










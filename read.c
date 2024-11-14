#include<stdio.h>
#include<stdlib.h>

char * read(char fileName[15], int line) {
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s\n", file);
    exit(0);
  }

  char buffer[256];
  int currentLine = 0;


  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    currentLine++;
    if (currentLine == line) {
      char *string = buffer;
      fclose(file);
      return(string);
    }
  }


  printf("Error: Line %d not found in file %s\n", line, file);
  fclose(file);
  exit(0);
}










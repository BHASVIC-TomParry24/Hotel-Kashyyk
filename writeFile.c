#include <stdio.h>
#include <stdlib.h>

void writeFile(char fileName[256], int line, char text[256]) {
    char buffer[256];
    int counter = 0;
    FILE *file = NULL;
    FILE *temp = NULL;
    file = fopen(fileName, "r");
    temp = fopen("temp.txt", "w+");

    if (!file)
    {
        printf("Unable to open the input file!!\n");
        exit(0);
    }
    if (!temp)
    {
        printf("Unable to open a temporary file to write!!\n");
        fclose(file);
        exit(0);
    }

    while (fgets(buffer, 256, file) != NULL)
    {
        counter++;

        if (counter == line)
            fputs(text, temp);
        else
            fputs(buffer, temp);
    }

    fclose(file);
    fclose(temp);
    remove(fileName);
    rename("temp.txt", fileName);
    printf(" Replacement did successfully..!! \n");
    exit(0);
}

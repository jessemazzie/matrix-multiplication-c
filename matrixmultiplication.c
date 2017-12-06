#include <stdio.h>
#include <stdlib.h>

void getMatrixSize(int *rows, int *columns, char fileName[20]);

int main(int argc, char *argv[])
{
    int rows = 0, columns = 0;
    
    printf("%i\n\n", argc);
    printf("%s",argv[1]);
    getMatrixSize(&rows, &columns, argv[1]);
    printf("Hello world\n");
}

void getMatrixSize(int *rows, int *columns, char fileName[20])
{
    FILE *file = fopen(fileName, "r");
    char csvCharacter;
    if(file == NULL)
        printf("File does not exist.\n");
    else
        printf("Not null.\n");
    do
    {
        csvCharacter = fgetc(file);
        //Following line was used for debugging purposes
        //printf("%c", csvCharacter);
    } while (csvCharacter != EOF);
}
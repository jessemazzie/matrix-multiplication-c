#include <stdio.h>
#include <stdlib.h>

void getMatrixSize(int *rows, int *columns, char fileName[20]);

int main(int argc, char *argv[]) {
    int rows = 0, columns = 0;
    if(argc <= 2) {
        printf("At least two CSV files (supplied via command line argument) are required. Exiting...\n");
        exit(0);
    }
    printf("%i\n\n", argc);
    printf("%s", argv[1]);
    getMatrixSize(&rows, &columns, argv[1]);
}

void getMatrixSize(int *rows, int *columns, char fileName[20]) {
    FILE *file = fopen(fileName, "r"); //Open filestream
    char csvCharacter;
    if (file == NULL) {
        printf("File does not exist.\n");
    } else {
        do {
            csvCharacter = fgetc(file);

            if (csvCharacter == ',')
                columns++;
            else if (csvCharacter == '\n')
                rows++;

            //Following line was used for debugging purposes
            //printf("%c", csvCharacter);
        } while (csvCharacter != EOF);
    }

    fclose(file); //Close filestream
}
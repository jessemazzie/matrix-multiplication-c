#include <stdio.h>
#include <stdlib.h>

void getMatrixSize(int *rows, int *columns, char fileName[20]);

int main(int argc, char *argv[]) {
    int rows = 1, columns = 1;

    if(argc <= 2) {
        printf("At least two CSV files (supplied via command line argument) are required. Exiting...\n");
        exit(0);
    }

    printf("%i\n\n", argc);
    printf("%s\t%s\n", "File name: ", argv[1]);
    getMatrixSize(&rows, &columns, argv[1]);
    printf("%s\t%i\n", "Rows: ", rows);
    printf("%s\t%i\n", "Columns: ", columns);
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
                (*columns)++;
            else if (csvCharacter == '\n')
                (*rows)++;

            //Following line was used for debugging purposes
            // printf("%c", csvCharacter);
            // printf("%s\t%i\n", "Rows: ", rows);
            // printf("%s\t%i\n", "Columns: ", columns);
        } while (csvCharacter != EOF);
        // printf("\n");
    }

    fclose(file); //Close filestream
}
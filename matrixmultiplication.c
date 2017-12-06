#include <stdio.h>
#include <stdlib.h>

void allocateMemoryForMatrix(int *matrix, int numRows, int numColumns);
void getMatrixSize(int *rows, int *columns, char fileName[20]);
void populateMatrix(int *matrix, char fileName[20], int numRows, int numColumns);

int main(int argc, char *argv[]) {
    int rows = 1, columns = 1;
    int matrixOne;
    int matrixTwo;

    if(argc <= 2) {
        printf("At least two CSV files (supplied via command line argument) are required. Exiting...\n");
        return 0;
    }

    printf("%i\n\n", argc);
    printf("%s\t%s\n", "File name: ", argv[1]);
    getMatrixSize(&rows, &columns, argv[1]);
    populateMatrix(&matrixOne, argv[1], rows, columns);
    printf("%s\t%i\n", "Rows: ", rows);
    printf("%s\t%i\n", "Columns: ", columns);

    return 0;
}

void getMatrixSize(int *rows, int *columns, char fileName[20]) {
    FILE *file = fopen(fileName, "r"); //Open filestream
    char csvCharacter;
    if (file == NULL) {
        printf("File does not exist.\n");
    } else {
        do {
            csvCharacter = fgetc(file);

            if (csvCharacter == ',' && csvCharacter != '\n')
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

/**
 * matrix is a pointer to the first element of a 2d array representing the matrix to be populated
 * fileName is the name of the file from which to populate the matrix
 * numRows is the number of rows in the file
 * numColumns is the number of columns in the file
 * */
void populateMatrix(int *matrix, char fileName[20], int numRows, int numColumns) {
    FILE *file = fopen(fileName, "r"); //Open filestream
    char csvCharacter;

    (*matrix) = malloc(numRows * sizeof(int)); //
    for(int i = 0; i < numRows; i++)
        (*matrix[i]) = malloc(numColumns * sizeof(int));

    if (file == NULL) {
        printf("File does not exist.\n");
    } else {
        do {
            csvCharacter = fgetc(file);

            for(int i = 0; i < numRows; i++) {
                for(int j = 0; j < numColumns; j++) {
                    (*matrix[i][j]) = csvCharacter;
                    printf("%c", csvCharacter);
                }
                csvCharacter = fgetc(file); //effectively discarding the newline character
                printf("%c", csvCharacter);
            }

            //Following line was used for debugging purposes
            printf("%c", csvCharacter);
        } while (csvCharacter != EOF);
        // printf("\n");
    }

    fclose(file); //Close filestream
}
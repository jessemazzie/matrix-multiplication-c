#include <stdio.h>
#include <stdlib.h>

void allocateMemoryForMatrix(int *matrix, int numRows, int numColumns);
void getMatrixSize(int *rows, int *columns, char fileName[20]);
void populateMatrix(int **matrix, char fileName[20], int numRows, int numColumns);

int main(int argc, char *argv[])
{
    int rows = 1, columns = 1;
    int *matrixOne;
    int matrixTwo;

    if (argc <= 2)
    {
        printf("At least two CSV files (supplied via command line argument) are required. Exiting...\n");
        return 0;
    }

    printf("%i\n\n", argc);
    printf("%s\t%s\n", "File name: ", argv[1]);
    getMatrixSize(&rows, &columns, argv[1]);
    printf("%s\t%i\n", "Rows: ", rows);
    printf("%s\t%i\n", "Columns: ", columns);

    //int matrixOne[rows][columns];

    populateMatrix(&matrixOne, argv[1], rows, columns);
    

    return 0;
}

void getMatrixSize(int *rows, int *columns, char fileName[20])
{
    FILE *file = fopen(fileName, "r"); //Open filestream
    char csvCharacter;
    if (file == NULL)
    {
        printf("File does not exist.\n");
    }
    else
    {
        do
        {
            csvCharacter = fgetc(file);

            if (csvCharacter == ',' && csvCharacter != '\n' && (*rows) <= 1) //only count number of columns in first row
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
void populateMatrix(int **matrix, char fileName[20], int numRows, int numColumns)
{
    FILE *file = fopen(fileName, "r"); //Open filestream
    int *currentNum = 0;
    //char csvCharacter;

    matrix = (int **)malloc(numRows * sizeof(int *)); //
    for(int i = 0; i < numRows; i++) {
        matrix[i] = (int *)malloc(numColumns * sizeof(int));
    }

    if (file == NULL)
    {
        printf("File does not exist.\n");
    }
    else
    {
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < numColumns; j++)
                fscanf(file, "%d,", &matrix[i][j]);
        }
        // printf("\n");

        for(int i = 0; i < numRows; i++) 
        {
            for(int j = 0; j < numColumns; j++)
                printf("%i ", matrix[i][j]);
            printf("\n\n");
        }
    }
    fclose(file); //Close filestream
}

//2D array reference: http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
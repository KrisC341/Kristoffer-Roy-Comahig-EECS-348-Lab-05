#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int *addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
int *multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
int *tranposeMatrix(int m1[SIZE][SIZE]);
void printMatrix(int m1[SIZE][SIZE]);


int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    
    printf("Add m1 + m2:\n");
    printMatrix(addMatrices(m1,m2));

    printf("\nMultiply m1 * m2:\n");
    printMatrix(multiplyMatrices(m1,m2));

    printf("\nTranspose m1:\n");
    printMatrix(tranposeMatrix(m1));

    printf("\nTranspose m2:\n");
    printMatrix(tranposeMatrix(m2));

    return 0;
}

void printMatrix(int m1[SIZE][SIZE]){
    if(SIZE == 0){
        printf("ERROR: NO MATRIX AVAILABLE TO PRINT.");
    }

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d, ", m1[i][j]);
        }
        printf("\n");
    }
}


int* addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    static int addMatrice[SIZE][SIZE];

    int m1Row = (sizeof(*m1) / sizeof(*m1[0]));
    int m1Col = (sizeof(m1)[0] / sizeof(*(*(m1 + 0) + 0)));
    int m2Row = (sizeof(*m2) / sizeof(*m2[0]));
    int m2Col = (sizeof(m2)[0] / sizeof(*(*(m2 + 0) + 0)));

    if((m1Row != m2Row) || (m1Col != m2Col) || (SIZE == 0)){
        printf("ERROR: DIMENSIONS INVALID FOR ADDITION. NULL WILL BE RETURNED.");
        return NULL;
    }

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            addMatrice[i][j] = m1[i][j] + m2[i][j];
        };
    };
    return addMatrice;
}

int *multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    static int multiMatrice[SIZE][SIZE];


    int m1Col = (sizeof(m1)[0] / sizeof(*(*(m1 + 0) + 0)));
    int m2Row = (sizeof(*m2) / sizeof(*m2[0]));


    if((m1Col != m2Row) || (SIZE == 0)){
        printf("ERROR, DIMENSIONS ARE INVALID FOR MULTIPLICATION\n");
        return NULL;
    }

    
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) { 
            multiMatrice[i][j] = 0;
        }
    }

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) { 
            for(int k = 0; k < SIZE; k++){
                multiMatrice[i][j] += (m1[i][k] * m2[k][j]);
            }
        }
    }
    return multiMatrice;
}

int* tranposeMatrix(int m1[SIZE][SIZE]){
    static int transposeMatrice[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            transposeMatrice[j][i] = m1[i][j];
        }
    }
    return transposeMatrice;
}
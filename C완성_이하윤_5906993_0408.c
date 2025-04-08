#include <stdio.h>
#include <stdlib.h>

void print_matrix(int** matrix, int rows, int cols) {
    printf("\n입력한 행렬:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N, M;
    printf("행의 수 N을 입력: ");
    scanf("%d", &N);
    printf("열의 수 M을 입력: ");
    scanf("%d", &M);

    int** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(M * sizeof(int));
    }

    printf("\n%d x %d 행렬의 원소를 입력:\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    print_matrix(matrix, N, M);

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
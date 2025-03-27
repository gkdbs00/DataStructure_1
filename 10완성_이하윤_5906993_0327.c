#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 2, cols = 2;
    int *matrix1, *matrix2, *result;

    // 동적 메모리 할당
    matrix1 = (int *)malloc(rows * cols * sizeof(int));
    matrix2 = (int *)malloc(rows * cols * sizeof(int));
    result = (int *)malloc(rows * cols * sizeof(int));

    if (matrix1 == NULL || matrix2 == NULL || result == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 첫 번째 행렬 입력
    printf("첫 번째 2x2 행렬 입력:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (matrix1 + i * cols + j));
        }
    }

    // 두 번째 행렬 입력
    printf("두 번째 2x2 행렬 입력:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (matrix2 + i * cols + j));
        }
    }

    // 행렬 덧셈
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(matrix1 + i * cols + j) + *(matrix2 + i * cols + j);
        }
    }

    // 결과 출력
    printf("행렬 덧셈 결과:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(result + i * cols + j));
        }
        printf("\n");
    }

    // 메모리 해제
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
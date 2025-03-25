#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    
    printf("정수의 개수를 입력하세요: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int)); // 동적 메모리 할당

    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    printf("%d개의 정수를 입력하세요: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 오름차순 정렬
    qsort(arr, n, sizeof(int), compare);

    printf("오름차순으로 정렬된 정수들:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // 메모리 해제
    return 0;
}
#include <stdio.h>

int main() {
    int N;
    
    printf("정수 N을 입력하세요: ");
    scanf("%d", &N);

    printf("%d 이하의 소수: ", N);

    for (int i = 2; i <= N; i++) {
        int is_prime = 1;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            printf("%d ", i);
        }
    }
    
    printf("\n");

    return 0;
}
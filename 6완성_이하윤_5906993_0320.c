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

/* 1.
   - 만약 n이 2 이하일 때 :
       - 2면 True 반환
       - 1이면 False 반환
   - 2부터 n까지 반복:
       - n이 해당 숫자로 나누어 떨어지면 False 반환
   - 반복문 종료 후 True 반환 (n은 소수임)

2.
   - 2부터 N까지 모든 숫자에 대해 is_prime() 호출
   - 소수일 경우 출력

3. 사용자 입력 N을 받고 명령문 실행 */

/* O(n)은 입력 값이 커질 수록 실행 시간 증가로 예측. */
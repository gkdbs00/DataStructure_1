#include <stdio.h>

typedef struct {
    int num1;
    int num2;
} Arithmetic;

int add(Arithmetic a) {
    return a.num1 + a.num2;
}

int subtract(Arithmetic a) {
    return a.num1 - a.num2;
}

int multiply(Arithmetic a) {
    return a.num1 * a.num2;
}

float divide(Arithmetic a) {
    if (a.num2 == 0) {
        printf("오류: 0으로 나눌 수 없습니다.\n");
        return 0;
    }
    return (float)a.num1 / a.num2;
}

int main() {
    Arithmetic arith;

    printf("첫 번째 양의 정수를 입력하세요: ");
    scanf("%d", &arith.num1);
    printf("두 번째 양의 정수를 입력하세요: ");
    scanf("%d", &arith.num2);

    printf("덧셈: %d\n", add(arith));
    printf("뺄셈: %d\n", subtract(arith));
    printf("곱셈: %d\n", multiply(arith));
    printf("나눗셈: %.2f\n", divide(arith));

    return 0;
}
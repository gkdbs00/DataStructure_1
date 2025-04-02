#include <stdio.h>

int fibonacci_recursive(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_interative(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	int a = 0, b = 1, result = 0;
	for (int i = 2; i <= n; i++) {
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

int main() {
	int choice = -1;
	int n;

	while (1) {
		printf("피보나치 수열 방법 선택 (1 : 재귀적, 2 : 순환적, 0 : 종료) : ");
		scanf_s("%d", &choice);

		if (choice == 0) {
			printf("프로그램이 종료되었습니다.\n");
			break;
		}
		printf("정수 N을 입력하세요 (종료하려면 0 입력) : ");
		scanf_s("%d", &n);

		if (n < 0) {
			printf("잘못된 입력입니다. 0 이상의 정수를 입력하세요.\n");
			continue;
		}
		if (choice == 1) {
			printf("F(%d) = %d (재귀적 방법)\n", n, fibonacci_recursive(n));
		}
		else if (choice == 2) {
			printf("F(%d) = %d (순환적 방법)\n", n, fibonacci_interative(n));
		}
		else {
			printf("잘못된 선택입니다. 1 또는 2를 입력하세요.\n");
		}
	}
	return 0;
}
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
		printf("�Ǻ���ġ ���� ��� ���� (1 : �����, 2 : ��ȯ��, 0 : ����) : ");
		scanf_s("%d", &choice);

		if (choice == 0) {
			printf("���α׷��� ����Ǿ����ϴ�.\n");
			break;
		}
		printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�) : ");
		scanf_s("%d", &n);

		if (n < 0) {
			printf("�߸��� �Է��Դϴ�. 0 �̻��� ������ �Է��ϼ���.\n");
			continue;
		}
		if (choice == 1) {
			printf("F(%d) = %d (����� ���)\n", n, fibonacci_recursive(n));
		}
		else if (choice == 2) {
			printf("F(%d) = %d (��ȯ�� ���)\n", n, fibonacci_interative(n));
		}
		else {
			printf("�߸��� �����Դϴ�. 1 �Ǵ� 2�� �Է��ϼ���.\n");
		}
	}
	return 0;
}
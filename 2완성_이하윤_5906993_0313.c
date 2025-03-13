#include <stdio.h>

int main()
{
    float num;

    printf("실수를 입력하세요. : ");
    scanf("%f", &num);

    unsigned int *ptr = (unsigned int *)&num;
    unsigned int binary = *ptr;

    unsigned int sign = (binary >> 31) & 1;

    unsigned int exponent = (binary >> 23) & 0xFF;

    unsigned int mantissa = binary & 0x7FFFFF;

    printf("부호 (1비트) : %d\n", sign);

    printf("지수 (8비트) : ");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");

    printf("가수 (23비트) : ");
    for (int i = 22; i >= 0; i--)
    {
        printf("%d", (mantissa >> i) & 1);
    }
    printf("\n");

    return 0;
}
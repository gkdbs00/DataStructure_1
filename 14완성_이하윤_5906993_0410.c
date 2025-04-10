#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int coef;
    int expo;
} Term;

int parse(char* s, Term poly[]) {
    int i = 0, idx = 0;
    while (s[i]) {
        int sign = 1, coef = 0, expo = 0;

        if (s[i] == '-') { sign = -1; i++; }
        else if (s[i] == '+') { i++; }

        while (isdigit(s[i])) {
            coef = coef * 10 + (s[i++] - '0');
        }
        if (s[i] == 'x') {
            if (coef == 0) coef = 1;
            i++;
            if (s[i] == '^') {
                i++;
                while (isdigit(s[i])) {
                    expo = expo * 10 + (s[i++] - '0');
                }
            } else expo = 1;
        } else expo = 0;

        poly[idx].coef = coef * sign;
        poly[idx].expo = expo;
        idx++;
    }
    return idx;
}

int multiply(Term A[], int na, Term B[], int nb, Term R[]) {
    int nr = 0;
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            int c = A[i].coef * B[j].coef;
            int e = A[i].expo + B[j].expo;
            int found = 0;
            for (int k = 0; k < nr; k++) {
                if (R[k].expo == e) {
                    R[k].coef += c;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                R[nr].coef = c;
                R[nr].expo = e;
                nr++;
            }
        }
    }
    return nr;
}

void print(Term R[], int n) {
    // 정렬 없이 큰 차수부터 나올 수 있게만 처리 (단순 버블 정렬)
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (R[i].expo < R[j].expo) {
                Term t = R[i]; R[i] = R[j]; R[j] = t;
            }

    for (int i = 0; i < n; i++) {
        if (R[i].coef == 0) continue;
        if (i > 0 && R[i].coef > 0) printf("+");
        if (R[i].expo == 0) printf("%d", R[i].coef);
        else if (R[i].expo == 1) printf("%dx", R[i].coef);
        else printf("%dx^%d", R[i].coef, R[i].expo);
    }
    printf("\n");
}

int main() {
    char in1[100], in2[100];
    Term A[20], B[20], R[50];

    printf("첫 번째 다항식: ");
    scanf("%s", in1);
    printf("두 번째 다항식: ");
    scanf("%s", in2);

    int na = parse(in1, A);
    int nb = parse(in2, B);
    int nr = multiply(A, na, B, nb, R);

    printf("결과: ");
    print(R, nr);
    return 0;
}
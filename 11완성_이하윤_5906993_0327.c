#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 정보를 저장할 구조체
typedef struct {
    char name[50];
    int student_id;
    int score;
} Student;

int main() {
    int n;
    Student *students;

    // 학생 수 입력
    printf("몇 명의 학생 정보를 입력하시나요? ");
    scanf("%d", &n);

    // 동적 메모리 할당
    students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 학생 정보 입력
    for (int i = 0; i < n; i++) {
        printf("[%d] 학생의 정보를 입력하세요 (이름 학번 점수): ", i + 1);
        scanf("%s %d %d", students[i].name, &students[i].student_id, &students[i].score);
    }

    // 학번 검색 기능
    while (1) {
        int search_id;
        printf("학번을 입력하세요 (0이면 종료): ");
        scanf("%d", &search_id);

        if (search_id == 0) break; // 0 입력 시 종료

        // 학생 탐색
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (students[i].student_id == search_id) {
                printf("이름: %s, 학번: %d, 점수: %d\n", students[i].name, students[i].student_id, students[i].score);
                found = 1;
                break;
            }
        }

        // 존재하지 않는 학번인 경우
        if (!found) {
            printf("해당 학번의 학생이 없습니다.\n");
        }
    }

    // 동적 메모리 해제
    free(students);

    return 0;
}
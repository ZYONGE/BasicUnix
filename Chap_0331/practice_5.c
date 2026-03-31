#include <stdio.h>

void show_grade(int grade);

int main(void) {
    
    int grade;
    printf("Enter your grade: ");
    scanf("%d", &grade);

    show_grade(grade);

    return 0;
}

void show_grade(int grade) {
    switch(grade){
        case 1:
            printf("1학년 학생입니다.\n");
            break;
        case 2:
            printf("2학년 학생입니다.\n");
            break;
        case 3:
            printf("3학년 학생입니다.\n");
            break;
        case 4:
            printf("4학년 학생입니다.\n");
            break;
        default:
            printf("잘못된 학년입니다.\n");
    }
}
#include <stdio.h>

void arithmetic(void) {
    double opd1, opd2;
    char op;
    int n;

    n = scanf("%lf %c %lf", &opd1, &op, &opd2);
    if (n != 3) {
        fprintf(stderr, "No matching characters\n");
        return;
    }

    switch (op) {
        case '+':
            printf("%lf %c %lf = %lf\n", opd1, op, opd2, opd1 + opd2);
            break;
        case '-':
            printf("%lf %c %lf = %lf\n", opd1, op, opd2, opd1 - opd2);
            break;
        case '*':
            printf("%lf %c %lf = %lf\n", opd1, op, opd2, opd1 * opd2);
            break;
        case '/':
            printf("%lf %c %lf = %lf\n", opd1, op, opd2, opd1 / opd2);
            break;
        default:
            fprintf(stderr, "Unsupported operator\n");
            break;
    }
}
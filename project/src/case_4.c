#include <case_4.h>


void recursion(int number, int step) {
        if (1+step != number) {
            printf("%d", 1+step);
            printf(" ");
            if (number > 1) {
                recursion(number, step+1);
            } else if (number < 1) {
                recursion(number, step-1);
            }
        } else {
            printf("%d", 1+step);
        }
        printf("\n");
}

#include <rec_mod.h>


void recursion(int number, int step) {
        if (step != number) {
            printf("%d", step);
            printf(" ");
            if (number > 1) {
                recursion(number, step+1);
            } else if (number < 1) {
                recursion(number, step-1);
            }
        } else {
            printf("%d", step);
        }
        printf("\n");
}

#include <utils.h>


size_t timer_from(int from) {
    size_t counter = 0;

    for (int i = from; i >= 0; --i) {
        ++counter;
        printf("%d", i);
        if (i != 0) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return counter;
}

size_t custom_pow(int base, int power) {
    size_t result = 1;
    for (int i = 0; i < power; ++i) {
        result = result * base;
    }
    return result;
}


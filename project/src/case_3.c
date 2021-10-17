#include <case_3.h>


unsigned char checking(int number) {
    if (number > 1) {
        for (int i = 2; i < number; ++i) {
            if (number % i == 0) {
                return '0';
            }
        }
        return '1';
    } else {
        return '0';
    }
    return '1';
}

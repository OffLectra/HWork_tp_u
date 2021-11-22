#include <is_prime_mod.h>


size_t is_prime(int number) {
    if (number > 1) {
        for (int i = 2; i < number; ++i) {
            if (number % i == 0) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
    return 1;
}

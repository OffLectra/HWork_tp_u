#include <utils.h>
#include <is_prime_mod.h>
#include <rec_mod.h>

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)

#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3
#define TST_FOO_MOD     4


int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    int Test_case = atoi(argv[1]);
    const char* data;
    data = argv[2];
    switch (Test_case) {
        case TST_FOO_FIX: {
            int to = atoi(data);
            unsigned int ticks_count = timer_from(to);
            printf("%u\n", ticks_count);
            break;
        }
        case TST_FOO_IMPL: {
            if (argc == 4) {
                int base = atoi(data);
                int pow =  atoi(argv[3]);
                long res = custom_pow(base, pow);
                printf("%ld\n", res);
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }
        case TST_MOD_IMPL: {
            int num = atoi(data);
            size_t check = is_prime(num);
            printf("%zu\n", check);
            break;
        }
        case TST_FOO_MOD: {
                int num = atoi(data);
                recursion(num, 1);
                break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}

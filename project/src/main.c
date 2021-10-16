#include "utils.h"
#include "case_3.h"
#include "case_4.h"

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)

#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3
#define TST_FOO_MOD     4


/* NOTE(stitaevskiy):
 * We use `atoi` function just for simplification and code reducing.
 * This function doesn't report conversation errors.
 * For safety program we recommend using `strtol` and its analogs.
 * (See `man atoi` and `man strtol` for more info).
 *
 * const char str_num[] = "1234";
 * char* end = NULL;
 * int val = (int) strtol(str_num, &end, 0);
 * if (end != '\0') {
 *     //ERROR
 * }
 *
 * */

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
                long res = custom_pow(base, pow);    // TODO: Implement me

                printf("%ld\n", res);
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }
        case TST_MOD_IMPL: {
            int num = atoi(data);
            unsigned char check = checking(num);
            printf("%c\n", check);

            // TODO: Print to stdout `1` if `num` is prime number and `0` otherwise
            // This function MUST be implemented in
            // a separate C-module (not in `main` or `utils` module)
            break;
        }
        case TST_FOO_MOD: {
                int num = atoi(data);
                recursion(num,0);
                break;               

        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}

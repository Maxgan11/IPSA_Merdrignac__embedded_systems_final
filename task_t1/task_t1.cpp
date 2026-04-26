#include "task_t1.h"

void task_t1(gmp_randstate_t state) {
    mpz_t a, b, res;
    mpz_inits(a, b, res, NULL);

    mpz_urandomb(a, state, 1000000); // 1 000k bits
    mpz_urandomb(b, state, 1000000); // 1 000k bits

    mpz_mul(res, a, b);

    mpz_clears(a, b, res, NULL);
}
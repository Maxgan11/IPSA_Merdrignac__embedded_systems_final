#include "task_t1.h"

void task_t1(gmp_randstate_t state) {
    mpz_t a, b, res;
    mpz_inits(a, b, res, NULL);

    //nombres aléatoires (equivalent de rd.getrandbits)
    mpz_urandomb(a, state, 500000); // 500k bits
    mpz_urandomb(b, state, 500000); // 500k bits

    // calcul : res = a * b
    mpz_mul(res, a, b);

    mpz_clears(a, b, res, NULL);
}
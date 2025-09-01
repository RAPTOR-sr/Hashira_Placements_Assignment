#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#define MAXK 50
#define MAXLEN 2000

void multiplyPoly(mpz_t coeffs[], int *deg, mpz_t r) {
    int d = *deg;
    mpz_init(coeffs[d+1]);

    for (int i = d; i >= 0; i--) {
        mpz_t temp;
        mpz_init(temp);

        if (i == d) {
            mpz_set_ui(coeffs[d+1], 0);
        }

        mpz_mul(temp, coeffs[i], r);
        mpz_sub(coeffs[i+1], coeffs[i+1], temp);

        mpz_clear(temp);
    }
    (*deg)++;
}

int main() {
    int n = 4, k = 3;

    char bases[4][4] = {"10", "2", "10", "4"};
    char values[4][MAXLEN] = {"4", "111", "12", "213"};

    mpz_t roots[MAXK];
    for (int i = 0; i < n; i++) {
        mpz_init(roots[i]);
        int base = atoi(bases[i]);
        mpz_set_str(roots[i], values[i], base);
    }

    mpz_t coeffs[MAXK];
    int degree = 0;

    for (int i = 0; i < MAXK; i++) {
        mpz_init(coeffs[i]);
    }
    mpz_set_ui(coeffs[0], 1);

    for (int i = 0; i < k; i++) {
        multiplyPoly(coeffs, &degree, roots[i]);
    }

    printf("Polynomial coefficients:\n");
    for (int i = 0; i <= degree; i++) {
        mpz_out_str(stdout, 10, coeffs[i]);
        printf(" ");
    }
    printf("\n");

    for (int i = 0; i < n; i++) mpz_clear(roots[i]);
    for (int i = 0; i <= degree; i++) mpz_clear(coeffs[i]);

    return 0;
}

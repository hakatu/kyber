#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "params.h"
#include "indcpa.h"
#include "polyvec.h"
#include "poly.h"

uint8_t seed[KYBER_SYMBYTES] = {0};

int main(void)
{
  // unsigned int i;
  // uint8_t pk[CRYPTO_PUBLICKEYBYTES];
  // uint8_t sk[CRYPTO_SECRETKEYBYTES];
  // uint8_t ct[CRYPTO_CIPHERTEXTBYTES];
  // uint8_t key[CRYPTO_BYTES];
  // uint8_t kexsenda[KEX_AKE_SENDABYTES];
  // uint8_t kexsendb[KEX_AKE_SENDBBYTES];
  // uint8_t kexkey[KEX_SSBYTES];
  polyvec matrix[KYBER_K];
  poly ap;

  gen_matrix(matrix, seed, 0);
  polyvec_basemul_acc_montgomery(&ap, &matrix[0], &matrix[1]);
  
  return 0;
}

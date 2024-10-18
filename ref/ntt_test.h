#ifndef NTT_TEST_H
#define NTT_TEST_H

#include <stdint.h>
#include "params.h"

#define zetas_test KYBER_NAMESPACE(zetas)
extern const int16_t zetas[128];

#define ntt_test KYBER_NAMESPACE(ntt)
void ntt_test(int16_t poly[256]);

#define invntt_test KYBER_NAMESPACE(invntt)
void invntt_test(int16_t poly[256]);

#define basemul_test KYBER_NAMESPACE(basemul)
void basemul_test(int16_t r[2], const int16_t a[2], const int16_t b[2], int16_t zeta);

#endif

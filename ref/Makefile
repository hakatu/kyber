CC ?= /usr/bin/cc
CFLAGS += -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wredundant-decls \
  -Wshadow -Wpointer-arith -O3 -fomit-frame-pointer
NISTFLAGS += -Wno-unused-result -O3 -fomit-frame-pointer
RM = /bin/rm

SOURCES = kex.c kem.c indcpa.c polyvec.c poly.c ntt.c cbd.c reduce.c verify.c
SOURCESKECCAK = $(SOURCES) fips202.c symmetric-shake.c
SOURCESNINETIES = $(SOURCES) sha256.c sha512.c aes256ctr.c symmetric-aes.c
HEADERS = params.h kex.h kem.h indcpa.h polyvec.h poly.h ntt.h cbd.h reduce.c verify.h symmetric.h
HEADERSKECCAK = $(HEADERS) fips202.h
HEADERSNINETIES = $(HEADERS) aes256ctr.h sha2.h

.PHONY: all speed shared clean

all: \
  test_kyber512 \
  test_kex512 \
  test_vectors512 \
  
speed: \
  test_speed512 \

sha3: \
  test_sha3 \

shake: \
  test_shake \

shared: \
  libpqcrystals_kyber512_ref.so
  
libpqcrystals_kyber512_ref.so: $(SOURCES) $(HEADERS) symmetric-shake.c
	$(CC) -shared -fPIC $(CFLAGS) -DKYBER_K=2 $(SOURCES) symmetric-shake.c -o libpqcrystals_kyber512_ref.so

test_kyber512: $(SOURCESKECCAK) $(HEADERSKECCAK) test_kyber.c randombytes.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) randombytes.c test_kyber.c -o test_kyber512

test_kex512: $(SOURCESKECCAK) $(HEADERSKECCAK) test_kex.c randombytes.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) randombytes.c test_kex.c -o test_kex512

test_vectors512: $(SOURCESKECCAK) $(HEADERSKECCAK) test_vectors.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) test_vectors.c -o test_vectors512

test_speed512: $(SOURCESKECCAK) $(HEADERSKECCAK) cpucycles.h cpucycles.c speed_print.h speed_print.c test_speed.c randombytes.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) randombytes.c cpucycles.c speed_print.c test_speed.c -o test_speed512

PQCgenKAT_kem512: $(SOURCESKECCAK) $(HEADERSKECCAK) PQCgenKAT_kem.c rng.c rng.h
	$(CC) $(NISTFLAGS) -DKYBER_K=2 -o $@ $(SOURCESKECCAK) rng.c PQCgenKAT_kem.c $(LDFLAGS) -lcrypto

test_sha3: fips202.c symmetric-shake.c fips202.h test_sha3.c
	$(CC) $(CFLAGS) -DKYBER_K=2 fips202.c symmetric-shake.c test_sha3.c -o test_sha3

test_shake: fips202.c symmetric-shake.c fips202.h test_shake.c
	$(CC) $(CFLAGS) -DKYBER_K=2 fips202.c symmetric-shake.c test_shake.c -o test_shake

test_reduce: reduce.c reduce_test.c
	$(CC) $(CFLAGS) -DKYBER_K=2 reduce.c reduce_test.c -o test_reduce

func_reduce: reduce.c reduce_func.c
	$(CC) $(CFLAGS) -DKYBER_K=2 reduce.c reduce_func.c -o func_reduce

test_ntt512: $(SOURCESKECCAK) $(HEADERSKECCAK) test_ntt.c randombytes.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) randombytes.c test_ntt.c -o test_ntt512

test_ntt_io: $(SOURCESKECCAK) $(HEADERSKECCAK) test_ntt_io.c randombytes.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) randombytes.c test_ntt_io.c -o test_ntt_io

test_ntt_input: $(SOURCESKECCAK) $(HEADERSKECCAK) test_ntt_input.c randombytes.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) randombytes.c test_ntt_input.c -o test_ntt_input

test_mul: $(SOURCESKECCAK) $(HEADERSKECCAK) test_mul.c randombytes.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) randombytes.c test_mul.c -o test_mul

test_ntt_data: $(SOURCESKECCAK) $(HEADERSKECCAK) test_ntt_data.c randombytes.c
	$(CC) $(CFLAGS) -DKYBER_K=2 $(SOURCESKECCAK) randombytes.c test_ntt_data.c -o test_ntt_data

clean:
	-$(RM) -rf *.gcno *.gcda *.lcov *.o *.so
	-$(RM) -rf test_kyber512
	-$(RM) -rf test_kex512
	-$(RM) -rf test_vectors512
	-$(RM) -rf test_speed512
	-$(RM) -rf PQCgenKAT_kem512

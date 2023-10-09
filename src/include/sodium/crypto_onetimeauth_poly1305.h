#ifndef crypto_onetimeauth_poly1305_H
#define crypto_onetimeauth_poly1305_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>

typedef struct crypto_onetimeauth_poly1305_state {
  unsigned char opaque[256];
} crypto_onetimeauth_poly1305_state;

size_t crypto_onetimeauth_poly1305_statebytes(void);

#define crypto_onetimeauth_poly1305_BYTES 16U

size_t crypto_onetimeauth_poly1305_bytes(void);

#define crypto_onetimeauth_poly1305_KEYBYTES 32U

size_t crypto_onetimeauth_poly1305_keybytes(void);

int crypto_onetimeauth_poly1305(unsigned char *out, const unsigned char *in, unsigned long long inlen, const unsigned char *k)
    __attribute__((nonnull(1, 4)));

int crypto_onetimeauth_poly1305_verify(const unsigned char *h, const unsigned char *in, unsigned long long inlen, const unsigned char *k)
    __attribute__((warn_unused_result)) __attribute__((nonnull(1, 4)));

int crypto_onetimeauth_poly1305_init(crypto_onetimeauth_poly1305_state *state, const unsigned char *key) __attribute__((nonnull));

int crypto_onetimeauth_poly1305_update(crypto_onetimeauth_poly1305_state *state, const unsigned char *in, unsigned long long inlen)
    __attribute__((nonnull(1)));

int crypto_onetimeauth_poly1305_final(crypto_onetimeauth_poly1305_state *state, unsigned char *out) __attribute__((nonnull));

void crypto_onetimeauth_poly1305_keygen(unsigned char k[crypto_onetimeauth_poly1305_KEYBYTES]) __attribute__((nonnull));

#endif

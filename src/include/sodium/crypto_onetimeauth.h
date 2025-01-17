#ifndef crypto_onetimeauth_H
#define crypto_onetimeauth_H

#include <stddef.h>

#include "crypto_onetimeauth_poly1305.h"

typedef crypto_onetimeauth_poly1305_state crypto_onetimeauth_state;

size_t crypto_onetimeauth_statebytes(void);

#define crypto_onetimeauth_BYTES crypto_onetimeauth_poly1305_BYTES

size_t crypto_onetimeauth_bytes(void);

#define crypto_onetimeauth_KEYBYTES crypto_onetimeauth_poly1305_KEYBYTES

size_t crypto_onetimeauth_keybytes(void);

#define crypto_onetimeauth_PRIMITIVE "poly1305"

const char *crypto_onetimeauth_primitive(void);

int crypto_onetimeauth(unsigned char *out, const unsigned char *in, unsigned long long inlen, const unsigned char *k) __attribute__((nonnull(1, 4)));

int crypto_onetimeauth_verify(const unsigned char *h, const unsigned char *in, unsigned long long inlen, const unsigned char *k)
    __attribute__((warn_unused_result)) __attribute__((nonnull(1, 4)));

int crypto_onetimeauth_init(crypto_onetimeauth_state *state, const unsigned char *key) __attribute__((nonnull));

int crypto_onetimeauth_update(crypto_onetimeauth_state *state, const unsigned char *in, unsigned long long inlen) __attribute__((nonnull(1)));

int crypto_onetimeauth_final(crypto_onetimeauth_state *state, unsigned char *out) __attribute__((nonnull));

void crypto_onetimeauth_keygen(unsigned char k[crypto_onetimeauth_KEYBYTES]) __attribute__((nonnull));

#endif

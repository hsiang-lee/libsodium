#ifndef crypto_verify_64_H
#define crypto_verify_64_H

#include <stddef.h>

#define crypto_verify_64_BYTES 64U

size_t crypto_verify_64_bytes(void);

int crypto_verify_64(const unsigned char *x, const unsigned char *y) __attribute__((warn_unused_result)) __attribute__((nonnull));

#endif

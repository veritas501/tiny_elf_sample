#pragma once

#include <stddef.h>
#include <stdint.h>

#include "icrt_syscall.h"

// copy from musl-libc
static inline int memcmp(const void *vl, const void *vr, size_t n) {
    const unsigned char *l = (const unsigned char *)vl;
    const unsigned char *r = (const unsigned char *)vr;
    for (; n && *l == *r; n--, l++, r++)
        ;
    return n ? *l - *r : 0;
}

// copy from https://blog.csdn.net/lqy971966/article/details/106127286
static inline const char *memmem(const char *haystack, size_t hlen,
                             const char *needle, size_t nlen) {
    const char *cur;
    const char *last;

    last = haystack + hlen - nlen;
    for (cur = haystack; cur <= last; ++cur) {
        if (!memcmp(cur, needle, nlen)) {
            return cur;
        }
    }
    return 0;
}

static inline void * alloc(size_t size){
    return __builtin_alloca(size);
}
#ifndef CRFC_4648_H
#define CRFC_4648_H

#include <stdint.h>

uint64_t encode_base64(void* dst, void* src, uint64_t size);
uint64_t encode_base32(void* dst, void* src, uint64_t size);
uint64_t encode_base32hex(void* dst, void* src, uint64_t size);
uint64_t encode_base16(void* dst, void* src, uint64_t size);

#ifdef CRFC_4648_IMPLEMENTATION

uint64_t encode_base64(void* dst, void* src, uint64_t size) {

    return 0;
}

uint64_t encode_base32(void* dst, void* src, uint64_t size) {

    return 0;
}

uint64_t encode_base32hex(void* dst, void* src, uint64_t size) {

    return 0;
}

uint64_t encode_base16(void* dst, void* src, uint64_t size) {

    return 0;
}

#endif

#endif
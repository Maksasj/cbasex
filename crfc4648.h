#ifndef CRFC_4648_H
#define CRFC_4648_H

#include <stdint.h>

static char base64_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static char base64_url_safe_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
static char base32_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
static char base32_hex_alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
static char base16_alphabet[] = "0123456789ABCDEF";

uint64_t encode_base64(char** dst, void* src, uint64_t size);
uint64_t encode_base32(char** dst, void* src, uint64_t size);
uint64_t encode_base32hex(char** dst, void* src, uint64_t size);
uint64_t encode_base16(char** dst, void* src, uint64_t size);

typedef struct {
    unsigned char a;
    unsigned char b;
    unsigned char c;
} bit_24_t;

#ifdef CRFC_4648_IMPLEMENTATION

uint64_t encode_base64(char** dst, void* src, uint64_t size) {
    uint64_t padding = size % 3;
    uint64_t wrote = 0;

    unsigned char a, b, c;
    unsigned int quantum = 0;

    uint64_t i = 0;
    for(; i < (size - padding); i += 3) {
        a = ((unsigned char*) src)[i];
        b = ((unsigned char*) src)[i + 1];
        c = ((unsigned char*) src)[i + 2];

        quantum = (a << 16) | (b << 8) | c;

        (*dst)[wrote++] = base64_alphabet[(quantum >> 18) & 0x3F];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 12) & 0x3F];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 6) & 0x3F];
        (*dst)[wrote++] = base64_alphabet[quantum & 0x3F];
    }

    a = ((unsigned char*) src)[i];
    b = ((unsigned char*) src)[i + 1];
    c = ((unsigned char*) src)[i + 2];

    quantum = (a << 16) | (b << 8) | c;

    if(padding == 1) {
        (*dst)[wrote++] = base64_alphabet[(quantum >> 18) & 0x3F];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 12) & 0x3F];
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
    } else if(padding == 2) {
        (*dst)[wrote++] = base64_alphabet[(quantum >> 18) & 0x3F];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 12) & 0x3F];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 6) & 0x3F];
        (*dst)[wrote++] = '=';
    }

    (*dst)[wrote++] = '\0';

    return wrote;
}

uint64_t encode_base32(char** dst, void* src, uint64_t size) {

    return 0;
}

uint64_t encode_base32hex(char** dst, void* src, uint64_t size) {

    return 0;
}

uint64_t encode_base16(char** dst, void* src, uint64_t size) {

    return 0;
}

#endif

#endif
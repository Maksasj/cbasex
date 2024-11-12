#ifndef CBASEX_H
#define CBASEX_H

#include <stdint.h>

#define BITE_MASK_6 (0b00111111)
#define BITE_MASK_5 (0b00011111)

static char base64_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static char base64_alphabet_decode[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1 };

static char base64_url_safe_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
static char base32_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
static char base32_hex_alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
static char base16_alphabet[] = "0123456789ABCDEF";

uint64_t encode_base64(char** dst, void* src, uint64_t size);
uint64_t encode_base32(char** dst, void* src, uint64_t size);
uint64_t encode_base32hex(char** dst, void* src, uint64_t size);
uint64_t encode_base16(char** dst, void* src, uint64_t size);

uint64_t decode_base64(char** dst, char* src, uint64_t size);
uint64_t decode_base32(char** dst, char* src, uint64_t size);
uint64_t decode_base32hex(char** dst, char* src, uint64_t size);
uint64_t decode_base16(char** dst, char* src, uint64_t size);

#ifdef CBASEX_IMPLEMENTATION

uint64_t encode_base64(char** dst, void* src, uint64_t size) {
    uint64_t padding = size % 3;
    uint64_t wrote = 0;

    uint8_t a, b, c;
    uint32_t quantum = 0;

    uint64_t i = 0;
    for(; i < (size - padding); i += 3) {
        a = ((uint8_t*) src)[i];
        b = ((uint8_t*) src)[i + 1];
        c = ((uint8_t*) src)[i + 2];

        quantum = (a << 16) | (b << 8) | c;

        (*dst)[wrote++] = base64_alphabet[(quantum >> 18) & BITE_MASK_6];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 12) & BITE_MASK_6];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 6) & BITE_MASK_6];
        (*dst)[wrote++] = base64_alphabet[quantum & BITE_MASK_6];
    }

    a = ((uint8_t*) src)[i];
    b = ((uint8_t*) src)[i + 1];
    c = ((uint8_t*) src)[i + 2];

    quantum = (a << 16) | (b << 8) | c;

    if(padding == 1) {
        (*dst)[wrote++] = base64_alphabet[(quantum >> 18) & BITE_MASK_6];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 12) & BITE_MASK_6];
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
    } else if(padding == 2) {
        (*dst)[wrote++] = base64_alphabet[(quantum >> 18) & BITE_MASK_6];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 12) & BITE_MASK_6];
        (*dst)[wrote++] = base64_alphabet[(quantum >> 6) & BITE_MASK_6];
        (*dst)[wrote++] = '=';
    }

    (*dst)[wrote++] = '\0';

    return wrote;
}

uint64_t encode_base32(char** dst, void* src, uint64_t size) {
    uint64_t padding = size % 5;
    uint64_t wrote = 0;

    uint64_t a, b, c, d, e;
    uint64_t quantum;

    uint64_t i = 0;
    for(; i < (size - padding); i += 5) {
        a = ((uint8_t*) src)[i];
        b = ((uint8_t*) src)[i + 1];
        c = ((uint8_t*) src)[i + 2];
        d = ((uint8_t*) src)[i + 3];
        e = ((uint8_t*) src)[i + 4];
        
        quantum = (a << 32) | (b << 24) | (c << 16) | (d << 8) | e;

        (*dst)[wrote++] = base32_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 25) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 20) & BITE_MASK_5];

        (*dst)[wrote++] = base32_alphabet[(quantum >> 15) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 10) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 5) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 0) & BITE_MASK_5];
    }

    a = ((uint8_t*) src)[i];
    b = ((uint8_t*) src)[i + 1];
    c = ((uint8_t*) src)[i + 2];
    d = ((uint8_t*) src)[i + 3];
    e = ((uint8_t*) src)[i + 4];
        
    quantum = (a << 32) | (b << 24) | (c << 16) | (d << 8) | e;

    if(padding == 1) {
        (*dst)[wrote++] = base32_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';

        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
    } else if(padding == 2) {
        (*dst)[wrote++] = base32_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 25) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 20) & BITE_MASK_5];

        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
    } else if(padding == 3) {
        (*dst)[wrote++] = base32_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 25) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 20) & BITE_MASK_5];

        (*dst)[wrote++] = base32_alphabet[(quantum >> 15) & BITE_MASK_5];
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
    } else if(padding == 4) {
        (*dst)[wrote++] = base32_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 25) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 20) & BITE_MASK_5];

        (*dst)[wrote++] = base32_alphabet[(quantum >> 15) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 10) & BITE_MASK_5];
        (*dst)[wrote++] = base32_alphabet[(quantum >> 5) & BITE_MASK_5];
        (*dst)[wrote++] = '=';
    }

    (*dst)[wrote++] = '\0';

    return wrote;
}

uint64_t encode_base32hex(char** dst, void* src, uint64_t size) {
    uint64_t padding = size % 5;
    uint64_t wrote = 0;

    uint64_t a, b, c, d, e;
    uint64_t quantum;

    uint64_t i = 0;
    for(; i < (size - padding); i += 5) {
        a = ((uint8_t*) src)[i];
        b = ((uint8_t*) src)[i + 1];
        c = ((uint8_t*) src)[i + 2];
        d = ((uint8_t*) src)[i + 3];
        e = ((uint8_t*) src)[i + 4];
        
        quantum = (a << 32) | (b << 24) | (c << 16) | (d << 8) | e;

        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 25) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 20) & BITE_MASK_5];

        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 15) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 10) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 5) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 0) & BITE_MASK_5];
    }

    a = ((uint8_t*) src)[i];
    b = ((uint8_t*) src)[i + 1];
    c = ((uint8_t*) src)[i + 2];
    d = ((uint8_t*) src)[i + 3];
    e = ((uint8_t*) src)[i + 4];
        
    quantum = (a << 32) | (b << 24) | (c << 16) | (d << 8) | e;

    if(padding == 1) {
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';

        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
    } else if(padding == 2) {
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 25) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 20) & BITE_MASK_5];

        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
    } else if(padding == 3) {
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 25) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 20) & BITE_MASK_5];

        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 15) & BITE_MASK_5];
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
        (*dst)[wrote++] = '=';
    } else if(padding == 4) {
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 35) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 30) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 25) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 20) & BITE_MASK_5];

        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 15) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 10) & BITE_MASK_5];
        (*dst)[wrote++] = base32_hex_alphabet[(quantum >> 5) & BITE_MASK_5];
        (*dst)[wrote++] = '=';
    }

    (*dst)[wrote++] = '\0';

    return wrote;
}

uint64_t encode_base16(char** dst, void* src, uint64_t size) {

    return 0;
}

uint64_t decode_base64(char** dst, char* src, uint64_t size) {
    uint64_t padding = size % 4;
    uint64_t wrote = 0;

    uint8_t a, b, c, d;
    uint32_t quantum = 0;

    uint64_t i = 0;
    for(; i < (size * 3) / 4 - padding; i += 4) {
        a = base64_alphabet_decode[src[i]];
        b = base64_alphabet_decode[src[i + 1]];
        c = base64_alphabet_decode[src[i + 2]];
        d = base64_alphabet_decode[src[i + 3]];

        c = (src[i + 2] == '=') ? 0 : c;
        d = (src[i + 3] == '=') ? 0 : d;

        quantum = (a  << 18) | (b << 12) | (c << 6) | d;

        (*dst)[wrote++] = (quantum >> 16) & 0xFF;

        if(src[i + 2] != '=')
            (*dst)[wrote++] = (quantum >> 8) & 0xFF;

        if(src[i + 3] != '=')
            (*dst)[wrote++] = quantum & 0xFF;
    }

    (*dst)[wrote++] = '\0';

    return wrote;
}

uint64_t decode_base32(char** dst, char* src, uint64_t size) {

}

uint64_t decode_base32hex(char** dst, char* src, uint64_t size) {

}

uint64_t decode_base16(char** dst, char* src, uint64_t size) {

}

#endif

#endif
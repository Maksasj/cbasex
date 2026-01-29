#define CBASEX_IMPLEMENTATION
#include "cbasex.h"

#include "test.h"

int test_encode_base64_empty()
{
    char input[] = "";
    char expected[] = "";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base64(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base64_f()
{
    char input[] = "f";
    char expected[] = "Zg==";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base64(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base64_fo()
{
    char input[] = "fo";
    char expected[] = "Zm8=";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base64(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);

    return OK;
}

int test_encode_base64_foo()
{
    char input[] = "foo";
    char expected[] = "Zm9v";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base64(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base64_foob()
{
    char input[] = "foob";
    char expected[] = "Zm9vYg==";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base64(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base64_fooba()
{
    char input[] = "fooba";
    char expected[] = "Zm9vYmE=";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base64(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base64_foobar()
{
    char input[] = "foobar";
    char expected[] = "Zm9vYmFy";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base64(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32_empty()
{
    char input[] = "";
    char expected[] = "";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32_f()
{
    char input[] = "f";
    char expected[] = "MY======";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32_fo()
{
    char input[] = "fo";
    char expected[] = "MZXQ====";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32_foo()
{
    char input[] = "foo";
    char expected[] = "MZXW6===";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32_foob()
{
    char input[] = "foob";
    char expected[] = "MZXW6YQ=";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32_fooba()
{
    char input[] = "fooba";
    char expected[] = "MZXW6YTB";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32_foobar()
{
    char input[] = "foobar";
    char expected[] = "MZXW6YTBOI======";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}
int test_encode_base32hex_empty()
{
    char input[] = "";
    char expected[] = "";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32hex(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32hex_f()
{
    char input[] = "f";
    char expected[] = "CO======";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32hex(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32hex_fo()
{
    char input[] = "fo";
    char expected[] = "CPNG====";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32hex(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32hex_foo()
{
    char input[] = "foo";
    char expected[] = "CPNMU===";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32hex(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32hex_foob()
{
    char input[] = "foob";
    char expected[] = "CPNMUOG=";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32hex(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32hex_fooba()
{
    char input[] = "fooba";
    char expected[] = "CPNMUOJ1";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32hex(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base32hex_foobar()
{
    char input[] = "foobar";
    char expected[] = "CPNMUOJ1E8======";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base32hex(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base16_empty()
{
    char input[] = "";
    char expected[] = "";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base16(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base16_f()
{
    char input[] = "f";
    char expected[] = "66";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base16(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base16_fo()
{
    char input[] = "fo";
    char expected[] = "666F";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base16(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base16_foo()
{
    char input[] = "foo";
    char expected[] = "666F6F";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base16(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base16_foob()
{
    char input[] = "foob";
    char expected[] = "666F6F62";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base16(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base16_fooba()
{
    char input[] = "fooba";
    char expected[] = "666F6F6261";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base16(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_encode_base16_foobar()
{
    char input[] = "foobar";
    char expected[] = "666F6F626172";
    uint64_t length = strlen(input);

    char *encoded = calloc(100, sizeof(char));
    uint64_t wrote = encode_base16(&encoded, input, length);

    ENSURE_STRING_EQ(encoded, expected);
    ENSURE_EQ(strlen(encoded) + 1, wrote);

    free(encoded);
    return OK;
}

int test_decode_base64_empty()
{
    char expected[] = "";
    char input[] = "";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base64_f()
{
    char expected[] = "f";
    char input[] = "Zg==";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base64_fo()
{
    char expected[] = "fo";
    char input[] = "Zm8=";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base64_foo()
{
    char expected[] = "foo";
    char input[] = "Zm9v";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base64_foob()
{
    char expected[] = "foob";
    char input[] = "Zm9vYg==";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base64_fooba()
{
    char expected[] = "fooba";
    char input[] = "Zm9vYmE=";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base64_foobar()
{
    char expected[] = "foobar";
    char input[] = "Zm9vYmFy";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32_empty()
{
    char expected[] = "";
    char input[] = "";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32_f()
{
    char expected[] = "f";
    char input[] = "MY======";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32_fo()
{
    char expected[] = "fo";
    char input[] = "MZXQ====";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32_foo()
{
    char expected[] = "foo";
    char input[] = "MZXW6===";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32_foob()
{
    char expected[] = "foob";
    char input[] = "MZXW6YQ=";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32_fooba()
{
    char expected[] = "fooba";
    char input[] = "MZXW6YTB";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32_foobar()
{
    char expected[] = "foobar";
    char input[] = "MZXW6YTBOI======";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32hex_empty()
{
    char expected[] = "";
    char input[] = "";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32hex_f()
{
    char expected[] = "f";
    char input[] = "CO======";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32hex_fo()
{
    char expected[] = "fo";
    char input[] = "CPNG====";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32hex_foo()
{
    char expected[] = "foo";
    char input[] = "CPNMU===";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32hex_foob()
{
    char expected[] = "foob";
    char input[] = "CPNMUOG=";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32hex_fooba()
{
    char expected[] = "fooba";
    char input[] = "CPNMUOJ1";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base32hex_foobar()
{
    char expected[] = "foobar";
    char input[] = "CPNMUOJ1E8======";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base16_empty()
{
    char expected[] = "";
    char input[] = "";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);

    return OK;
}

int test_decode_base16_f()
{
    char expected[] = "f";
    char input[] = "66";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base16_fo()
{
    char expected[] = "fo";
    char input[] = "666F";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base16_foo()
{
    char expected[] = "foo";
    char input[] = "666F6F";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base16_foob()
{
    char expected[] = "foob";
    char input[] = "666F6F62";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base16_fooba()
{
    char expected[] = "fooba";
    char input[] = "666F6F6261";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int test_decode_base16_foobar()
{
    char expected[] = "foobar";
    char input[] = "666F6F626172";
    uint64_t length = strlen(input);

    char *decoded = calloc(100, sizeof(char));
    uint64_t wrote = decode_base64(&decoded, input, length);

    ENSURE_STRING_EQ(decoded, expected);
    ENSURE_EQ(strlen(decoded) + 1, wrote);

    free(decoded);
    return OK;
}

int main()
{
    RUN_TEST(test_encode_base64_empty);
    RUN_TEST(test_encode_base64_f);
    RUN_TEST(test_encode_base64_fo);
    RUN_TEST(test_encode_base64_foo);
    RUN_TEST(test_encode_base64_foob);
    RUN_TEST(test_encode_base64_fooba);
    RUN_TEST(test_encode_base64_foobar);
    RUN_TEST(test_encode_base32_empty);
    RUN_TEST(test_encode_base32_f);
    RUN_TEST(test_encode_base32_fo);
    RUN_TEST(test_encode_base32_foo);
    RUN_TEST(test_encode_base32_foob);
    RUN_TEST(test_encode_base32_fooba);
    RUN_TEST(test_encode_base32_foobar);
    RUN_TEST(test_encode_base32hex_empty);
    RUN_TEST(test_encode_base32hex_f);
    RUN_TEST(test_encode_base32hex_fo);
    RUN_TEST(test_encode_base32hex_foo);
    RUN_TEST(test_encode_base32hex_foob);
    RUN_TEST(test_encode_base32hex_fooba);
    RUN_TEST(test_encode_base32hex_foobar);
    RUN_TEST(test_encode_base16_empty);
    RUN_TEST(test_encode_base16_f);
    RUN_TEST(test_encode_base16_fo);
    RUN_TEST(test_encode_base16_foo);
    RUN_TEST(test_encode_base16_foob);
    RUN_TEST(test_encode_base16_fooba);
    RUN_TEST(test_encode_base16_foobar);

    RUN_TEST(test_decode_base64_empty);
    RUN_TEST(test_decode_base64_f);
    RUN_TEST(test_decode_base64_fo);
    RUN_TEST(test_decode_base64_foo);
    RUN_TEST(test_decode_base64_foob);
    RUN_TEST(test_decode_base64_fooba);
    RUN_TEST(test_decode_base64_foobar);
    RUN_TEST(test_decode_base32_empty);
    RUN_TEST(test_decode_base32_f);
    RUN_TEST(test_decode_base32_fo);
    RUN_TEST(test_decode_base32_foo);
    RUN_TEST(test_decode_base32_foob);
    RUN_TEST(test_decode_base32_fooba);
    RUN_TEST(test_decode_base32_foobar);
    RUN_TEST(test_decode_base32hex_empty);
    RUN_TEST(test_decode_base32hex_f);
    RUN_TEST(test_decode_base32hex_fo);
    RUN_TEST(test_decode_base32hex_foo);
    RUN_TEST(test_decode_base32hex_foob);
    RUN_TEST(test_decode_base32hex_fooba);
    RUN_TEST(test_decode_base32hex_foobar);
    RUN_TEST(test_decode_base16_empty);
    RUN_TEST(test_decode_base16_f);
    RUN_TEST(test_decode_base16_fo);
    RUN_TEST(test_decode_base16_foo);
    RUN_TEST(test_decode_base16_foob);
    RUN_TEST(test_decode_base16_fooba);
    RUN_TEST(test_decode_base16_foobar);

    return 0;
}
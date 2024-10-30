#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FAIL 0
#define OK 1

typedef int (*test_case_t)();

void run_test(const char* test_name, test_case_t test_case) {
    int result = (*test_case)();

    printf("%-10s %-100s %-10s\n", "Running test", test_name, (result ? "\x1B[32mSucceed\x1B[0m" : "\x1B[31mFailed\x1B[0m"));
}

void run_test_group(test_case_t test_case) {
    printf("%s\n", "Running test group");

    int result = (*test_case)();
}

#define RUN_TEST(TEST) run_test(#TEST, &(TEST));

#define RUN_TEST_GROUP(GROUP) run_test_group(&(GROUP))

#define ENSURE_EQ(A, B) if((A) != (B)) return FAIL
#define ENSURE_STRING_EQ(A, B) if(strcmp((A), (B)) != 0) return FAIL

#define CRFC_4648_IMPLEMENTATION
#include "crfc4648.h"

int test_encode_base64_empty() {
   char input[] = "";
   char expected[] = "";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base64(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base64_f() {
   char input[] = "f";
   char expected[] = "Zg==";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base64(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base64_fo() {
   char input[] = "fo";
   char expected[] = "Zm8=";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base64(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base64_foo() {
   char input[] = "foo";
   char expected[] = "Zm9v";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base64(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base64_foob() {
   char input[] = "foob";
   char expected[] = "Zm9vYg==";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base64(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base64_fooba() {
   char input[] = "fooba";
   char expected[] = "Zm9vYmE=";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base64(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base64_foobar() {
   char input[] = "foobar";
   char expected[] = "Zm9vYmFy";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base64(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32_empty() {
   char input[] = "";
   char expected[] = "";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32_f() {
   char input[] = "f";
   char expected[] = "MY======";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32_fo() {
   char input[] = "fo";
   char expected[] = "MZXQ====";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32_foo() {
   char input[] = "foo";
   char expected[] = "MZXW6===";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32_foob() {
   char input[] = "foob";
   char expected[] = "MZXW6YQ=";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32_fooba() {
   char input[] = "fooba";
   char expected[] = "MZXW6YTB";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32_foobar() {
   char input[] = "foobar";
   char expected[] = "MZXW6YTBOI======";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}
   int test_encode_base32hex_empty() {
   char input[] = "";
   char expected[] = "";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32hex(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32hex_f() {
   char input[] = "f";
   char expected[] = "CO======";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32hex(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32hex_fo() {
   char input[] = "fo";
   char expected[] = "CPNG====";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32hex(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32hex_foo() {
   char input[] = "foo";
   char expected[] = "CPNMU===";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32hex(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32hex_foob() {
   char input[] = "foob";
   char expected[] = "CPNMUOG=";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32hex(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32hex_fooba() {
   char input[] = "fooba";
   char expected[] = "CPNMUOJ1";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32hex(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base32hex_foobar() {
   char input[] = "foobar";
   char expected[] = "CPNMUOJ1E8======";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base32hex(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base16_empty() {
   char input[] = "";
   char expected[] = "";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base16(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base16_f() {
   char input[] = "f";
   char expected[] = "66";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base16(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base16_fo() {
   char input[] = "fo";
   char expected[] = "666F";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base16(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base16_foo() {
   char input[] = "foo";
   char expected[] = "666F6F";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base16(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base16_foob() {
   char input[] = "foob";
   char expected[] = "666F6F62";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base16(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base16_fooba() {
   char input[] = "fooba";
   char expected[] = "666F6F6261";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base16(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int test_encode_base16_foobar() {
   char input[] = "foobar";
   char expected[] = "666F6F626172";
   uint64_t length = strlen(input);
   
   char* encoded = calloc(100, sizeof(char));
   uint64_t wrote = encode_base16(&encoded, input, length);

   ENSURE_STRING_EQ(encoded, expected);

   free(encoded);
   return OK;
}

int main() {
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

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
void buffer_overflow(char* input) {
    printf("wasm bof test\n");

    char buffer[8];
    char buffer1[8]="boftest"

    strcpy(buffer, input);
    printf("%s", buffer);
    printf("\n");
}

EMSCRIPTEN_KEEPALIVE
void format_string_bug(char* input) {
    printf("wasm fsb test\n");

    printf(input);
    printf("\n");
}

EMSCRIPTEN_KEEPALIVE
void out_of_bound(int input) {
    printf("wasm oob test\n");

    char buffer[8] = "CERTCERT";
    printf("%c", buffer[input]);
    printf("\n");
}

EMSCRIPTEN_KEEPALIVE
void use_after_free(char* input) {
    printf("wasm uaf test\n");

    char *ptr = (char*)malloc(8);
    strcpy(ptr, input);
    free(ptr);  

    printf("%s", ptr);  
    printf("\n");
}

EMSCRIPTEN_KEEPALIVE
void double_free() {
    printf("wasm dfb test\n");

    char *ptr = (char *)malloc(32);
    if (!ptr) {
        printf("malloc failed\n");
        return;
    }

    free(ptr); 
    free(ptr);  

    printf("test complete\n");
}

EMSCRIPTEN_KEEPALIVE
void integer_overflow( ) {
    printf("wasm integer overflow  test\n");

    int max = INT_MAX;
    int min = INT_MIN;

    printf("INT_MAX: %d\n", max);
    printf("INT_MIN: %d\n", min);

    int overflow = max + 1;
    printf("Overflow (INT_MAX + 1): %d\n", overflow);

    int underflow = min - 1;
    printf("Underflow (INT_MIN - 1): %d\n", underflow);
}


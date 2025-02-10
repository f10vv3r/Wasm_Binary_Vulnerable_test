#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
void buffer_overflow(char* input) {
    printf("wasm bof test\n");

    char buffer[8];
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


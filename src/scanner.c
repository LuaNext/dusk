#include <stdio.h>
#include <stdlib.h>

FILE* file;
char character;

int scanner_open(char* filename) {
    file = fopen(filename, "r");

    if (file == NULL) {
        return 0;
    }

    return 1;
}

char scanner_consume() {
    character = fgetc(file);
    return character;
}

int scanner_eof() {
    if (character != EOF) {
        return 0;
    }

    return 1;
}

void scanner_close() {
    fclose(file);
}
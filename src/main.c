#include <stdio.h>
#include <string.h>

#include "include/scanner.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: dusk <file> [options]\n");
        printf("       Run the dusk interpreter\n");
        printf("       on a bytecode file.\n");
        printf("Options:\n");
        printf("       -j, --jit\n");
        printf("       Run file using JIT compilation.\n");
        printf("       -v, --version\n");
        printf("       Check the version of dusk.\n");
    } else {
        int jit = 0;
        char* file;

        for (int i = 0; i < argc; i++) {
            char* arg = argv[i];
            
            if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0) {
                printf("dusk v1.0.0-alpha\n");
                return 0;
            } else if (strcmp(arg, "-j") == 0 || strcmp(arg, "--jit") == 0) {
                jit = 1;
            } else {
                file = arg;
            }
        }

        int canOpen = scanner_open(file);
        if (canOpen == 0) {
            printf("DUSK ERROR: ");
            printf("Could not open file \"%s\".\n", file);
            return 1;
        }


        if (jit == 1) {

        } else {

        }
    }

    return 0;
}
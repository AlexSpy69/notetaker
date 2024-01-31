#include <stdio.h>
#include <textcolors.h>

void redtext() {
    printf("\033[1;31m");
}

void greentext() {
    printf("\033[0;32m");
}

void bluetext() {
    printf("\033[0;34m");
}

void normaltext() {
    printf("\033[0m");
}

#include <stdio.h>
#include <string.h>
#include "../include/files.h"

void showmanual();

int main(int argc, char* argv[]) {
    if (argc==1) {
        redtext();
        printf("No arguments given\n");
        showmanual();
    }
    else {
        if (strcmp(argv[1], "create") == 0) {
            ncreate(argv[2]);
        }
        else if (strcmp(argv[1], "read") == 0) {
            nread(argv[2]);
        }
        else if (strcmp(argv[1], "write") == 0) {
            nwrite(argv[2]);
        }
        else if (strcmp(argv[1], "truncate") == 0) {
            ntruncate(argv[2]);
        }
        else if (strcmp(argv[1], "delete") == 0) {
            ndelete(argv[2]);
        }
        else {
            redtext();
            printf("Wrong arguments given\n");
            showmanual();
        }
        normaltext();
    }
    
    return 0;
}

void showmanual() {
    normaltext();
    printf("\nNOTE TAKER\n\n");
    printf("notetaker create *name*\n");
    printf("notetaker read *name*\n");
    printf("notetaker write *name*\n");
    printf("notetaker truncate *name*\n");
    printf("notetaker delete *name*\n");
}

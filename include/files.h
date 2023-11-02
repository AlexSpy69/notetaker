#include <stdio.h>
#include <stdlib.h>
#include <textcolors.h>

void ncreate(char filename[]) {
    FILE * fPtr;
    fPtr = fopen(filename, "w");
    if (fPtr == NULL) {
        redtext();
        printf("File could not be created.\n");
        normaltext();
        exit(EXIT_FAILURE);
    }
    greentext();
    printf("File created: %s\n", filename);
    fclose(fPtr);
}

void nread(char filename[]) {
    bluetext();
    printf("%s\n", filename);
    normaltext();
    FILE * fPtr;
    fPtr = fopen(filename, "r");
    if (fPtr == NULL) {
        redtext();
        printf("File could not be opened.\n");
        normaltext();
        exit(EXIT_FAILURE);
    }
    char ch;
    do {
        ch = fgetc(fPtr);
        printf("%c", ch);
    } while (ch != EOF);
    printf("\n");
    fclose(fPtr);
}

void nwrite(char filename[]) {
    bluetext();
    printf("%s\n", filename);
    normaltext();
    FILE * fPtr;
    fPtr = fopen(filename, "w");
    if (fPtr == NULL) {
        redtext();
        printf("File could not be opened.\n");
        normaltext();
        exit(EXIT_FAILURE);
    }
    char ch[256];
    fgets(ch, sizeof(ch), stdin);
    int i;
    for (i=1; i>sizeof(ch); i++) {
        printf("%c", ch[i]);
    }

    fprintf(fPtr, ch);

    greentext();
    printf("File written\n");
    fclose(fPtr);
}

void ntruncate(char filename[]) {
    FILE * fPtr;
    fPtr = fopen(filename, "w");
    if (fPtr == NULL) {
        redtext();
        printf("File could not be opened.\n");
        normaltext();
        exit(EXIT_FAILURE);
    }
    fprintf(fPtr, "");

    greentext();
    printf("File truncated\n");
    fclose(fPtr);
}

void ndelete(char filename[]) {
    int status = remove(filename);
    if (status != 0) {
        redtext();
        printf("File could not be removed.\n");
        normaltext();
        exit(EXIT_FAILURE);
    }

    greentext();
    printf("File removed\n");
}

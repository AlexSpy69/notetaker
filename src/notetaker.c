#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#include <files.h>
#include <stringcmp.h>

void nshowall();
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
        else if (strcmp(argv[1], "showall") == 0) {
            nshowall();
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

void nshowall() {
    char cwd[256];
    getcwd(cwd, sizeof(cwd));
    bluetext();
    printf("Current working directory: %s\n", cwd);
    normaltext();
    DIR *d;
    struct dirent *dir;
    d = opendir(cwd);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

void showmanual() {
    normaltext();
    printf("\nNOTE TAKER\n\n");
    printf("notetaker create *name*\n");
    printf("notetaker read *name*\n");
    printf("notetaker write *name*\n");
    printf("notetaker truncate *name*\n");
    printf("notetaker delete *name*\n");
    printf("notetaker showall\n");
}

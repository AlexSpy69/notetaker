#include <string.h>
#include <stringcmp.h>

int prefix(const char *pre, const char *str) {
    return strncmp(pre, str, strlen(pre)) == 0;
}
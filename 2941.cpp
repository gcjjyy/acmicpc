#include <stdio.h>

char W[101];

int main() {
    int len = 0;
    int found = 0;

    scanf("%s", W);

    char *p = W;
    while(*p) {
        if(*p == '=' && *(p-1) == 'z' && *(p-2) == 'd') {
            found += 2;
        }
        else if(*p == '=' || *p == '-') {
            found++;
        }
        else if(*p == 'j' && (*(p-1) == 'l' || *(p-1) == 'n')) {
            found++;
        }

        len++;
        p++;
    }

    printf("%d\n", len - found);

    return 0;
}
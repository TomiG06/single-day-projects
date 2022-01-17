#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii(char c) {
    return (int) "%d", c;
}

#define MIN ascii('a')-1
#define MAX MIN + 26
#define ROT 13
//Works for ROT in {0,...,26}

int main() {
    char txt[100];
    printf("Enter word in lowercase: ");
    scanf("%s", txt);
    for(int x = 0; x < strlen(txt); ++x) {
        int ascval = ascii(txt[x]);
        if(ascval <= MAX-ROT) {
            printf("%c", ascval + ROT);
        } else {
            printf("%c", ascval - 26 + ROT);
        }
    }
    printf("\n");
    return 0;
}

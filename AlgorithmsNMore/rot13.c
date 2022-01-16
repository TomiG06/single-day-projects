#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii(char c) {
    return (int) "%d", c;
}

#define MIN ascii('a')
#define MAX MIN + 25
#define ROT 13

int main() {
    char txt[100];
    printf("Enter word in lowercase: ");
    scanf("%s", txt);
    
    for(int x = 0; x < strlen(txt); ++x) {
        int ascval = ascii(txt[x]);
        if(ascval <= MIN + 12) {
            printf("%c", ascval + 13);
        } else {
            printf("%c", ascval-13);
        }
    }
    printf("\n");
    return 0;
}

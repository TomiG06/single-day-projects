//Works for ROT in {0,...,26}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN1 'a'-1
#define MAX1 MIN1 + 26

#define MIN2 'A'-1
#define MAX2 MIN2 + 26


char rotate(char c, int rot) {
    if(!((MIN1 < c && c < MAX1) || (MIN2 < c && c < MAX1))) return c;

    if(c <= MAX1-rot || c <= MAX2-rot) return c + rot;
    
    return c - 26 + rot;
}

int main(int argc, char* argv[]) {
    int rot = atoi(argv[1]);
    for(int x = 0; x < strlen(argv[2]); ++x) {
        putchar(rotate(argv[2][x], rot));
    }
    putchar(10);
    return 0;
}

#ifndef ROD_H
#define ROD_H

#define MAX 64
//Like a stack
typedef struct rod {
    char stack[MAX];
    char TOP;
} rod;

void push(rod* r, char disk);
char pop(rod* r);
char peek(rod* r);
char is_empty(rod* r);
rod init_rod();

#endif

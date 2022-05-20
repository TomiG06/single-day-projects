#include <stdlib.h>
#include "rod.h"

char is_empty(rod* r) { return r->TOP == -1; }

void push(rod* r, char disk) { r->stack[++r->TOP] = disk; }

char pop(rod* r) {
    char ret = 0;
    if(!is_empty(r)) {
        ret = r->stack[r->TOP];
        r->stack[r->TOP--] = 0;
    }
    return ret;
}

char peek(rod* r) { return r->TOP != -1 ? r->stack[r->TOP]: 0; }

rod init_rod() {
    rod r;
    r.TOP = -1;
    return r;
}


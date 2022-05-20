#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "rod.h"

enum {
    FAIL = 0,
    SUCCESS,
    NOT_FOUND
};

rod* setup(char max);
char take_positions_and_validate();
char make_slide(rod* rods);
char check_if_win(rod* rods, int max);

#endif

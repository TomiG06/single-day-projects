#include <stdlib.h>
#include <stdio.h>
#include "rod.h"
#include "gameplay.h"

static int positions[2] = {-1, -1};

char is_valid_rod() {
    char f = 0, t = 0;
    if(positions[0] == positions[1]) goto finish_is_valid_rod;
    for(int i = 0; i < 3; i++) {
        if(positions[0] == i) f = 1;
        if(positions[1] == i) t = 1;
    }

finish_is_valid_rod:
    return f & t;
}

char take_positions_and_validate() {

    printf("\nFrom: ");
    scanf("%d", &positions[0]);
    printf("To: ");
    scanf("%d", &positions[1]);

    positions[0]--;
    positions[1]--;

    if(!is_valid_rod()) return FAIL;

    return SUCCESS;
}

char make_slide(rod* rods) {
    char disk = peek(&rods[positions[0]]);
    if(!disk) return NOT_FOUND;

    char bottom = peek(&rods[positions[1]]);
    if(bottom < disk && bottom) return FAIL;

    pop(&rods[positions[0]]);
    push(&rods[positions[1]], disk);

    return SUCCESS;
}

char check_if_win(rod* rods, int max) {
    if(rods[2].stack[0] == max && rods[2].stack[max-1] == 1) return 1;
    return 0;
}

rod* setup(char max) {
    static rod rods[3];

    for(int i = 0; i < 3; i++) {
        rods[i] = init_rod();

        for(char j = max; j > 0; j--) {
            if(i) rods[i].stack[j] = 0;
            else push(&rods[i], j);
        }
    }

    return rods;
}

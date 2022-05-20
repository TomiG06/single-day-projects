//https://en.wikipedia.org/wiki/Tower_of_Hanoi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rod.h"
#include "gameplay.h"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: th [disk amount]\n");
        return 1;
    }
    int max = atoi(argv[1]);

    if(max < 1 || max > MAX) {
        printf("Must 0 < disk amount < %d\n", MAX);
        return 1;
    }

    rod* rods = setup(max);
    int input, slide;
    int round = 0;
    int round_to_start_checking = pow(2, max) - 1;
    
    while(1) {
        for(int i = max-1; i > -1; i--) {
            printf("%3.0d %3.0d %3.0d\n", rods[0].stack[i], rods[1].stack[i], rods[2].stack[i]);
        }
        printf("------------\n%3d %3d %3d\n", 1, 2, 3);

        if(round_to_start_checking <= round && check_if_win(rods, max)) {
            printf("Conrgatulations, you win!\n");
            break;
        }

        while(1) {
            while((input = take_positions_and_validate()) != SUCCESS) printf("Either a given position is invalid or both positions are the same\nReenter positions\n");
            slide = make_slide(rods);
            if(slide == FAIL) {
                printf("Either the given disk is bigger than the top of the destination or there is no disk in the given position\nReenter positions\n");
                continue;
            } else if(slide == NOT_FOUND) {
                printf("There is no disk in the given position\nReenter positions\n");
                continue;
            }
            
            round++;
            break;
        }
        system("clear");

    }

    return 0;
}

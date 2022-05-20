#include <stdio.h>
#include <stdlib.h>

char win(short* board) {
    for(int x = 0; x < 9; x+=3) if(board[x] && board[x] == board[x+1] && board[x] == board[x+2]) return board[x];
    for(int x = 0; x < 3; ++x)  if(board[x] && board[x] == board[x+3] && board[x] == board[x+6]) return board[x];
    if(board[0] && board[0] == board[4] && board[0] == board[8]) return board[0];
    if(board[2] && board[2] == board[4] && board[2] == board[6]) return board[0];
    return 0;
}

void check(short* board) {
    char status = win(board);
    if(status) {
        printf("Player%d wins!\n", status);
        goto departure;
    }
    for(char x = 0; x<9; ++x) {
        if(x < 8 && !board[x]) return;
        if(x == 8 && board[x]) {
            printf("Tie\n");
            goto departure;
        }
    }
departure:
    free(board);
    exit(0); 
}

char place(short* board, int pl, int pos) {
    if(pos < 0 || pos > 8) return 2;
    if(board[pos]) return 0;
    board[pos] = pl;
    return 1;
}

void display(short* board) {
    printf("%d|%d|%d\n-----\n%d|%d|%d\n-----\n%d|%d|%d\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

void init(short* board, char p) {
    system("clear");
    display(board);
    char pc;
    int in;
    char* msg = (p == 1) ? "Player1: " : "Player2: ";
    while(1) {
        printf("%s", msg);
        scanf("%d", &in);
        pc = place(board, p, in-1);
        if(!pc) printf("Position already taken\n");
        else if(!pc&1) printf("Invalid position\n");
        else break;
    }
    check(board);
}

int main() {
    short* board = (short*) calloc(9, 2);
    while(1) {
        init(board, 1);
        init(board, 2);
    }
}

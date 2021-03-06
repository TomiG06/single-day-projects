#include <stdio.h>
#include <stdlib.h>

//Sieve of Eratosthenes (But in C)
//creates an array where non zero elements are prime numbers

int main(int argc, char* argv[]){
    if(argc == 1) exit(1);
    int limit = atoi(argv[1]);
    int len = limit-2;
    int* range = (int*) malloc(len*sizeof(int));
    for(int i = 0; i<len; ++i) range[i] = i+2;
    for(int x = 0; x<len; ++x) {
        int num = range[x];
        if(num*num > limit) break;
        if(num == 0) continue;
        for(int y=num-2; y<len; y+=num) if(num!=range[y]) range[y] = 0;
    }
    for(int x=0; x<len; ++x) if(range[x]!=0) printf("%d\n", range[x]);
    free(range);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//Sieve of Eratosthenes (But in C)
//loops and prints through a list of numbers where non zero elements are prime

int main() {
        int limit;
        printf("Limit: ");
        scanf("%d", &limit);
        int len = limit-2;
        int* range = (int*) malloc(len*sizeof(int));
	for(int i; i<len; ++i) {
		range[i] = i+2;
	}

        for(int x = 0; x<len; ++x) {
                int num = range[x];
                if(num*num > limit) {
                        break;
                }
                if(num == 0) {
                        continue;
                }
                for(int y=0; y<len; ++y) {
                        if(range[y]%num == 0 && range[y] != num) {
                                range[y] = 0;
                        }
                }
        }
        for(int x=0; x<len; ++x) {
                printf("%d\n", range[x]);
        }
        free(range);
        return 0;
}

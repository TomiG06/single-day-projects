#include <stdio.h>

int main() {
	int num1 = 0;
	int num2 = 1;
	int n, newnum;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("%d %d ", num1, num2);
	for(int x = 0; x < n; x++) {
		newnum = num1 + num2;
		num1 = num2;
		num2 = newnum;
		printf("%d ", num2);
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

struct Stack {
	int stack[MAX];
	int TOP;
}s;

int peek(struct Stack s) {
	if(s.TOP>-1) { return s.stack[s.TOP]; }
       	else { return -1; }
}


int isFull(struct Stack s) {
	return s.TOP==MAX-1;
}

int isEmpty(struct Stack s) {
	return s.TOP == -1;
}

int pop(struct Stack *s) {
	if(!(s->TOP==-1)) {
		s->stack[s->TOP] = 0;
		s->TOP--;
		return 1;
	} else {
		return 0;
	}
}

int push(struct Stack * s, int element) {
	if(s->TOP<MAX-1) {
		s->TOP += 1;
		s->stack[s->TOP] = element;
		return 1;
	} else {
		return 0;
	}
}

int main() {
	s.TOP = -1;
	printf("isEmpty: %d\n", isEmpty(s));
	push(&s, 12);
	push(&s, 14);
	push(&s, 15);
	printf("isFull: %d\n", isFull(s));
	printf("peek: %d\n", peek(s));
	pop(&s);
	printf("Popped: %d\n", peek(s));
	return 0;
}

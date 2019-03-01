// applied_math_lab_1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "malloc.h"
unsigned int *fib_gen(unsigned int x_next,unsigned int x_prev, unsigned int m,unsigned int count) {
	unsigned int *storage;
	if ((storage = (unsigned int*)malloc(count * sizeof(unsigned int))) != NULL) {
		unsigned int element;
		storage[0] = x_prev;
		storage[1] = x_next;
		for (int i = 0; i < count-2; i++) {
			element = (storage[i+1]+storage[i]) % m;
			storage[i + 2] = element;
			printf("%d\n", element);
		}
		return storage;
	}
	else {
		printf("Out of memory!\n");
	}
};
unsigned int *lkg(unsigned int a,unsigned int x, unsigned int c, unsigned int m, unsigned int count) {
	unsigned int *storage;
	if ((storage = (unsigned int*)malloc(count * sizeof(unsigned int))) != NULL) {
		unsigned int element;
		storage[0] = x;
		for (int i = 0; i < count - 1; i++) {
			element = (a*storage[i]+c) % m;
			storage[i + 1] = element;
			printf("%d\n", element);
		}
		return storage;
	}
	else {
		printf("Out of memory!\n");
	}
};
void normalize(unsigned int *selection) {
};
int main()
{
	unsigned int *selection;
    return 0;
}


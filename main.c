// generator.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include "malloc.h"
#define OUTPUTFILE "OUTPUT.csv"
#define MAXINT 2147483647	// 2^31 - 1
int *fib_gen(int x_next, int x_prev,int m, int length) {
	int *storage;
	if ((storage = (int*)malloc(length * sizeof(int))) != NULL) {
		int element;
		storage[0] = x_prev;
		storage[1] = x_next;
		for (int i = 0; i < length - 2; i++) {
			// (a + b) mod n = [(a mod n) + (b mod n)] mod n
			int sum = (storage[i] % m) + (storage[i + 1] % m);
			if (sum < 0) {
				sum += (MAXINT + 1);
			}
			element = sum%m;
			storage[i + 2] = element; 
		}
		return storage;
	}
	else {
		printf("Out of memory!\n");
	}
};
float *normalize(int *selection, int m, int length) {
	float *normalize_selection;
	if ((normalize_selection = (float*)malloc(length * sizeof(float))) != NULL) {
		for (int i = 0; i < length; i++) {
			printf("%d\n", selection[i]);
			normalize_selection[i] = ((float) selection[i]) / m;
			printf("%d\n", normalize_selection[i]);
		}
		return normalize_selection;
	}
};
int main()
{
	int *selection = fib_gen(11, 56, MAXINT, 500);
	/*for (int i = 1;i<500;i++) {
		if (selection[0] == selection[i]) printf("T=%d", i);
		printf("%d\n",selection[i]);
	}*/
	float *normalize_selection = normalize(&selection[0], MAXINT, 500);
	/*for (int i = 1; i<500; i++) {
		if (normalize_selection[0] == normalize_selection[i]) printf("T=%d", i);
		printf("%d\n", normalize_selection[i]);
	}*/
	return 0;
}

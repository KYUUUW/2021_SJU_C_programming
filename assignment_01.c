#include<stdio.h>
#include<math.h>
#pragma warning(disable: 4996)

int* MAX(int* ar);
int* MIN(int* ar);

void main() {
	int N;
	int ar[100];
	int i;
	int* p;
	int* a,* b, *tmp;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (p = ar; *(p - 1) != 0; p++) {
			scanf("%d", p);
		}
		a = MAX(ar);
		b = MIN(ar);
		if (b < a) {
			tmp = a;
			a = b;
			b = tmp;
		}
		if (a + 1 >= b) {
			printf("none");
		}
		else {
			for (p = a + 1; p < b-1; p++) {
				printf("%d ", *p);
			}
			printf("%d", *p);
		}
		printf("\n");
	}
}

int* MAX(int* ar) {
	int* p;
	int* max = ar;

	for (p = ar; *p != 0; p++) {
		if (*max < *p) {
			max = p;
		}
	}

	return max;
}

int* MIN(int* ar) {
	int* p;
	int* min = ar;

	for (p = ar; *p != 0; p++) {
		if (*min > *p) {
			min = p;
		}
	}

	return min;
}

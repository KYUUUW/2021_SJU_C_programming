#include<stdio.h>
#pragma warning(disable: 4996)

typedef struct complex {
	double r;
	double i;
}COMPLEX;

COMPLEX add_complex(COMPLEX a, COMPLEX b) {
	COMPLEX r = { a.r + b.r, a.i + b.i };
	return r;
}

void example11_06() {
	COMPLEX a, b, r;

	scanf("%lf %lf", &a.r, &a.i);
	scanf("%lf %lf", &b.r, &b.i);

	r = add_complex(a, b);
	printf("%.1lf %.1lf", r.r, r.i);
}

COMPLEX* larger_complex(COMPLEX* a, COMPLEX* b) {
	double abs_a, abs_b;

	abs_a = a->r * a->r + a->i * a->i;
	abs_b = b->r * b->r + b->i * b->i;
	return abs_a > abs_b ? a : b;
}


void example11_07() {
	COMPLEX a, b;
	COMPLEX* r;

	scanf("%lf %lf", &a.r, &a.i);
	scanf("%lf %lf", &b.r, &b.i);

	r = larger_complex(&a, &b);
	printf("%.1lf %.1lf", r->r, r->i);
}

void main() {
	typedef struct d {
		int m;
		int d1;
		int d2;
		int d3;
		int b;
	} DISH;
	int i;

	DISH d[2];

	for (i = 0; i < 2; i++) {
		scanf("%d %d %d %d %d", &d[i].m, &d[i].d1, &d[i].d2, &d[i].d3, &d[i].b);
	}

	for (i = 0; i < 2; i++) {
		printf("%d\n%d\n%d\n%d\n%d\n", d[i].m, d[i].d1, d[i].d2, d[i].d3, d[i].b);
	}
}
#include<stdio.h>
#include<math.h>
#pragma warning(disable: 4996)

void input(int* ar, int N) {
	int* p;

	for (p = ar; p < ar + N; p++) {
		scanf("%d", p);
	}
}

int* diff(int* ar, int N) {
	int* g = ar, *p;
	int max = 0, tmp;

	for (p = ar + 1; p < ar + N; p++) {
		tmp = (*(p-1) - *p) * (*(p - 1) - *p);
		
		if (tmp > max) {
			max = tmp;
			g = p;
		}
	}

	return g;
}

void question01() {
	int N, ar[100];
	int* g;

	scanf("%d", &N);
	input(ar, N);

	g = diff(ar, N);
	printf("%d %d", *(g - 1), *g);
}

void sort(int N, int id[], double avg[]) {
	int i, j;
	double* a, * b;
	double dTmp;
	int iTmp;

	for (i = 0; i < N -1; i++) {
		for (j = 0; j < N - 1; j++) {
			a = avg + j;
			b = avg + j + 1;
			if (*a < *b) {
				dTmp = *a;
				*a = *b;
				*b = dTmp;

				iTmp = *(id + j);
				*(id + j) = *(id + j + 1);
				*(id + j + 1) = iTmp;
			}
		}
	} 
}

void question02() {
	int arrId[100], arrKor[100], arrMath[100];
	double arrAvg[100];
	int i, N;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d %d", arrId + i, arrKor + i, arrMath + i);
		*(arrAvg + i) = (*(arrKor + i) + *(arrMath + i)) / 2;
	}

	sort(N, arrId, arrAvg);

	for (i = 0; i < 3; i++) {
		printf("%d %.1f\n", arrId[i], arrAvg[i]);
	}
}

void test_sort() {
	int i;
	int ids[3] = { 1, 2, 3 };
	double avg[3] = { 90.0, 70.0, 80.0 };

	sort(3, ids, avg);

	for (i = 0; i < 3; i++) {
		printf("%d %.1f\n", ids[i], avg[i]);
	}
}

void main() {
	question02();
}

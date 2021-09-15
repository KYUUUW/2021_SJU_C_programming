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

	for (i = 0; i < N; i++) {
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
		*(arrAvg + i) = (double) (*(arrKor + i) + *(arrMath + i)) / 2.0;
	}

	sort(N, arrId, arrAvg);

	for (i = 0; i < N; i++) {
		printf("%d %.1f\n", *(arrId + i), *(arrAvg + i));
	}
}

void test_sort() {
	int i;
	int ids[6] = { 1, 2, 3, 4, 5, 6 };
	double avg[6] = { 90.0, 70.0, 80.0, 10.0, 20.0, 100.0 };

	sort(6, ids, avg);

	for (i = 0; i < 6; i++) {
		printf("%d %.1f\n", ids[i], avg[i]);
	}
}

// quesion 03

void eliminate(char *ar) {
	char * q, * p, * r = ar;
	char isSame;
	char tmp;

	p = ar;
	while(*p != '*') {
		isSame = *p;
		q = p + 1;
		// find same char
		while(*q != '*') {
			if(*q == isSame) {
				// slash
				r = q;
				while(*r != '*') {
					*r = *(r + 1);
					r++;
				}
 			}
			else {
				q++;
			}
		}
		p++;
	}
}

void question03() {
	char ar[101];
	char *p;

	p = ar;
	do {
		scanf("%c", p);
		p++;
	} while(*(p - 1) != '*');

	eliminate(ar);

	p = ar;
	while(*p != '*') {
		printf("%c", *p);
		p++;
	}

	printf("*\n");
}

void repeat(char *ar, int N) {
	int len = 0, i, j;
	char *p, *q;

	// 길이재기
	p = ar;
	len = 0;
	for(p = ar; *p != '*'; p++) {
		len++;
	}

	p = ar;
	for(i = 0; i < len; i++) {
		for(j = 1; j < N; j++) {
			*(p + i + (len * j)) = *(p + i);
		}
	}

	*(ar + (len * N)) = '*';
	*(ar + (len * N) + 1) = '\0';
}

void question04() {
	char ar[101];
	char *p;
	int N;

	scanf("%s", ar);
	scanf("%d", &N);

	repeat(ar, N);

	printf("%s", ar);
}

void print(char* str, int len) {
	char* p;

	for(p = str; p < str + len ; p++) {
		if(*p >= 'a' && *p <= 'z') {
			printf("%c", *p + ('A' - 'a'));
		}
		else {
			printf("%c", *p);
		}
	}
}

void question05() {
	char str[101], *p;

	char* word;
	int len, max;

	scanf("%[^\n]s", str);
	// printf("%s", str);

	len = max = 0;
	for(p = str; *p != '*'; p++) {
		if(*p != ' ') {
			len++;
		}
		else {
			if(max < len) {
				max = len;
				word = p - len;
			}
			printf("%d\n", len);
			len = 0;
		}
	}
	if(max < len) {
		max = len;
		word = p - len;
	}
	printf("%d\n", len);

	print(word, max);
}

int main() {
	question05();
}

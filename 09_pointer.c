#include<stdio.h>
#pragma warning(disable: 4996)

void question01() {
	int x, y, z;
	int* px, * py, * pz, *tmp;
	
	px = &x, py = &y, pz = &z;

	scanf("%d %d %d", px, py, pz);

	tmp = px;
	px = pz;
	pz = py;
	py = tmp;

	printf("%d %d %d", *px, *py, *pz);
}

void question02() {
	int i;
	char ch[20];

	scanf("%s", ch);

	for (i = 0; i < 20; i++) {
		if (*(ch + i) == '#') {
			for (--i; i >= 0; i--) {
				printf("%c", *(ch + i));
			}
			break;
		}
	}
};

void question03() {
	int ar[50] = { 0 }, N;
	int cnt = 0;
	int* p, *tmp;

	scanf("%d", &N);

	for (p = ar; p < ar + N; p++)
		scanf("%d", p);

	for (p = ar; p < ar + N; p++)
		if (*p == 0) {
			printf("%d", cnt);
			break;
		}
		else {
			cnt++;
		}
}

void question04() {
	int x[3];
	int i, tmp;
	int* p;

	for (p = x; p < x + 3; p++)
		scanf("%d", p);

	for (p = x; p < x + 2; p++) {
		if (*p > *(p + 1)) {
			tmp = *p;
			*p = *(p + 1);
			*(p + 1) = tmp;
		}
	}

	for (p = x; p < x + 2; p++) {
		if (*p > *(p + 1)) {
			tmp = *p;
			*p = *(p + 1);
			*(p + 1) = tmp;
		}
	}

	printf("%d", *(x+1));
}

void question05() {
	int ar[5];
	int* p, *q;
	int cnt;


	for (p = ar; p < ar + 5; p++) {
		scanf("%d", p);
	}

	for (p = ar; p < ar+5; p++) {
		cnt = 0;
		for (q = ar; q < ar + 5; q++) {
			if (*p < *q) {
				cnt++;
			}
		}
		printf("%d=r%d ", *p, cnt+1);
	}
	
}

void question06() {
	char ar[11];
	char* p, * q;
	int cnt;
	int maxCnt = 0;
	char freqChr, metric;


	scanf("%s", ar);

	for (p = ar; p < ar + 10; p++) {
		cnt = 0;
		metric = *p;

		for (q = ar; q < ar + 10; q++) {
			if (metric == *q) {
				cnt++;
			}
		}

		if (maxCnt < cnt) {
			maxCnt = cnt;
			freqChr = metric;
		}
	}

	printf("%c %d", freqChr, maxCnt);
}

void input(int* a, int* b, int* c) {
	scanf("%d %d %d", a, b, c);
}

void output(int* a, int* b, int* c) {
	printf("%d %d %d", *a, *b, *c);
}

void question07() {
	int x, y, z;
	input(&x, &y, &z);
	output(&x, &y, &z);
}

void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void question08() {
	int i, n;
	int *p;
	int ar[50];
	int a, b;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}

	scanf("%d %d", &a, &b);

	swap(&ar[a], &ar[b]);

	for (i = 0; i < n; i++) {
		printf(" %d", ar[i]);
	}
}

int* mid(int* ar) {
	int i;
	int min, max;

	if ((*ar >= *(ar + 1) && *(ar + 1) >= *(ar + 2)) 
		|| (*ar <= *(ar + 1) && *(ar + 1) <= *(ar + 2))) {
		return ar + 1;
	}
	else if ((*(ar + 1) >= *(ar + 2) && *(ar + 2) >= *ar) 
		|| (*(ar + 1) <= *(ar + 2) && *(ar + 2) <= *ar)) {
		return ar + 2;
	}
	else {
		return ar;
	}
} 

void question09() {
	int *p;
	int ar[3];
	for (p = ar; p < (ar + 3); p++) {
		scanf("%d", p);
	}

	printf("%d", *mid(ar));

}

void gcdlcm(int x, int y, int* gcm, int* lcm) {
	int tmp, large, small;

	if (x > y) {
		large = x;
		small = y;
	}
	else {
		large = y;
		small = x;
	}

	tmp = large;
	while (tmp % x != 0 || tmp % y != 0) {
		tmp++;
	}
	*gcm = tmp;

	tmp = small;
	while (x % tmp != 0 || y % tmp != 0) {
		tmp--;
	}
	*lcm = tmp;
}

void question10() {
	int x, y;
	int lcm, gcd;

	scanf("%d %d", &x, &y);
	gcdlcm(x, y, &gcd, &lcm);

	printf("%d %d", lcm, gcd);
}

void strcopy(char* a, char* b) {
	int i;

	for (i = 0; i < 7; i++) {
		*(b + i) = *(a + i);
	}
}

void question11() {
	char a[7], b[7];
	scanf("%s", a);
	strcopy(a, b);

	printf("%s", b);
}

void addArrray(int *a, int *b, int *c, int n) {
	int i;

	for (i = 0; i < n; i++) {
		*(c + i) = *(a + i) + *(b + n - 1 - i);
	}
}

void question12() {
	int a[20], b[20], c[20];
	int *p, n;

	scanf("%d", &n);

	for (p = a; p < a + n; p++) {
		scanf("%d", p);
	}

	for (p = b; p < b + n; p++) {
		scanf("%d", p);
	}
	
	addArrray(a, b, c, n);

	for (p = c; p < c + n; p++) {
		printf(" %d", *p);
	}
}

int arrsum(int* s, int* e) {
	int* p;
	int sum = 0;

	for (p = s; p <= e; p++) {
		sum += *p;
	}

	return sum;
}

void question13() {
	int n, s, e;
	int* p;
	int ar[100];

	scanf("%d %d %d", &n, &s, &e);

	for (p = ar; p < ar + n; p++) {
		scanf("%d", p);
	}

	printf("%d", arrsum(ar + s, ar + e));
}

int add_to_k(int* s, int* e) {
	int* p;
	int sum = 0;

	for (p = s; p <= e; p++) {
		sum += *p;
	}

	return sum;
}

void question14() {
	int n, sum;
	int d[100];
	int* p;

	scanf("%d", &n);

	sum = 0;
	for (p = d; p < d + n; p++) {
		scanf("%d", p);
		sum += add_to_k(d, p);
	}

	printf("%d", sum);
}

void ABC(int* s, int k) {
	int i, tmp;
	int max = *s;
	int maxIdx = 0;

	for (i = 0; i < k; i++) {
		if (max < *(s + i)) {
			max = *(s + i);
			maxIdx = i;
		}
	}

	tmp = *s;
	*s = max;
	*(s + maxIdx) = tmp;
}


void question15() {
	int arr[10], i;
	int* p;

	for (p = arr; p < arr + 10; p++) {
		scanf("%d", p);
	}

	for (i = 10; i >= 2; i--) {
		ABC(arr + 10 - i, i);
	}


	for (p = arr; p < arr + 10; p++) {
		printf(" %d", *p);
	}
}

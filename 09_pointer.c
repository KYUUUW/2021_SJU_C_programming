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

}

void main() {
	question04();
}
#include<stdio.h>
#include<limits.h>
#pragma warning(disable: 4996)

void q01() {
	typedef struct vector {
		int x;
		int y;
		int z;
	} v;

	v v1, v2;
	scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
	scanf("%d %d %d", &v2.x, &v2.y, &v2.z);

	printf("%d %d %d\n", v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
	printf("%d", v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

void q02() {
	typedef struct time {
		int h;
		int m;
		int s;
	} T;

	T t1, t2;
	T r = { 0, 0, 0 };
	int delta;

	scanf("%d %d %d", &t2.h, &t2.m, &t2.s);
	scanf("%d %d %d", &t1.h, &t1.m, &t1.s);

	r.h = t1.h - t2.h;

	delta = t1.m - t2.m;
	if (delta < 0) {
		r.h -= 1;
		r.m = 60 + delta;
	}
	else {
		r.m = delta;
	}

	delta = t1.s - t2.s;
	if (delta < 0) {
		r.m -= 1;
		r.s = 60 + delta;
	}
	else {
		r.s = delta;
	}

	printf("%d %d %d", r.h, r.m, r.s);
}

void q03() {
	int i, sum;
	double avg;

	typedef struct student {
		char name[10];
		int score;
	} S;

	S s[5];

	sum = 0;
	for (i = 0; i < 5; i++) {
		scanf("%s %d", s[i].name, &s[i].score);
		sum += s[i].score;
	}
	avg = sum / 5.0;

	for (i = 0; i < 5; i++) {
		if ((double)s[i].score >= avg) {
			continue;
		}
		printf("%s\n", s[i].name);
	}
}

void q04() {
	int i, N;
	int score[3];
	typedef struct student {
		char name[20];
		double avg;
		char grd;
	} S;

	S s[20];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s %d %d %d", s[i].name, &score[0], &score[1], &score[2]);
		s[i].avg = (double)(score[0] + score[1] + score[2]) / 3.0;

		if (s[i].avg >= 90) {
			s[i].grd = 'A';
		}
		else if (s[i].avg >= 80) {
			s[i].grd = 'B';
		}
		else if (s[i].avg >= 70) {
			s[i].grd = 'C';
		}
		else {
			s[i].grd = 'F';
		}
	}
	for (i = 0; i < N; i++) {
		printf("%s %.1f %c\n", s[i].name, s[i].avg, s[i].grd);
	}
}

void q05() {
	int i, N;
	int score[3];
	typedef struct student {
		char name[10];
		double avg;
		char grd;
	} S;
	S* p;

	S s[50];

	scanf("%d", &N);


	for (p = s; p < s + N; p++) {
		scanf("%s %d %d %d", p->name, &score[0], &score[1], &score[2]);
		p->avg = (double)(score[0] + score[1] + score[2]) / 3.0;

		if (p->avg >= 90) {
			p->grd = 'A';
		}
		else if (p->avg >= 80) {
			p->grd = 'B';
		}
		else if (p->avg >= 70) {
			p->grd = 'C';
		}
		else {
			p->grd = 'D';
		}
	}
	for (p = s; p < s + N; p++) {
		printf("%s %.1f %c\n", p->name, p->avg, p->grd);
	}
}

void q06() {
	
	int i, n;
	typedef  struct student {
		int s;
		int w;
		int h;
	} S;
	int sum[4] = { 0 };

	S s[10];
	S* p;
	scanf("%d", &n);

	for (p = s; p < s + n; p++) {
		scanf("%d %d %d", &p->s, &p->w, &p->h);

		if (p->s == 1) { // 남성
			if (p->h < 165) { // 남성 키
				if (p->w < 60) { // 남성 키 무게
					sum[1]++;
				}
				else if(p->w < 70) {
					sum[3]++;
				}
				else {
					sum[2]++;
				}
			}
			else if (p->h < 175) {
				if (p->w < 60) { // 남성 키 무게
					sum[2]++;
				}
				else if (p->w < 70) {
					sum[1]++;
				}
				else {
					sum[3]++;
				}
			}
			else {
				if (p->w < 60) { // 남성 키 무게
					sum[3]++;
				}
				else if (p->w < 70) {
					sum[2]++;
				}
				else {
					sum[1]++;
				}
			}
		}
		else {
			if (p->h < 165) { // 여성 키
				if (p->w < 50) { // 여성 키 무게
					sum[1]++;
				}
				else if (p->w < 60) {
					sum[3]++;
				}
				else {
					sum[2]++;
				}
			}
			else if (p->h < 175) {
				if (p->w < 50) { // 여성 키 무게
					sum[2]++;
				}
				else if (p->w < 60) {
					sum[1]++;
				}
				else {
					sum[3]++;
				}
			}
			else {
				if (p->w < 50) { // 여성 키 무게
					sum[3]++;
				}
				else if (p->w < 60) {
					sum[2]++;
				}
				else {
					sum[1]++;
				}
			}
		}
	}

	printf("%d %d %d", sum[1], sum[2], sum[3]);
}

void q07() {
	int ar[10];
	int max;
	int i, j;

	struct node {
		int idx;
		int num;
	};

	struct node n[10];

	for (i = 0; i < 10; i++) {
		scanf("%d", &ar[i]);
	}

	for (i = 0; i < 10; i++) {
		n[i].idx = 0;
		n[i].num = INT_MIN;

		for (j = 0; j < 10; j++) {
			if (n[i].num < ar[j]) {
				n[i].idx = j;
				n[i].num = ar[j];
			}
		}
		ar[n[i].idx] = INT_MIN;
		//printf("\n[%d] [%d]\n", n[i].idx, n[i].num);
	}

	printf("%d %d", n[2].num, n[6].num);
}

typedef struct complex {
	float n;
	float i;
}C;

C add(C c1, C c2) {
	C r = { c1.n + c2.n, c1.i + c2.i };
	return r;
}

void q08() {
	C c1, c2, r;

	scanf("%f %f", &c1.n, &c1.i);
	scanf("%f %f", &c2.n, &c2.i);

	r = add(c1, c2);
	printf("%.1f + %.1fi", r.n, r.i);
}

typedef struct result {
	int top;
	int low;
	int std;
	char pass;
	int diff;
} RESULT;

void passorfail(RESULT *r) {
	r->diff = r->top - r->low;
	if (r->diff <= r->std) {
		r->pass = 'P';
	}
	else {
		r->pass = 'F';
	}
}

void q09() {
	RESULT r;

	scanf("%d %d %d", &r.top, &r.low, &r.std);
	passorfail(&r);
	printf("%d %c", r.diff, r.pass);
}

typedef struct date {
	int y;
	int m;
	int d;
} DATE;

DATE* select_min_date(DATE* d1, DATE* d2) {
	if (d1->y < d2->y) {
		return d1;
	}
	else if (d1->y > d2->y) {
		return d2;
	}

	if (d1->m < d2->m) {
		return d1;
	}
	else if (d1->m > d2->m) {
		return d2;
	}

	if (d1->d < d2->d){
		return d1;
	}
	else {
		return d2;
	}
}

void q10() {
	DATE d1, d2;
	DATE* r;

	scanf("%d/%d/%d", &d1.y, &d1.m, &d1.d);
	scanf("%d/%d/%d", &d2.y, &d2.m, &d2.d);

	r = select_min_date(&d1, &d2);
	printf("%d/%d/%d", r->y, r->m, r->d);
}

typedef struct stScore {
	char name[10];
	int score;
}ST_SCORE;

ST_SCORE* select_min(ST_SCORE* s) {
	ST_SCORE* p;
	ST_SCORE* min;

	min = s;
	for (p = s; p < s + 5; p++) {
		// printf("\n[%d][%d]\n", min->score, s->score);
		if (min->score > p->score) {
			min = p;
		}
	}

	return min;
}

void q11() {
	ST_SCORE s[5];
	ST_SCORE* p, *min;

	for (p = s; p < s + 5; p++) {
		scanf("%s %d", &p->name, &p->score);
	}

	min = select_min(s);

	printf("%s %d", min->name, min->score);
}

typedef struct student {
	char name[10];
	int x;
	int y;
	int z;
	double avg;
} STUDENT;

void read_data(STUDENT* st) {
	int i;

	for (i = 0; i < 10; i++) {
		scanf("%s %d %d %d", &st[i].name, &st[i].x, &st[i].y, &st[i].z);
		st[i].avg = (float)(st[i].x + st[i].y + st[i].z) / 10.0;
	}
}

void calc_avg(STUDENT* st) {
	int i;

	for (i = 0; i < 10; i++) {
		st[i].avg = (float)(st[i].x + st[i].y + st[i].z) / 3.0;
	}
}

void sort(STUDENT* st) {
	STUDENT* p, * q;
	STUDENT* max;
	STUDENT tmp;

	for (p = st; p < st + 10; p++) {
		max = p;
		for (q = p + 1; q < st + 10; q++) {
			if (max->avg < q->avg) {
				max = q;
			}
		}
		tmp = *p;
		*p = *max;
		*max = tmp;
	}
}

void print_score(STUDENT* st) {
	int i;

	sort(st);

	printf("%s %.2f\n", st[0].name, st[0].avg);
	printf("%s %.2f\n", st[9].name, st[9].avg);

	for (i = 7; i <= 9; i++) {
		printf("%s %.2f\n", st[i].name, st[i].avg);
	}
}

void main() {
	STUDENT st[10];

	read_data(st);
	calc_avg(st);
	print_score(st);
}
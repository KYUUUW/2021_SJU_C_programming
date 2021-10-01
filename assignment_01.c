#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)

long wheel2 = 0;

int* MAX(int* ar);
int* MIN(int* ar);

void question01_01() {
	int N;
	int ar[100];
	int i;
	int* p;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (p = ar; *(p - 1) != 0; p++) {
			scanf("%d", p);
		}
		printf("%d %d\n", *MAX(ar), *MIN(ar));
	}
}

void question01_02() {
	int N;
	int ar[100];
	int i;
	int* p;
	int* a,* b, *tmp;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (p = ar; 1; p++) {
			scanf("%d", p);
			if (*p == 0) {
				break;
			}
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

int passengerN(int n) { // 5 미만 승객인지 검사
	if (n < 5) return -1; // 5 보다 적은 승객이면 -1
	return 0; // 5 이상이면 1
}


void question02_01() {
	int N;
	int ar[21] = { 0 }, * p, * q;
	int metric;
	int i, n_dup, dup_exist = 0;

	scanf("%d", &N); // 승객 수 입력받기

	for (p = ar; p < ar + N; p++) { // 좌석번호 입력받기
		scanf("%d", p);
	}

	if (passengerN(N) == -1) { // 예약 좌석이 부족한 경우
		printf("-1\n"); 
		return; // 프로그램 종료
	}

	for (p = ar; p < ar + N; p++) { // 모든 좌석을 순회한다.
		if (*p == 0 || *p == -1) { // 0 의 의미는 예약되지 않았다는 뜻. -1 의 의미는 중복처리 되었다는 뜻
			continue;
		}
		metric = *p; // 포인터에 저장된 좌석 번호를 기준으로 삼는다.
		n_dup = 1; // 중복 좌석 카운터를 1 으로 초기화한다.
		for (q = p + 1; q < ar + N; q++) { // 해당 좌석 뒤를 모두 순회해서 중복을 찾는다.
			if (*q == metric) { // 중복 좌석을 찾으면
				n_dup++; // 중복횟수를 더해준다.
				dup_exist = 1; // 중복 있음 체크
				*q = -1; // 체크된 중복을 의미하는 -1 마커를 넣는다.
			}
		}
		if (n_dup != 1) { // 중복이 있다면
			printf("%d %d\n", metric, n_dup); // 중복 정보를 출력한다.
		}
	}
	if (dup_exist == 0) { // 중복이 존재하지 않는다면
		printf("0"); // 0 출력
	}
}

void rebooking(int ar[]) { // 중복 제거 함수
	int* p = NULL, * q = NULL; // 순회용 포인터
	int isExist; // 중복여부 마커
	int availableSeat; // 잔여 좌석

	for (p = ar; *p != 0; p++) { // 예약 내역 전체 순회
		isExist = 0; // 중복 마커 초기화
		for (q = ar; q < p; q++) { // 앞서 예약된 내역을 조회한다.
			if (*q == *p) { // 중복이 있다면
				isExist = 1; // 마커를 체크하고
				break; // 중복 조회를 종료한다.
			}
		}
		if (isExist == 1) { // 예약이 중복되었다면
			availableSeat = changeseat(ar); // 좌석을 변경한다.
			*p = availableSeat; // 좌석을 변경한다.
		}
	}
}

int changeseat(int ar[]) {
	int i; // 좌석번호 순회에 쓰일 변수
	int* p = NULL; // 예약조회에 쓰일 포인터
	int isExist; // 예약여부

	for (i = 1; i <= 21; i++) { // 가장 작은 수를 찾기위해 작은수부터 탐색한다.
		isExist = 0; // 예약여부를 확인할 마커를 0 으로 초기화한다.
		for (p = ar; *p != 0; p++) { // ar 을 순회한다. 예약되지 않은 좌석은 0으로 초기화 되어있다.
			if (i == *p) { // 이미 예약되어있다면
				isExist = 1; // 예약여부를 마킹하고
				break; // 반복 종료
			}
		}
		if (isExist == 0) {
			return i; // 만약 예약되지 않은 좌석번호가 있다면 해당 수를 return 한다.
		}
	}
}

void question_02_02() {
	int N; // 예약자 수
	int ar[22] = { 0 }, *p = NULL, * q = NULL; // 예약자 수만큼 예약된 좌석번호를 저장할 배열
	int i, n_dup, dup_exist = 0; // 중복여부를 체크하기 위한 변수

	scanf("%d", &N); // 승객 수 입력받기

	for (p = ar; p < ar + N; p++) { // 좌석번호 입력받기
		scanf("%d", p); // 좌석번호 입력받기
	}

	if (passengerN(N) == -1) { // 예약 좌석이 부족한 경우
		printf("-1"); // -1 출력black
		return; // 프로그램 종료
	}
	else { // 예약 좌석이 부족하지 않은 경우
		printf("0\n"); // 예약 좌석이 부족하지 않은 경우 0 출력
	}

	rebooking(ar); // 중복 제거 함수 호출

	for (p = ar; p < ar + N; p++) { // 모든 좌석을 순회한다.
		printf("%d ", *p); // 좌석번호 출력
	}
}

int test_rebooking(int N) {
	// generate number
	int ar[22] = { 0 };
	int origin[22];
	int i, j, k, tmp;

	for (i = 0; i < N; i++) {
		srand(time(NULL) + i + N + wheel2);
		wheel2++;
		ar[i] = (rand() % 21) + 1;
	}

	for (k = 0; k < 22; k++) {
		origin[k] = ar[k];
	}

	rebooking(ar);

	// 중복확인
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == j) {
				continue;
			}
			if (ar[i] == ar[j]) {
				for (k = 0; k < 22; k++) {
					printf("%d ", origin[k]);
				}
				return 1;
			}
		}
	}

	return 0;
}

void main() {
	/*
	int toBeContinue;
	int wheel = 0;
	while (1) {
		srand((GetTickCount() + wheel + wheel2));
		toBeContinue = test_rebooking(rand() % 17 + 5);
		if (toBeContinue == 1) {
			return;
		}
		wheel++;
	}
	*/
	question_02_02();
}

void question03() {
	char str[101], *p;
	int len = 0;
	int maxLen = 0;

	scanf("%[^#]s", str);

	for (p = str; *p != '\0'; p++) {
		if (*p >= 'a' && *p <= 'z') {
			len++;
			printf("%c", *p);
		}
		else {
			if (maxLen < len) {
				maxLen = len;
			}
			len = 0;
			printf("\n");
		}
	}
	if (maxLen < len) {
		maxLen = len;
	}
	printf("\n");
	printf("\n%d", maxLen);
}

void question04() {
	int x[10], y[10], *p, *q;
	int n = 0, m = 0;
	int tmp, *max, *min;

	p = x;
	while (1) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			break;
		}
		*p = tmp;
		n++;
		p++;
	}
	
	p = y;
	while (1) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			break;
		}
		*p = tmp;
		m++;
		p++;
	}

	for (p = x; p < x + n; p++) { // x 을 내림차순으로 만든다.
		max = p;
		for (q = p + 1; q < x + n; q++) {
			if (*max < *q) {
				max = q;
			}
		}
		for (q = y; q < y + m; q++) {
			if (*max < *q) {
				max = q;
			}
		}
		if (max != p) {
			tmp = *p;
			*p = *max;
			*max = tmp;
		}
	}

	for (p = y; p < y + m; p++) { // y 를 오름차순으로 만든다.
		min = p;
		for (q = p + 1; q < y + m; q++) {
			if (*min > *q) {
				min = q;
			}
		}
		if (min != p) {
			tmp = *p;
			*p = *min;
			*min = tmp;
		}
	}

	for (p = x; p < x + n; p++) {
		printf("%d ", *p);
	}
	printf("\n");
	for (p = y; p < y + m; p++) {
		printf("%d ", *p);
	}
}
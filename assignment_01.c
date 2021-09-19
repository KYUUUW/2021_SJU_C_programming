#include<stdio.h>
#include<math.h>
#pragma warning(disable: 4996)

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

void rebooking(int *ar) { // 중복 제거 함수
	int* p, *q; // 순회용 포인터
	int isExist; // 중복여부 마커
	int availableSeat;

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

int changeseat(int* ar) {
	int i; // 좌석번호 순회에 쓰일 변수
	int* p; // 예약조회에 쓰일 포인터
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

void main() {
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
	else {
		printf("0\n");
	}

	rebooking(ar);

	for (p = ar; p < ar + N; p++) { // 모든 좌석을 순회한다.
		printf("%d ", *p);
	}
}

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

int passengerN(int n) { // 5 �̸� �°����� �˻�
	if (n < 5) return -1; // 5 ���� ���� �°��̸� -1
	return 0; // 5 �̻��̸� 1
}


void question02_01() {
	int N;
	int ar[21] = { 0 }, * p, * q;
	int metric;
	int i, n_dup, dup_exist = 0;

	scanf("%d", &N); // �°� �� �Է¹ޱ�

	for (p = ar; p < ar + N; p++) { // �¼���ȣ �Է¹ޱ�
		scanf("%d", p);
	}

	if (passengerN(N) == -1) { // ���� �¼��� ������ ���
		printf("-1\n"); 
		return; // ���α׷� ����
	}

	for (p = ar; p < ar + N; p++) { // ��� �¼��� ��ȸ�Ѵ�.
		if (*p == 0 || *p == -1) { // 0 �� �ǹ̴� ������� �ʾҴٴ� ��. -1 �� �ǹ̴� �ߺ�ó�� �Ǿ��ٴ� ��
			continue;
		}
		metric = *p; // �����Ϳ� ����� �¼� ��ȣ�� �������� ��´�.
		n_dup = 1; // �ߺ� �¼� ī���͸� 1 ���� �ʱ�ȭ�Ѵ�.
		for (q = p + 1; q < ar + N; q++) { // �ش� �¼� �ڸ� ��� ��ȸ�ؼ� �ߺ��� ã�´�.
			if (*q == metric) { // �ߺ� �¼��� ã����
				n_dup++; // �ߺ�Ƚ���� �����ش�.
				dup_exist = 1; // �ߺ� ���� üũ
				*q = -1; // üũ�� �ߺ��� �ǹ��ϴ� -1 ��Ŀ�� �ִ´�.
			}
		}
		if (n_dup != 1) { // �ߺ��� �ִٸ�
			printf("%d %d\n", metric, n_dup); // �ߺ� ������ ����Ѵ�.
		}
	}
	if (dup_exist == 0) { // �ߺ��� �������� �ʴ´ٸ�
		printf("0"); // 0 ���
	}
}

void rebooking(int ar[]) { // �ߺ� ���� �Լ�
	int* p = NULL, * q = NULL; // ��ȸ�� ������
	int isExist; // �ߺ����� ��Ŀ
	int availableSeat; // �ܿ� �¼�

	for (p = ar; *p != 0; p++) { // ���� ���� ��ü ��ȸ
		isExist = 0; // �ߺ� ��Ŀ �ʱ�ȭ
		for (q = ar; q < p; q++) { // �ռ� ����� ������ ��ȸ�Ѵ�.
			if (*q == *p) { // �ߺ��� �ִٸ�
				isExist = 1; // ��Ŀ�� üũ�ϰ�
				break; // �ߺ� ��ȸ�� �����Ѵ�.
			}
		}
		if (isExist == 1) { // ������ �ߺ��Ǿ��ٸ�
			availableSeat = changeseat(ar); // �¼��� �����Ѵ�.
			*p = availableSeat; // �¼��� �����Ѵ�.
		}
	}
}

int changeseat(int ar[]) {
	int i; // �¼���ȣ ��ȸ�� ���� ����
	int* p = NULL; // ������ȸ�� ���� ������
	int isExist; // ���࿩��

	for (i = 1; i <= 21; i++) { // ���� ���� ���� ã������ ���������� Ž���Ѵ�.
		isExist = 0; // ���࿩�θ� Ȯ���� ��Ŀ�� 0 ���� �ʱ�ȭ�Ѵ�.
		for (p = ar; *p != 0; p++) { // ar �� ��ȸ�Ѵ�. ������� ���� �¼��� 0���� �ʱ�ȭ �Ǿ��ִ�.
			if (i == *p) { // �̹� ����Ǿ��ִٸ�
				isExist = 1; // ���࿩�θ� ��ŷ�ϰ�
				break; // �ݺ� ����
			}
		}
		if (isExist == 0) {
			return i; // ���� ������� ���� �¼���ȣ�� �ִٸ� �ش� ���� return �Ѵ�.
		}
	}
}

void question_02_02() {
	int N; // ������ ��
	int ar[22] = { 0 }, *p = NULL, * q = NULL; // ������ ����ŭ ����� �¼���ȣ�� ������ �迭
	int i, n_dup, dup_exist = 0; // �ߺ����θ� üũ�ϱ� ���� ����

	scanf("%d", &N); // �°� �� �Է¹ޱ�

	for (p = ar; p < ar + N; p++) { // �¼���ȣ �Է¹ޱ�
		scanf("%d", p); // �¼���ȣ �Է¹ޱ�
	}

	if (passengerN(N) == -1) { // ���� �¼��� ������ ���
		printf("-1"); // -1 ���black
		return; // ���α׷� ����
	}
	else { // ���� �¼��� �������� ���� ���
		printf("0\n"); // ���� �¼��� �������� ���� ��� 0 ���
	}

	rebooking(ar); // �ߺ� ���� �Լ� ȣ��

	for (p = ar; p < ar + N; p++) { // ��� �¼��� ��ȸ�Ѵ�.
		printf("%d ", *p); // �¼���ȣ ���
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

	// �ߺ�Ȯ��
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

	for (p = x; p < x + n; p++) { // x �� ������������ �����.
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

	for (p = y; p < y + m; p++) { // y �� ������������ �����.
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
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

void rebooking(int *ar) { // �ߺ� ���� �Լ�
	int* p, *q; // ��ȸ�� ������
	int isExist; // �ߺ����� ��Ŀ
	int availableSeat;

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

int changeseat(int* ar) {
	int i; // �¼���ȣ ��ȸ�� ���� ����
	int* p; // ������ȸ�� ���� ������
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

void main() {
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
	else {
		printf("0\n");
	}

	rebooking(ar);

	for (p = ar; p < ar + N; p++) { // ��� �¼��� ��ȸ�Ѵ�.
		printf("%d ", *p);
	}
}

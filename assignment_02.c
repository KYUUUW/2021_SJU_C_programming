#include<stdio.h> 
#include<string.h>
#pragma warning(disable: 4996)

int isNumber(char a) { // ASCII 가 숫자인지 확인하는 함수
	if (a >= '0' && a <= '9') { // 숫자일경우 1 return
		return 1; // 숫자일경우 1 return
	}
	return 0; // 아니면 0
}

void resetStr(char* str) { // 문자열을 초기화하는 함수
	int i, len; // 문자열의 길이를 저장할 변수

	len = strlen(str); // 문자열의 길이를 저장
	for (i = 0; i < len; i++) { // 문자열의 길이만큼 반복
		str[i] = '\0'; //	문자열을 초기화
	}
}

void convert(char* A, char* B, int N) {
	char tmpStr[100] = { '\0' }; // 문자열을 저장할 변수
	int lenA, lenNum, i, num;
	char* a, * b, * p, * q; // 포인터 커서들
	lenA = strlen(A); // 문자열의 길이를 저장
	b = B; // 문자열을 저장할 변수에 포인터 커서를 저장
	for (a = A; a < A + lenA; a++) { // 문자열의 길이만큼 반복
		if (*a >= 'A' && *a <= 'Z') { // 대문자일 경우
			*b = *a + N; // 대문자일 경우 대문자를 숫자만큼 더해서 저장
		}
		else if (*a >= 'a' && *a <= 'z') { // 소문자일 경우
			*b = *a - N; // 소문자일 경우 소문자를 숫자만큼 빼서 저장
		}
		else if (isNumber(*a)) { // 숫자인지 확인
			p = tmpStr; // 숫자 str 을 담아놓을 tmpStr 포인터 생성
			for (q = a; isNumber(*q); q++) { // 뒤를 확인하며 숫자가 어디있는지 확인
				*p = *q; //  tmpStr 로 숫자들을 복사한다.
				p++; // tmpStr 포인터 증가
			}
			num = atoi(tmpStr); // str 을 integer 로 만든다.
			for (i = 0; i < N; i++) { // 문제의 조건: N 번 반복
				*b = num + 'A' - 1; // 문제의 조건: 숫자번째 대문자
				b++; // 포인터를 다음 공간을 가르키게 함
			}
			b--; // 포인터를 빈공간에서 마지막 문자로 원상복구
			a = --q; // a 포인터를 마지막으로 처리된 문자로 보냄
			resetStr(tmpStr); // 임시 문자열을 초기화함
		}
		else { // 아니면
			*b = ' '; // 빈공간으로 저장
		}
		b++; // 다음 공간으로 이동
	}
}

void question_01_01() {
	char A[21]; // 문자열을 저장할 변수
	char B[100] = { '\0' }; // 출력 문자열을 저장할 변수
	char tmpStr[100] = { '\0' }; // 문자열을 저장할 변수
	int N, lenA, lenNum, i, num;  
	char* a, *b, *p, *q; // 포인터 커서들

	scanf("%s", A); // 문자열을 입력받음
	scanf("%d", &N); // 숫자를 입력받음
 
	lenA = strlen(A); // 문자열의 길이를 저장
	b = B; // 문자열을 저장할 변수에 포인터 커서를 저장
	for (a = A; a < A + lenA; a++) { // 문자열의 길이만큼 반복
		if (*a >= 'A' && *a <= 'Z') { // 대문자일 경우
			*b = *a + N; // 대문자일 경우 대문자를 숫자만큼 더해서 저장
		}
		else if (*a >= 'a' && *a <= 'z') { // 소문자일 경우
			*b = *a - N; // 소문자일 경우 소문자를 숫자만큼 빼서 저장
		}
		else if (isNumber(*a)) { // 숫자인지 확인
			p = tmpStr; // 숫자 str 을 담아놓을 tmpStr 포인터 생성
			for (q = a; isNumber(*q); q++) { // 뒤를 확인하며 숫자가 어디있는지 확인
				*p = *q; //  tmpStr 로 숫자들을 복사한다.
				p++; // tmpStr 포인터 증가
			}
			num = atoi(tmpStr); // str 을 integer 로 만든다.
			for (i = 0; i < N; i++) { // 문제의 조건: N 번 반복
				*b = num + 'A' - 1; // 문제의 조건: 숫자번째 대문자
				b++; // 포인터를 다음 공간을 가르키게 함
			}
			b--; // 포인터를 빈공간에서 마지막 문자로 원상복구
			a = --q; // a 포인터를 마지막으로 처리된 문자로 보냄
			resetStr(tmpStr); // 임시 문자열을 초기화함
		}
		else { // 아니면
			*b = ' '; // 빈공간으로 저장
		} 
		b++; // 다음 공간으로 이동
	}

	printf("%s", B); // 출력
}

void question_01_02() {
	char A[21]; // 문자열을 저장할 변수
	char B[100] = { '\0' }; // 출력 문자열을 저장할 변수
	char C[100] ={ '\0' }; // 출력 문자열을 저장할 변수
	char tmpStr[100] = { '\0' }; // 문자열을 저장할 변수
	int lenA, lenNum, N, num;  
	char* a, *b, *p, *q; // 포인터 커서들

	gets(A); // 문자열을 입력받음
	gets(B); //	문자열를 입력받음

	for (N = 1; N <= 10; N++) {

	convert(A, C, N); // A 를 변환 한 값을 C 에 저장
	// printf("\n[Case1] [%d] [%s] [%s]\n", N, A, C);
	if (strcmp(C, B) == 0) { // B 와 C 가 같다면
		printf("1"); // 1 을 출력
		return; // 함수 종료
	}

	resetStr(C); // C 를 초기화 함
	convert(B, C, N); // B 를 변환 한 값을 C 에 저장
	// printf("\n[Case2] [%d] [%s] [%s]\n", N, B, C);
	if (strcmp(C, A) == 0) { // A 와 C 가 같다면
		printf("2"); // 2 을 출력
		return; // 함수 종료
	}
}

printf("0"); //	0 을 출력
return;
}


void strcp_p(char* s, char* f, char* dest) { // 문자열 s 를 복사하여 dest 에 저장하는 함수
	char* p, * q; //	포인터 커서들

	p = s; // s 를 p 에 저장
	q = dest; //	dest 를 q 에 저장

	for (; p <= f; p++) { // p 와 f 사이의 문자를 복사하는 반복문
		*q = *p; // p 문자를 q 문자열에 저장
		q++; // q 포인터를 다음 공간으로 이동
	}
	(*q) = '\0'; // 문자열 종료 문자를 삽입한다.
}

void question02() {
	int i, len; // 변수들
	char input[1010]; // 입력 문자열을 저장할 변수
	char ar[10][101]; // 문자열을 저장할 변수
	char ch; // 문자를 저장할 변수
	char* s, * f, * p, * front; // 포인터 커서들

	gets(input); // 입력 문자열을 입력받음

	i = 0; // i 를 0 으로 초기화
	s = input; // s 를 input 에 저장
	for (p = input; 1; p++) { // 입력 문자열이 끝날때까지 반복
		if ((*p) == ' ' || *(p) == '\0') { // p 가 공백 또는 문장의 끝을 만나면
			f = p - 1; // f 에 단어의 마지막 포인터를 넣고
			strcp_p(s, f, ar[i]); // 준비해둔 복사 함수를 이용해서 ar 로 복사한다.
			puts(ar[i]); // 문제의 조건: 분리된 단어를 출력한다.
			i++; // 배열의 다음칸을 가리키게 하고
			s = f + 2; // 단어 파싱의 시작점을 다음 단어로 만든다.

			if ((*p) == '\0') { // 문자열이 종료라면
				break; // 반복을 끝낸다.
			}
		}
	}
	len = i; // 문자열의 길이를 len 에 저장한다.

	/* 입력 정상여부 테스트코드
	printf("\nlen[%d]\n", len);
	for (i = 0; i < len; i++) {
		printf("\n[%s]\n", ar[i]);
	}
	*/

	front = ar[0]; // front 를 ar 의 첫번째 문자열로 설정한다.
	for (i = 1; i < len; i++) { // 문자열 배열의의 길이만큼 반복
		if (strcmp(front, ar[i]) > 0) { // front 문자열에 ar 의 i 번째 문자열이 앞서는 문자열이라면
			front = ar[i]; // front 를 ar 의 i 번째 문자열로 설정한다.
		}
	}

	puts(front); // 문제의 조건: 분리된 단어를 출력한다.
}

void question03() {
	char str1[100] = { '\0' }; // 문자열을 저장할 변수
	char str2[100] = { '\0' }; // 문자열을 저장할 변수
	char* p, * s, * f; // 포인터 커서들
	int len, len2, cnt; // 변수들
	gets(str1); // 입력 문자열을 입력받음
	gets(str2); // 입력 문자열을 입력받음
	len = strlen(str1); // 문자열의 길이를 len 에 저장한다.
	len2 = strlen(str2);

	s = str1; // s 를 str1 에 저장
	cnt = 0; // cnt 를 0 으로 초기화
	for (p = str1; p < str1 + len; p++) { // 문자열의 길이만큼 반복
		if ((*p) == ' ' || (*p) == '.' || (*p) == '\0') { // 단어의 끝을 만나면
			f = p - 1; // f 에 단어의 마지막 포인터를 넣고

			// printf("\n[strncmp] [%s] [%s] [%d]", s, str2, f - s + 1);
			if (strncmp(s, str2, f - s + 1) == 0 
				&& strncmp(s, str2, len2) == 0) { // 기준과 단어가 같은지 확인하고
				cnt++; // 같다면 카운트한다.
			}

			for (; (*p) == ' ' ||  (*p) == '.'; p++) {} // 다시 단어 또는 문장의 끝이 나올때까지 전진
			if ((*p) == '\0') { // 문장의 끝이라면 반복 종료
				break; // 반복을 끝낸다.
			}

			s = p; // 단어의 시작 지점을 s 로 표시	
		}
	}

	printf("%d", cnt); // 출력
}

int s_check(char* p, char* q) { // 문자열에 소문자가 몇개 들어가는지 확인하는 함수
	int cnt = 0; // 카운트 변수

	// printf("\npointer [p][%p]:[%c] / [q][%p]:[%c]\n", p, *p,  q, *q);

	while (1) { // 반복
		if (p > q) { // p 의 포인터가 q 의 포인터보다 크면
			return cnt; // 카운트 변수를 반환한다.
		}

		if (*p >= 'a' && *p <= 'z') { // p 의 포인터가 소문자라면
			cnt++; // 카운트 변수를 증가시킨다.
		}
		p++; // p 의 포인터를 전진시킨다.
	}
}
 
void main() {
	char str[201]; // 문자열을 저장할 변수
	int M, k1, k2, i, cnt, len, last_idx; // 변수들
	int* p, *s, *f; // 포인터들

	scanf("%d", &M); // 문자열의 개수를 입력받음
	scanf("%d %d", &k1, &k2); // 위치를 입력받음
	getchar(); // 버퍼의 엔터를 입력받음

	for (i = 0; i < M; i++) { // 문자열의 개수만큼 반복
		gets(str); // 문자열을 입력받음

		len = strlen(str); // 문자열의 길이를 len 에 저장한다.
		if (len - 1 < k2) { // 문자열의 길이가 k2 보다 작으면
			last_idx = len - 1; // 마지막 인덱스를 마지막 문자의 인덱스로 저장한다.
		}
		else { // 문자열의 길이가 k2 보다 크면
			last_idx = k2; // 마지막 인덱스를 k2 로 저장한다.
		}

		s = str + k1; // s 에 문자열의 시작 지점을 저장한다.
		f = str + last_idx; // f 에 문자열의 마지막 지점을 저장한다.

		cnt = s_check(s, f); // 문자열에 소문자가 몇개 들어가는지 확인한다.

		if (cnt == 0) { // 소문자가 들어가지 않았다면
			continue; // 다음 문자열로 넘어간다.
		}
		else { // 소문자가 들어갔다면
			printf("%d\n", cnt); // 출력
		}
	}
}
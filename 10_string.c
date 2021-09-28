#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

void question01() {
	char ar[21], * p;

	scanf("%s", ar);

	for (p = ar; *p != '\0'; p++) {
		if ('a' <= *p && *p <= 'z') {
			printf("%c", *p);
		}
	}

	/* Type or paste your code in this area */

	return 0;
}

void question02() {
	int input;
	int i;
	char* p;
	char digit;
	char ar[10] = { '\0 ' };

	scanf("%d", &input);

	p = ar;
	i = input;
	while(1) {

		digit = '0' + (i % 10);
		*p = digit;
		p++;

		if (i / 10 == 0) {
			break;
		}
		i /= 10;
	}

	printf("%s", ar);
}

void question03() {
	char ar[201] = { '\0' };
	char tmp;
	int len;
	int i, j;

	scanf("%s", ar);

	for (i = 0; ar[i] != '\0'; i++) {}
	len = i;

	for (i = 0; i < len; i++) {
		tmp = ar[0];
		printf("%s\n", ar);
		for (j = 1; j < len; j++) {
			ar[j - 1] = ar[j];
		}
		ar[len - 1] = tmp;
	}
}

void question04() {
	char a[101] = { '\0' };
	char b[101] = { '\0' };
	int i, len;
	int isSame;

	scanf("%s", a);
	scanf("%s", b);

	for (i = 0; a[i] != '\0'; i++) {}
	len = i;

	isSame = 1;
	for (i = 0; i < len; i++) {
		if (a[i] != b[i]) {
			isSame = 0;
		}
	}

	printf("%d %d", len, isSame);
}

void question05() {
	char str1[41] = { '\0' };
	char str2[21] = { '\0' };
	char tmp;
	int position;
	int i, j, len1, len2;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &position);

	for (i = 0; str1[i] != '\0'; i++) {}
	len1 = i;

	for (i = 0; str2[i] != '\0'; i++) {}
	len2 = i;

	for (i = len1 - 1; i >= position; i--) {
		str1[i + len2] = str1[i];
	}

	j = 0;
	for (i = position; i <= position + len2 - 1; i++) {
		str1[i] = str2[j];
		j++;
	}

	printf("%s", str1);
}

void question06() {
	char str1[41] = { '\0' };
	char str2[21] = { '\0' };
	char tmp;
	int position, ord;
	int i, j, len1, len2;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &position);
	scanf("%d", &ord);

	for (i = 0; str1[i] != '\0'; i++) {}
	len1 = i;

	for (i = 0; str2[i] != '\0'; i++) {}
	len2 = i;

	for (i = len1 - 1; i >= position; i--) {
		str1[i + len2] = str1[i];
	}
	
	if (ord == 0) {
		j = 0;
		for (i = position; i <= position + len2 - 1; i++) {
			str1[i] = str2[j];
			j++;
		}
	}
	else {
		j = len2 -1;
		for (i = position; i <= position + len2 - 1; i++) {
			str1[i] = str2[j];
			j--;
		}
	}

	printf("%s", str1);
}

void question07() {
	char* zeros[] = { "", "TEN", "HUN", "THO" };
	char* digits[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int i;
	int round = 1000;
	int len = 3;
	int input;
	int startToPrint = 0;

	scanf("%d", &input);

	while (len != 0) {
		i = (input / round) % 10;
		if (i != 0) {
			printf("%s ", digits[i]);
			startToPrint = 1;
		}
		i =len;
		if (i != 0 && startToPrint == 1) {
			printf("%s ", zeros[i]);
			startToPrint = 0;
		}
		len--;
		round /= 10;
	}

	printf("%s ", digits[(input / round) % 10]);
	printf("%s ", zeros[len]);
}

void question08() {
	char str1[51] = { '\0' };
	char str2[51] = { '\0' };
	int i;
	int forward;

	scanf("%s", str1);
	scanf("%s", str2);

	for (i = 0; i < 51; i++) {
		if (str1[i] > str2[i]) {
			forward = 1;
			break;
		}
		else if(str1[i] < str2[i]) {
			forward = 2;
			break;
		}
	}

	if (forward == 1) {
		printf("%s%s", str1, str2);
	}
	else if (forward == 2) {
		printf("%s%s", str2, str1);
	}
}

int check(char* str) {
	int len, i, j;

	len = strlen(str);

	j = len - 1;
	for (i = 0; i < len  / 2; i++) {
		if (str[i] != str[j]) {
			return 0;
		}
		j--;
	}
	return 1;
}

void question09() {
	char str[31];
	
	scanf("%s", str);
	printf("%d %d", strlen(str), check(str));
}

void question10() {
	char str[101], minStr[101];
	int i, N, len, minLen = 200;

	scanf("%d", &N);
	getchar();

	for (i = 0; i < N; i++) {
		gets(str);
		len = strlen(str);

		if (len < minLen) {
			strcpy(minStr, str);
			minLen = len;
		}
	}

	printf("%s", minStr);
}

void question11() {
	char str1[81] = { '\0' };
	char str2[11] = { '\0' };
	int len1;
	int len2;
	int i, j;
	int isDiff;
	int isInclude;

	scanf("%s", str1);
	scanf("%s", str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	isInclude = 0;
	for (i = 0; i <= len1 - len2; i++) {
		isDiff = 0;
		for (j = 0; j < len2; j++) {
			if (str1[i + j] != str2[j]) {
				isDiff = 1;
				break;
			}
		}
		if (isDiff == 0) {
			isInclude = 1;
		}
	}

	printf("%d %d", len1, isInclude);
}

void main() {
	char str1[101] = { '\0' };
	char str2[101] = { '\0' };
	int len1;
	int len2;
	int i, j;
	int isDiff;
	int nInclude;

	gets(str1);
	gets(str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	nInclude = 0;
	for (i = 0; i <= len1 - len2;) {
		isDiff = 0;
		for (j = 0; j < len2; j++) {
			if (str1[i + j] != str2[j]) {
				isDiff = 1;
				break;
			}
		}
		if (isDiff == 0) {
			nInclude++;
			i += len2;
		}
		else {
			i++;
		}
	}

	printf("%d", nInclude);
}
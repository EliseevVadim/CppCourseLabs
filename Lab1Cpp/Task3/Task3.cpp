#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <cstring>
using namespace std;
/*Елисеев Вадим, ИВТ-5, Вариант 7
Функция strchr. Формат char* strchr(char* s, int c).
Функция находит в строке s первое вхождение символа с и возвращает подстроку, начинающуюся с этого символа.*/
char* MyStrchr(char* s, int c) {
	bool flag = false;
	char* result = new char[256];
	int pos = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] == c) {
			flag = true;
			for (int i = 0; s[i] != '\0'; i++) {
				result[i] = s[pos];
				pos++;
			}
			break;
		}		
		pos++;
	}
	if (!flag) {
		result = NULL;
	}
	if (pos == 1) {
		result = s;
	}
	return result;
}
void writeAnswer(char* s,  char* m) {
	printf("Classic strchr's result:\n");
	if (s != NULL) {
		printf("%s\n", s);
	}
	else {
		printf("Nothing\n");
	}
	printf("My strchr's result:\n");
	if (m != NULL) {
		printf("%s", m);
	}
	else {
		printf("Nothing");
	}
}
int main()
{
	char s[256];
	printf("Enter the source line:\n");
	gets_s(s);
	char a;
	printf("Enter a character for search:\n");
	scanf("%c", &a);
	char* standart_res = strchr(s, a);
	char* my_res = MyStrchr(s, a);
	writeAnswer(standart_res, my_res);
	/*delete standart_res;
	standart_res = nullptr;
	delete my_res;
	my_res = nullptr;*/
	return 0;
}

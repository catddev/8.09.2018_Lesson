#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>

using namespace std;

bool isDigit(char a) {
	return(a >= '0' && a <= '9');
}
bool isAlpha(char a) {
	return(a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z');
}
void check_string(char* str) {
	int d = 0, a = 0, o = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (isDigit(str[i]))
			d++;
		else if (isAlpha(str[i]))
			a++;
		else o++;
	}
	cout << "Digits: " << d << endl;
	cout << "Alpha: " << a << endl;
	cout << "Others: " << o << endl;
}
// Подсчитать количество слов во введенном предложении.
// а) *между словами находится только один пробел
// б) ** пробелы также могут располагаться в начале и в конце предложения
// в) *** пробелы могут располагаться в начале и в конце предложения, и между словами может быть болееодного пробела

// а), б)
int spaces(char* str) {
	int k = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			if (i == 0 || i == (strlen(str) - 1)) continue; // б)
			// if(str[i]==str[i-1]) continue;
			k++;
		}
	}
	return k + 1;
}
// в)
int lot_of_spaces(char* str) {
	int k = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			if (i == (strlen(str) - 1)) continue;
			k++;
		}

	}
	if (str[0] == ' ') return k;
	return k + 1;
}
int subStr(char* str1, const char* str2) {
	int k = 0;
	int words = 0;
	int tmp = 0;
	for (int i = 0; i < strlen(str1); i++)
	{
		k = 0;
		tmp = i;
		for (int j = 0; j < strlen(str2); j++)
		{
			if (str1[i++] != str2[j]) break;
			else k++;
		}
		i = tmp;
		if (k == strlen(str2)) words++;
	}
	return words;
}

int SubString(char* str1, const char* str2) {
	int k = 0;
	while (strstr(str1, str2))
	{

		str1 = strstr(str1, str2) + strlen(str2); // сдвиг указателя на длину искомой подстроки после нахождения этой подстроки один раз
		cout << str1 << endl;
		k++;
	}
	return k;
}
void len(const char* str, int n) {

	int k = strlen(str);
	int free = n - k;

	cout << "Busy: " << k << endl;
	cout << "Free: " << free << endl;
}

size_t strlen_mine(const char* str) { // size_t = unsigned int
	int k = 0;
	while (*str != '\0') {
		k++;
		str++;
	}
	return k;
}

void str_change(char* str) {

	char* p = str;
	while (*p != '\0') {
		if (*p == '.') *p = '!';
		p++;
	}
	/*cout << str << endl;*/ // НЕ ВЫВЕДЕТ НИЧЕГО, Т.К. указатель оказывается в конце на "\0"
	//нужно вспомогательный указатель 
	cout << str << endl;
}
void str_change2(char* str) {

	char* p = str;
	while (*p != '\0') {
		if (*p == '?') *p = '1';
		p++;
	}
	cout << str << endl;
}
size_t any_symbol(const char* str) {
	char C;
	cin >> C;

	int k = 0;
	while (*str != '\0') {
		if (*str == C)
			k++;
		str++;
	}
	return k;
}
size_t symbol(const char* str) {
	int k = 0;
	while (*str != '\0') {
		if (*str == '%')
			k++;
		str++;
	}
	return k;
}


int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	char arr[100];

	cin.getline(arr, 100);
	//cin.getline(arr, 10,'.'); // можно любой разделитель
	cout << arr << endl;

	/*cin >> arr;*/
	// разделитель точка означает что строка будет считываться до точки, а далее игнор

/*	cout << arr[0] << endl;
	cout << strlen(arr) << endl;
	check_string(arr);

*/
/*cout << lot_of_spaces(arr) << endl;*/

//cout << strstr(arr, "is") << endl; // returns pointer to the word

//cout << subStr(arr, "is") << endl; // const char !!!!!!!!!!!!!!

/*cout << SubString(arr, "is") << endl;*/


	len(arr, 100);


	cout << strlen_mine(arr) << endl;


	str_change(arr);
	str_change2(arr);

	cout << any_symbol(arr, '&') << endl;
	cout << symbol(arr) << endl;

	cout << arr << endl;


	system("pause");
	return 0;
}
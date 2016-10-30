#include<iostream>
#include<assert.h>
using namespace std;
bool isValidIP(char *str) {
	int numCount = 0;
	char *address = str;
	char *flag = ".";
	char *p = strtok(address,flag);
	while (p) {
		if (atoi(p) < 0 || atoi(p) > 255)	return false;
		++numCount;
		if (numCount > 4)	return false;
		p = strtok(NULL, flag);
	}
	return true;
}
unsigned int main() {
	char *str=(char *)malloc(sizeof(char)*20);
	cin >> str;
	cout << isValidIP(str);

	return 0;
}

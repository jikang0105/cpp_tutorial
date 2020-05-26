#include <iostream>

using namespace std;

int main() {

	/*
	사칙연산자 : +, -, *, /, %(나머지 연산자)
	관계연산자 : 값대 값을 연산하여 참/거짓으로 결과를 반환한다.
	>, >=, <, <=, ==(같다), !=(다르다)
	
	논리연산자 : 참/거짓 대 참/거짓 연산하여 참/거짓으로 결과를 반환한다.
	AND(&&), OR(||), NOT(!)
	
	A	B	AND OR
	0	0	0	0
	1	0	0	1
	0	1	0	1
	1	1	1	1

	A	NOT
	0	1
	1	0
	*/

	cout << "10 < 20 = " << (10 < 20) << endl;
	cout << "10 <= 20 = " << (10 <= 20) << endl;
	cout << "10 > 20 = " << (10 > 20) << endl;
	cout << "10 >= 20 = " << (10 >= 20) << endl;
	cout << "10 == 20 = " << (10 == 20) << endl;
	cout << "10 != 20 = " << (10 != 20) << endl;

	int number = 0;

	cout << "enter number : ";
	cin >> number;

	cout << "10 ~ 20 = " << (10 <= number && number <= 20) << endl;

	return 0;
}
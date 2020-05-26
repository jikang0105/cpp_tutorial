#include <iostream>

using namespace std;

int main() {

	/*
	숙제 1. 구구단을 2단 부터 9단까지 출력하는 중첩 for문 만들기
	*/

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << j << "*" << i << "=" << j * i << "  |  ";
		}
		cout << endl;
	}
	cout << endl;

	/*
	숙제 2. 별을 아래의 형태로 출력되게 한다.
	*
	**
	***
	****
	*****
	*/

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	/*
	숙제 3. 별을 아래의 형태로 출력되게 한다.
	*****
	****
	***
	**
	*
	*/

	// for(int i = 0; i < 5; ++i)
	//	for(int j = 0; j < 5 - i; ++j)

	for (int i = 5; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	/*
	숙제 4. 별을 아래의 형태로 출력되게 한다.
	   *
	  ***
	 *****
	*******
	*/
	/*
	for (int i = 4, a = 3; i <= 7; i++, a--) {
		
		for (int j = 1; j <= i; j++) {
			if (j <= a) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	cout << endl;
	*/
	/*
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 + i; j++) {
			if (j < 3 - i) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	*/

	// 공백 : 3, 2, 1, 0    별 : 1, 3, 5, 7,

	for (int i = 0; i < 4; i++) {
		// 공백을 출력하기 위한 for 문
		for (int j = 0; j < 3 - i; ++j) {
			cout << " ";
		}

		// 별을 출력하기 위한 for문
		for (int j = 0; j < i * 2 + 1; ++j) {
			cout << "*";
		}
		cout << endl;
	}
}
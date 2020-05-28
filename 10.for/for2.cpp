#include <iostream>

using namespace std;

int main() {

	/*
	2단  3단  4단
	5단  6단  7단
	8단  9단  10단
	*/

	for (int i = 2; i < 11; i += 3) {
		for (int j = 1; j <= 9; ++j) {
			cout << i << " * " << j << " = " << i * j << "\t";
			cout << i + 1 << " * " << j << " = " << (i + 1) * j << "\t";
			cout << i + 2 << " * " << j << " = " << (i + 2) * j << endl;
		}
		cout << endl;
	}


	/*
	    *
	   ***
	  *****
	 *******
	  *****
	   ***
	    *
	*/

	int iLine = 7;
	int iCount = 0;

	for (int i = 0; i < iLine; i++) {
		iCount = i;

		// i값이 7줄 기준 4, 5, 6 즉 밑의 삼각형을 구성할때만 if문에 들어가게 된다.
		if (i >= iLine / 2) {
			iCount = iLine - 1 - i;
		}

		for (int j = 0; j < 3 - iCount; ++j) {
			cout << " ";
		}
		
		// 공백 : 3, 2, 1, 0, 1, 2, 3

		// 별 : 1, 3, 5, 7, 5, 3, 2, 1
		
	}

}
#include <iostream>

using namespace std;

int main() {


	/*
		do while 문 : 반복문의 한 종류이다.
		형태 : do {}while(조건식); 의 형태로 구성된다.
		while문은 처음 진입부터 조건식을 체크하지만, do while은 처음 한번은 무조건 동작이 되고
		그 후에 조건식을 체크해서 true일 경우 동작되는 반복문이다.
		*/

	int iNumber = 0;

	do {
		cout << iNumber << endl;
	} while (iNumber > 0);

}
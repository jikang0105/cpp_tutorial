#include <iostream>

using namespace std;

int main() {

	/*
	쉬프트 연산자 : <<, >> ( cout, cin에 사용하는 것 x, 값 대 값을 연산하여 값으로 나오게 한다.
	이 연산자 또한 이진수 단위의 연산을 한다.

	20 << 2 == 80 == 20 * (2^2)
	20을 2진수로 변환한다.
	10100 -> 왼쪽으로 2칸 옮긴다 -> 1010000 -> 10진수로 변환한다 -> 64 + 16 -> 80

	20 << 3 == 160 == 20 * (2^3)
	10100000 == 160

	20 << 4 == 320 == 20 * (2^4)
	101000000 == 320

	빠른 곱하기
	
	// 정수대 정수 연산의 경우 정수가 결과로 도출되어 소수점 아래의 숫자는 삭제된다.
	// 정수대 실수 연산의 경우 실수가 결과로 도출된다.

	20 >> 2 == 00101 == 5 == 20 / (2^2)
	20 >> 3 == 00010 == 2 == 20 / (2^3)

	빠른 나누기

	*/

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;

	// iNumber에는 187이 들어가있다. 이 값을 <- 이방향으로 16비트 이동시키면,
	// 상위 16비트의 값이 들어가게 된다.
	iNumber <<= 16;

	// 하위 16비트를 채운다.
	iNumber |= iLow;

	// iHigh 값을 출력한다.
	cout << "iHigh = " << (iNumber >> 16) << endl;
	// iLow 값을 출력한다.
	// iNumber == 0000 0000 1011 1011 0011 0100 1111 1000
	// 0x0000ffff == 0000 0000 0000 0000 1111 1111 1111 1111
	cout << "iLow = " << (iNumber & 0x0000ffff) << endl;

	// 증감연산자 : ++, -- 가 있다. 1증가, 1감소이다.
	// 전치와 후치
	iNumber = 10;

	// 전치
	++iNumber;

	// 후치
	iNumber++;

	cout << ++iNumber << endl; // 13
	cout << iNumber++ << endl; // 13
	cout << iNumber << endl; //14


	return 0;
}
#include <iostream>

using namespace std;

int main() {
	
	// 상수 : 변하지 않는 수. 값을 한번 지정해좋으면 바꿀 수 없다.
	// 상수는 선언과 동시에 값을 지정해두어야 한다.

										// 이진수
	const int iAttack = 0x000000001;	//		1
	const int iArmor = 0x000000002;		//	   10
	const int iHP = 0x00000004;			//    100
	const int iMP = 0x00000008;			//   1000
	const int iCritical = 0x00000010;	//  10000

	// 1 | 100 = 101 | 10000 = 10101		// 버프를 각 비트에 추가할 때 OR연산자
	int iBuf = iAttack | iHP | iCritical;

	// 연산자 축약형 : 연산자를 줄여서 사용할 수 있다.
	// 아래를 풀어서 쓰면 iBuf = iBuf ^ iHP;
	// iBuf = 10101 ^ 00100 == 10001		// 버프를 각 비트에서 추가하거나 뺄때 XOR연산자
	iBuf ^= iHP;
	// iBuf = 10001 ^ 00100 == 10101		// 스위치 같은 역할
	iBuf ^= iHP;

	// 10101 & 00001 = 00001				// 버프가 활성화를 확인할 때 AND연산자
	cout << "Attack : " << (iBuf & iAttack) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;

	// 배열을 사용해도 되지만 굳이 비드단위 연산자를 사용하는 이유 속도가 빠르다는 장점
	
	return 0;
}
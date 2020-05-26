#include <iostream>

using namespace std;

int main() {
	
	/*
	분기문에는 크게 2가지 종류가 잇다. if문, switch문이 존재한다.
	if 문: 조건을 체크해주는 기능이다.
	형태 : if(조건식) {}(코드블럭)
	if문은 조건식이 true가 될 경우 코드블럭 안의 코드가 동작된다.
	false일 경우에는 동작되지 않는다.
	*/

	if (true){
		cout << "if문 조건이 true입니다." << endl;
	}

	if (false) {
		cout << "if문 조건이 false입니다." << endl;
	}


										//	이진수
	const int iAttack = 0x000000001;	//		1
	const int iArmor = 0x000000002;		//	   10
	const int iHP = 0x00000004;			//    100
	const int iMP = 0x00000008;			//   1000
	const int iCritical = 0x00000010;	//  10000

	// 1 | 100 = 101 | 10000 = 10101		// 버프를 각 비트에 추가할 때 OR연산자
	int iBuf = iAttack | iHP | iCritical;

	// 버프가 있는지 확인한다.

	if ((iBuf & iAttack) != 0) {
		cout << "Attack 버프가 있습니다." << endl;
	}

	// if문 아래에 들어갈 코드가 1줄일 경우 {}(코드블럭)을 생략할 수 있다.

	if ((iBuf & iArmor) != 0)
		cout << "Armor 버프가 있습니다." << endl;

	if ((iBuf & iHP) != 0)
		cout << "HP 버프가 있습니다." << endl;

	if ((iBuf & iMP) != 0)
		cout << "MP 버프가 있습니다." << endl;

	if ((iBuf & iCritical) != 0)
		cout << "Critical 버프가 있습니다." << endl;

	/*
	else : if문과 반드시 같이 사용잉 되어야 한다.
	fi문 조건이 false일 경우 else가 있다면 elds 구문 안의 코드가 동작된다.

	*/

	if (false)
		cout << "if문 조건이 true입니다." << endl;
	else
		cout << "if문 조건이 false입니다." << endl;

	/*
	else if : if문과 반드시 같이 사용이 되어야 한다.
	if문 아래 와야하고 else보다는 위에 있어야 한다.
	else if는 자신의 위에 있는 조건식이 false일 경우 다음 else if의 조건식을 체크한다.
	else if는 몇개든 사용이 가능하다.
	*/

	int iNumber = 10;

	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10 ~ 20 사이의 숫자입니다." << endl;

	else if (21 <= iNumber && iNumber <= 30)
		cout << "21 ~ 30 사이의 숫자입니다." << endl;

	else if (31 <= iNumber && iNumber <= 40)
		cout << "31 ~ 40 사이의 숫자입니다." << endl;

	else
		cout << "그 외의 숫자입니다." << endl;

		

	return 0;
}
#include <iostream>

using namespace std;

struct _tagStudent {
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float	fAvg;
};

int main() {

	int iNumber = 100;

	// 바꾸지 않을 상수의 문자열들만 이 방법으로 활용한다. 추후 문자열이 바뀔 가능성이 있다면,
	// 사전에 배열을 형성하여 문자를 할당한다.
	const char* pText = "테스트 문자열";
	
	cout << pText << endl;
	cout << (int*)pText << endl;
		
	/*
	상수이므로 변경이 불가능 하다.
	pText[1] = 'a';
	pText[2] = 'b';
	*/

	// 포인터가 가리키는 대상이 달라진다
	pText = "abcd";

	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "abcdefg";

	cout << pText << endl;
	cout << (int*)pText << endl;

	// 배열을 사전에 선언하여 문자를 할당하는 경우 문자가 상수가 아닌 변수가 된다.
	char str[8] = "adcdefg";

	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;

	// 연산자 우선순위 때문에 .을 먼저 인식하게 된다. 메모리 주소.은 잘못된 문법이다.
	// 그러므로 *pStudent를 괄호로 감싸준 후에 .을 이용해서 가리키는 대상의 멤버변수에
	// 접근해야 한다.
	(*pStudent).iKor = 50;

	// 메모리주소-> 을 이용해서 가리키는 대상의 멤버에 접근할 수 있다.
	pStudent->iKor = 80;

	cout << tStudent.iKor << endl;

	// void : 타입이 없다. void의 포인터 타입을 활용할 수 있다.
	// void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 모두 저장가능하다.
	// 단, 역참조가 불가능하고 메모리 주소만 저장 가능하다.
	void* pVoid = &iNumber;

	cout << "iNumber Address : " << pVoid << endl;
	// 역참조가 불가능하다.
	//*pvoid = 10;
	
	// 형변환을 하면 가능하다.
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	// 다음의 형식으로도 가능하다.
	*((int*)pVoid) = 9999;
	cout << iNumber << endl;

	pVoid = &tStudent;

	cout << "tStudent Address : " << pVoid << endl;


	return 0;
}
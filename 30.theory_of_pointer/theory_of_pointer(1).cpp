#include <iostream>

using namespace std;

int main() {

	/*
	포인터 : 가리키다. 일반 변수는 일반적인 값을 저장하게 되지만 포인터 변수는 메모리 주소를
	저장하게 된다. 모든 변수 타입은 포인터 타입을 선언할 수 잇다. int변수의 주소는 int 포인터
	변수에 저장해야 한다. 포인터는 메모리 주소를 담아놓은 변수이기 때문에 x86으로 개발할때는
	무조건 4byte가 나온다. x64일때는 8byte가 나온다.

	포인터는 자기 스스로 아무런 일도 할 수 없다. 반드시 다른 변수의 메모리 주소를 가지고 있어야
	일을 할 수 있는데 가지고 있는 그 메모리 주소에 접근해서 값을 제어할 수 있다.

	형태 : 변수타입 *변수명; 의 형태로 선언한다.
	*/

	int iNumber = 100;
	
	// 변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.
	// 변수 압페 &을 붙여주면 해당 변수의 메모리 주소가 된다.
	// pNum은 iNumber변수의 메모리 주소를 값으로 갖게 됐다. 그러므로 pNum을 이용해서
	// iNumber의 값을 제어할 수 있게 된 것이다.
	int* pNum = &iNumber;

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	// pNum을 이용해서 iNumber의 값을 제어해보자.
	// 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
	// 역참조는 포인터 변수 앞에 *을 붙이게 되면 역참조가 된다.
	cout << *pNum << endl;
	*pNum = 1234;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;


	/*
	포인터와 배열을 관계 : 베열명은 포인터다. 배열명 자체가 해당배열의 메모리에서의 시작점 주소를
	의미한다.
	*/
	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "iArray Address : " << iArray << endl;
	cout << "iArray[0] Address : " << &iArray[0] << endl;

	int* pArray = iArray;

	cout << pArray[2] << endl;

	/*
	포인터 연산 : +, - 연산을 제공한다. ++, -- 도 가능한데 1을 증가하게 되면
	단순히 메모리 주소값이 1증가하는 것이 아니다.
	int포인터의 경우 int 타입의 메모리 주소를 갖게 되는데 메모리 주소에 1을 더해주면
	1증가가 아닌 가리키는 해당 포인터 타입의 변수타입 크기만큼 증가하게 된다.
	int 포인터이므로 int의 크기인 4만큼 값이 증가하게 되는 것이다.
	*/
	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;
	

	return 0;
}
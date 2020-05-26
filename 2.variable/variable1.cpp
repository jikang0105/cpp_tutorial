#include <iostream>

using namespace std;

int main() {

	/*
	변수 : 변하는 수, 값이 바뀔 수 있다.

	용량의 최소단위 : bit
	1byte = 8bit
	1kbyte = 1024byte
	1mbyte = 1024kbyte
	1gbyte = 1024mbyte
	1tbyte = 1024gbyte

	문자를 표현하는 방법 : ASCII코드표를 가지고 있다.
	false : 0
	true : 0이 아닌 모든수

	종류		|	용량		|	데이터	|	표현범위			|	unsigned		|
	char	|	1byte	|	문자		|  -128 ~ 127		|	0 ~ 255			|
	bool	|	1byte	|	참/거짓	|  true / false		|	true / false	|
	short	|	2byte	|	정수		|  -32768 ~ 32767	|	0 ~ 65545		|
	int		|	4byte	|	정수		|  약 -22억 ~ 21억	|	0 ~ 약 43억		|
	float	|	4byte	|	실수		|
	double	|	8byte	|	실수		|

	*/

	// 변수형의 이름 가장 앞에는 '_' 와 알파벳만 사용할 수 있다.
	// = : 대입연사자이다. 오른쪽에 있는 값을 온족으로 대입한다.
	int number = 10;
	number = 20;

	cout << number << endl;

	bool	bTest = true;
	bTest = false;

	cout << bTest << endl;

	// 영문이나 숫자는 1byte를 차지한다. 하지만 한글이나 한문, 등의 문자들은 2byte를
	// 차지하기 때문에 char 변수 하나에 저장하기가 힘달다.
	char	cTest = 't';

	cout << cTest << endl;
	
	float fNumber = 3.14f;

	cout << fNumber << endl;

	double dNumber = 123.4567;

	cout << dNumber << endl;

	return 0;

}
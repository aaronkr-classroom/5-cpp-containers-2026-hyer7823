// 4-2.cpp
#include <iostream>
#include <iomanip>  // setw() 함수

using namespace std;

int main(void) {
	for (int i = 1; i <= 100; i++) {
		cout << setw(3) << i << ": " << setw(6) << i * i << endl;
	}
	return 0;
}

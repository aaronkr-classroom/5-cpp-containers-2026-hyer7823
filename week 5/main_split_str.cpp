// main_split_str.cpp
#include <iostream>
#include <vector>
#include <string>
#include "split_str.h"

using namespace std;

int main(void) {
	string s;
	cout << "Enter any string, E0f to quit: ";
	// 문자열을 한 행씩 입력받아 분할
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// 벡터 v에 저장한 단어를 각각 출력
		for (vector < string>::size_type i = 0;
			i != v.size(); i++) {
			cout << v[i] << endl;
		}
	}
	return 0;
}

// frame.cpp
#include <vector>
#include <string>
#include "frame.h"

using std::vector; using std::string; using std::max;

string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0;
		i != v.size(); ++i) {
		maxlen = max(maxlen, v[i].size());
	}
	return maxlen;
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v); // 위에 있는 함수 호출
	string border(maxlen + 4, '*'); // 문자열의 이름은 border

	// 윗 테두리 만들기
	ret.push_back(border);

	// 왼쪽 + 오른쪽 테두리 만들기
	for (vector<string>::size_type i = 0;
		i != v.size(); ++i) {
		ret.push_back(
			"* " +
			v[i] +
			string(maxlen - v[i].size(), ' ') +
			" *");
	}

	// 아래 테두리 만들기
	ret.push_back(border);
	return ret;
}

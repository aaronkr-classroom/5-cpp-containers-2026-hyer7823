// grade.cpp
#include <vector>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"
#include "median.h"


//  중간고사 점수, 기말고사 점수, 과제 점수의 벡터로 학생의 종합
//  점수를 구함. 이 함수는 인수를 복사하지 않고 median 함수가
//  해당 작업을 실행
double grade(double mid, double fin, const vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("No homework!");
	}

	// return (mid * 0.2 + fin * 0.4 + (hw1 + hw2 ...) / hw.size())
	// NEW grade() 함수
	return grade(mid, fin, median(hw));
}

// 계산하는 grade() 함수
double grade(double midterm, double final, double homework) {
	return midterm * 0.2 + final * 0.4 + homework * 0.4;

}


// Student_info 계산
double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info&) {
	return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	// vector<Student_info>::size_type i = 0;
	vector<Student_info>::iterator iter = students.begin();

	// 불변성: students 벡터의 [0, 1) 범위에 있는
	// 요소들은 과목을 통과한 학생들의 정보
	//while (i != students.size()) {
	while (iter != students.end()) {
		//if (fgrade(students[i])) {
		if (fgrade(*iter)) {
			// fail.push_back(students[i]);
			fail.push_back(*iter);
			// students.erase(students.begin() + i); // i 번째 제거
			iter = students.erase(iter);
		}
		else {
			// ++i;
			++iter;
		}
	}
	return fail;
}

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	// 불변성: students 벡터의 [0, 1) 범위에 있는
	// 요소들은 과목을 통과한 학생들의 정보
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			// ++i;
			++iter;
		}
	}
	return fail;
}

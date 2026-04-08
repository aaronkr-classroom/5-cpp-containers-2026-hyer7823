#include <iostream>     // 입출력
#include <vector>       // 벡터 사용
#include <string>       // 문자열 처리
#include <sstream>      // 문자열 분리
#include <algorithm>    // 정렬

using namespace std;

// 문자열을 공백 기준으로 나누는 함수
vector<string> splitWords(const string& line) {
    vector<string> words;          // 단어들을 저장할 벡터
    stringstream ss(line);         // 문자열 스트림 생성
    string word;

    // 공백 기준으로 단어 추출
    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

// 단어들을 하나의 문자열로 합치는 함수
string joinWords(const vector<string>& words) {
    string result;

    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";  // 마지막 단어가 아니면 공백 추가
    }

    return result;
}

int main() {
    vector<string> lines;       // 입력 문장들 저장
    vector<string> rotations;   // 모든 회전 결과 저장
    string input;

    cout << "문장을 입력하세요 (빈 줄 입력 시 종료):" << endl;

    // 여러 줄 입력 받기
    while (true) {
        getline(cin, input);

        if (input.empty())  // 빈 줄이면 입력 종료
            break;

        lines.push_back(input);
    }

    // 각 줄에 대해 처리
    for (const string& line : lines) {

        // 1. 단어 분리
        vector<string> words = splitWords(line);
        int n = words.size();

        // 2. 모든 회전 생성
        for (int i = 0; i < n; i++) {
            vector<string> rotated;

            // i번째 단어부터 끝까지
            for (int j = i; j < n; j++) {
                rotated.push_back(words[j]);
            }

            // 처음부터 i-1까지 뒤에 붙이기
            for (int j = 0; j < i; j++) {
                rotated.push_back(words[j]);
            }

            // 하나의 문자열로 합쳐서 저장
            rotations.push_back(joinWords(rotated));
        }
    }

    // 3. 사전순 정렬
    sort(rotations.begin(), rotations.end());

    // 4. 결과 출력
    cout << "\n=== 순열 인덱스 결과 ===" << endl;
    for (const string& r : rotations) {
        cout << r << endl;
    }

    return 0;
}

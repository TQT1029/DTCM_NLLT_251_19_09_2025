#include <iostream>
#include <string>
#include <vector>
#include  <random>

using namespace System;
using namespace std;

string RandomWord() {
	// Tạo engine và seed
	random_device rd;
	mt19937 gen(rd()); // Mersenne Twister engine

	// Tạo phân phối số nguyên từ 1 đến 100

	// Sẵn danh sách từ 5 ký tự (không dấu)
	vector<string> wordList = {
		"apple","grape","mango","peach","melon",
		"berry","lemon","olive","robot","tiger",
		"zebra","eagle","chair","table","radio",
		"light","sound","water","earth","flame",
		"couch","piano","shark","cocoa","chili"
	};

	int wordListLength = wordList.size() - 1;

	uniform_int_distribution<int> dist(0, wordListLength);
	int randomIndex = dist(gen);

	return wordList[randomIndex];
}

void checkWord(vector<bool>& checkBox, string inputAns, string result) {

	int countCorrectWord = 0;
	//kiểm tra số từ đúng
	for (int i = 0; i < 5; i++) {
		if (inputAns[i] == result[i]) {
			checkBox[i] = true;
			countCorrectWord++;
		}
	}
}

void SpoilAns(vector<bool> checkBox, string& spoilAns, string result) {
	for (int i = 0; i < 5; i++) {
        if (!checkBox[i]) {
            spoilAns[i] = result[i];
        }
    }

}

void main() {
	vector<bool> checkBox(5, false);
	string spoilAns = "*****";

	string result = RandomWord();
	string inputAns;

	cout << result << endl;
	//Số lần thử
	for (int i = 0; i < 5; i++) {
		cin >> inputAns;
		checkWord(checkBox, inputAns, result);


	}


}
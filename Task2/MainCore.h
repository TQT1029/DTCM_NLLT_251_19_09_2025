#pragma once
#include <string>
#include <vector>
#include <random>

class GameLogic {
private:
	std::string resultWord;
	std::string spoilAns;
	std::vector<bool> checkBox;
	int triesLeft;

	std::string RandomWord() {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::vector<std::string> wordList = {
			"apple","grape","mango","peach","melon",
			"berry","lemon","olive","robot","tiger",
			"zebra","eagle","chair","table","radio",
			"light","sound","water","earth","flame",
			"couch","piano","shark","cocoa","chili"
		};
		std::uniform_int_distribution<int> dist(0, (int)wordList.size() - 1);
		return wordList[dist(gen)];
	}

public:
	GameLogic() {
		StartGame();
	}

	void StartGame() {
		resultWord = RandomWord();
		spoilAns = "*****";
		checkBox = std::vector<bool>(5, false);
		triesLeft = 5;
	}

	// Trả về chuỗi gợi ý sau khi đoán
	std::string ProcessGuess(const std::string& guess, bool& win, bool& lose) {
		if (guess.length() != 5) return spoilAns;

		for (int i = 0; i < 5; i++) {
			if (guess[i] == resultWord[i]) {
				checkBox[i] = true;
				spoilAns[i] = resultWord[i];
			}
		}

		// Kiểm tra thắng
		win = true;
		for (int i = 0; i < 5; i++) {
			if (!checkBox[i]) { win = false; break; }
		}

		if (win) return spoilAns;

		// Giảm số lần thử
		triesLeft--;
		if (triesLeft == 0) {
			lose = true;
		}
		return spoilAns;
	}

	int GetTriesLeft() const { return triesLeft; }
	std::string GetAnswer() const { return resultWord; }
};

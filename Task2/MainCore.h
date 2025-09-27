#pragma once
#include <string>
#include <vector>
#include <random>

class GameLogic {
public:
	struct WordItem {
		std::string word;
		std::wstring description;
	};

	WordItem resultItem;              // chứa từ và mô tả
	std::string spoilAns;
	std::vector<bool> checkBox;
	std::vector<std::string> guessHistory; // lưu lịch sử đoán
	int triesLeft;

	WordItem RandomWord() {
		std::random_device rd;
		std::mt19937 gen(rd());

		std::vector<WordItem> wordList = {
			{"apple",   L"Thường được nhắc đến trong câu chuyện về khu vườn cấm. (Từ này có 5 chữ)"},
			{"astronomy", L"Khoa học nghiên cứu về các vì sao, hành tinh và vũ trụ. (Từ này có 9 chữ)"},
			{"berry",   L"Thường xuất hiện trên bánh ngọt hoặc được làm mứt. (Từ này có 5 chữ)"},
			{"chili",   L"Nhỏ bé nhưng có thể làm nóng cả món ăn. (Từ này có 5 chữ)"},
			{"cocoa",   L"Nguồn gốc của một loại đồ uống nóng được yêu thích vào mùa đông. (Từ này có 5 chữ)"},
			{"couch",   L"Vật dụng thường dùng để nằm xem TV. (Từ này có 5 chữ)"},
			{"dragon",  L"Sinh vật huyền thoại thường thở ra lửa trong truyền thuyết. (Từ này có 6 chữ)"},
			{"eagle",   L"Biểu tượng của tầm nhìn sắc bén và sức mạnh trên bầu trời. (Từ này có 5 chữ)"},
			{"earth",   L"Không chỉ là đất, mà còn là ngôi nhà của tất cả chúng ta. (Từ này có 5 chữ)"},
			{"flame",   L"Xuất hiện khi nhiệt độ quá cao và có chất dễ cháy. (Từ này có 5 chữ)"},
			{"galaxy",  L"Tập hợp khổng lồ của hàng tỷ ngôi sao, hành tinh và bụi vũ trụ. (Từ này có 6 chữ)"},
			{"grape",   L"Nhỏ bé nhưng khi kết hợp lại có thể tạo ra thức uống khiến người ta say. (Từ này có 5 chữ)"},
			{"jungle",  L"Khu rừng rậm rạp, nơi sinh sống của nhiều loài động vật hoang dã. (Từ này có 6 chữ)"},
			{"lemon",   L"Thường dùng làm gia vị, tạo vị chua mạnh. (Từ này có 5 chữ)"},
			{"light",   L"Thứ giúp xua tan bóng tối. (Từ này có 5 chữ)"},
			{"mango",   L"Một loại trái cây nhiệt đới, thường được cắt lát và ăn vào mùa hè. (Từ này có 5 chữ)"},
			{"melon",   L"Một loại quả lớn, thường được cắt miếng để giải nhiệt. (Từ này có 5 chữ)"},
			{"nebula",  L"Đám mây bụi và khí trong vũ trụ, nơi hình thành các ngôi sao mới. (Từ này có 6 chữ)"},
			{"olive",   L"Một loại quả nhỏ, dầu ép từ nó là nguyên liệu phổ biến toàn cầu. (Từ này có 5 chữ)"},
			{"peach",   L"Trong văn hóa phương Đông, nó được xem là biểu tượng của sự trường thọ. (Từ này có 5 chữ)"},
			{"piano",   L"Nhạc cụ có nhiều phím, âm thanh vừa mạnh mẽ vừa tinh tế. (Từ này có 5 chữ)"},
			{"quantum", L"Khái niệm vật lý mô tả các hạt cực nhỏ và hành vi kỳ lạ của chúng. (Từ này có 7 chữ)"},
			{"radio",   L"Thiết bị từng là công cụ chính để nghe tin tức trước thời kỳ internet. (Từ này có 5 chữ)"},
			{"robot",   L"Nhân vật thường thấy trong các câu chuyện tương lai về trí tuệ nhân tạo. (Từ này có 5 chữ)"},
			{"shark",   L"Kẻ săn mồi dưới biển, thường bị sợ hãi trong phim ảnh. (Từ này có 5 chữ)"},
			{"sound",   L"Thứ bạn không nhìn thấy nhưng có thể nghe được. (Từ này có 5 chữ)"},
			{"table",   L"Nó giữ cho đồ vật không rơi xuống đất. (Từ này có 5 chữ)"},
			{"tiger",   L"Động vật thường được gọi là 'chúa sơn lâm'. (Từ này có 5 chữ)"},
			{"water",   L"Không màu, không mùi, nhưng không có thì không có sự sống. (Từ này có 5 chữ)"},
			{"zebra",   L"Động vật có hoa văn như bàn phím đen trắng. (Từ này có 5 chữ)"}
		};

		std::uniform_int_distribution<int> dist(0, (int)wordList.size() - 1);
		return wordList[dist(gen)];
	}

public:
	GameLogic() {
		StartGame();
	}

	void StartGame() {
		resultItem = RandomWord();
		spoilAns = std::string(resultItem.word.length(), '*');
		checkBox = std::vector<bool>(resultItem.word.length(), false);
		guessHistory.clear(); // reset lịch sử khi bắt đầu game mới
		triesLeft = 5;
	}

	// 🔹 Hàm ResetGame (có thể gọi khi thắng hoặc muốn đổi từ)
	void ResetGame() {
		StartGame();
	}

	// Trả về chuỗi gợi ý sau khi đoán
	std::string ProcessGuess(const std::string& guess, bool& win, bool& lose) {
		if (guess.length() != resultItem.word.length()) return spoilAns;

		// Lưu vào lịch sử đoán
		guessHistory.push_back(guess);

		for (int i = 0; i < resultItem.word.length(); i++) {
			if (guess[i] == resultItem.word[i]) {
				checkBox[i] = true;
				spoilAns[i] = resultItem.word[i];
			}
		}

		// Kiểm tra thắng
		win = true;
		for (int i = 0; i < resultItem.word.length(); i++) {
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

	// Hàm lấy lịch sử đoán
	std::vector<std::string> GetGuessHistory() const {
		return guessHistory;
	}

	int GetTriesLeft() const { return triesLeft; }
	std::string GetAnswer() const { return resultItem.word; }
	std::wstring GetDescription() const { return resultItem.description; }
};

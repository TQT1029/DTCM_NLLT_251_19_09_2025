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
			{"apple",     L"Thứ quả từng khiến một cặp đôi trong truyền thuyết phải rời bỏ thiên đường, vừa ngọt ngào vừa ẩn chứa sự cám dỗ. (5 chữ)"},
			{"astronomy", L"Bộ môn mà con người ngước nhìn lên bầu trời đêm, cố gắng giải mã những chấm sáng xa xăm tưởng như bất tận. (9 chữ)"},
			{"banana",    L"Một nụ cười vàng cong cong của thiên nhiên, thường xuất hiện trong giỏ trái cây nhiệt đới. (6 chữ)"},
			{"berry",     L"Những viên ngọc nhỏ bé mọc thành chùm, thường để lại vết màu đỏ tím trên môi và ngón tay. (5 chữ)"},
			{"book",      L"Cánh cửa giấy dẫn lối bạn vào vô số thế giới, chỉ cần lật từng trang là bước vào một cuộc phiêu lưu. (4 chữ)"},
			{"bridge",    L"Chiếc cầu nối hai bờ xa cách, nơi con người vượt qua khoảng trống mà thiên nhiên tạo ra. (6 chữ)"},
			{"castle",    L"Pháo đài nguy nga, từng là nơi trú ngụ của những kẻ đội vương miện và những câu chuyện cổ tích. (6 chữ)"},
			{"chili",     L"Hạt lửa tí hon, chỉ cần chạm vào đầu lưỡi là cả thế giới bỗng bùng cháy trong khoảnh khắc. (5 chữ)"},
			{"cocoa",     L"Hạt nâu nhỏ bé, khi nghiền ra lại trở thành nguồn gốc của thứ ngọt ngào khiến cả thế giới say mê. (5 chữ)"},
			{"couch",     L"Người bạn im lặng trong phòng khách, luôn sẵn sàng đón bạn ngả lưng sau một ngày dài. (5 chữ)"},
			{"desert",    L"Biển cát mênh mông không có sóng, chỉ có gió và cái nóng thiêu đốt. (6 chữ)"},
			{"dragon",    L"Con vật chỉ tồn tại trong truyền thuyết, vừa là kẻ hủy diệt vừa là biểu tượng quyền năng, thở ra lửa. (6 chữ)"},
			{"eagle",     L"Kẻ thống trị bầu trời, đôi mắt sắc bén có thể nhìn thấy con mồi từ khoảng cách không tưởng. (5 chữ)"},
			{"earth",     L"Quả cầu xanh trôi nổi trong vũ trụ, nơi chứa đựng mọi câu chuyện của sự sống. (5 chữ)"},
			{"flame",     L"Điệu nhảy đỏ cam, bập bùng trong bóng tối, vừa sưởi ấm vừa có thể thiêu rụi tất cả. (5 chữ)"},
			{"forest",    L"Mê cung xanh thẳm, nơi ánh sáng khó lọt xuống và muôn loài ẩn mình. (6 chữ)"},
			{"galaxy",    L"Thành phố khổng lồ của các vì sao, xoay vần trong bóng tối vô tận. (6 chữ)"},
			{"garden",    L"Mảnh đất nhỏ nơi con người gieo hy vọng, để rồi nở thành hương sắc. (6 chữ)"},
			{"grape",     L"Những giọt ngọc mọc thành chùm, khi ép lại biến thành thứ chất lỏng khiến người ta chếnh choáng. (5 chữ)"},
			{"harmony",   L"Trạng thái khi mọi âm thanh, màu sắc và cảm xúc cùng hòa quyện thành một bản nhạc êm dịu. (7 chữ)"},
			{"ice",       L"Nước ngủ đông, lạnh lẽo và trong suốt, thường làm run rẩy đầu lưỡi khi chạm vào. (3 chữ)"},
			{"island",    L"Mảnh đất cô độc giữa biển cả, như một dấu chấm xanh nổi trên trang giấy xanh thẳm. (6 chữ)"},
			{"jungle",    L"Mê cung rậm rạp của cây cối và âm thanh hoang dã, nơi ánh sáng khó xuyên qua. (6 chữ)"},
			{"keyboard",  L"Dàn phím đen trắng hoặc nhựa cứng, mỗi lần chạm vào là một ký hiệu được sinh ra. (8 chữ)"},
			{"lemon",     L"Trái vàng tươi, chỉ một giọt nước cũng đủ khiến khuôn mặt nhăn lại vì vị chua gắt. (5 chữ)"},
			{"light",     L"Kẻ xua tan bóng tối, vô hình nhưng lại làm mọi thứ hiện rõ trước mắt. (5 chữ)"},
			{"mountain",  L"Gã khổng lồ bằng đá, đứng sừng sững, đỉnh đầu đôi khi đội chiếc mũ trắng bằng tuyết. (8 chữ)"},
			{"mango",     L"Trái cây nhiệt đới, vàng óng, ngọt ngào như mùa hè nằm gọn trong lòng bàn tay. (5 chữ)"},
			{"melon",     L"Quả tròn to, vỏ dày, bên trong chứa ngọt ngào mát lạnh của mùa hè. (5 chữ)"},
			{"nebula",    L"Đám mây vũ trụ rực rỡ, nơi những ngôi sao được sinh ra từ hỗn độn. (6 chữ)"},
			{"ocean",     L"Biển cả mênh mông, nơi sóng nối sóng, không thấy đâu là điểm dừng. (5 chữ)"},
			{"olive",     L"Quả nhỏ bé, khi ép ra lại thành thứ chất lỏng xanh vàng nuôi sống cả nền ẩm thực. (5 chữ)"},
			{"peach",     L"Trái cây có lớp áo mịn như nhung, bên trong là vị ngọt dịu dàng. (5 chữ)"},
			{"piano",     L"Cỗ máy âm thanh với hàng chục phím đen trắng, chỉ cần đôi tay lướt qua là cả bản nhạc vang lên. (5 chữ)"},
			{"quantum",   L"Thế giới kỳ lạ nơi hạt vừa là sóng vừa là hạt, nơi trực giác con người thường thất bại. (7 chữ)"},
			{"radio",     L"Hộp nhỏ biết nói, truyền những âm thanh từ nơi xa xôi đến tai bạn. (5 chữ)"},
			{"river",     L"Dải lụa bạc uốn lượn qua đồng bằng, mang theo sự sống từ núi cao ra biển cả. (5 chữ)"},
			{"robot",     L"Cỗ máy mang hình dáng con người, đôi khi ngoan ngoãn, đôi khi khiến ta lo sợ về tương lai. (5 chữ)"},
			{"shark",     L"Bóng đen lặng lẽ dưới làn nước xanh, hàm răng sắc bén khiến cả đại dương phải dè chừng. (5 chữ)"},
			{"sound",     L"Thứ vô hình, chỉ hiện hữu khi tai bạn rung lên, có thể là nhạc, tiếng cười hay tiếng khóc. (5 chữ)"},
			{"star",      L"Ngọn đèn nhỏ treo trên bầu trời đêm, lấp lánh nhưng xa vời vợi. (4 chữ)"},
			{"sunflower", L"Chiếc mặt trời thứ hai mọc từ lòng đất, luôn quay theo ánh sáng thật trên cao. (9 chữ)"},
			{"table",     L"Mặt phẳng bốn chân, nơi bữa ăn, sách vở và câu chuyện cùng tụ họp. (5 chữ)"},
			{"tiger",     L"Chiến binh rừng xanh khoác áo vằn, bước đi uy nghiêm khiến muôn loài nể sợ. (5 chữ)"},
			{"umbrella",  L"Chiếc lá nhân tạo, bung ra thành vòng tròn để che mưa nắng cho con người. (8 chữ)"},
			{"volcano",   L"Ngọn núi ngủ yên nhưng trong lòng chứa lửa, đôi khi thức giấc và phun trào dữ dội. (7 chữ)"},
			{"water",     L"Dòng chảy vô hình của sự sống, không màu không mùi nhưng nuôi dưỡng mọi sinh vật. (5 chữ)"},
			{"xylophone", L"Dãy thanh gỗ nhiều màu, mỗi cú gõ vang lên như tiếng cười trong trẻo. (9 chữ)"},
			{"yacht",     L"Con thuyền sang trọng, lướt trên sóng như một cung điện nổi. (5 chữ)"},
			{"zebra",     L"Con ngựa khoác áo sọc đen trắng, như thể vừa bước ra từ một bàn cờ. (5 chữ)"}
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

#pragma once

class Player {
private:
	std::string name;
	int money;
	int maxAP;
	std::string toolInven[2];
	std::string itemInven[24];
public:
	//새캐릭터
	Player(std::string _name) {
		name = _name;
		money = 0;
		maxAP = 100;
		for (int i = 0; i < 2; i++) {
			toolInven[i] = "비어 있음";
		}
		for (int i = 0; i < 24; i++) {
			itemInven[i] = "비어 있음";
		}
	}
	//불러오기
	//위에서 아래로 이름, 돈, ap, tool, item \n으로 구분
	Player() {
		std::string character;
		std::cout << "불러올 캐릭터의 이름을 입력하세요: ";
		std::cin >> character;
		std::ifstream load("./save/" + character + ".txt");


	}
};
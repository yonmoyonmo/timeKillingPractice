#pragma once
#include "tool.h"
#include "item.h"

class Player {
private:
	std::string name;
	int money;
	int maxAP;
	std::string toolInven[2];
	std::string itemInven[24];
	int itemlimit = 0;
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
		itemlimit = 0;
	}
	//불러오기
	//위에서 아래로 이름, 돈, ap, tool, item \n으로 구분
	Player() {
		std::string character;
		std::cout << "불러올 캐릭터의 이름을 입력하세요: ";
		std::cin >> character;
		std::string _money;
		std::string _AP;
		std::string _itemlimit;

		std::ifstream load("./save/" + character + ".txt");
	
		while (load.peek() != EOF) {
				std::getline(load, name);
				std::getline(load, _money);
				std::getline(load, _AP);
				std::getline(load, toolInven[0]);
				std::getline(load, toolInven[1]);
				for (int i = 0; i < 24; i++) {
					std::getline(load, itemInven[i]);
				}
				std::getline(load, _itemlimit);
			}
		load.close();
		money = std::stoi(_money);
		maxAP = std::stoi(_AP);
		itemlimit = std::stoi(_itemlimit);

	}
	void save() {
		std::ofstream save("./save/" + name + ".txt");
		
		save << name << std::endl;
		save << money << std::endl;
		save << maxAP << std::endl;
		save << toolInven[0] << std::endl;
		save << toolInven[1] << std::endl;
		for (int i = 0; i < 24; i++) {
			save << itemInven[i] << std::endl;
		}
		save << itemlimit << std::endl;
		save.close();
	}
	std::string getName() {
		return name;
	}
	int getMoney() {
		return money;
	}
	int getMaxAp() {
		return maxAP;
	}
	std::string getToolsInven(int choice) {
		return toolInven[choice];
	}
	void getItemInven() {
		for (int i = 0; i < 24; i++) {
			std::cout << itemInven[i]<<"\t"<<" | ";
			if (i == 5) std::cout << "\n";
			if (i == 11) std::cout << "\n";
			if (i == 17) std::cout << "\n";
			if (i == 23) std::cout << "\n";
		}
	}
	void getATool() {
		srand((unsigned int)time(NULL));
		int random = rand() % 2;
		Tool* tool = new Tool(random);
		toolInven[random] = tool->getNameOfTool();
	}
	void getAItem(int choice) {
		if (choice == 0) {
			if (toolInven[0] == "낚싯대") {
				Item* item = new Item(choice);
				if (itemlimit < 24) {
					itemInven[itemlimit] = item->getNameOfItem();
					itemlimit++;
				}
				else {
					std::cout << "템창이 꽉찼읍니다" << std::endl;
				}
			}
			else {
				std::cout << "낚싯대가 필요합니다" << std::endl;
			}
		}
		else if (choice == 1) {
			if (toolInven[1] == "잠자리채") {
				Item* item = new Item(choice);
				if (itemlimit < 24) {
					itemInven[itemlimit] = item->getNameOfItem();
					itemlimit++;
				}
				else {
					std::cout << "템창이 꽉찼읍니다" << std::endl;
				}
			}
			else {
				std::cout << "잠자리채가 필요합니다" << std::endl;
			}
		}
		else if (choice == 2) {
			Item* item = new Item(choice);
			if (itemlimit < 24) {
				itemInven[itemlimit] = item->getNameOfItem();
				itemlimit++;
			}
			else {
				std::cout << "템창이 꽉찼읍니다" << std::endl;
			}
		}
		else {
			std::cout << "오잉??" << std::endl;
		}
		
	}
	void sell() {
		if (0 <= itemlimit && itemlimit < 24) {
			srand((unsigned int)time(NULL));
			int random = rand() % 1000;
			money += random;
			itemInven[itemlimit] = "비어있음";
			if(itemlimit != 0) itemlimit--;
		}
		else {
			std::cout << "???????????????" << std::endl;
		}
	}
};
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

#include "player.h"
#include "item.h"
#include "tool.h"

Player& makeNewCharacter() {
	std::string name;
	std::cout << "캐릭터의 이름을 입력하라" << std::endl;
	std::cin >> name;
	Player* newone = new Player(name);
	return *newone;
}
Player& loadCharacter() {
	Player* oldone = new Player();
	return *oldone;
}
void printCharacterInfo(Player& player) {
	std::cout<<"&&& 이름: "<< player.getName() <<std::endl;
	std::cout <<"$$$ 돈: " << player.getMoney() << std::endl;
	std::cout <<"AP: "<< player.getMaxAp() << std::endl;
	std::cout <<"도구 1번 : "<< player.getToolsInven(0) << std::endl;
	std::cout << "도구 2번 : " << player.getToolsInven(1) << std::endl;
	player.getItemInven();
}

void getItem(Player& player) {
	std::cout << "0. 낚시  1.곤충채집  2.열매따기" << std::endl;
	int choice = 0;
	std::cin >> choice;
	player.getAItem(choice);
}


int main()
{
	Player guichana("none");
	Player& current = guichana;
	while (1) {
		std::cout << "===== (흙수저) 동물의 숲 =====" << std::endl;
		int choice;
		std::cout << "선택하시오" << std::endl;
		std::cout << "1. 새 캐릭터\t" << "2. 불러오기\t" << "3. 저장하기\t"<<std::endl;
		std::cout << "4. 도구얻기\t" << "5. 정보보기\t" << "6. 아이템얻기\t" << "7. 아이템팔기\t" << std::endl;
		std::cout << "0. 종료" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			current = makeNewCharacter();
			printCharacterInfo(current);
			break;
		case 2:
			current = loadCharacter();
			break;
		case 3:
			current.save();
			break;
		case 4:
			current.getATool();
			break;
		case 5:
			printCharacterInfo(current);
			break;
		case 6:
			getItem(current);
			break;
		case 7:
			current.sell();
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}



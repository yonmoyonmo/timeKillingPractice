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
	std::cout << player.getName() << std::endl;
	std::cout << player.getMoney() << std::endl;
	std::cout << player.getMaxAp() << std::endl;
	std::cout << player.getToolsInven(0) << std::endl;
}

int main()
{
	Player guichana("none");
	Player& current = guichana;
	std::cout << "test" << std::endl;
	std::cout << "=====" << std::endl;
	int choice;
	std::cout << "선택하시오" << std::endl;
	std::cout << "1. 새 캐릭터" << std::endl;
	std::cout << "2. 불러오기" << std::endl;
	std::cout << "3. 종료" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		current = makeNewCharacter();
		break;
	case 2:
		current = loadCharacter();
		break;
	case 3:
		exit(0);
		break;
	default:
		break;
	}
	printCharacterInfo(current);
	current.save();
	Sleep(5000);
	return 0;
}



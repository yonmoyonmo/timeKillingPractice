#pragma once

//ä��, ����, �ݱ� �� ��������
class Item {
private:
	std::string name;
	int price;
	int choice;
	std::string fishs[5] = {"�ؾ�","����","���","�˾Ҿ�","��¡��"};
	std::string bugs[5] = {"����","�������","��������","�ϴü�","�罿����" };
	std::string fruits[5] = { "���","������","����","��","�ڸ�" };
public:
	Item() {
		name = "none";
		price = 0;
		choice = -99;
	}
	Item(int ch) :choice(ch) {
		srand((unsigned int)time(NULL));
		int random = rand() % 5;
		if (choice == 0) name = fishs[random];
		else if (choice == 1) name == bugs[random];
		else if (choice == 2) name == fruits[random];
		price = rand() % 100;
	}
	int getPrice() {
		return price;
	}
	std::string getNameOfItem() {
		return name;
	}
	

};
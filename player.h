#pragma once

class Player {
private:
	std::string name;
	int money;
	int maxAP;
	std::string toolInven[2];
	std::string itemInven[24];
public:
	//��ĳ����
	Player(std::string _name) {
		name = _name;
		money = 0;
		maxAP = 100;
		for (int i = 0; i < 2; i++) {
			toolInven[i] = "��� ����";
		}
		for (int i = 0; i < 24; i++) {
			itemInven[i] = "��� ����";
		}
	}
	//�ҷ�����
	//������ �Ʒ��� �̸�, ��, ap, tool, item \n���� ����
	Player() {
		std::string character;
		std::cout << "�ҷ��� ĳ������ �̸��� �Է��ϼ���: ";
		std::cin >> character;
		std::ifstream load("./save/" + character + ".txt");


	}
};
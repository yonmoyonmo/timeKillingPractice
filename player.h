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
		std::string _money;
		std::string _AP;

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
			}
		load.close();
		money = std::stoi(_money);
		maxAP = std::stoi(_AP);

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
};
#pragma once

//Ã¤Áý, ³¬½Ã, ÁÝ±â ½Ã ·£´ý»ý¼º
class Item {
private:
	std::string name;
	int price;
	int choice;
	std::string fishs[5] = {"ºØ¾î","°íµî¾î","»ó¾î","¾Ë¾Ò¾î","¿ÀÂ¡¾î"};
	std::string bugs[5] = {"³ªºñ","¹«´ç¹ú·¹","¹ÙÄû¹ú·¹","ÇÏ´Ã¼Ò","»ç½¿¹ú·¹" };
	std::string fruits[5] = { "»ç°ú","º¹¼þ¾Æ","´ëÃß","¹è","ÀÚ¸ù" };
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
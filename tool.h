#pragma once

class Tool {
private:
	std::string name;
	int toolId;
public:
	Tool() {
		name = "none";
		toolId = -99;
	}
	Tool(int _toolId):toolId(_toolId) {
		if (toolId == 0) name = "���˴�";
		else if (toolId == 1) name = "���ڸ�ä";
	}
	std::string getNameOfTool() {
		return name;
	}
	int getIdOfTool() {
		return toolId;
	}
};
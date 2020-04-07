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
		if (toolId == 0) name = "≥¨ΩÀ¥Î";
		else if (toolId == 1) name = "¿·¿⁄∏Æ√§";
	}
	std::string getNameOfTool() {
		return name;
	}
	int getIdOfTool() {
		return toolId;
	}
};
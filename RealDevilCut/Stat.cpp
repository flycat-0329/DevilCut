#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Stat.h"

using namespace std;

Stat makeStat(string fileName) {
	ifstream statFile{ fileName };
	string line;
	Stat stat;
	vector<Stat> statList;

	if (!statFile) {
		cout << "스텟 파일에 그런 애 없어요" << endl;
		return stat;
	}

	while (getline(statFile, line)) {
		cout << line << endl;
		stringstream ss(line);

		string token;
		string temp_name;

		getline(ss, stat.name, ',');
		getline(ss, token, ','); stat.level = stoi(token);
		getline(ss, token, ','); stat.attack = stoi(token);
		getline(ss, token, ','); stat.def = stoi(token);
		getline(ss, token, ','); stat.spd = stoi(token);
		getline(ss, token, ','); stat.hp = stoi(token);
		getline(ss, token, ','); stat.gold = stoi(token);
		getline(ss, token, ','); stat.exp = stoi(token);

		statList.push_back(stat);
	}

	return statList[rand() % statList.size()];
}
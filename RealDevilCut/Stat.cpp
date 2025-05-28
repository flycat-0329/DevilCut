#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
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

void printStat(Stat stat) {
	system("cls");
	cout << "이름: " << stat.name << endl;
	cout << "레벨: " << stat.level << endl;
	cout << "EXP: " << stat.exp << "/" << exp_cap[stat.level - 1] << endl << endl;

	cout << "HP: " << stat.hp << endl;
	cout << "공격력: " << stat.attack << endl;
	cout << "방어력: " << stat.def << endl;
	cout << "스피드: " << stat.spd << endl << endl;

	cout << "보유금: " << stat.gold << endl;
	_getch();
}
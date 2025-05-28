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
		cout << "���� ���Ͽ� �׷� �� �����" << endl;
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
	cout << "�̸�: " << stat.name << endl;
	cout << "����: " << stat.level << endl;
	cout << "EXP: " << stat.exp << "/" << exp_cap[stat.level - 1] << endl << endl;

	cout << "HP: " << stat.hp << endl;
	cout << "���ݷ�: " << stat.attack << endl;
	cout << "����: " << stat.def << endl;
	cout << "���ǵ�: " << stat.spd << endl << endl;

	cout << "������: " << stat.gold << endl;
	_getch();
}
#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Stat {
	string name;
	int level = 1;
	int attack;
	int def;
	int spd;
	int hp;
	int gold;
	int exp;
};

Stat makeStat(string fileName);

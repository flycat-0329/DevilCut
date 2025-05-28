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

extern int exp_cap[10];

Stat makeStat(string fileName);
void printStat(Stat stat);

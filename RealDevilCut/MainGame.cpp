#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Stat.h"
using namespace std;

Stat player;
int exp_cap[5] = { 10, 20, 30, 40, 50 };

void deadEvent() {

}

void battle(Stat monster) {
	system("cls");
	int playerSelect;
	int firstAttack;

	while (true) {
		system("cls");
		cout << "					���� ����" << endl << endl;
		cout << "					" << monster.name << endl;
		cout << "					HP: " << monster.hp << endl << endl;

		cout << "�� ����" << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "���ݷ�: " << player.attack << endl;
		cout << "����: " << player.def << endl;
		cout << "���ǵ�: " << player.spd << endl << endl;
		cout << "1. ����\n2. ��������" << endl;
		cin >> playerSelect;
		switch (playerSelect) {
		case 1:
			if (player.spd == monster.spd) {
				firstAttack = rand() % 2;
			}
			else if (player.spd > monster.spd) {
				firstAttack = 0;	//�÷��̾� ����
			}
			else {
				firstAttack = 1;	//���� ����
			}

			if (firstAttack == 0) {
				monster.hp -= static_cast<int>((player.attack - monster.def) * ((static_cast<double>(rand()) / RAND_MAX) * 0.2 + 0.9));
				if (monster.hp <= 0) {
					player.exp += monster.exp;
					if (player.exp >= exp_cap[player.level - 1]) {
						player.exp -= exp_cap[player.level - 1];
						player.level += 1;
					}

					return;
				}
				player.hp -= static_cast<int>((monster.attack - player.def) * ((static_cast<double>(rand()) / RAND_MAX) * 0.2 + 0.9));
				if (player.hp <= 0) {
					deadEvent();
				}
			}
			else {
				player.hp -= static_cast<int>((monster.attack - player.def) * ((static_cast<double>(rand()) / RAND_MAX) * 0.2 + 0.9));
				if (player.hp <= 0) {
					deadEvent();
				}
				monster.hp -= static_cast<int>((player.attack - monster.def) * ((static_cast<double>(rand()) / RAND_MAX) * 0.2 + 0.9));
				if (monster.hp <= 0) {
					player.exp += monster.exp;
					if (player.exp >= exp_cap[player.level - 1]) {
						player.exp -= exp_cap[player.level - 1];
						player.level += 1;
					}
				}
			}
			break;
		case 2:
			int runSwitch = rand() % 100;

			if (runSwitch < 50 + (player.spd - monster.spd) * 5) {
				cout << "����� ������ �����ƴ�!" << endl;
				_getch();
				return;
			}
			else {
				cout << "����� ����ġ�� ������ �ݻ� ���������� ���Ҵ�." << endl;
				_getch();
			}
		}
	}
}

int main() {
	string playerName;
	cout << "����� �̸��� �Է����ּ���." << endl;
	cin >> playerName;

	player.name = playerName;
	player.level = 1;
	player.attack = 10;
	player.def = 2;
	player.spd = 5;
	player.hp = 100;
	player.exp = 0;
	player.gold = 0;

	srand(time(NULL));

	while (true) {
		system("cls");

		int randomSwitch = rand() % 1;
		switch (randomSwitch) {
		case 0:
			cout << "����� ������ ���� ��ó���� ���͸� ������." << endl;
			_getch();
			cout << "�༮�� ���� �ο򿡼� �з� �� ������ ������ �� ����̴�." << endl;
			_getch();
			cout << "����� ���� �¼��� ����." << endl;
			_getch();
			battle(makeStat("basicMonsterStat.txt"));
		case 1:
			cout << "����� �� ���� �ɾ�� �� ���͸� ������." << endl;
			_getch();
			cout << "�������� ������ �༮���� Ȯ���� ���غ��δ�." << endl;
			_getch();
			cout << "����� ���� �¼��� ����." << endl;
			_getch();
			battle(makeStat("normalMonsterStat.txt"));
		case 2:
			cout << "�� �ӿ��� �߿��� �ϴ� �� ���� ������ ������." << endl;
			_getch();
			cout << "�ƹ����� ���� ���� ���� ���� ���� �� ����." << endl;
			_getch();
			cout << "����� ���� �¼��� ����." << endl;
			_getch();
			battle(makeStat("normalMonsterStat.txt"));
			cout << "������ �����ϴ� ����� ��� �� ���� ������ ���常�� �����ִٴ� ����� ���ݴ´�." << endl;
			_getch();
			cout << "�� �༮ ��ŭ�� ���� �̱��� ���ϸ���� ������ ���." << endl;
			cout << "1. �ο��.\n2. ����ģ��." << endl;
			int temp;
			cin >> temp;

			if (temp == 1) {
				battle(makeStat("strongMonsterStat.txt"));
			}
			else {
				cout << "����� ������� �����ƴ�." << endl;
				_getch();
				cout << "����� ����ġ�� ������ �� ������ �� ���͸� ����Ʈ������ �����ߴ�." << endl;
				_getch();
			}
		case 3:
			cout << "����� ��� ���� �߿� ������ �߰��ߴ�." << endl;
			_getch();
			int temp = rand() % 3;
			if (temp == 0) {
				player.attack += 1; 
				cout << "����� ���� ���� �� ������ ����� ���." << endl;
				_getch();
			}
			else if(temp == 0) player.def += 1;
			else if(temp == 0) player.spd += 1;
		}
	}
}
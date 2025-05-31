#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ios>
#include <limits>
#include "Stat.h"
using namespace std;

Stat player;
int exp_cap[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

void deadEvent() {
	system("cls");
	cout << "���� �� �̻� �������� �ʴ´�." << endl;
	Sleep(1000);
	cout << "�� �ָ��� �������� �ٰ��´�." << endl;
	Sleep(1000);
	cout << "�������� ����̰� ������ ���� ���ٴ�.. ȯ���ΰ�?" << endl << endl;
	Sleep(2000);
	exit(0);
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

		while (true) {
			cin >> playerSelect;

			if (cin) {
				break;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}

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
					return;
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

void village() {
	int villageSwitch;

	system("cls");
	cout << "����� ������ �ϴ� ���� ������ ������ �ִٴ� ���� �߰��ߴ�." << endl;
	_getch();
	cout << "������ ������?" << endl << endl;
	_getch();
	cout << "1. ����" << endl << "2. ���� �ʴ´�" << endl;

	while (true) {
		cin >> villageSwitch;

		if (cin) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	switch (villageSwitch) {
	case 1:
		int sellSelect;
		int sleepSelect;
		bool isBuy = false;
		bool buyEnd = false;

		system("cls");
		cout << "����� �������� ���� Ȯ���ϰ� �ϰ� ����� �ߴ�." << endl;
		_getch();
		cout << "�� �� ������ ����� �θ���." << endl;
		_getch();
		cout << "����: �� ��! �ڳ� ���谡�ΰ�? ���� �ͼ� ���� �� �غ��� �ʰڳ�?" << endl << endl;
		_getch();

		while (true) {
			system("cls");
			cout << "������: " << player.gold << endl << endl;
			cout << "1. Ư�� ö �� (30G)" << endl << "���ݷ� + 5" << endl << endl;
			cout << "2. Ư�� �� ��Ʈ (50G)" << endl << "���� + 3" << endl << endl;
			cout << "3. Ư�� �Ź� (30G)" << endl << "���ǵ� + 3" << endl << endl;
			cout << "4. ���� ����" << endl;

			while (true) {
				cin >> sellSelect;

				if (cin) {
					break;
				}
				else {
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}

			switch (sellSelect) {
			case 1:
				if (player.gold >= 30) {
					player.gold -= 30;
					player.attack += 5;
					isBuy = true;
				}
				break;
			case 2:
				if (player.gold >= 50) {
					player.gold -= 50;
					player.def += 3;
					isBuy = true;
				}
				break;
			case 3:
				if (player.gold >= 30) {
					player.gold -= 30;
					player.spd += 3;
					isBuy = true;
				}
				break;
			case 4:
				buyEnd = true;
				break;
			}
			if (buyEnd) break;
		}
		
		system("cls");
		if (isBuy == true) {
			cout << "����: ���� �ŷ�����! ���谡 ���, �������� �� �鷯�޶��!" << endl;
			cout << "���� ���� ���ǵ��� �غ����״ϱ� ���̾�!! ũ������!!" << endl;
			_getch();
		}
		else {
			cout << "����, �ƹ� �͵� ���� �ʴ°ǰ�? �װ� �� �ƽ���" << endl;
			cout << "������ �� �ٽ� �鷯�ֽð�. �� ���� ���ǵ��� �������״ϱ� ���̾�!" << endl;
			_getch();
		}

		system("cls");
		cout << "������ ��� ���ƴٴϴٺ��� ���� �߽ɰ��� �ڸ����� ������ ������." << endl;
		cout << "�ƹ����� ������ �� ������ ���� ���� ���� �� ����." << endl << endl;
		cout << "1. ���� ����\n2. �� ���� �ٻڴ�. ������ ������ �����." << endl;

		while (true) {
			cin >> sleepSelect;

			if (cin) {
				break;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}

		system("cls");
		switch (sleepSelect) {
		case 1:
			cout << "����� �������� ����� �Ϸ� ���� ���´�." << endl;
			cout << "�Ƿΰ� ������ ȸ���� ������ �޾Ҵ�!" << endl;
			player.hp = 100;
			_getch();
			break;
		case 2:
			cout << "����� ������ ���� ������ ���ư���." << endl;
			cout << "ǫ���� ħ��� ���ִ� ������ �� �տ��� �Ƹ��ŷ����� �ֽ� �����Ѵ�." << endl;
			cout << "�� �� ����� ���� �ӿ��� ������ ������ ��������." << endl;

			int r = rand() % 3;
			switch (r) {
			case 0:
				player.attack += 3;
				cout << "���ݷ��� 3 �����Ͽ����ϴ�." << endl;
				_getch();
				break;
			case 1:
				player.def += 2;
				cout << "������ 2 �����Ͽ����ϴ�." << endl;
				_getch();
				break;
			case 2:
				player.spd += 1;
				cout << "���ǵ尡 1 �����Ͽ����ϴ�." << endl;
				_getch();
				break;
			}
		}
	}
}

int main() {
	string playerName;
	cout << "����� �̸��� �Է����ּ���." << endl;
	cin >> playerName;

	//���ΰ� ���� init
	player.name = playerName;
	player.level = 1;
	player.attack = 10;
	player.def = 2;
	player.spd = 5;
	player.hp = 100;
	player.exp = 0;
	player.gold = 0;

	int turnCount = 0;

	srand(time(NULL));

	//��Ʈ�� ����
	system("cls");
	cout << "���� ��ﵵ ���� �ʴ� ���� �Ʊ� ���� �θ𿡰� ��������." << endl;
	cout << "�� �ӿ� ������ ���� ������ �� �� �Ǹ� ��ɲ��̾���." << endl;
	_getch();
	cout << endl << "������ �����غ��� �������� �� �̼��� ����̾���." << endl;
	cout << "������ �������� ���θ����� Ȧ�� ������ �������� ���ڱ� ���� ���̸� �� Ű�� �� ������ ������." << endl;
	cout << "�Ϸ簡 �ִ��ϰ� ������ ������ ������ ������ �޷��� ��, ���� ���̴� �� ���� ����ôٰ� �Ѵ�." << endl;
	_getch();
	cout << endl << "�׷��ٰ� ���̿��� ����� �� ����� ǥ���ϴ� ����� �ƴϾ���." << endl;
	cout << "��� �Ʒ��� ��Ű�鼭�� ����Ѵٴ� ���� Ŀ�� Ī�� �� �������� �β������ߴ� ������������" << endl;
	cout << "�׷����� �������� ���� ����Ѵٴ� �͸�ŭ�� �� �� �־���." << endl;
	_getch();
	cout << endl << "�׷��ϱ� ������..." << endl;
	_getch();
	cout << endl << "���� �������� ������ �Ϸ� ���ٰ� �ص� �ʹ� �̿������� ������." << endl;
	_getch();
	//������� ��Ʈ��

	while (true) {
		system("cls");
		int playerSelect;
		cout << "1. ������ ����Ѵ�" << endl;
		cout << "2. �� �ɷ�ġ�� ����" << endl;
		cout << "3. ������ ��ģ��" << endl;

		while (true) {
			cin >> playerSelect;

			if (cin) {
				break;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}

		system("cls");

		int randomSwitch = rand() % 4;
		switch (playerSelect) {
		case 1:		//������ �������� ��
			turnCount++;

			if (player.level >= 10) {
				cout << "���� �����߳�..." << endl;
				_getch();
				cout << "�� ���� ���̰� �������� ������ �ϰھ�!" << endl;
				_getch();
				cout << endl << "�׾��!!" << endl;
				_getch();
				battle(makeStat("bossStat.txt"));
			}

			switch (randomSwitch) {
			case 0:
				cout << "����� ������ ���� ��ó���� ���͸� ������." << endl;
				_getch();
				cout << "�༮�� ���� �ο򿡼� �з� �� ������ ������ �� ����̴�." << endl;
				_getch();
				cout << "����� ���� �¼��� ����." << endl;
				_getch();
				battle(makeStat("basicMonsterStat.txt"));
				break;
			case 1:
				cout << "����� �� ���� �ɾ�� �� ���͸� ������." << endl;
				_getch();
				cout << "�������� ������ �༮���� Ȯ���� ���غ��δ�." << endl;
				_getch();
				cout << "����� ���� �¼��� ����." << endl;
				_getch();
				battle(makeStat("normalMonsterStat.txt"));
				break;
			case 2:
				cout << "�� �ӿ��� �߿��� �ϴ� �� ���� ������ ������." << endl;
				_getch();
				cout << "�ƹ����� ���� ���� ���� ���� ���� �� ����." << endl;
				_getch();
				cout << "����� ���� �¼��� ����." << endl;
				_getch();
				battle(makeStat("normalMonsterStat.txt"));
				system("cls");
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
				break;
			case 3:
				cout << "����� ��� ���� �߿� �ź�ο� ������ �߰��ߴ�." << endl;
				_getch();
				int t = rand() % 3;
				if (t == 0) {
					player.attack += 1;
					cout << "����� ���� ���� �� ������ ����� ���." << endl;
				}
				else if (t == 1) {
					player.def += 1;
					cout << "����� ���� ���� �� �ܴ����� ����� ���." << endl;
				}
				else if (t == 2) {
					player.spd += 1;
					cout << "����� ���� ���� �� �������� ����� ���." << endl;
				}
				_getch();
				break;
			}

			if (turnCount % 4 == 0) {
				village();
			}
			break;
		case 2:
			printStat(player);
			break;

		case 3:
			exit(0);
			break;
		}
	}
}
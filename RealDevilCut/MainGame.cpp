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
		cout << "					몬스터 정보" << endl << endl;
		cout << "					" << monster.name << endl;
		cout << "					HP: " << monster.hp << endl << endl;

		cout << "내 정보" << endl << endl;
		cout << "HP: " << player.hp << endl;
		cout << "공격력: " << player.attack << endl;
		cout << "방어력: " << player.def << endl;
		cout << "스피드: " << player.spd << endl << endl;
		cout << "1. 공격\n2. 도망가기" << endl;
		cin >> playerSelect;
		switch (playerSelect) {
		case 1:
			if (player.spd == monster.spd) {
				firstAttack = rand() % 2;
			}
			else if (player.spd > monster.spd) {
				firstAttack = 0;	//플레이어 선공
			}
			else {
				firstAttack = 1;	//몬스터 선공
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
				cout << "당신은 무사히 도망쳤다!" << endl;
				_getch();
				return;
			}
			else {
				cout << "당신은 도망치려 했지만 금새 따라잡히고 말았다." << endl;
				_getch();
			}
		}
	}
}

int main() {
	string playerName;
	cout << "당신의 이름을 입력해주세요." << endl;
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
			cout << "당신은 지나온 마을 근처에서 몬스터를 만났다." << endl;
			_getch();
			cout << "녀석은 영역 싸움에서 밀려 숲 밖으로 도망쳐 온 모양이다." << endl;
			_getch();
			cout << "당신은 전투 태세에 들어갔다." << endl;
			_getch();
			battle(makeStat("basicMonsterStat.txt"));
		case 1:
			cout << "당신은 숲 길을 걸어가던 중 몬스터를 만났다." << endl;
			_getch();
			cout << "마을에서 만났던 녀석보다 확실히 강해보인다." << endl;
			_getch();
			cout << "당신은 전투 태세에 들어갔다." << endl;
			_getch();
			battle(makeStat("normalMonsterStat.txt"));
		case 2:
			cout << "숲 속에서 야영을 하던 중 몬스터 무리를 만났다." << endl;
			_getch();
			cout << "아무래도 오늘 밤은 편히 쉬지 못할 것 같다." << endl;
			_getch();
			cout << "당신은 전투 태세에 들어갔다." << endl;
			_getch();
			battle(makeStat("normalMonsterStat.txt"));
			cout << "전투에 몰입하던 당신은 어느 새 몬스터 무리의 대장만이 남아있다는 사실을 깨닫는다." << endl;
			_getch();
			cout << "저 녀석 만큼은 쉽게 이기지 못하리라는 생각이 든다." << endl;
			cout << "1. 싸운다.\n2. 도망친다." << endl;
			int temp;
			cin >> temp;

			if (temp == 1) {
				battle(makeStat("strongMonsterStat.txt"));
			}
			else {
				cout << "당신은 재빠르게 도망쳤다." << endl;
				_getch();
				cout << "당신은 도망치며 언젠가 더 강해져 저 몬스터를 쓰러트리리라 다짐했다." << endl;
				_getch();
			}
		case 3:
			cout << "당신은 고된 여정 중에 샘물을 발견했다." << endl;
			_getch();
			int temp = rand() % 3;
			if (temp == 0) {
				player.attack += 1; 
				cout << "당신은 힘이 조금 더 강해진 기분이 든다." << endl;
				_getch();
			}
			else if(temp == 0) player.def += 1;
			else if(temp == 0) player.spd += 1;
		}
	}
}
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
	cout << "몸이 더 이상 움직이지 않는다." << endl;
	Sleep(1000);
	cout << "저 멀리서 누군가가 다가온다." << endl;
	Sleep(1000);
	cout << "이족보행 고양이가 수레를 끌고 오다니.. 환각인가?" << endl << endl;
	Sleep(2000);
	exit(0);
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
					return;
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

void village() {
	int villageSwitch;

	system("cls");
	cout << "당신은 모험을 하던 도중 쉴만한 마을이 있다는 것을 발견했다." << endl;
	_getch();
	cout << "마을에 들어가볼까?" << endl << endl;
	_getch();
	cout << "1. 들어간다" << endl << "2. 들어가지 않는다" << endl;

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
		cout << "당신은 마을에서 정비를 확실하게 하고 가기로 했다." << endl;
		_getch();
		cout << "그 때 상인이 당신을 부른다." << endl;
		_getch();
		cout << "상인: 이 봐! 자네 모험가인가? 여기 와서 구경 좀 해보지 않겠나?" << endl << endl;
		_getch();

		while (true) {
			system("cls");
			cout << "소지금: " << player.gold << endl << endl;
			cout << "1. 특제 철 검 (30G)" << endl << "공격력 + 5" << endl << endl;
			cout << "2. 특제 방어구 세트 (50G)" << endl << "방어력 + 3" << endl << endl;
			cout << "3. 특제 신발 (30G)" << endl << "스피드 + 3" << endl << endl;
			cout << "4. 구매 종료" << endl;

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
			cout << "상인: 좋은 거래였어! 모험가 양반, 다음에도 꼭 들러달라고!" << endl;
			cout << "더욱 좋은 물건들을 준비할테니까 말이야!! 크하하하!!" << endl;
			_getch();
		}
		else {
			cout << "뭐야, 아무 것도 사지 않는건가? 그것 참 아쉽군" << endl;
			cout << "다음에 꼭 다시 들러주시게. 더 좋은 물건들을 가져올테니까 말이야!" << endl;
			_getch();
		}

		system("cls");
		cout << "마을을 잠시 돌아다니다보니 마을 중심가에 자리잡은 여관이 보였다." << endl;
		cout << "아무래도 오늘은 저 곳에서 묵는 것이 좋을 것 같다." << endl << endl;
		cout << "1. 묵고 간다\n2. 갈 길이 바쁘다. 빠르게 마을을 벗어나자." << endl;

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
			cout << "당신은 여관에서 편안한 하루 밤을 보냈다." << endl;
			cout << "피로가 완전히 회복된 느낌을 받았다!" << endl;
			player.hp = 100;
			_getch();
			break;
		case 2:
			cout << "당신은 모험을 위해 앞으로 나아갔다." << endl;
			cout << "푹신한 침대와 맛있는 음식이 눈 앞에서 아른거렸지만 애써 무시한다." << endl;
			cout << "그 때 당신의 마음 속에서 강인한 의지가 느껴졌다." << endl;

			int r = rand() % 3;
			switch (r) {
			case 0:
				player.attack += 3;
				cout << "공격력이 3 증가하였습니다." << endl;
				_getch();
				break;
			case 1:
				player.def += 2;
				cout << "방어력이 2 증가하였습니다." << endl;
				_getch();
				break;
			case 2:
				player.spd += 1;
				cout << "스피드가 1 증가하였습니다." << endl;
				_getch();
				break;
			}
		}
	}
}

int main() {
	string playerName;
	cout << "당신의 이름을 입력해주세요." << endl;
	cin >> playerName;

	//주인공 스텟 init
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

	//인트로 시작
	system("cls");
	cout << "나는 기억도 나지 않는 갓난 아기 시절 부모에게 버려졌다." << endl;
	cout << "숲 속에 버려진 나를 구해준 건 한 악마 사냥꾼이었다." << endl;
	_getch();
	cout << endl << "돌이켜 생각해보면 아저씨는 참 미숙한 사람이었다." << endl;
	cout << "마을과 동떨어진 오두막에서 홀로 지내던 아저씨가 갑자기 생긴 아이를 잘 키울 수 있을리 없었다." << endl;
	cout << "하루가 멀다하고 마을에 내려가 아이의 울음을 달래는 법, 밥을 먹이는 법 등을 물어봤다고 한다." << endl;
	_getch();
	cout << endl << "그렇다고 아이에게 제대로 된 사랑을 표현하는 사람도 아니었다." << endl;
	cout << "고된 훈련을 시키면서도 사랑한다는 말은 커녕 칭찬 한 마디조차 부끄러워했던 아저씨였지만" << endl;
	cout << "그럼에도 아저씨가 나를 사랑한다는 것만큼은 알 수 있었다." << endl;
	_getch();
	cout << endl << "그러니까 아저씨..." << endl;
	_getch();
	cout << endl << "내가 아저씨의 복수를 하러 간다고 해도 너무 미워하지는 말아줘." << endl;
	_getch();
	//여기까지 인트로

	while (true) {
		system("cls");
		int playerSelect;
		cout << "1. 여행을 계속한다" << endl;
		cout << "2. 내 능력치를 본다" << endl;
		cout << "3. 여행을 마친다" << endl;

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
		case 1:		//전투를 선택했을 때
			turnCount++;

			if (player.level >= 10) {
				cout << "드디어 도달했나..." << endl;
				_getch();
				cout << "네 놈을 죽이고 아저씨의 복수를 하겠어!" << endl;
				_getch();
				cout << endl << "죽어라!!" << endl;
				_getch();
				battle(makeStat("bossStat.txt"));
			}

			switch (randomSwitch) {
			case 0:
				cout << "당신은 지나온 마을 근처에서 몬스터를 만났다." << endl;
				_getch();
				cout << "녀석은 영역 싸움에서 밀려 숲 밖으로 도망쳐 온 모양이다." << endl;
				_getch();
				cout << "당신은 전투 태세에 들어갔다." << endl;
				_getch();
				battle(makeStat("basicMonsterStat.txt"));
				break;
			case 1:
				cout << "당신은 숲 길을 걸어가던 중 몬스터를 만났다." << endl;
				_getch();
				cout << "마을에서 만났던 녀석보다 확실히 강해보인다." << endl;
				_getch();
				cout << "당신은 전투 태세에 들어갔다." << endl;
				_getch();
				battle(makeStat("normalMonsterStat.txt"));
				break;
			case 2:
				cout << "숲 속에서 야영을 하던 중 몬스터 무리를 만났다." << endl;
				_getch();
				cout << "아무래도 오늘 밤은 편히 쉬지 못할 것 같다." << endl;
				_getch();
				cout << "당신은 전투 태세에 들어갔다." << endl;
				_getch();
				battle(makeStat("normalMonsterStat.txt"));
				system("cls");
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
				break;
			case 3:
				cout << "당신은 고된 여정 중에 신비로운 샘물을 발견했다." << endl;
				_getch();
				int t = rand() % 3;
				if (t == 0) {
					player.attack += 1;
					cout << "당신은 힘이 조금 더 강해진 기분이 든다." << endl;
				}
				else if (t == 1) {
					player.def += 1;
					cout << "당신은 뼈가 조금 더 단단해진 기분이 든다." << endl;
				}
				else if (t == 2) {
					player.spd += 1;
					cout << "당신은 몸이 조금 더 가벼워진 기분이 든다." << endl;
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
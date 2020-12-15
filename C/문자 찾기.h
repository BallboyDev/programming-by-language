#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Person {
public:
	string *name = new string[number()];
	int num;
	int number() {
		cout << "참가 인원수를 입력하세요 : ";
		cin >> num;
		return num;
	}
	void names() {
		for (int k = 0; k < num; k++) {
			cout << "참가자 이름을 입력하세요 : ";
			cin >> name[k];
		}
	}
};

class UpAndDownGame :public Person {
	static int RNumber;
	static char min, max, mid;
	
public:
	static int answer(); //렌덤 숫자 출력
	static void GameStart();
};

char UpAndDownGame::min = 65;
char UpAndDownGame::max = 90;
char UpAndDownGame::mid = 0;
int UpAndDownGame::RNumber = answer();

int UpAndDownGame::answer() {
	srand((unsigned)time(0));
	int n = (rand() % 26)+65;
	return n;
}

void UpAndDownGame::GameStart() {
	cout << "Up & Down 게임을 시작합니다." << endl;
	Person player;
	player.names();
	int i = 0;
	while (mid != RNumber) {
		cout << "답은 " << min << "과 " << max << "사이에 있습니다." << endl;
		cout << player.name[i] << " >> ";
		cin >> mid;
		if (mid == RNumber) {
			cout << player.name[i] << "이 이겼습니다." << endl;
			break;
		}
		else if (mid > RNumber) max = mid;
		else min = mid;
		i++;
		i = i % player.num;
	}
}

int main() {
	UpAndDownGame::GameStart();

}//드디어 완성 !!!!!!!!!!!!!!!!!!!!!!!!!!!ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 존나 행복해 ㅋㅋㅋㅋ

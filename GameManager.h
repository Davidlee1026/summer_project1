#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Monster.h"
#include <vector>
#include <string>

using namespace std;

class GameManager {
private:
	Player* player;
	Monster* monster;
	int monsterCount;
	int turn;
	bool monsterJustRespawned = false;

	vector<int> eventTurns; // ���� �̺�Ʈ �� ����

	void GenerateEarlyEventTurns();
	void CheckEventTurn();
	bool ShouldTriggerRandomEvent();
	void TriggerRandomEvent();

public:
	GameManager(const string& playername);
	~GameManager();

	void startGame();
	void PlayerTurn();
	void MonsterTurn();
	void PrintStatus();
	bool IsGameover();
	int getMonsterKillCount() const;
	int getTurnCount() const;
};

#endif 
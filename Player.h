#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>
using namespace std;

class Player : public Character {
private:
    int ultimateCooldown;
    int healCooldown;

public:
    Player(const string& name, int hp);

    void basicAttack(Character& target);
    void skill2(Character& target);         // ġ��Ÿ ����
    void ultimateSkill(Character& target);  // �ñر�
    void heal();                            // ȸ��

    void reduceCooldowns();  // �ϸ��� ��Ÿ�� ����

    bool canUseUltimate() const;
    bool canUseHeal() const;

    void printStatus() const override;
};

#endif

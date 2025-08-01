#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(const string& name, int hp)
    : name(name), hp(hp), maxHp(hp) {
}

void Character::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
    cout << name << "��/�� " << damage << "�� �������� �Ծ����ϴ�. (HP: " << hp << "/" << maxHp << ")\n";
}

void Character::heal(int amount) {
    hp += amount;
    if (hp > maxHp) hp = maxHp;
    cout << name << "��/�� " << amount << "��ŭ ü���� ȸ���߽��ϴ�. (HP: " << hp << "/" << maxHp << ")\n";
}

bool Character::isAlive() const {
    return hp > 0;
}

string Character::getName() const {
    return name;
}

int Character::getHP() const {
    return hp;
}

int Character::getMaxHP() const {
    return maxHp;
}

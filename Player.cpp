#include "Player.h"
#include <iostream>
#include <cstdlib> // rand() 사용을 위해 필요
// #include <ctime> // srand()가 main으로 이동했으므로 여기서는 불필요
using namespace std;

Player::Player(const string& name, int hp)
    : Character(name, hp), ultimateCooldown(0), healCooldown(0) {
    // srand()는 main 함수에서 한 번만 호출되도록 수정됨
}

void Player::basicAttack(Character& target) {
    int damage = 10;
    cout << name << "이/가 기본 공격을 사용했습니다!\n";
    target.takeDamage(damage);
}

void Player::skill2(Character& target) {
    cout << name << "이/가 치명타 스킬을 사용했습니다!\n";
  
    int critChance = rand() % 100; // 0~99
    int damage = (critChance < 30) ? 30 : 15; // 30% 확률로 30 데미지, 아니면 15


    if (critChance < 30)
        cout << "치명타 성공!! ";
    else
        cout << "치명타 실패. ";

    target.takeDamage(damage);
}

bool Player::ultimateSkill(Character& target) {
    if (canUseUltimate()) {
        cout << name << "이/가 궁극기를 사용했습니다!\n";
        target.takeDamage(50);
        ultimateCooldown = 5; // 쿨타임 설정
        return true;
    }
    else {
        cout << "궁극기는 아직 쿨타임입니다. (" << ultimateCooldown << "턴 남음)\n";
        return false;
    }
}

bool Player::heal() {
    if (canUseHeal()) {
        int healAmount = static_cast<int>((maxHp - hp) * 0.5); // 잃은 체력의 50% 회복
        if (healAmount <= 0) { // 체력이 가득 찼거나 회복량이 0 이하일 경우
            cout << name << "의 체력이 이미 가득 찼습니다!\n";
            return false;
        }
        Character::heal(healAmount); // 부모 클래스의 heal 함수 호출
        healCooldown = 3; // 쿨타임 설정
        return true;
    }
    else {
        cout << "힐은 아직 쿨타임입니다. (" << healCooldown << "턴 남음)\n";
        return false;
    }
}

int Player::getUltimateCooldown() const {
    return ultimateCooldown;
}

int Player::getHealCooldown() const {
    return healCooldown;
}


void Player::reduceCooldowns() {
    if (ultimateCooldown > 0) ultimateCooldown--;
    if (healCooldown > 0) healCooldown--;
}

bool Player::canUseUltimate() const {
    return ultimateCooldown == 0;
}

bool Player::canUseHeal() const {
    return healCooldown == 0;
}

void Player::printStatus() const {
    cout << name << " (플레이어) HP: " << hp << "/" << maxHp << "\n";
}

// 이 함수만 남기고 'increaseMaxHp' (소문자 'p') 버전은 제거
void Player::increaseMaxHP(int amount) {
    maxHp += amount;
    hp += amount; // 최대 체력 증가 시 현재 체력도 증가 (넘지 않도록)
    if (hp > maxHp) hp = maxHp;
    cout << name << "의 최대 체력이 " << amount << " 증가했습니다! (현재: " << maxHp << ")\n";
}

void Player::healToFull() {
    hp = maxHp;
    cout << "체력이 전부 회복됨! (" << hp << "/" << maxHp << ")\n";
}

void Player::resetUltimateCooldown() {
    ultimateCooldown = 0;
}

// Player.cpp 파일 내용의 어딘가 (예: 맨 마지막)에 추가
void Player::heal(int amount) {
    // Character의 heal 함수를 호출하여 실제 체력 회복 로직을 수행
    Character::heal(amount);
}


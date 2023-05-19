#ifndef CHARACTERS_H
#define CHARACTERS_H
#include "buffs.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Character
{
protected:
    std::string name;
    int hp, mana, stamina;
    std::vector<std::shared_ptr<Buff>> buffs;
    Character(int hpInit, int manaInit, int staminaInit, std::string& nameInit);
public:
    virtual ~Character() = default;
    virtual void showInfo()const;
    void setMana(const int newMana);
    void setHP(const int newHP);
    void addBuff(std::shared_ptr<Buff>&);
    virtual std::string getName();
    friend class CharacterList;
};

class NPC: public Character
{
    std::vector<std::string> lines;
public:
    NPC(std::vector<std::string>& linesInit, int& hpInit, int& manaInit, int& staminaInit, std::string& nameInit);
    ~NPC() = default;
    void showInfo()const;
};

class Player: public Character
{
    std::string IGN;
    int level;
public:
    Player(std::string& IGNINIT, int levelInit, int hpInit, int manaInit, int staminaInit, std::string& nameInit);
    ~Player() = default;
    void showInfo()const override;
};

class CharacterList
{
    std::vector<std::shared_ptr<Character>> characters;
public:
    CharacterList() = default;
    ~CharacterList() = default;
    void addCharacter(std::shared_ptr<Character>& toAdd);
    void showAll() const;
    void showPlayers() const;
    void deleteCharacter(std::string&);
    std::shared_ptr<Character> operator[](std::string& toSearch);
};

#endif // CHARACTERS_H

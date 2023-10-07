#include "characters.h"

Character::Character(int hpInit, int manaInit, int staminaInit, std::string& nameInit):hp(hpInit), mana(manaInit), stamina(staminaInit), name(nameInit)
{}

void Character::showInfo()const
{
    std::cout << "NAME: " << name << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "Stamina: " << stamina << std::endl;
    std::cout << "Buffs: " << std::endl;
    for(int i = 0; i < buffs.size(); i++)
        std::cout << *buffs[i] << std::endl;
}

void Character::addBuff(std::shared_ptr<Buff>& buffPointer)
{
    buffs.push_back(buffPointer);
}

std::string Character::getName()
{
    return name;
}

void Character::setHP(const int newHP)
{
    hp = newHP;
}

void Character::setMana(const int newMana)
{
    mana = newMana;
}

NPC::NPC(std::vector<std::string>& linesInit, int& hpInit, int& manaInit, int& staminaInit, std::string& nameInit)
    : Character(hpInit, manaInit, staminaInit, nameInit), lines(linesInit)
    {}

void NPC::showInfo()const
{
    Character::showInfo();
    std::cout << "Lines of dialogue: ";
    for(int i = 0; i < lines.size(); i++)
        std::cout << lines[i] << std::endl;
    std::cout << std::endl;
}

Player::Player(std::string& IGNINIT, int levelInit, int hpInit, int manaInit, int staminaInit, std::string& nameInit)
        :Character(hpInit, manaInit, staminaInit, nameInit), IGN(IGNINIT), level(levelInit)
    {}

void Player::showInfo()const
{
    Character::showInfo();
    std::cout << "IGN: " << IGN << std::endl;
    std::cout << "Level: " << level << std::endl;
}

void CharacterList::addCharacter(std::shared_ptr<Character>& toAdd)
{
    characters.push_back(toAdd);
}

void CharacterList::showAll()const
{
    for(int i = 0; i < characters.size(); i++)
        characters[i]->showInfo();
}

void CharacterList::showPlayers()const
{
    for(int i = 0; i < characters.size(); i++){
        std::shared_ptr<Player> p = std::dynamic_pointer_cast<Player>(characters[i]);
        if(p != nullptr)
            p->showInfo();
    }
}

std::shared_ptr<Character> CharacterList::operator[](std::string& toSearch)
{
    for(int i = 0; i < characters.size(); i++)
        if(characters[i]->getName() == toSearch)
            return characters[i];
    throw std::invalid_argument("Could not find the person!");
}

void CharacterList::deleteCharacter(std::string& toDelete)
{
    bool deletion = false;

    std::vector<std::shared_ptr<Character>>::iterator p = characters.begin();


    for(p; p != characters.end(); p++){
        if((*p)->getName() == toDelete)
            break;
    }

    characters.erase(p);
}

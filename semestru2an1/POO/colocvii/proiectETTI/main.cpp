#include <iostream>
#include "characters.h"

int main()
{
    std::string menuItem;
    CharacterList Clist;

    while(true)
    {
        std::cout << "Hello, what would You like to do?\n";
        std::cout << "1. Add a new character\n";
        std::cout << "2. See all characters\n";
        std::cout << "3. See all player characters\n";
        std::cout << "4.Modify an existing character given a name\n";
        std::cout << "5.Delete a character given a name\n";
        std::cout << "6. Exit\n";
        std::cin >> menuItem;
        if(menuItem == "1"){
            std::cout << "You chose to add a new character\n What type of character would you like it to be?\n";
            std::cout << "1.NPC\n2.Player\n3.Enemy\n";
            std::string option;
            std::cin >> option;
            std::cout << "Give me a name\n";
            std::string name;
            std::cin >> name;
            std::cout << "Give me an HP value\n";
            int hp;
            std::cin >> hp;
            std::cout << "Give me a Mana value\n";
            int mana;
            std::cin >> mana;
            std::cout << "Give me a Stamina value\n";
            int stamina;
            std::cin >> stamina;
            if(option == "1"){
                std::cout << "You chose to add an NPC. Now you have to give me a few parameters\n";
                std::cout << "Give me a line of dialogue for the NPC\n";
                std::string line;
                std::cin >> line;
                std::vector<std::string> lines;
                lines.push_back(line);
                std::shared_ptr<Character> newCharacter = std::make_shared<NPC>(lines, hp, mana, stamina, name);
                Clist.addCharacter(newCharacter);
            }
            if(option == "2"){
                std::cout << "You chose to add a PLAYER. Now you have to give me a few parameters\n";
                std::cout << "Give me an in game name\n";
                std::string IGN;
                std::cin >> IGN;
                std::cout << "Give me a level\n";
                int level;
                std::cin >> level;
                std::shared_ptr<Character> newCharacter = std::make_shared<Player>(IGN, level, hp, mana, stamina, name);
                Clist.addCharacter(newCharacter);
            }

        }
        else if(menuItem == "2"){
            Clist.showAll();
        }
        else if(menuItem == "3"){
            Clist.showPlayers();
        }
        else if(menuItem == "4"){
            std::cout << "Give me a name to modify\n";
            std::string name;
            std::cin >> name;
            try{
                Clist[name];
                std::cout << "What do you want to change from: " << name << "?\n";
                std::cout << "1. HP\n";
                std::cout << "2. Mana\n";
                std::cout << "3. Add buff\n";
                std::string option;
                std::cin >> option;
                if(option == "1"){
                    std::cout << "Give me a new hp value\n";
                    int hp;
                    std::cin >> hp;
                    Clist[name]->setHP(hp);
                }
                else if(option == "2"){
                    std::cout << "Give me a new Mana value\n";
                    int mana;
                    std::cin >> mana;
                    Clist[name]->setMana(mana);
                }
                else if(option == "3"){
                    std::cout << "Give me the buffs duration\n";
                    int duration;
                    std::cin >> duration;
                    std::cout << "Give me the buffs description\n";
                    std::string description;
                    std::cin >> description;
                    std::shared_ptr<Buff> newBuff = std::make_shared<Buff>(duration, description);
                    Clist[name]->addBuff(newBuff);
                }
            }
            catch(std::exception& err)
            {
                std::cout << err.what() << std::endl;
            }
        }
        else if(menuItem == "5"){
            std::cout << "Give me a character name\n";
            std::string name;
            std::cin >> name;
            try{
                Clist[name];
                Clist.deleteCharacter(name);
            }
            catch(std::exception& err){
                std::cout << err.what() << std::endl;
            }
        }
        else if(menuItem == "6"){
            std::cout << "Goodbye!\n";
            break;
        }
    }
    return 0;
}

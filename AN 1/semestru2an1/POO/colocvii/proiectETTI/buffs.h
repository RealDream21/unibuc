#ifndef BUFFS_H
#define BUFFS_H
#include <string>
#include <iostream>

class Buff
{
    int duration;
    std::string description;
public:
    Buff(int duration, std::string& description);
    ~Buff() = default;
    friend std::ostream& operator<<(std::ostream&, const Buff&);
};

#endif // BUFFS_H

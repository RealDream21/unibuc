#include "buffs.h"

Buff::Buff(int durationInit, std::string& descriptionInit)
        : duration(durationInit), description(descriptionInit)
{}

std::ostream& operator<<(std::ostream& os, const Buff& a)
{
    os << "Description: " << a.description << std::endl;
    os << "Duration: " << a.duration << " seconds";
    return os;
}

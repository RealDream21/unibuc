#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <string>
#include <exception>
#include <iostream>
#include <vector>
#include <memory>

class InvalidCnp: public std::exception
{
public:
    char * what();
};


class Participant
{
    int rezultatConcurs;
    int varsta;
    std::string nume;
    std::string cnp;
    static std::vector<std::string> cnp_util;
public:
    Participant(const std::string& numeInit, const std::string& cnpInit, const int rezultatConcursInit);
    Participant(std::string& numeInit, std::string& cnpInit);
    Participant();
    friend std::ostream& operator<<(std::ostream&, const Participant&);
};

class ParticipantConcursTematic: public Participant{
};

#endif // PARTICIPANT_H

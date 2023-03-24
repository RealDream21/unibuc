#include <iostream>
#include <string>
#include <utility>

class student {
    std::string nume;
public:
    student(std::string nume_) : nume(std::move(nume_)) { std::cout << "constructor student: " << nume << "\n"; }
    student(const student& other) : nume(other.nume) { std::cout << "cc student: " << nume << "\n"; }
    student& operator=(const student& other) { nume = other.nume; std::cout << "op= student: " << nume << "\n"; return *this; }
    ~student() { std::cout << "destructor student: " << nume << "\n"; }
    friend std::ostream& operator<<(std::ostream& os, const student& st) { os << "st: " << st.nume << "\n"; return os; }
};

class profesor {
    std::string nume;
public:
    profesor(std::string nume_) : nume(std::move(nume_)) { std::cout << "constructor profesor: " << nume << "\n"; }
    profesor(const profesor& other) : nume(other.nume) { std::cout << "cc profesor: " << nume << "\n"; }
    profesor& operator=(const profesor& other) { nume = other.nume; std::cout << "op= profesor: " << nume << "\n"; return *this; }
    ~profesor() { std::cout << "destructor profesor: " << nume << "\n"; }
    friend std::ostream& operator<<(std::ostream& os, const profesor& p) { os << "prof: " << p.nume << "\n"; return os; }
};

class curs {
    profesor prof;
public:
    curs() : prof("prof") { std::cout << "constructor implicit curs\n"; }
    curs(const profesor& prof_) : prof(prof_) { std::cout << "constructor curs: " << prof << "\n"; }
    curs(const curs& other) : prof(other.prof) { std::cout << "cc curs: " << prof << "\n"; }
    curs& operator=(const curs& other) { prof = other.prof; std::cout << "op= curs: " << prof << "\n"; return *this; }
    ~curs() { std::cout << "destructor curs: " << prof << "\n"; }
    friend std::ostream& operator<<(std::ostream& os, const curs& c) { os << "curs: " << c.prof << "\n"; return os; }
};

class curs_obligatoriu : public curs {
    student st;
public:
    curs_obligatoriu(const student& st_) : st(st_) { std::cout << "constructor curs_obligatoriu: " << st << "\n"; }
    curs_obligatoriu(const curs_obligatoriu& other) :  curs(other), st(other.st) { std::cout << "cc curs_obligatoriu: " << st << "\n"; }
    curs_obligatoriu& operator=(const curs_obligatoriu& other) { st = other.st; std::cout << "op= curs_obligatoriu: " << st << "\n"; return *this; }
    ~curs_obligatoriu() { std::cout << "destructor curs_obligatoriu: " << st << "\n"; }
    friend std::ostream& operator<<(std::ostream& os, const curs_obligatoriu& c) { os << "curs_obligatoriu: " << c.st << "\n"; return os; }
};

int main() {
    student s{"a"};
    profesor p{"b"};
    curs_obligatoriu co{s};
}

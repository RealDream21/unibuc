#include <iostream>
#include <memory>

class I_O
{
    virtual void showInfo()const = 0;
    virtual void readInfo()= 0;
public:
    friend std::ostream& operator<<(std::ostream& os, const I_O&);
    friend std::istream& operator>>(std::istream& is,I_O&);
};

std::ostream& operator<<(std::ostream& os, const I_O& other)
{
    other.showInfo();
    return os;
}

std::istream& operator>>(std::istream& is, I_O& other)
{
    other.readInfo();
    return is;
}


class MyClass: public I_O
{
    int a, b, c;
protected:
    virtual void showInfo() const override;
    virtual void readInfo() override;
public:
    MyClass() = default;
};

void MyClass::showInfo()const
{
    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
}

void MyClass::readInfo()
{
    std::cout << "a:\n";
    std::cin >> a;
    std::cout << "b:\n";
    std::cin >> b;
    std::cout << "c:\n";
    std::cin >> c;
}

class Derived: public MyClass
{

public:
    void showInfo()const override;
    void readInfo();
};

void Derived::showInfo()const
{
    MyClass::showInfo();
    std::cout << "Show from derived class\n";
}

void Derived::readInfo()
{
    std::cout << "Read from derived\n";
}


int main()
{
    std::shared_ptr<MyClass> a = std::make_shared<Derived>();
    std::cout << *a << *a;
}

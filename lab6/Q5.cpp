#include <iostream>
#define SUCCESS 0

using namespace std;

class Complex
{
public:
    int real, img;
    Complex()
    {
        cout << "Enter real part";
        cin >> real;
        cout << "Enter imaginary part";
        cin >> img;
    }
    void display()
    {
        cout << real << "+i" << img;
    }
};

class ComplexMath : public Complex
{
private:
public:
    ComplexMath()
    {
    }

    ComplexMath &operator+(const Complex a)
    {
        real += a.real;
        img += a.img;
        return *this;
    }
};

int main()
{
    Complex a;
    ComplexMath c;
    a.display();
    std::cout << "+";
    c.display();
    cout << "=";
    (c + a).display();
    return SUCCESS;
}
#include <iostream>
#include <cstring>
#define SUCCESS 0
using namespace std;
class Student
{
private:
protected:
    string name;
    int rank;

public:
    virtual string getName() = 0;
    virtual int getRank() = 0;
};
class Engineering : public Student
{
private:
public:
    Engineering(string n, int r)
    {
        name = n;
        rank = r;
    }
    string getName()
    {
        return name;
    }
    int getRank()
    {
        return rank;
    }
};
class Medicine : public Student
{
private:
public:
    Medicine(string n, int r)
    {
        name = n;
        rank = r;
    }
    string getName()
    {
        return name;
    }
    int getRank()
    {
        return rank;
    }
};
class Science : public Student
{
private:
public:
    Science(string n, int r)
    {
        name = n;
        rank = r;
    }
    string getName()
    {
        return name;
    }
    int getRank()
    {
        return rank;
    }
};

int main()
{
    Student *st[3];
    st[0] = new Engineering("Kingly", 1);
    st[1] = new Medicine("Surreal", 2);
    st[2] = new Science("NoName", 3
    );
    cout << "Student of various field" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Name " << st[i]->getName() << endl;
        cout << "Rank " << st[i]->getRank() << endl;
    }
    return SUCCESS;
}
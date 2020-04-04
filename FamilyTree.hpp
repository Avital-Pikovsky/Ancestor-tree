#include <string>
#include <iostream>

using namespace std;

namespace family
{

class Tree
{
    string name;
    Tree *mom, *dad;

public:
    Tree(string n)
    {
        name = n;;
        dad = nullptr;
        mom = nullptr;
    }

    Tree &addFather(string son, string father);
    Tree &addMother(string son, string mother);
    string relation(string relative);
    string find(string relation);
    void display();
    void remove(string relative);

    ~Tree()
    {
        if (dad != nullptr)
            delete dad;
        if (mom != nullptr)
            delete mom;
    }
};

} // namespace family
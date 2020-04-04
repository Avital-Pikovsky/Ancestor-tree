#include "FamilyTree.hpp"
#include <iostream>

using namespace std;
using namespace family;

//A function that adds a father to someone who already exists in the tree.
Tree &Tree::addFather(string son, string father)
{
    if (son == name && dad == nullptr)
    {
        dad = new Tree(father);
        return *this;
    }
    else if (son != name)
        throw runtime_error(son + " does not exist!");
    else //if (dad != nullptr)
        throw runtime_error(son + " already has a father!");
}
//A function that adds a mother to someone who already exists in the tree.
Tree &Tree::addMother(string son, string mother)
{
    if (son == name && mom == nullptr)
    {
        mom = new Tree(mother);
        return *this;
    }
    else if (son != name)
        throw runtime_error(son + " does not exist!");

    else// if (mom != nullptr)
        throw runtime_error(son + " already has a mother!");
}

string Tree::relation(string name)
{
    return "";
}
string Tree::find(string relation)
{
    return "";
}
void Tree::display()
{
}
void Tree::remove(string name)
{
}

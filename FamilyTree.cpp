#include "FamilyTree.hpp"
#include <iostream>

using namespace std;
using namespace family;

//A function that adds a father to someone who already exists in the tree.
Tree &Tree::addFather(string son, string father)
{
    if (son == name)
    {
        if (dad == nullptr)
        {
            dad = new Tree(father);
            return *this;
        }
        else
            throw runtime_error(son + " already has a father!");
    }
    else if (dad != nullptr)
    {
        try
        {
            dad->addFather(son, father);
            return *this;
        }
        catch (runtime_error &x)
        {
        };
    }
    if (mom != nullptr)
        try
        {
            mom->addFather(son, father);
            return *this;
        }
        catch (runtime_error &x)
        {
        };
    // else (son != name)
    throw runtime_error(son + " does not exist! by: " + name);
}
//A function that adds a mother to someone who already exists in the tree.
Tree &Tree::addMother(string son, string mother)
{
    if (son == name) // && mom == nullptr)
    {
        if (mom == nullptr)
        {
            mom = new Tree(mother);
            return *this;
        }
        else
            throw runtime_error(son + " already has a mother!");
    }
    else if (mom != nullptr)
    {
        try
        {
            mom->addMother(son, mother);
            return *this;
        }
        catch (runtime_error &x)
        {
        };
    }

    if (dad != nullptr)
        try
        {
            dad->addMother(son, mother);
            return *this;
        }
        catch (runtime_error &x)
        {
        };

    //else if (son != name)
    throw runtime_error(son + " ///does not exist!");
}

string Tree::relation(string relative)
{
    string ans = "unrelated";

    if (relative == name)
    {
        ans = "me";
        return ans;
    }

    if (dad != nullptr)
    {
        ans = dad->relation(relative);

        if (ans != "unrelated")
        {
            if (ans == "me")
                ans = "father";
            else if (ans == "father" || ans == "mother")
                ans = "grand" + ans;
            else
                ans = "great-" + ans;
        }
    }
    if ((ans == "unrelated") && (mom != nullptr))
    {
        ans = mom->relation(relative);

        if (ans != "unrelated")
        {
            if (ans == "me")
                ans = "mother";
            else if ((ans == "mother") || (ans == "father"))
                ans = "grand" + ans;
            else
                ans = "great-" + ans;
        }
    }

    return ans;
}
string Tree::find(string relation)
{

    if (relation == "me")
        return name;
    if (relation == "mother")
        return mom->name;
    if (relation == "father")
        return dad->name;

    // cout << "nuu maa : " << relation << endl;
    // string str = relation;
    // for (size_t i = 0; i <= relation.length() - 1; i++)
    // {
    //     cout << "nuu maa2 : " << str << endl;

    //     if (str.at(i) == '-')
    //     {
    //         str.erase(i);
    //     }
    // }

    return "";
}
void Tree::display()
{
    int num;
    printFamily(num = 0);
}

void Tree::remove(string relative)
{
    // if (relation(relative) == "unrelated"){
    //     throw runtime_error(relative + " doesn't exist");

    if ((dad != nullptr) && (dad->name == relative))
    {
        delete dad;
        dad = nullptr;
    }
    else
    {
        if (dad != nullptr)
            dad->remove(relative);
    }
    if ((mom != nullptr) && (mom->name == relative))
    {

        delete mom;
        mom = nullptr;
    }
    else
    {
        if (mom != nullptr)
            mom->remove(relative);
    }
    if (name == relative)
    {
        throw runtime_error(name + " can't be removed!");
    }
}
void Tree::printFamily(int num)
{
    if (num == 0)
        cout << "*************" << name << "'s Famiy:" << endl;

    num += 10;

    if (dad != nullptr)
        dad->printFamily(num);

    cout << endl;
    for (int i = 10; i < num; i++)
        cout << " ";
    cout << name << "\n";

    if (mom != nullptr)
        mom->printFamily(num);
}

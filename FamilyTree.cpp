/*
 *AUTHOR: Avital Pikovsky
 *
 * Date: 2020-04
 *
 */
#include "FamilyTree.hpp"
#include <iostream>
#include <algorithm>

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
    if (son == name)
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
//A function that gets the name of 
//someone who is in the tree and returns its relation to the root.
//If it is not found in the tree, return unrelated.
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
//A function that gets a string that specifies a relative and returns
// the person's name from the tree that maintains this ratio.
string Tree::find(string relation)
{
    if (relation == "me")
        return name;
    if (relation == "mother" && mom!=nullptr)
        return mom->name;
    if (relation == "father" && dad!=nullptr)
        return dad->name;

    if (relation.at(0) == 'g')
    {
        relation.erase(std::remove(relation.begin(), relation.end(), '-'), relation.end());

            relation.erase(0, 5);

            if (dad != nullptr)
            try{
                return dad->find(relation);
            }
            catch(runtime_error &x){};

            if (mom != nullptr)
            try{
                return mom->find(relation);
            }
            catch(runtime_error &x){};
        
    }
    throw runtime_error("The tree cannot handle the: " + relation + " relation");
}
void Tree::display()
{
    int num;
    printFamily(num = 0);
}
//A function that gets the name of someone who is in the tree
// and deletes it and all of its parents from the tree.

void Tree::remove(string relative)
{
    // static bool check = false;
    // if (!check)
    // {
    //     cout<<"name: "<<name<<endl;
    //     cout<<"relative: "<<relative<<endl;
    //     check = true;
    //     if (relation(relative)=="unrelated")
    //         throw runtime_error(relative + " doesn't exist");
    // }
    if (name == relative)
    {
        throw runtime_error(name + " can't be removed!");
    }
    if ((dad != nullptr) && (dad->name == relative))
    {
        delete dad;
        dad = nullptr;
        return;
    }
    else if (dad != nullptr){
        try{
            dad->remove(relative);
            return;
        }
        catch(runtime_error &x){};
    }
    if ((mom != nullptr) && (mom->name == relative))
    {

        delete mom;
        mom = nullptr;
        return;
    }
    else if (mom != nullptr){
        try{
            mom->remove(relative);
            return;
        }
        catch(runtime_error &x){};
        
    }
    throw runtime_error(relative + " doesn't exist");


}
void Tree::printFamily(int num)
{
    if (num == 0)
        cout << "*************" << name << "'s Famiy:*************" << endl;

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

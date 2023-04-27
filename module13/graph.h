#pragma once
#pragma once

#include "arrayTemplate.h"

#define NAMELENGTH 30

typedef char Name[NAMELENGTH];


class RelationsGraph
{
public:
    struct Person { 
        Person();
        Person(const Name _name, int _id);
        Person& operator=(const Person& other);
        Person(const Person& other);

        bool operator==(const Person& other);

        Name name; 

        friend class RelationsGraph;
    private:
        int id; 
    };
    RelationsGraph();

    void addnewMan(const Name name);

    void delMan(const Name name);

    void addFriendship(const Name name_1, const Name name_2);

    void showThreeHandshakes();

private: 

    bool are_friends(const Person& m1, const Person& m2);

    bool man_exists_with_id(int man_id);

    Person findManByName(const Name name);
private: 
    int friend_matrix[SIZE][SIZE];
    StaticArray<Person> people; 
    StaticArray<bool> busyids; 
};

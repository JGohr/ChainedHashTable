#include "HashTable.h"

/*
Create a array of TableEntry objects with a size of T_S

    "this->arrayOfEntries = new TableEntry * [T_S];" will only allocate the amount of
    contiguous space required to store all T_S TableEntry objects.

    We then call a no-args constructor on each address where a head TableEntry object
    will be stored. 
*/
HashTable::HashTable()
{
    this->arrayOfEntries = new TableEntry * [T_S];

    for(int i = 0; i < T_S; i++)
    {
        this->arrayOfEntries[i] = new TableEntry();
    }
}

HashTable::~HashTable()
{
    delete [] arrayOfEntries;
}

//Return a double pointer to the beginning of the array property arrayOfEntries
TableEntry** HashTable::getArrayOfEntries()
{
    return this->arrayOfEntries;
}

/*
    Inserts a TableEntry object with _value into the HashTable

    Two Cases:
        #1 - Node is first to be inserted under the hashed value(or "key")
        #2 - Node is NOT the first under the key, this will start our linked list of TableEntry objects
        under the designated key
*/
void HashTable::insert(int _value)
{
    //Getting a pointer to arrayOfEntries with the hashedValue as its index 
    int hashedValue = hash(_value);
    TableEntry* headNodeAtHash = this->arrayOfEntries[hashedValue];

    //Case #1 First Node to be inserted
    if(headNodeAtHash->v == NULL)
    {
        headNodeAtHash->v = _value;
        headNodeAtHash->k = hashedValue;
        return;
    }

    //Case #2 NOT first node, traverse to end of linked list & insert node
    TableEntry* tmp = headNodeAtHash;

    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    tmp->next = new TableEntry(hashedValue, _value);
    return;

}

/*
    Deletes a TableEntry object by value in the HashTable

    Two Cases:
        #1 - Node is first to be deleted under the hashed value(key)
        #2 - Node is NOT first, this will require us to delete the node while
        ensuring the linked list stays in tact.
*/
void HashTable::del(int _value)
{
    //Getting a pointer to arrayOfEntries with the hashedValue as its index
    int hashedValue = hash(_value);
    TableEntry* headNodeAtHash = this->arrayOfEntries[hashedValue];

    //Case #1 Head Node 
    if(headNodeAtHash->v == _value)
    {
        TableEntry* tmp2 = headNodeAtHash->next;

        headNodeAtHash->v = headNodeAtHash->getNextNodeValue();
        headNodeAtHash->next = headNodeAtHash->next->next;

        delete tmp2;
        return;
    }

    //Case #2 Not head node
    TableEntry* tmp = headNodeAtHash;

    while(tmp->getNextNodeValue() != _value)
    {
        tmp = tmp->next;
    }

    /*
    At this point, tmp will be the node PRIOR to the node we want to delete
    
             node 2 delete
                  v
        O -> O -> O -> O -> nullptr
            tmp  

    We simply check if the node to be deleted is the last in the linked list and handle accordingly
    */
    TableEntry* tmp2 = tmp->next;

    if(tmp->next->next == nullptr)
    {
        tmp->next = nullptr;

        delete tmp2;
        return;
    }

    tmp->next = tmp->next->next;

    delete tmp2;
    return;
}

/*
    Print a list of all items at list[_key]
    Output: Values at Key => '2': 2 52 102 152 202 252 ... 952
*/
void HashTable::search(int _key)
{
    TableEntry* headNodeAtHash = this->arrayOfEntries[_key];
    TableEntry* tmp = headNodeAtHash;

    std::cout << "Values at Key => '" << _key << "': ";

    while(tmp != NULL)
    {
        std::cout << tmp->v << " ";
        tmp = tmp->next;
    }

    std::cout << "\n";
    return;

}

//Operates similar to HashTable::search() + traverses a linked list to check for a given value
int HashTable::searchByValue(int _key, int _value)
{
    TableEntry* headNodeAtKey = this->arrayOfEntries[_key];
    TableEntry* tmp = headNodeAtKey;

    while(tmp->v != _value)
    {
        tmp = tmp->next;

        if(tmp->next == nullptr && tmp->v != _value)
        {
            std::cout << "Cannot find value\n";
            return NULL;
        }
    }

    return tmp->v;
}

//Return is a int between {0...(T_S - 1)}
int HashTable::hash(int _value)
{
    return _value % T_S;
}
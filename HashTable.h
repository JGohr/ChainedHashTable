#include <iostream>
#include "TableEntry.h"

/*
    HashTable will contain a "TableEntry" double pointer.
        This is simply just a pointer to the start of our allocated array.
        Since the start of an array is just a pointer itself, this explains the need for a double pointer (:

        ########################################################################################################

        Acccessing Data via the Double Ptr **listOfEntries:
            HashTable table;
            TableEntry** myList = table.getListOfEntries();

            myList is now a pointer to the start of our allocated contiguous memory.

            Accessing the start of the myList object can be done just as a array could > myList[index]
            
            Good resource about what the [] actually do the the object https://madebyevan.com/obscure-cpp-features/

        #########################################################################################################
*/

class HashTable
{
    private:
        TableEntry **arrayOfEntries;

    public:
        int const T_S = 50;

        TableEntry** getArrayOfEntries();
        void insert(int _value);
        void del(int _value);
        void search(int _key);
        int searchByValue(int _key, int _value);
        int hash(int _value);

        HashTable();
        ~HashTable();
};
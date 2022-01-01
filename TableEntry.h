#include <cstdio>
#include <iostream>

class TableEntry
{   
    public:
        int k, v;
        TableEntry* next;

        int getNextNodeValue();

        TableEntry();
        TableEntry(int _k, int _v);
};
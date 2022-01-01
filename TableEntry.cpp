#include "TableEntry.h"

TableEntry::TableEntry()
{
    this->k = 0;
    this->v = 0;
    this->next = nullptr;
}

TableEntry::TableEntry(int _k, int _v)
{
    this->k = _k;
    this->v = _v;
    this->next = nullptr;
}

int TableEntry::getNextNodeValue()
{
    return this->next->v;
}

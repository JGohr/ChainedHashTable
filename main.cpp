#include <iostream>
#include <chrono>
#include "HashTable.h"

int main(void)
{
    auto start = std::chrono::high_resolution_clock::now();

    int userInput;
    std::cout << "Enter a number: ";
    std::cin >> userInput;
    std::cout << "\n";

    //#########################################################

    HashTable table;

    for(int i = 0; i < userInput; i++)
    {
        table.insert(i);
    }

    for(int i = 0; i < table.T_S; i++)
    {
        table.search(i);
    }
    
    //##########################################################

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Total Milliseconds: " << duration.count() << std::endl;

    std::cin >> userInput;

    return 0;
}
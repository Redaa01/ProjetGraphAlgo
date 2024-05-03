#include <iostream>
#include "distance.h"
#include <vector>
#include "application.h"

#include "rang.h"


int main()
{
    //application a;
    //a.menuPrincipal();
    std::vector<int> aps = {12, 1, 4, 7, 11, 15, 18, 21, 23, 25, 26, 28, 31};
    std::vector<int> fs = {31, 2, 3, 0, 4, 9, 0, 4, 6, 8, 0, 8, 9, 11, 0, 3, 6, 0, 7, 8, 0, 8, 0, 10, 0, 0, 11, 0, 10, 12, 0, 0};
    Rang rg;

    std::vector<int> r = rg.calculeRang(fs,aps);


    for (int i = 1; i <= aps[0]; i++)
        std::cout << "rang[" << i << "] = " << r[i] << std::endl;

    return 0;
}

#ifndef DANTZIG_H_INCLUDED
#define DANTZIG_H_INCLUDED

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Dantzig
{
public :
    Dantzig();
    bool AlgoDantzig(vector<vector<int>>& dist) const;
};

#endif // DANTZIG_H_INCLUDED

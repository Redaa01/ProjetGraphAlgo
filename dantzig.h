#ifndef DANTZIG_H_INCLUDED
#define DANTZIG_H_INCLUDED

#include <vector>

using std::vector;

class Dantzig
{
public :
    Dantzig();
    bool AlgoDantzig(vector<vector<int>>& dist) const;
};

#endif // DANTZIG_H_INCLUDED

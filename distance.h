#ifndef DISTANCE_H
#define DISTANCE_H
#include <vector>
#include <iostream>

using std::vector;

class distance
{
    public:
        distance();
        void descente_largeur(int r,const vector<int>& fs, const vector<int>& aps, vector<int>& dist);
        void edit(const vector<int> dist);
};

#endif // DISTANCE_H



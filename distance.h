#ifndef DISTANCE_H
#define DISTANCE_H
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;

class distance
{
    public:
        distance();
        void mat_distance(const vector<int>& FS, const vector<int>& APS, vector<vector<int>>& matriceDistance);
        void descente_largeur(int r,const vector<int>& fs, const vector<int>& aps, vector<int>& dist);
        void edit(const vector<int> dist);
};

#endif // DISTANCE_H



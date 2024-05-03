#ifndef RANG_H_INCLUDED
#define RANG_H_INCLUDED

#include <vector>
#include <string>

using std::vector;

class Rang
{
public :
    Rang();
    void empiler(int x, vector<int> &pilch);
    vector<int> calculeRang(const vector<int>& fs, const vector<int>& aps);
    void demi_degre_interieur(const vector<int>& FS, const vector<int>& APS, vector<int> &DDI);
};

#endif // RANG_H_INCLUDED

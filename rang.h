#ifndef RANG_H_INCLUDED
#define RANG_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::vector;

class Rang
{
public :
    Rang(const vector<int>& aps, const vector<int>& fs);
    vector<int> calculeRang();
    int getTailleAps() const;
    void empiler(int x);
    void ecrireRangsDansFichier(vector<int> &rang, const std::string &nomFichier);
    void lireGrapheDepuisFichier(const std::string &nomFichier);
private :
    vector<int> d_pilch;
    vector<int> d_fs;
    vector<int> d_aps;
};

#endif // RANG_H_INCLUDED

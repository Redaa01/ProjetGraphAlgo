#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED

#include <vector>
#include <string>

class Noeud {
public :
    Noeud();
    int id();

private :
    int id;
    vector<string> info[];
    vector<int> poids_arcs[];
};

#endif // NOEUD_H_INCLUDED

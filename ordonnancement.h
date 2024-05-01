#ifndef ORDONNANCEMENT_H_INCLUDED
#define ORDONNANCEMENT_H_INCLUDED

#include <vector>
#include <string>
#include "graph.h"

using std::string;
using std::vector;

class Ordonnancement
{
public :
    Ordonnancement(const Graph& graph);
    void AlgoOrdonnancement(vector<int>& dateAuPlusTot, vector<int>& dateAuPlusTard, vector<string>& sommetCritique);
private :
    Graph d_graph;
    vector<int> calculDDI() const;
    vector<int> calculAPP() const;
    vector<int> calculFP() const;

};

#endif // ORDONNANCEMENT_H_INCLUDED

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
    /*Ordonnancement(const Graph& graph);
    void AlgoOrdonnancement(vector<int>& dateAuPlusTot, vector<int>& dateAuPlusTard, vector<string>& sommetCritique);*/
    Ordonnancement();
    void AlgoOrdonnancement(const vector<int> file_pred, const vector<int> adr_prem_pred, const vector<int> duree_taches, vector<int>& file_pred_critique, vector<int>& adr_prem_pred_critique, vector<int>& longueur_critique);
private :
    Graph d_graph;
    vector<int> calculDDI() const;
    vector<int> calculAPP() const;
    vector<int> calculFP() const;

};

#endif // ORDONNANCEMENT_H_INCLUDED

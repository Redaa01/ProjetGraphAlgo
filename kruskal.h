#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include "graph.h"

class Kruskal
{
public :
    Kruskal();
    void AlgoKruskal(Graph g, Graph &t, int *prem, int *pilch, int *cfc, int *NbElem);
    void fusionner(int i, int j, int *prem, int *pilch, int *cfc, int *NbElem);
    void affichet(int *a, int n);
    void trier(Graph &g);
    void affichage(Graph g);
    void saisie(Graph &g);
};

#endif // KRUSKAL_H_INCLUDED

#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "Graph.h"
#include "distance.h"
#include "dijkstra.h"
#include <iostream>
using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::string;
class application
{
    public:
        application();
        void menuPrincipal();
        void load();
        void FSandAPS();
        void matrice();
        void algorithmes();

        string toStringVector(const vector<int>& tab);

        bool verifieDistance();
        bool verifieDijkstra(int sommet_depart);
        bool verifieFS_APS_NonVide();
        bool verifieMatrice_NonVide();

        void transformeVersMatrice();
        void transformeVersFS_APS();
        void printVector(const vector<int>& v);

        vector<vector<int>> englobe_Distance();
        void englobe_Dijkstra(int sommet_depart, vector<int>& d, vector<int>& pr);
    private:
        Graph d_graphe;
};

#endif // APPLICATION_H

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graph.h"
#include "distance.h"
#include "dijkstra.h"
#include "kruskal.h"
#include "prufer.h"
#include "dantzig.h"

#include <iostream>
#include <vector>

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

        bool verifieKruskal();
        bool verifiePruferEncode();
        bool verifiePruferDecode(const vector<int>& p);
        bool verifieFS_APS_NonVide();
        bool verifieMatrice_NonVide();
        bool verifieDantzig();
        void transformeVersMatrice();
        void transformeVersFS_APS();
        void printVector(const vector<int>& v);

        vector<vector<int>> englobe_Distance();
        bool englobe_Dantzig();
        void englobe_Dijkstra(int sommet_depart, vector<int>& d, vector<int>& pr);
        void englobe_Kruskal();
        vector<int> englobe_Prufer_encode();
        void englobe_Prufer_decode(const vector<int>& p);
    private:
        Graph d_graphe;
};

#endif // APPLICATION_H

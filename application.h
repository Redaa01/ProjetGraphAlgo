#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "Graph.h"
#include "distance.h"
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
        bool verifieFS_APS_NonVide();
        bool verifieMatrice_NonVide();

        void transformeVersMatrice();
        void transformeVersFS_APS();
        void printVector(const vector<int>& v);
        vector<vector<int>> englobe_Distance();
    private:
        Graph d_graphe;
};

#endif // APPLICATION_H

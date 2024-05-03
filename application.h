#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graph.h"
#include "distance.h"
#include "dijkstra.h"
#include "kruskal.h"
#include "prufer.h"
#include "dantzig.h"
#include "ordonnancement.h"
#include "rang.h"
#include "tarjan.h"

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
        void transforme_FP_APP_TO_FS_APS(const vector<int>& fp, const vector<int>& app, vector<int>& fs, vector<int>& aps);


        bool verifieDistance();
        bool verifieDijkstra(int sommet_depart);
        bool verifieRang();
        bool verifieKruskal();
        bool verifiePruferEncode();
        bool verifiePruferDecode(const vector<int>& p);
        bool verifieFS_APS_NonVide();
        bool verifieMatrice_NonVide();
        bool verifieDantzig();
        bool verifieTarjan();

        void transformeVersMatrice();
        void transformeVersFS_APS();
        void printVector(const vector<int>& v);

        vector<vector<int>> englobe_Distance();
        vector<int> englobe_Rang();
        void englobe_Tarjan(vector<int>& cfc, vector<int>& pilch, vector<int>& pred, vector<int>& prem, vector<int>& base, vector<int>& baseInitiale);
        void englobe_Ordonnancement(const vector<int>& duree_taches, const vector<int>& fp, const vector<int>& app, vector<int>& longueur_critique);
        bool englobe_Dantzig();
        void englobe_Dijkstra(int sommet_depart, vector<int>& d, vector<int>& pr);
        void englobe_Kruskal();
        vector<int> englobe_Prufer_encode();
        void englobe_Prufer_decode(const vector<int>& p);
    private:
        Graph d_graphe;
};

#endif // APPLICATION_H

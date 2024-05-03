#ifndef GRAPH_H
#define GRAPH_H

#include "noeud.h"

#include <memory>
#include <sstream>
#include <vector>
using std::make_unique;
using std::stringstream;
using std::unique_ptr;
using std::vector;

struct arete {
    int s; // première extrémité de l'arête
    int t; // deuxième extrémité de l’arête
    double p; // poids de l’arête
};

class Graph
{
private:
    vector<int> FS;
    vector<int> APS;
    vector<vector<int>> matAdj;
    bool usingFsAndAps;
    vector<unique_ptr<Noeud>> sommets;
    vector<vector<int>> couts;
    bool est_oriente;
    bool a_des_poids;

    void initialiserSommets(unsigned size = 1);
    void verifIntegritee();
    bool verifIntegriteeSommets();
    bool verifIntegriteeSommets_FS_APS();
    bool verifIntegriteeSommets_MatAdj();


public:
    Graph(bool est_oriente = true); // couts vide
    Graph(const vector<int>& FS, const vector<int>& APS); // est_oriente = false, couts vide
    Graph(const vector<vector<int>>& matAdj, bool est_oriente = true); // couts vide
    Graph(const vector<int>& FS, const vector<int>& APS, const vector<int>& couts); // est_oriente = false
    Graph(const vector<vector<int>>& matAdj, const vector<vector<int>>& cout, bool est_oriente = true);
    Graph(const vector<int>& FS, const vector<int>& APS, const vector<vector<int>>& couts);
    Graph(const vector<int>& FS, const vector<int>& APS, bool est_oriente);
    Graph(const Graph& g);
    Graph(const vector<int>& fs, const vector<int>& aps, const vector<unique_ptr<Noeud>>& sommets, bool est_oriente, bool a_des_poids);
    Graph(const vector<vector<int>>& matAdj, const vector<unique_ptr<Noeud>>& sommets, bool est_oriente, bool a_des_poids);

    Graph& operator=(const Graph& g);

    bool getEst_oriente() const;
    bool getA_Des_Poids() const;
    vector<int> getFS() const;
    vector<int> getAPS() const;
    vector<vector<int>> getMatAdj() const;
    bool isUsingFsAndAps() const;
    const vector<unique_ptr<Noeud>>& getSommets() const;
    vector<vector<int>> getCouts() const;

    void setFSandAPS(const vector<int>& fs, const vector<int>& aps);
    void setOriente(bool oriente);
    void setMatrice(const vector<vector<int>>& mat);
    void setCout(const vector<vector<int>>& mat);
    void setUsingFsAndAps(bool usingFsAps);
    void setA_des_poids(bool apoids);

    void ajouterNoeud(const Noeud& n, const vector<int>& pred, const vector<int>& succ);
    void FS_APS_to_MatAdj(vector<vector<int>>& matAdj) const;
    void matAdj_to_FS_APS(vector<int>& FS, vector<int>& APS) const;
    void print(std::ostream& ost) const;
    void saveIn(std::ostream& ost) const;
    string toString() const;

    int nbSommets() const;
    int getArc(int pred, int succ);
    int getNbArc() const;

    int n; // nombre de sommets du graphe
    int m; //nombre d’arêtes du graphe arete *a;
    arete *a; // tableau des aretes
};

// Global functions
std::ostream& operator<<(std::ostream& ost, const Graph& g);

#endif // GRAPH_H

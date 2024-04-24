#include "graph.h"

#include <vector>

graph::graph()
{

}

graph::graph(const vector<int>& FS, const vector<int>& APS) : FS{FS}, APS{APS},
                    usingFsAndAPS{true}, est_oriente{true}, a_des_poids{false}
{

}

graph::graph(const vector<vector<int>>& matAdj) : matAdj{matAdj},
                    usingFsAndAPS{false}, est_oriente{true}, a_des_poids{false}
{

}

vector<int> graph::getFS() const
{
    return FS;
}


vector<int> graph::getAPS() const
{
    return APS;
}

vector<vector<int>> graph::getMatAdj() const
{
    return matAdj;
}

void graph::setFSandAPS(const vector<int>& fs, const vector<int>& aps)
{
    FS = fs;
    APS = aps;
    usingFsAndAPS = true;
}
void graph::setOriente(bool oriente)
{
    est_oriente = oriente;
}
void graph::setMatrice(const vector<vector<int>>& mat)
{
    matAdj = mat;
    usingFsAndAPS = false;
}

void graph::setCout(const vector<vector<int>>& mat)
{
    couts = mat;
    a_des_poids = true;
}

void graph::setUsingFsAndAps(bool usingFsAndAPS)
{
    usingFsAndAPS = usingFsAndAPS;
}
void graph::setA_des_poids(bool apoids)
{
    a_des_poids = apoids;
}

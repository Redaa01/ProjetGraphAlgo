#ifndef GRAPH_H
#define GRAPH_H

using namespace::std;
#include <vector>

class graph
{
    public:
        graph();
        graph(const vector<int>& FS, const vector<int>& APS);
        graph(const vector<vector<int>>& matAdj);

        vector<int> getFS() const;
        vector<int> getAPS() const;
        vector<vector<int>> getMatAdj() const;

        void setFSandAPS(const vector<int>& fs, const vector<int>& aps);
        void setMatrice(const vector<vector<int>>& mat);
        void setCout(const vector<vector<int>>& mat);
        void setUsingFsAndAps(bool usingFsAps);
        void setA_des_poids(bool apoids);
        void setOriente(bool oriente);
    private:
        vector<int> FS;
        vector<int> APS;
        vector<vector<int>> matAdj;
        vector<vector<int>> couts;

        bool usingFsAndAPS;
        bool est_oriente;
        bool a_des_poids;
};

#endif // GRAPH_H

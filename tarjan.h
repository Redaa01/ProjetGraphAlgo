#ifndef TARJAN_H
#define TARJAN_H
#include <vector>

using std::vector;

class tarjan
{
    public:
        tarjan();
        void AlgoTarjan(const vector<int>& FS, const vector<int>& APS);
        void fortconnexe(const vector<int>& FS, const vector<int>& APS, vector<int>& cfc, vector<int>& pilch, vector<int>& pred, vector<int>& prem);
        void traversee(int s, int& p, int& k, const vector<int>& FS, const vector<int>& APS, vector<int>& cfc, vector<int>& pilch, vector<int>& pred, vector<int>& prem, vector<int>& tarj, vector<bool>& entarj, vector<int>& num, vector<int>& ro);
        void empiler(int x, vector<int>& pilch);
        void versGrapheReduit(const vector<int>& cfc, const vector<int>& prem,const vector<int>& fs,const vector<int>& aps, vector<vector<int>>& mat);
        void TrierTableau_QuickSort(vector<int>& tab, int g, int d);
        int partition(vector<int>& t, int g, int d);
        void base_Greduit(const vector<int>& fsR, const vector<int>& apsR, vector<int>& baseR_GrapheR);
        void edition_bases(const vector<int>& prem, const vector<int>& pilch, const vector<int>& baseR, vector<int>& baseInitiale);
};

#endif // TARJAN_H

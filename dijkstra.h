#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>

using std::vector;

class dijkstra
{
    public:
        dijkstra();
        void faitDijkstra(const vector<int>& fs, const vector<int>& aps, const vector<vector<int>>& p, int s, vector<int> &d, vector<int> &pr);
};

#endif // DIJKSTRA_H

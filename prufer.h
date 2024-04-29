#ifndef PRUFER_H
#define PRUFER_H
#include <vector>

using std::vector;

class prufer
{
    public:
        prufer();
        void Prufer_decode(const vector<int>& p, vector<vector<int>>& mat);
        void Prufer_encode(vector<vector<int>> mat, vector<int>& p);
};

#endif // PRUFER_H

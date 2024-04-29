#include "prufer.h"

prufer::prufer()
{
    //ctor
}

void prufer::Prufer_decode(const vector<int>& p, vector<vector<int>>& mat)
{
    unsigned m = p[0], n = m + 2;
    vector<int> s(m + 3);

    mat.clear();
    mat.resize(n + 1);
    mat[0].resize(2);
    mat[0][0] = n;
    mat[0][1] = n + m;
    for(unsigned i = 1; i <= n; ++i) mat[i].resize(n + 1, 0);

    for(unsigned i = 1; i <= n; ++i) s[i] = 0;
    for(unsigned i = 1; i <= m; ++i) ++s[p[i]];

    for(unsigned i = 1; i <= m; ++i)
    {
        unsigned k = 1;
        while(s[k] != 0) ++k;

        mat[p[i]][k] = 1;
        mat[k][p[i]] = 1;

        s[k] = -1;
        --s[p[i]];
    }

    int k = -1;
    for(unsigned i = 1; i <= n; ++i)
    {
        if(s[i] == 0)
        {
            if(k == -1) k = i;
            else
            {
                mat[i][k] = 1;
                mat[k][i] = 1;
            }
        }
    }
}

void prufer::Prufer_encode(vector<vector<int>> mat, vector<int>& p)
{
    unsigned n = mat[0][0];
    p.clear();
    p.resize(n-1);
    p[0] = n-2;

    for(unsigned i = 1; i <= n; ++i)
    {
        mat[i][0] = 0;
        for(unsigned j = 1; j <= n; ++j)
        {
            mat[i][0] += mat[i][j];
        }
    }

    for(unsigned k = 1; k <= n-2; ++k)
    {
        int i = 1, j = 1;
        while(mat[i][0] != 1) ++i;
        while(mat[i][j] != 1) ++j;

        p[k] = j;
        mat[i][j] = 0;
        mat[j][i] = 0;
        mat[i][0] = 0;
        --mat[j][0];
    }
}

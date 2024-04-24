#include "dijkstra.h"

dijkstra::dijkstra()
{

}

void dijkstra::faitDijkstra(const vector<int>& fs, const vector<int>& aps, const vector<vector<int>>& p, int s, vector<int> &d, vector<int> &pr)
{
        int ind;
        int i, j, k, v;
        int n = aps[0];
        int m = fs[0];
        pr.resize(n+1, 0);
        d.resize(n+1, 0);
        vector<int> inS(n+1);

        for(i = 1; i <= n; i++)
        {
            d[i] = p[s][i];
            inS[i] = 1;
            pr[i] = s;
        }

        d[s] = 0;
        inS[s] = 0;
        ind = n-1;
        while(ind > 0)
        {
            m = 100;
            for(i = 1; i <= n; i++)
            {
                if(inS[i] == 1)
                {
                    if(d[i] > 0 and d[i] < m)
                    {
                        m = d[i];
                        j = i;
                    }
                }
            }
            if(m == 100)
                    return;
            inS[j] = 0;
            --ind;
            k = aps[j];
            while(fs[k] != 0)
            {
                if(inS[fs[k]] == 1)
                {
                    v = d[j] + p[j][fs[k]];
                    if(d[fs[k]] == -1 or v < d[fs[k]])
                    {
                        d[fs[k]] = v;
                        pr[fs[k]] = j;
                    }
                }
                k++;
            }
        }
}

#include "dantzig.h"

Dantzig::Dantzig()
{

}

bool Dantzig::AlgoDantzig(vector<vector<int>>& dist) const
{
    int n = dist[0][0]; //n = dist.size()
    int x;
    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i <= k; ++i)
        {
            for(int j = 0; j <= k; ++j)
            {
                if((x = dist[i][j] + dist[j][k+1]) < dist[i][k+1]){
                    dist[i][k+1] = x;
                }
                if((x = dist[k+1][j] + dist[j][i]) < dist[k+1][i]){
                    dist[k+1][i] = x;
                }
            }
            if((dist[i][k+1]+ dist[k+1][i]) < 0){
                return false;
            }
        }
        for(int i = 0; i <= k; ++i)
        {
            for(int j = 0; j <= k; ++j)
            {
                if((x = dist[i][k+1] + dist[k+1][j]) < dist[i][j]){
                    dist[i][j] = x;
                }
            }
        }
    }
    return true;
}

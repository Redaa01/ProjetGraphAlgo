#include "kruskal.h"
#include <iostream>

Kruskal::Kruskal()
{

}


void Kruskal::AlgoKruskal(const Graph& g, Graph &t)
{
        //TRANSFORMATION DU GRAPH AVEC LA STRUCTURE VOULU
        typedef struct {
            int s;
            int t;
            double p;
        } arete;
        typedef struct {
            int n;
            int m;
            vector<arete> a;
        } graphe;

        arete ar;
        graphe graphReturn;
        vector<int> FS  = g.getFS();
        vector<int> APS = g.getAPS();
        graphReturn.n = APS.size();
        vector<vector<int>> cout = g.getCouts();
        int j = 1;

        for(unsigned i = 1; i < APS.size(); i++)
        {
            while(FS[j] != 0)
            {
                ar.s = FS[j];
                ar.t = i+1;
                ar.p = cout[i][FS[j]-1];

                graphReturn.a.push_back(ar);
                j++;
            }
            j++;
        }
        graphReturn.m = graphReturn.a.size();

        //TRIE DU GRAPHE EN FONCTION DES COUTS ET DES ARRETES
        double p;
            for (int i = 0; i < graphReturn.m - 1; i++)
                for (int j = i + 1; j < graphReturn.m; j++)
                    if ((graphReturn.a[j].p < graphReturn.a[i].p) || (graphReturn.a[j].p == graphReturn.a[i].p && graphReturn.a[j].s < graphReturn.a[i].t) || (graphReturn.a[j].p == graphReturn.a[i].p && graphReturn.a[j].t < graphReturn.a[i].t))
                    {
                        p = graphReturn.a[j].p;
                        graphReturn.a[j].p = graphReturn.a[i].p;
                        graphReturn.a[i].p = p;
                    }

        //INITIALISATION DES DONNEES
        int n = graphReturn.n;
        int *prem = new int[n + 1];
        int *pilch = new int[n + 1];
        int *cfc = new int[n + 1];
        int *NbElem = new int[n + 1];
        for(int i = 1; i <= n; i++)
        {
            prem[i] = i;
            pilch[i] = 0;
            cfc[i] = i;
            NbElem[i] = 1;
        }

        //KRUSKAL
        graphe GraphFinal;
        GraphFinal.a.resize(n-1);
        int x;
        int y;
        int i = 0; int cpt = 0;
        while(cpt < n-1)
        {
            arete ar = graphReturn.a[i];
            x = cfc[ar.s];
            y = cfc[ar.t];
            if(x != y)
            {
                GraphFinal.a[cpt++] = graphReturn.a[i];
                if(NbElem[i] < NbElem[cpt])
                {
                    int aux = i;
                    i = cpt;
                    cpt = aux;
                }
                int s = prem[cpt];
                cfc[s] = i;
                while(pilch[s] != 0)
                {
                    s = pilch[s];
                    cfc[s] = i;
                }
                pilch[s] = prem[i];
                prem[i] = prem[cpt];
                NbElem[i] += NbElem[cpt];
            }
            i++;
        }
        GraphFinal.n = graphReturn.n;
        GraphFinal.m = graphReturn.n - 1;

        vector<vector<int>> matriceCout(APS[0]);
        vector<vector<int>> matrice(APS[0]);
        for(unsigned i = 0; i < matrice.size(); i++)
        {
            matrice[i].resize(APS[0]);
            for(unsigned j = 0; j < matrice[i].size(); j++)
            {
                vector<vector<int>> matriceCout(APS[0]);
                matrice[i][j] = 0;
            }
        }

        for(unsigned i = 0; i < GraphFinal.a.size(); i++)
        {
            matriceCout[GraphFinal.a[i].s][GraphFinal.a[i].t] = GraphFinal.a[i].p;
            matrice[GraphFinal.a[i].s][GraphFinal.a[i].t] = 1;
        }

        t.setMatrice(matrice);
        t.setCout(matriceCout);
}


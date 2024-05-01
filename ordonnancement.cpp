#include "ordonnancement.h"
//#include "rang.h"
#include <algorithm>

Ordonnancement::Ordonnancement(const Graph& graph) : d_graph{graph}
{

}

void Ordonnancement::AlgoOrdonnancement(vector<int>& dateAuPlusTot, vector<int>& dateAuPlusTard, vector<string>& sommetCritique)
{
    int nbS = d_graph.nbSommets();
    vector<int> tabRang;
    //rang(tabRang);
    tabRang[0]=0;
    int rangMax = *std::max_element(tabRang.begin(), tabRang.end());
    vector<int> numerotation;
    numerotation.push_back(0);
    for (int i = 0; i <= rangMax; i++)
    {
        for (int j = 1; j <= nbS; j++)
        {
            if (tabRang[j] == i)
                numerotation.push_back(j);
        }
    }
    vector<int> calculFp = calculFP();
    vector<int> calculApp = calculAPP();
    vector<int> calculDdi = calculDDI();
    dateAuPlusTot.resize(nbS + 1);
    dateAuPlusTard.resize(nbS + 1);
    for (int i = 0; i <= nbS; i++)
    {
        dateAuPlusTot[i] = 0;
        dateAuPlusTard[i] = 0;

    }
    for (int i = 1; i <= nbS; i++)
    {
        int current = numerotation[i];
        int arcMaximum = 0;
        for (int j = 0; j < calculDdi[current]; j++)
        {
            int pred = calculFp[calculApp[current]+j];
            int duree = d_graph.getArc(pred,current) + dateAuPlusTot[pred];
            if(duree > arcMaximum)
            {

                arcMaximum = duree;
            }
        }

        dateAuPlusTot[current] = arcMaximum;
    }

    for (int i = nbS; i > 0; i--)
    {
        int current = numerotation[i];
        int arcMinimum = dateAuPlusTot[nbS];
        int k = d_graph.getAPS()[current];
        while(d_graph.getFS()[k] != 0)
        {
            int succ = d_graph.getFS()[k];
            int duree = dateAuPlusTard[succ] - d_graph.getArc(current,succ);
            if (duree < arcMinimum)
            {
                arcMinimum = duree;
            }
            k++;
        }
        dateAuPlusTard[current] = arcMinimum;
    }

    for (int i = 1; i <= nbS; i++)
    {
        if (dateAuPlusTard[i] == dateAuPlusTot[i])
            sommetCritique.push_back(d_graph.getSommets()[i]->getInfo());
    }
}

vector<int> Ordonnancement::calculAPP() const
{
	vector<int> app;
	vector<int> calculDdi = calculDDI();
	int n = d_graph.getAPS()[0];
	app.resize(n+1);
	app[0] = n;
	app[1] = 1;
	for(int i=1; i<n; i++)
		app[i+1] = app[i] + calculDdi[i] + 1;
	return app;
}

vector<int> Ordonnancement::calculFP() const
{
	vector<int> calculApp = calculAPP();
	vector<int> fp;
	int n = d_graph.getAPS()[0];
	int m = d_graph.getFS()[0];
	fp.resize(m+1);
	fp[0] = m;
	int k=1,j;
	for(int i = 1; i <= n; i++)
	{
		 while ((j = d_graph.getFS()[k]) > 0)
		{
			fp[calculApp[j]] = i;
			calculApp[j]++;
			k++;
		 }
	 k++;
 	}
 	fp[calculApp[n]] = 0;
	for(int i=n-1; i>=1; i--)
	{
		fp[calculApp[i]] = 0;
		calculApp[i+1] = calculApp[i] + 1;
	}
	calculApp[1] = 1;
 	return fp;
}



vector<int> Ordonnancement::calculDDI() const
{
	int n = d_graph.nbSommets();
    vector <int> ddi;
    ddi.resize(n+1);
    ddi[0] = n;
    for(int s = 1; s <= n; s++)
       ddi[s] = 0;
    for(int k = 1; k < d_graph.getFS()[0]; k++)
    {
        if (d_graph.getFS()[k] !=0)
            ddi[d_graph.getFS()[k]] ++;
    }
    return ddi;
}


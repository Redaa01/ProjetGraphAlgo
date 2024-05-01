#include <iostream>
#include "distance.h"
#include <vector>
#include "application.h"

#include "kruskal.h"

void testKruskal()
{
    Graph g, t;
    Kruskal k;
    k.saisie(g);
    int n = g.n;
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
    cout<<"init"<<endl;
    k.affichet(prem,n);
    k.affichet(pilch,n);
    k.affichet(cfc,n);
    k.affichet(NbElem,n);



    k.trier(g);
    cout<<"tri"<<endl;
    k.affichet(prem,n);
    k.affichet(pilch,n);
    k.affichet(cfc,n);
    k.affichet(NbElem,n);

    k.AlgoKruskal(g, t, prem, pilch, cfc,NbElem);

    cout<<"kruskal"<<endl;
    k.affichet(prem,n);
    k.affichet(pilch,n);
    k.affichet(cfc,n);
    k.affichet(NbElem,n);

    k.affichage(t);
    delete[] prem;
    delete[] pilch;
    delete[] cfc;
    delete[] NbElem;
}

int main()
{
    application a;
    a.menuPrincipal();
    //testKruskal();
    return 0;
}

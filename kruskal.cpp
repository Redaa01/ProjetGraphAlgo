#include "kruskal.h"

#include <iostream>
using namespace std;

Kruskal::Kruskal()
{

}

void Kruskal::saisie(Graph &g)
{
    int s, t;
    arete ar;
    cout << "Saisie d'un graphe non oriente value arete par arete " << endl <<
    endl;
    cout << "Donnez le nombre de sommets : ";
    cin >> g.n;
    do
    {
        cout << "Donnez le nombre d'aretes : ";
        cin >> g.m;
    } while (g.m < g.n);
        g.a = new arete[g.m];
    cout << "Saisissez les " << g.m << " aretes" << endl;
    for (int i = 0; i < g.m; i++)
    {
        cout << "arete n " << i + 1 << " :" << endl;
        do
        {
            cout << "extremite 1 (entre 1 et " << g.n << " ) : ";
            cin >> s;
            ar.s = s;
        } while ((s < 1) && (s > g.n));
        do
        {
            cout << "extremite 2 (entre 1 et " << g.n << " ) : ";
            cin >> t;
            ar.t = t;
        }while ((t < 1) && (t > g.n));
            g.a[i] = ar;
        cout << "Poids de l'arete : ";
        cin >> g.a[i].p;
    }
}

void Kruskal::affichage(Graph g)
{
    for (int i = 0; i < g.m; i++)
    cout << "Arete No " << i + 1 << " : (" << g.a[i].s << " , " <<
    g.a[i].t << ") --- " << g.a[i].p << endl;
}

void Kruskal::trier(Graph &g)
{
    double p;
    for (int i = 0; i < g.m - 1; i++)
    for (int j = i + 1; j < g.m; j++)
    if ((g.a[j].p < g.a[i].p) || (g.a[j].p == g.a[i].p && g.a[j].s
    < g.a[i].t) || (g.a[j].p == g.a[i].p && g.a[j].t < g.a[i].t))
    {
        p = g.a[j].p;
        g.a[j].p = g.a[i].p;
        g.a[i].p = p;
    }
}
void Kruskal::affichet(int *a, int n)
{
    for(int i =1; i<=n;i++)
    {
        cout<<a[i]<<"|"<<" ";
    }
    cout<<endl;

}

void Kruskal::fusionner(int i, int j, int *prem, int *pilch, int *cfc, int *NbElem)
// i et j sont les numéros des composantes à fusionner
// en une seule composante qui portera le numéro le plus
// petit des deux
{
    if (NbElem[i] < NbElem[j])
    {
        int aux = i;
        i = j;
        j = aux;
    }
    int s = prem[j];
    cfc[s] = i;

    while (pilch[s] != 0)
    {
        s = pilch[s];
        cfc[s] = i;
    }
    pilch[s] = prem[i];
    prem[i] = prem[j];
    NbElem[i] += NbElem[j];
}

void Kruskal::AlgoKruskal(Graph g, Graph &t, int *prem, int *pilch, int *cfc, int *NbElem)
{
    int n = g.n;
    t.a = new arete[g.n-1];
    int x; // respectivement le numéro de composante de la 1ère extrémité del’arête courante
    int y; // respectivement le numéro de composante de la 2ème extrémité del’arête courante
    int i = 0, j = 0;//respectivement indice dans g et t
    while (j < g.n-1)
    {
        arete ar = g.a[i];
        x = cfc[ar.s];
        y = cfc[ar.t];
        cout<<x<<" "<<y<<endl;
        if (x != y)
        {
            t.a[j++] = g.a[i];
            cout<<x<<" "<<y<<endl;
            affichet(prem,n);
            affichet(pilch,n);
            affichet(cfc,n);
            affichet(NbElem,n);
            fusionner(x, y, prem, pilch, cfc, NbElem);
        }
        i++;
    }
    t.n = g.n;
    t.m = g.n - 1;
}

#include "tarjan.h"

tarjan::tarjan()
{
    //ctor
}

void tarjan::AlgoTarjan(const vector<int>& FS, const vector<int>& APS)
{
    vector<int> cfc, pilch, pred, prem;
    fortconnexe(FS, APS, cfc, pilch, pred, prem);
}

void tarjan::fortconnexe(const vector<int>& FS, const vector<int>& APS, vector<int>& cfc, vector<int>& pilch, vector<int>& pred, vector<int>& prem)
{
    int n = APS[0], p = 0;

    cfc.clear();
    cfc.resize(n + 1);
    cfc[0] = n;

    pilch.clear();
    pilch.resize(n + 1);

    pred.clear();
    pred.resize(n + 1, 0);

    prem.clear();
    prem.reserve(n + 1);
    prem.push_back(0);

    vector<int> tarj;
    tarj.reserve(n + 1);
    vector<bool> entarj(n + 1, true);
    vector<int> num(n + 1, 0);
    vector<int> ro(n + 1, 0);

    int k = 0;

    pilch[0] = 0;

    for(int s = 1; s <= n; ++s)
    {
        if(num[s] == 0)
        {
            traversee(s, p, k, FS, APS, cfc, pilch, pred, prem, tarj, entarj, num, ro);
        }
    }
    prem[0] = k;
}

void tarjan::traversee(int s, int& p, int& k, const vector<int>& FS, const vector<int>& APS, vector<int>& cfc, vector<int>& pilch, vector<int>& pred, vector<int>& prem, vector<int>& tarj, vector<bool>& entarj, vector<int>& num, vector<int>& ro)
{
    ++p;
    num[s] = p;
    ro[s] = p;

    tarj.push_back(s);

    int i = APS[s];
    int t = FS[i];
    while(t != 0)
    {
        if(num[t] == 0)
        {
            pred[t] = i;
            traversee(t, p, k, FS, APS, cfc, pilch, pred, prem, tarj, entarj, num, ro);
        }

        if(entarj[t]){
            if(ro[t] < ro[s]) ro[s] = ro[t];
            else if(num[t] < ro[s] and entarj[t]) ro[s] = num[t];
        }

        ++i;
        t = FS[i];
    }

    if(ro[s] == num[s])
    {
        ++k;

        int u = 0;
        do
        {
            u = tarj.back();
            tarj.pop_back();
            entarj[u] = false;
            empiler(u, pilch);
            cfc[u] = k;
        } while(u != s);

        prem.push_back(pilch[0]);
        pilch[0] = 0;
    }
}

void tarjan::empiler(int x, vector<int>& pilch)
{
    pilch[x] = pilch[0];
    pilch[0] = x;
}

void tarjan::versGrapheReduit(const vector<int>& cfc, const vector<int>& prem,const vector<int>& fs,const vector<int>& aps, vector<vector<int>>& mat)
{
    //On initialise correctement la matrice representant le futur graphe reduit
    mat.resize(prem[0]+1);
    mat[0].resize(2);
    mat[0][0] = prem[0];
    for(int i = 1; i <= prem[0] ; ++i)
            mat[i].resize(prem[0]+1,0);

    //On commence par l'ordre croissant des composantes
    bool est_deja_dans_composant = false;
    for(int composant = 1; composant <= prem[0] ; ++composant)
    {
        //On commence par chercher l'ensemble des sommets qui sont dans le composant courant
        for(int i = 1 ; i <= cfc[0] ; ++i)
        {
            //Si le sommet courant est dans la composante, on regarde tous ses successeurs
            if(cfc[i] == composant)
            {
                vector<int> est_deja; //Tableau qui nous renseigne sur le fait qu'une composante a deja ete trouvee (on ne la met pas deux fois)
                bool est_vide = true;
                est_deja.reserve(prem[0]); //Au maximum...
                //On commence a chercher les successeurs...
                int j = aps[i];
                while(fs[j] != 0) //Parcourt des successeurs
                {
                    //Le composant du successeurs
                    int comp_suiv = cfc[fs[j]];
                    if(!est_vide) //Si est_deja n'est pas vide
                    {
                        //On regarde si la composante trouvee est deja presente
                        for(unsigned k = 0 ; k < est_deja.size() ; ++k)
                        {
                            //Si elle est deja ou que le successeur est en fait dans la meme composante
                            if(comp_suiv == est_deja[k] || comp_suiv == composant)
                                est_deja_dans_composant = true;
                        }
                    }
                    //Si la comoosante n'est pas encore dans est_deja
                    if(!est_deja_dans_composant)
                    {
                        if(composant != comp_suiv)//Dans le cas ou c'est vide, il faut verifier cette condition avant de l'ajouter
                        {
                            est_deja.push_back(comp_suiv);
                            est_vide = false;
                        }
                    }
                    //On regarde le successeur suivant
                    ++j;
                    est_deja_dans_composant = false;
                }
                //Si le tableau est_deja contient plus d'un élément
                if(est_deja.size() > 1)
                {
                    TrierTableau_QuickSort(est_deja, 0, est_deja.size());
                }
                //Si est_deja n'est pas vide (dans le cas ou aucun des sommets de la composante
                //n'a de successeur autre que des sommets appartenant a cette composante)
                if(!est_vide)
                {
                    unsigned cpt = 0;
                    unsigned k = 1;
                    //On met les composantes trouvees dans la matrice en tant que successeur de la composante courante
                    while(cpt < est_deja.size() && k < mat[composant].size())
                    {
                        if(est_deja[cpt] == (int)k)
                        {
                            mat[composant][k] = 1;
                            ++cpt;
                        }
                        ++k;
                    }
                }
                //On enleve tous les elements du tableau
                est_deja.clear();
            } // fin du if
        }//fin du for i
    } //fin des composantes

    //A ce stade l'integralite de la matrice est remplie sauf la cellule contenant le nombre d'arcs et de sommets.
    //On parcourt la matrice definitive pour determiner le nombre d'arcs pour en deduire mat[0][1]
    int nb_arcs = 0;
    for(unsigned i = 1 ; i < mat.size() ; ++i)
        for(unsigned j = 1 ; j < mat[i].size() ; ++j)
            if(mat[i][j] == 1)
                nb_arcs++;

    mat[0][1] = nb_arcs;
}

void tarjan::TrierTableau_QuickSort(vector<int>& tab, int g, int d)
{
    if(g<d)
    {
        int m = partition(tab,g,d);
        TrierTableau_QuickSort(tab,g,m-1);
        TrierTableau_QuickSort(tab,m+1,d);
    }
}

int tarjan::partition(vector<int>& t, int g, int d)
{
    //Sert pour le tri du tableau
    int m = g;
    for(int i = g+1 ; i <= d ; ++i)
    {
        if(t[i] < t[g])
        {
            ++m;
            std::swap(t[i],t[m]);
        }
    }
    std::swap(t[g],t[m]);
    return m;
}

void tarjan::base_Greduit(const vector<int>& fsR, const vector<int>& apsR, vector<int>& baseR_GrapheR)
{
    int nb_sommets = apsR[0];
    baseR_GrapheR.resize(nb_sommets+1);
    vector<int> ddir(nb_sommets+1);
    for(int i = 0 ; i <= nb_sommets ; ++i)
        ddir[i] = 0;

    for(int kr = 1 ; kr <= fsR[kr] ; kr++)
        ddir[fsR[kr]]++;


    int nb = 0;
    for(int c = 1 ; c <= nb_sommets ; c++)
        if (ddir[c] == 0)
            baseR_GrapheR[++nb] = c;

    baseR_GrapheR[0] = nb;
}

void tarjan::edition_bases(const vector<int>& prem, const vector<int>& pilch, const vector<int>& baseR, vector<int>& baseInitiale)
{
    int nb = baseR[0];                  // Nombre de CFC de l’unique base du graphe réduit
    baseInitiale.resize(nb+1);            // pile qui mémorise les sommets des bases du graphe initial
    baseInitiale[0] = nb;
    int p = 1;
    int som = prem[baseR[1]];           // premier sommet de la première CFC
    while(p >= 1)
    {
        if((p<= nb) && (som != 0))
        {
             baseInitiale[p] = som;
             p++;
             if(p <= nb)
                 som = prem[baseR[p]];
             //else printVector(Base);    // Affiche le contenu du tableau Base contenant les sommets d’une base du graphe initial
        }
        else
        {
             p--;
             som = pilch[baseInitiale[p]];
        }
    }
}

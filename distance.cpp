#include "distance.h"

distance::distance()
{

}

void distance::descente_largeur(int r,const vector<int>& fs, const vector<int>& aps, vector<int>& dist)
{
    int nb_sommets = aps[0];
    int i = 0;
    int j = 1;
    int k = 0;
    int ifin;
    int s;
    int t;
    int it;
    vector<int> fil(nb_sommets+1);
    fil[0] = nb_sommets;
    dist.resize(nb_sommets+1);
    dist[0] = nb_sommets;
    fil[1] = r;

    for(int h = 1 ; h <= nb_sommets ; ++h)
    {
        dist[h] = -1;
    }
    dist[r] = 0;

    while(i<j) //Tq la file d'attente n'est pas vide
    {
        ++k;
        ifin = j;
        while(i<ifin) //On parcourt le bloc courant
        {
            ++i;
            s = fil[i];
            it = aps[s];
            t = fs[it];
            while(t>0) //On parcourt tous les successeurs de chaque sommet du bloc courant
            {
                if(dist[t] == -1) //Si le successeur du sommet courant n'est pas encore marqué
                {
                    ++j;
                    fil[j] = t; //On le place dans le bloc suivant en préparation et on lui affecte la distance courante
                    dist[t] = dist[fil[i]]+1;//dist[t] = k;//Variante : dist[t] = dist[fil[i]]+1;
                }
                t = fs[++it];
            }
        }
    }
}

void distance::edit(const vector<int> dist)
{
    for(int i = 1; i <= dist[0]; i++)
    {
        std::cout<<dist[i]<<" - ";
    }
}

/*exemple :
    distance d;
    vector<int> fs{13, 2, 3, 4, 0, 2, 3, 4, 0, 5, 0, 0, 4, 0};
    vector<int> aps{5, 1, 5, 9, 11, 12};
    vector<int> dist;
    d.descente_largeur(1, fs, aps, dist);
    d.edit(dist);
*/

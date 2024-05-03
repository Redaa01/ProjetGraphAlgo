#include "rang.h"


Rang::Rang(const vector<int>& aps, const vector<int>& fs) : d_aps{aps}, d_fs{fs}
{

}

int Rang::getTailleAps() const
{
    return d_aps[0];
}

void Rang::empiler(int x) // avec x dans {1, ... , n}
{
    d_pilch[x] = d_pilch[0];
    d_pilch[0] = x;
}



vector<int> Rang::calculeRang()
{
    int n = d_aps[0], taillefs = d_fs[0], s, k, h, t;
    vector<int> rang(n + 1);
    vector<int> ddi(n + 1, 0);
    vector<int> pilch(n + 1);
    vector<int> prem(n + 1);
    //calcul de ddi
    for (int i = 0; i < taillefs; i++)
    {
        s = d_fs[i];
        if (s > 0)
            ddi[s]++;
    }
    //calcul du rang
    pilch[0] = 0;
    for (s = 1; s <= n; s++)
    {
        rang[s] = -1; // n : nombre de sommets de G represente l'infini
        if (ddi[s] == 0)
            empiler(s);
    }

    k = -1;
    s = pilch[0];
    prem[0] = s;
    while (pilch[0] > 0)
    {
        k++;
        pilch[0] = 0;
        while (s > 0)
        {
            rang[s] = k;
            h = d_aps[s];
            t = d_fs[h];
            while (t > 0)
            {
                ddi[t]--;
                if (ddi[t] == 0)
                    empiler(t);
                h++;
                t = d_fs[h];
            }
            s = pilch[s];
        }
        s = pilch[0];
        prem[k + 1] = s;
    }

    return rang;
}

void Rang::ecrireRangsDansFichier(vector<int> &rang, const std::string &nomFichier)
{
    std::ofstream fichier(nomFichier);
    if (fichier.is_open())
    {
        for (size_t i = 1; i < rang.size(); ++i)
        {
            fichier << "rang[" << i << "] = " << rang[i] << std::endl;
        }
        fichier.close();
        std::cout << "Rangs écrits dans le fichier : " << nomFichier << std::endl;
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
    }
}

void Rang::lireGrapheDepuisFichier(const std::string &nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (fichier.is_open())
    {
        int n, m;
        fichier >> n >> m;
        d_aps.resize(n + 1);
        d_fs.resize(n + m + 1);
        d_aps[0] = n;
        d_fs[0] = n + m;

        for (int i = 1; i <= n; ++i)
        {
            fichier >> d_aps[i];
        }

        for (int i = 1; i <= n + m; ++i)
        {
            fichier >> d_fs[i];
        }

        fichier.close();
        std::cout << "Graphe lu depuis le fichier : " << nomFichier << std::endl;
    }
    else
    {
        std::cout << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
    }
}

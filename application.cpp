#include "application.h"

application::application()
{
    //ctor
}

void application::menuPrincipal()
{
    cout<<"Bienvenue dans l'application console."<<endl;
    cout<<"Que souhaitez-vous faire ?\n"<<endl;
    int choix = 0;
    cout<<"0. Quitter\n";
    cout<<"1. Charger un graphe.\n";
    cout<<"2. Lancer un algorithme\n";
    cin>>choix;
    while(choix < 0 || choix > 2)
    {
        cout<<"Erreur, le choix saisi n'existe pas. Veuillez ressaisir votre choix :"<<endl;
        cout<<"0. Quitter";
        cout<<"1. Charger un graphe.\n";
        cout<<"2. Lancer un algorithme\n";
        cin>>choix;
    }
    switch(choix)
    {
    case 0:
    {
        break;
    }
    case 1 :
    {
        load();
        break;
    }
    case 2:
    {
        algorithmes();
        break;
    }
    default:{break;}
    }
}

void application::load()
{
    int choix;
    cout<<endl<<"Bienvenue dans le menu de chargement d'un graphe. De quelle maniere voulez-vous le saisir?"<<endl;
    do {
        std::cout<<"> 1. Via FS/APS ?"<<std::endl;
        std::cout<<"> 2. Via la matrice ?"<<std::endl;
        std::cout<<"> 3. Via un fichier ?"<<std::endl;
        std::cin>>choix;
    }while(choix < 0 || choix > 3);

    switch(choix)
    {
        case 1: FSandAPS();
                break;
        case 2: matrice();
                break;
        /*case 3: fichier();
                break;*/ //A FAIRE
    }

    menuPrincipal();
}

void application::FSandAPS()
{
        int n, m;
        vector<int> APS;
        vector<int> FS;
        vector<vector<int>> p;
        cout<<"Entrez le nombre de sommets du graphe : ";
        cin>>n;

        APS.resize(n+1);
        APS[0] = n;

        cout<<"Entrez le nombre d'arcs du graphe : ";
        cin>>m;

        FS.resize(n+m+1);
        FS[0] = n+m;

        int a_des_poids;
        cout<<"Est-ce qu'il y a des poids dans votre graphe ?"<<endl;
        cout<<"> 1. OUI\n";
        cout<<"> 2. NON\n";
        cin>>a_des_poids;
        if(a_des_poids == 1)
        {
            p.resize(n+1);
            for(int i = 1; i <= n; i++)
            {
                p[i].resize(n+1);
            }

            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    p[i][j] = -1;
                }
            }

            int k = 0;
            int ns;
            for(int i = 1; i <= n; i++)
            {
                APS[i] = k+1;
                cout<<"Donner le nombre de successeurs du sommet "<<i<<" : ";
                cin>>ns;
                cout<<"Donner a cote de chaque successeur de "<<i<<" le poids de l'arc correspondant (Successeur Poids): \n";
                for(int j = 1; j <= ns; j++)
                {
                    int s;
                    do{
                       cin>>s;
                    }while(s <= 0|| s > n);
                    FS[++k] = s;
                    cin>>p[i][FS[k]];
                }
                FS[++k] = 0;
            }
            d_graphe.setFSandAPS(FS, APS);
            d_graphe.setCout(p);
        }
        else
        {
            int k = 0;
            int ns;
            for(int i = 1; i <= n; i++)
            {
                APS[i] = k+1;
                cout<<"Donner le nombre de successeurs du sommet "<<i<<" : ";
                cin>>ns;
                cout<<"Donner a cote de chaque successeur de "<<i<<" : \n";
                for(int j = 1; j <= ns; j++)
                {
                    int s;
                    do{
                       cin>>s;
                    }while(s <= 0|| s > n);
                    FS[++k] = s;
                }
                FS[++k] = 0;
            }
            d_graphe.setFSandAPS(FS, APS);
            d_graphe.setA_des_poids(false);
        }
}

void application::matrice()
{
    bool choixOriente;
    do{
        std::cout<<"S'agit-il d'un graphe oriente ? (1 = oui/0 = non)";
        std::cin>>choixOriente;
    }while(choixOriente != 1 && choixOriente != 0);

    int tailleMatrice;
    std::cout<<"Nombre de noeud : ";
    std::cin>>tailleMatrice;

    int nbArcs;
    std::cout<<"Nombre d'arcs : ";
    std::cin>>nbArcs;

    vector<vector<int>> Matrice(tailleMatrice+1);

    Matrice[0].push_back(tailleMatrice);
    Matrice[1].push_back(nbArcs);

    for(int i = 1; i <= tailleMatrice; i++)
    {
        Matrice[0][i] = 0;
    }

    for(int i = 1; i < tailleMatrice; i++)
    {
        Matrice[i].resize(tailleMatrice+1);
    }
    for(int i = 1; i <= tailleMatrice; i++)
    {
        for(int j = 1; j <= tailleMatrice; j++)
        {
            std::cout<<"Case n°["<<i<<"]["<<j<<"]";
            std::cin>>Matrice[i][j];
        }
    }
    d_graphe.setMatrice(Matrice);
    d_graphe.setOriente(choixOriente);
}

void application::algorithmes()
{
    cout<<"Bienvenue dans le menu Algorithmes.\n"<<endl;
    cout<<"Veuillez choisir un algorithme parmi ceux propose :\n"<<endl;
    int choix = 0;
    cout<<"0. Quitter\n";
    cout<<"1. Algorithme des distances.\n";
    cout<<"2. Algorithme du rang\n";
    cout<<"3. Algorithme de Tarjan\n";
    cout<<"4. Algorithme de l'ordonnancement\n";
    cout<<"5. Algorithme de Dijkstra\n";
    cout<<"6. Algorithme de Dantzig\n";
    cout<<"7. Algorithme de Kruskal\n";
    cout<<"8. Codage de Prufer\n";
    cout<<"9. Decodage de Prufer\n";
    cin>>choix;
    while(choix < 0 || choix > 9)
    {
        cout<<"Erreur, le nombre saisi ne correspond a aucun algorithme. Veuillez en ressaisir un.\n"<<endl;
        cout<<"0. Quitter\n";
        cout<<"1. Algorithme des distances.\n";
        cout<<"2. Algorithme du rang\n";
        cout<<"3. Algorithme de Tarjan\n";
        cout<<"4. Algorithme de l'ordonnancement\n";
        cout<<"5. Algorithme de Dijkstra\n";
        cout<<"6. Algorithme de Dantzig\n";
        cout<<"7. Algorithme de Kruskal\n";
        cout<<"8. Codage de Prufer\n";
        cout<<"9. Decodage de Prufer\n";
        cin>>choix;
    }
    switch(choix)
    {
    case 0:
    {
        break;
    }
    case 1 :
    {
        vector<vector<int>> mat_dist;
        if(verifieDistance())
        {
             mat_dist = englobe_Distance();
             string s = "";
             for(unsigned i = 0 ; i < mat_dist.size() ; ++i)
             {
                 s += toStringVector(mat_dist[i]) + "\n";
             }
             cout<<"Resultat de l'algorithme des distances :"<<s<<endl;
        }
        break;
    }
}
}

string application::toStringVector(const vector<int>& tab)
{

    string s = "[ ";
    for(unsigned i = 0 ; i < tab.size() ; ++i)
    {
        s += std::to_string(tab[i]) + ", ";
    }
    s += "]";
    return s;
}


bool application::verifieDistance()
{
    //Il faut que fs et aps soit initialisé ou la matrice ET que le graphe soit oriente.
    if(d_graphe.getEst_oriente())
    {
        if(d_graphe.isUsingFsAndAps())
        {
            if(verifieFS_APS_NonVide())
                return true;
            else
            {
                std::cout<<"ERREUR DISTANCE: FS et APS vide !"<<endl;
                return false;
            }
        }
        else if(verifieMatrice_NonVide())
        {
            return true;
        }
        else
        {
            std::cout<<"ERREUR DISTANCE: Matrice vide !"<<endl;
            return false;
        }
    }
    else
    {
        std::cout<<"ERREUR DISTANCE: Graphe non oriente !"<<endl;
        return false;
    }
}

vector<vector<int>> application::englobe_Distance()
{
    vector<vector<int>> matriceDistance;
    if(!d_graphe.isUsingFsAndAps())
    {
        transformeVersFS_APS();
    }
    distance d;
    d.mat_distance(d_graphe.getFS(),d_graphe.getAPS(),matriceDistance);
    return matriceDistance;
}

void application::transformeVersMatrice()
{
    vector<vector<int>> matrice ;
    d_graphe.FS_APS_to_MatAdj(matrice);

    for(unsigned i = 1 ; i < matrice.size() ; ++i)
        printVector(matrice[i]);

    d_graphe = Graph(matrice, d_graphe.getSommets(), d_graphe.getEst_oriente(), d_graphe.getA_Des_Poids());
}

void application::transformeVersFS_APS()
{
    vector<int> fs, aps;
    d_graphe.matAdj_to_FS_APS(fs,aps);

    d_graphe = Graph(fs, aps, d_graphe.getSommets(), d_graphe.getEst_oriente(), d_graphe.getA_Des_Poids());
}

bool application::verifieFS_APS_NonVide()
{
    if(d_graphe.getFS().empty() || d_graphe.getAPS().empty())
    {
        return false;
    }
    return true;
}

bool application::verifieMatrice_NonVide()
{
    vector<vector<int>> mat = d_graphe.getMatAdj();
    if(mat.empty())
        return false;
    else if(mat[0].size() != 2)
    {
        return false;
    }
    else
    {
        unsigned size = mat[1].size();
        for(unsigned i = 2 ; i < mat.size() ; ++i)
        {
            if(mat[i].size() != size)
                return false;
        }
        return true;
    }
}

void application::printVector(const vector<int>& v)
{
    unsigned i = 0;
    cout << "[";
    for(i = 0; i < v.size() - 1; ++i)
    {
        cout << v[i] << ", ";
    }
    cout << v[i] << "]\n";
}

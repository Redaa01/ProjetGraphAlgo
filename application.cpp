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

}

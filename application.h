#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <iostream>
#include <graph.h>
using std::cout;
using std::cin;
using std::vector;
using std::endl;

class application
{
    public:
        application();
        void menuPrincipal();
        void load();
        void FSandAPS();
        void matrice();
        void algorithmes();
    private:
        graph d_graphe;
};

#endif // APPLICATION_H

#ifndef NOEUD_H
#define NOEUD_H

#include <iostream>
using namespace::std;

class noeud
{
    public:
        noeud(int id);
        noeud(int id, const string& info);
        noeud(const noeud& n);

        int getId() const; //permet de récupérer l'id du noeud
        string getInfo() const; //permet de récupérer l'info du noeud

        void setId(int id); //permet d'inseret un id du noeud
        void setInfo(const string& info); //permet d'insérer une info du noeud
    private:
        int d_id;
        string d_info;
};

#endif // NOEUD_H

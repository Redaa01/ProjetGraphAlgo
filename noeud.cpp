#include "noeud.h"

noeud::noeud(int id) : d_id{id}, d_info{}
{}

noeud::noeud(int id, const string& info) : d_id{id}, d_info{info}
{}

noeud::noeud(const noeud& n) : d_id{n.d_id}, d_info{n.d_info}
{}

int noeud::getId() const
{
    return d_id;
}

string noeud::getInfo() const
{
    return d_info;
}

void noeud::setId(int id)
{
    d_id = id;
}

void noeud::setInfo(const string& info)
{
    d_info = info;
}

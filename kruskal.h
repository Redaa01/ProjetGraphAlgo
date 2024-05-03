#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include "graph.h"

class Kruskal
{
public :
    Kruskal();
    void AlgoKruskal(const Graph& g, Graph &t);
};

#endif // KRUSKAL_H_INCLUDED

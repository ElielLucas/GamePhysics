#ifndef BFS_H
#define BFS_H
#include <algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<thing.h>
using namespace std;
typedef vector<int> vecInt;
class Bfs
{
    int N;
    vecInt  *V;

public:
    Bfs(){}
    Bfs(int N);
    ~Bfs();
    void initGrafo(int N);
    void insereAresta(int u, int v);
    void excluiAresta(int u, int v);
    bool temAresta(int u, int v);
    void bfs(int s, int*d, int*p);
    int grau(int u){return V[u].size();}
    vector<int> v(int u);
    int popular();
};


#endif // BFS_H

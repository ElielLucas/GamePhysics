#include "bfs.h"

Bfs::Bfs(int N)
{
    this->N=N;
    V=new vecInt[N+1];
}
Bfs::~Bfs()
{
    delete []V;
}
void Bfs::initGrafo(int N)
{
    this->N=N;
    V=new vecInt[N+1];
}
void Bfs::insereAresta(int u, int v)
{
    bool ok=true;
    for(int i=0;i<(int)V[u].size();i++)
    {
        if(V[u][i]==v)
            ok=false;
    }
    if(ok)V[u].push_back(v);
}

void Bfs::excluiAresta(int u, int v)
{
    vector<int>aux;
    for(int i=0;i<(int)V[u].size();i++)
    {
        if(V[u][i]!=v)
            aux.push_back(V[u][i]);
    }
    V[u].clear();
    V[u]=aux;
}

bool Bfs::temAresta(int u, int v)
{
    for(int i=0;i<(int)V[u].size();i++)
    {
        if(V[u][i]==v)
            return true;
    }
    return false;
}

void Bfs::bfs(int s, int*dist, int*p)
{
    for(int i=0;i<N;i++)
    {
        dist[i]=INT_MAX;
        p[i]=-1;
    }
    dist[s]=0;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        int uSize=V[u].size();
        Q.pop();
        for(int i=0;i<uSize;i++)
        {
            int v=V[u][i];
            if(dist[v]>dist[u]+1)
            {
                Q.push(v);
                p[v]=u;
                dist[v]=dist[u]+1;
            }
        }
    }
}


vector<int>  Bfs::v(int u)
{
    vector<int> saida;
    for(int i=0;i<(int)V[u].size();i++)
    {
        saida.push_back(V[u][i]);
    }
    return saida;
}

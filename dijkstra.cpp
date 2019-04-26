#include<bits/stdc++.h>

#define s2s pair<int,int>

using namespace std;

int d[100];
int par[100];

struct pri{

    int operator() (const pair<int,int>&p1,const pair<int,int>&p2){

        return p1.second<p2.second;
    }
}p;



bool relax(int u, int v, int w){

    if(d[v]>d[u]+w){
        d[v]=d[u]+w;
        par[v]=u;
        return true;
    }
    else{
        return false;
    }
}

void findd(int v){

    if(v!=par[v]){

        findd(par[v]);
    }
   cout<<v<<"  ";

}


void in(int V,int s){

    for(int i=0;i<V;i++){
        d[i]=SHRT_MAX;
        par[i]=i;
    }
    d[s]=0;

}
int main(void){

    int V,E,s=0;
    priority_queue<s2s,vector<s2s>,pri > q;

    vector<s2s> vec[100];
    cin>>V>>E;
    in(V,0);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back(s2s(v,w));
    }
    int cnt=V;
    q.push(s2s(s,d[s]));
    while(cnt--){
        int u=q.top().first;
        q.pop();
        for(int k=0;k<vec[u].size();k++){
            int v=vec[u][k].first;
            int w=vec[u][k].second;
            if(relax(u,v,w)){
                q.push(s2s(v,d[v]));
            }

        }

    }
    for(int i=0;i<V;i++){
        cout<<d[i]<<endl;
    }

    findd(3);

    return 0;
}

/*
4 5
0 1 10
1 2 20
2 3 15
1 3 5
3 0 50
*/


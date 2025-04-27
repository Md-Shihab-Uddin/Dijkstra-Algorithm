#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
vector<int> ans(vector<vector<vector<int>>>&adj,vector<int>&parent,int N){
    vector<int>dist(N+1,INT_MAX);
    dist[1]=0;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        int u=pq.top()[1];
        pq.pop();
        for(auto child:adj[u]){
            int v=child[0];
            int wt=child[1];
            if(dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
                parent[v]=u;
            }
        }

    }
    return dist;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<vector<int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int>parent(N+1,-1);
   vector<int>dist=ans(adj,parent,N);
   if(parent[N]==-1)cout<<-1<<endl;
   else{
    vector<int>path;
    int node=N;
    while(node!=-1){
        path.push_back(node);
        node=parent[node];
    }
    reverse(path.begin(),path.end());
    for(auto it:path){
       cout<<it<<" ";
    }
   }
   

   
   
    return 0;
}

#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
vector<int>dijkstra(vector<vector<vector<int>>>&adj,int src){
    int edges=adj.size();
    vector<int>dist(edges,INT_MAX);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        int u=pq.top()[1];
        pq.pop();
        for(auto x:adj[u]){
            int v=x[0];
            int wt=x[1];
            if(dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
            }


        }
    }
    return dist;
}

int main(){
  int n,m,src;
  cin>>n>>m>>src;
  vector<vector<vector<int>>>adj(n);
  for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
  }
  vector<int>ans=dijkstra(adj,src);
  for(auto &it:ans){
    cout<<it<<" ";  
  }
    return 0;
}
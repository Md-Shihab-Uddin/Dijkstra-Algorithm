#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int ans(vector<vector<vector<int>>>&adj,int N){
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
            }
        }

    }
    return dist[N];
}

int main(){
  int N,M;
  cin>>N>>M;
  vector<int>cost(N);
  for(int i=0;i<N;i++){
    cin>>cost[i];
  }
  vector<vector<vector<int>>>adj(N+1);
  for(int i=0;i<M;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back({v,cost[v-1]});
    adj[v].push_back({u,cost[u-1]});
  }
  cout<<ans(adj,N)<<endl;

    return 0;
}
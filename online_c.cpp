#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
vector<int> ans(vector<vector<vector<int>>>&adj,int N){
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
    return dist;
}

int main(){
    int N, M, F;
    cin >> N >> M >> F;

    vector<int> capacity(N + 1); // 1-indexed
    for (int i = 1; i <= N; i++) {
        cin >> capacity[i];
    }

    vector<vector<vector<int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int student;
    cin >> student;

    // Get distances from Lab 1
    vector<int> dist = ans(adj, N);
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   for(int i=1;i<=N;i++){
    pq.push({dist[i]+F,i});
   }
   while (!pq.empty() && student > 0) {
    int u = pq.top().second;
    int cost = pq.top().first;
    pq.pop();
    int toAssign = min(capacity[u], student);
    for (int i = 0; i < toAssign; i++) {
        cout << cost << " ";
    }
    student -= toAssign;
}

   while(student--){
    cout<<-1<<" ";
    
   }
   
    return 0;
}

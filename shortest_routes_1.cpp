#include <bits/stdc++.h>
using namespace std;
int main(){
    typedef pair<long long, int> pii; 
    const long long INF = 99999999999999;

    int n, m; //n nodi m archi
    cin>> n >> m; //input

    vector<vector<pii>> adj(n+1); //graph
    adj.resize(n+1);

    for(int i=0; i<m; i++){
        int A, B, C; //
        
        //start at city A, end in city B and lenght is C
        cin>> A >> B >> C;
        adj[A].push_back({C, B});
    } //get all the connections in my graph

    int start=1; //city one is the starter one
    vector<long long> dist(n+1, INF); //vector of distances
    dist[start]=0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    pq.push({0, start}); //insert the first pair in the queue

    while(!pq.empty()){
        int d = pq.top().first; //d is the distance of the first element in the queue (first pair item)
        int k = pq.top().second; //u is the city, second pair item
        pq.pop(); //remove them because I no longer need them

        if (d > dist[k]) continue; //if we already found a short route we continue with the next round of the cycle 

        for(auto& edge: adj[k]){
            int v= edge.second;
            int w= edge.first; //explore connections of the city

            if(dist[k]+ w < dist[v]){
                dist[v] = dist[k] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<< dist[i] <<" ";
    }
    return 0;
}
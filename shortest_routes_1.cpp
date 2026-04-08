#include <bits/stdc++.h>
using namespace std;
int main(){
    typedef pair<long long, int> pii; //pii is abbreviation for  pair
    const long long INF = 99999999999999; //set INF to a number big enough

    int n, m; //n nodes m edges
    cin>> n >> m; //input

    vector<vector<pii>> adj(n+1); //graph (since cities start at 1 I need n+1)
    // adj.resize(n+1); is not necessary because the size was set to n+1 in the previous line

    for(int i=0; i<m; i++){ //i<m and not n because I am reading edges
        int A, B, C; //a=from b=to c=weight
        cin>> A >> B >> C; //input

        adj[A].push_back({C, B}); //insert edges in the graph = in the vector of A's connections
        //insert the pair with weight C and connection B
    } //one-way roads

    int start=1; //start from city 1
    vector<long long> dist(n+1, INF); //vector of weights
    dist[start]=0; //first one is 0 because I'm already there

    priority_queue<pii, vector<pii>, greater<pii>> pq; //priority queue named pq
    //1. type of queue
    //2. vector of the same type for storage reasons 
    //3. how to sort them (it sorts them by smaller .first of the pairs)
    pq.push({0, start}); //insert the first pair in the queue, weight is 0 and edge is start

    while(!pq.empty()){ //why priority queue is not empty
        int d = pq.top().first; //d is the weight of the first element in the queue=.top (first pair item)
        int k = pq.top().second; //k is the node of the first element=.top (second pair item)
        pq.pop(); //remove them from the queue because I no longer need them

        if (d > dist[k]) continue; 
        /* Now that I saved the value d, I compare it to the weight of the k node in the weights array
        if it's bigger, which means I already found the shortest way, I continue to the next round of the 
        cycle
        */

        for(auto& edge: adj[k]){ //& is reference (like in function parameters), auto looks what's inside adj 
        //already so for all nodes connected to k (current node):
            int v= edge.second; //store the second element (the node) in v
            int w= edge.first; //store the first element (the weight) in w

            if(dist[k]+ w < dist[v]){ //dist[v] is the shortest route we know so far, dist[k] is 
            //the weight to the k node, w is the weight from v to k, so if it's easier to get to 
            //v from k than the previous route...
                dist[v] = dist[k] + w; //I update the weight vector because I find a faster way
                pq.push({dist[v], v}); //So now I have to explore the connections of v so I put it in the queue
                //as a pair with its distance
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<< dist[i] <<" ";
    } //output of the weight array 
    return 0;
}
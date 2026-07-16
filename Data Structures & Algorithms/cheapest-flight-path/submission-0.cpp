class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(V);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
        }

        vector<vector<int>> dist(V,vector<int>(k+2,1e9));
        dist[src][0] = 0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});

        while(!pq.empty()){
            auto[cost,node,stops] = pq.top();
            pq.pop();

            if(node == dst) return cost;

            if(stops > k) continue;

            for(auto it:adj[node]){
                int nextNode = it.first;
                int nextCost = it.second;

                int newCost = cost+nextCost;

                if(newCost < dist[nextNode][stops+1]){
                    dist[nextNode][stops+1] = newCost;
                    pq.push({newCost,nextNode,stops+1});
                }
            }
        }
        return -1;
    }
};

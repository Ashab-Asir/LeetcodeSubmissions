class Solution {
public:
    
    int dijkstra(int n, int src, int dest , vector<pair<int,int>>adj[]){

        vector<int> dist(n,2e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;

            for(auto child:adj[node]){
                int child_wt = child.second;
                int child_node = child.first;

                if(dist[child_node]>dist[node]+child_wt){
                    dist[child_node] = dist[node]+child_wt;
                    pq.push({dist[child_node],child_node});
                }
            }
        }
        return dist[dest];
    }



    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            if(it[2]!=-1){
                adj[it[0]].push_back({it[1],it[2]});
                adj[it[1]].push_back({it[0],it[2]});
            }

        }

        int dist = dijkstra(n, source, destination,adj);
        if(dist<target){
           return {};
        }
        

        bool hasPath = (dist==target);

        for(auto& it:edges){
            if(it[2]!=-1){
                continue;
            }

            it[2] = hasPath ? 2e9 : 1;

            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});

            if(!hasPath){
                int newDist = dijkstra(n,source,destination,adj);
                if(newDist<=target){
                    hasPath= true;
                    it[2] += (target-newDist);
                }
            }


        }

        if(hasPath){
            return edges;
        }
        return {};
        
    }
};
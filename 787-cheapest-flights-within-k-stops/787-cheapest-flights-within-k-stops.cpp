class Solution {
public:
    
    class node{
        public:
            int src;
            int cost;
            int count;
    };
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto flight: flights)
            adj[flight[0]].push_back({flight[1], flight[2]});
        
        vector<int> dist(n, INT_MAX);
        queue<node> q;
        q.push({src, 0, k + 1});
        
        int min_price = INT_MAX;
        
        while(not q.empty()){
            
            auto top = q.front(); q.pop();
            int src = top.src;
            int cost = top.cost;
            int count = top.count;
            
            if(src == dst)
                min_price = min(min_price, cost);
            
            if(cost > dist[src])
                continue;
            
            dist[src] = cost;                
            
            for(auto neighbor: adj[src]){
                int price = neighbor.second;
                
                if(price != -1 and count - 1 >= 0 and cost + price < min_price){
                    q.push({neighbor.first, (cost + price), count - 1});
                }                
                
            }
            
        }
        
        return (min_price == INT_MAX) ? -1 : min_price;
        
        
    }
};
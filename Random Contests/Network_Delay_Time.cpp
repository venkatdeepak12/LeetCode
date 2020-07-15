/*

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node,
and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2

*/

//Code:

class Solution {
public:
  
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>());
        int i,j;
        for(auto &x:times)
        {
            graph[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,int>> q;
        q.push({k,0});
        vector<int> vis(n+1,INT_MAX);
        while(!q.empty())
        {
            auto it=q.front();
            int curr=it.first;
            q.pop(); 
            if(vis[curr]!=INT_MAX and vis[curr]<=it.second)
            {
                continue;
            }
            vis[curr]=it.second;
             for(auto &x:graph[curr])
                {
                    q.push({x.first,it.second+x.second});
                }
            
        }
        int dist=*max_element(vis.begin()+1,vis.end());
        return (dist==INT_MAX?-1:dist);
    }
};

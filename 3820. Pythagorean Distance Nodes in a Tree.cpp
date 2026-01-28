```cpp
/*
Core Idea:
Calculates shortest path distances from three given special nodes (x, y, z) to all other nodes using Breadth-First Search (BFS).
Then, for each node, it checks if its distances to x, y, and z (when sorted as a, b, c) satisfy the Pythagorean theorem (a^2 + b^2 = c^2).
The function returns the count of such "special" nodes.

Time Complexity: O(N + E), where N is the number of nodes and E is the number of edges.
Three BFS traversals each take O(N + E). Graph construction and final iteration take O(N + E) and O(N) respectively.

Space Complexity: O(N + E), where N is the number of nodes and E is the number of edges.
This accounts for the adjacency list and distance vectors used for BFS.
*/
class Solution {
public:

    vector<int> bfs(int s,vector<vector<int>>& adj, int n){
        vector<int> dist( n,-1);
        queue<int> q;
        q.push(s);
        dist[s]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int i:adj[u]){
                if (dist[i] == -1){
                    dist[i] = dist[u]+1;
                    q.push(i);
                }
            }
        }
        return dist;
    }

    
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dx= bfs(x, adj , n);
        vector<int> dy= bfs(y, adj , n);
        vector<int> dz= bfs(z, adj , n);

        int cnt=0;
        for(int i =0;i<n;i++){
            vector<int>v={dx[i],dy[i],dz[i]};
            sort(v.begin(),v.end());

            int a=v[0], b=v[1], c=v[2];

            if (1ll*a*a + 1ll*b*b ==1ll*c*c){
                cnt++;
            }
        }

        return cnt;
    }
};
```
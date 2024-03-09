class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int level[200003];
        vector<vector<int>> adj(200003);
        queue<int> q;
        memset(level,-1,sizeof(level));
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        q.push(source);
        level[source]=0;

        while(!q.empty())
        {
            int u=q.front();
            cout<<u<<endl;
            if(u == destination)
                return true;

            q.pop();
            for(int i=0;i<adj[u].size();i++)
            {
                if(level[adj[u][i]]==-1)
                {
                    level[adj[u][i]]=0;
                    q.push(adj[u][i]);
                }
            }
        }
        return false;
    }
};
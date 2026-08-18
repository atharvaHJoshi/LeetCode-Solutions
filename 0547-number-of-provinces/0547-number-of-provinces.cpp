/// solved using DFS


class Solution {
public:

    void dfs( int u , vector<vector<int>>& adj , vector<bool>& visited )
    {
        visited[u] = true;

        for( int i = 0 ; i < adj[u].size() ; i++ )
        {
            if ( adj[u][i] ==1 && !visited[i] )
            {
                dfs( i , adj , visited );
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numsOfProvinces = 0;
        int n = isConnected.size();
        vector<bool> visited( n , false );
        for( int i = 0 ; i < n ; i++ )
        {
            if( !visited[i] )
            {
                dfs( i , isConnected , visited );
                numsOfProvinces++;
            }
        }
        return numsOfProvinces;      
    }
};
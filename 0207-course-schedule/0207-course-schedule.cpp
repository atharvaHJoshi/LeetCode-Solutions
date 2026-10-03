class Solution {

private:

    bool isCyclicDFS( int src , vector<bool> &vis , vector<bool> &recPath , vector<vector<int>>& edges )
    {
        vis[src] = true;
        recPath[src] = true;

        for( int i = 0 ; i < edges.size() ; i++ )
        {
            int v = edges[i][0];
            int u = edges[i][1];

            if( u == src )
            {
                if ( !vis[v] )
                {
                    if ( isCyclicDFS( v , vis , recPath , edges ) )
                    {
                        return true;
                    } 
                }
                else if (recPath[v])
                {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited( numCourses , false );
        vector<bool> recPath( numCourses , false );

        for( int i = 0 ; i < numCourses ; i++ )
        {
            if ( !visited[i] )
            {
                if ( isCyclicDFS( i , visited, recPath , prerequisites) )
                {
                    return false;
                }
            }
        }

        return true;
    }
};
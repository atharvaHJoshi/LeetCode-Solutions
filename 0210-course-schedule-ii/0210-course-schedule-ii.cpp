class Solution {

private:
    bool isCyclicDFS( int src , vector<bool> &visited, vector<bool> &recPath, vector<vector<int>>& edges , stack<int>& st)
    {
        visited[src] = true;
        recPath[src] = true;

        for( int i = 0 ; i < edges.size() ; i++ )
        {
            int v = edges[i][0];
            int u = edges[i][1];

            
            if ( u == src )
            {
                if( !visited[v] )
                {
                    if ( isCyclicDFS( v , visited , recPath , edges , st ) )
                    {
                        return true;
                    }
                }
                else if ( recPath[v] )
                {
                    return true;
                }
            }
        }

        recPath[src] = false;
        st.push( src);

        return false;
    }


public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges)
    {
        vector<bool> visited( numCourses , false );
        vector<bool> recPath( numCourses , false );   

        stack<int> st;

        for( int i = 0 ; i < numCourses ; i++ )
        {
            if ( !visited[i] )
            {
                 if ( isCyclicDFS( i , visited , recPath , edges , st ) )
                 {
                    return {};
                 }
            }
        }


        vector<int> result;
        while( !st.empty() )
        {
            result.push_back( st.top() );
            st.pop();
        }

        return result;
    }
};
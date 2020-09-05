vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    vector<int> visited(V);
    fill(visited.begin(),visited.end(),0);
    g[src][src]=0;
    visited[src]=1;
    int c=V-1;
    while(c!=0)
    {
       int m=INT_MAX;
       int j=0;
       for(int i=0;i<V;i++)
       {     
           if(g[src][i]<m && visited[i]==0)
           {
               m=g[src][i];
               j=i;
           }
       }  
       visited[j]=1;
       for(int i=0;i<V;i++)
       {
           if(g[src][i]>(g[j][i]+m) && g[j][i]!=0)
              g[src][i]=g[j][i]+m;
       }
       c--;
    }
    vector<int> v(V);
    for(int i=0;i<V;i++)
      v[i]=g[src][i];
    return v;  
}

bool isCyclicDirected(int V, vector<vector<int>> adj)
{
    vector<int> visit(V);
    fill(visit.begin(),visit.end(),0);
    stack<int> s;
    int nod=0;
    visit[nod]=2;
    s.push(nod);
    int c=1;
    while(s.empty()==0)
    {
        nod=s.top();
        c=0;
        for(int i=0;i<adj[nod].size();i++)
        {
          if(visit[adj[nod][i]]==0)
          {
              c=1;
              s.push(adj[nod][i]);
              visit[adj[nod][i]]=2;
              break;
          }
          else if(visit[adj[nod][i]]==2)
             return 1;
        }
        if(c==0)
        {
            visit[s.top()]=1;
            s.pop();
        }
        if(s.empty()==1)
        {
        for(int i=0;i<V;i++)
          if(visit[i]==0)
          {
              s.push(i);
              break;
          }        
        
        }
    }
    return 0;
}

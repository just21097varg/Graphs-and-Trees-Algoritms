bool isCyclicUndirected(vector<vector<int>> g, int V)
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
        for(int i=0;i<g[nod].size();i++)
        {
          if(visit[g[nod][i]]==0)
          {
              c=1;
              s.push(g[nod][i]);
              visit[g[nod][i]]=2;
              break;
          }
          else if(visit[g[nod][i]]==2)
          {
             int m=s.top();
             s.pop();
             if(s.top()!=g[nod][i])
               return 1;
             else
               s.push(m);
          }
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

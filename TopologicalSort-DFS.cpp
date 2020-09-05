vector<int> topoSort(int V, vector<vector<int>> adj) 
{
    // Your code here
    vector<int> visit(V);
    fill(visit.begin(),visit.end(),0);
    stack<int> s,st;
    int nod=0;
    visit[nod]++;
    s.push(nod);
    int c=1;
    while(s.empty()==0)
    {
        nod=s.top();
        c=0;
        for(int i=0;i<adj[nod].size();i++)
          if(visit[adj[nod][i]]==0)
          {
              c=1;
              s.push(adj[nod][i]);
              visit[adj[nod][i]]++;
              break;
          }
        if(c==0)
        { 
            st.push(s.top());
            s.pop();
        }
        if(s.empty()==1)
        {
            for(int i=1;i<V;i++)
              if(visit[i]==0)
              {
                  s.push(i);
                  visit[i]++;
                  break;
              }
        }
        
    }
    vector<int> t;
    while(st.empty()==0)
    {
        t.push_back(st.top());
        st.pop();
    }
    
   return t; 
}

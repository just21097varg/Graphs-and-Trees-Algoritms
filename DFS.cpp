vector<int> DFS(vector<vector<int>> v,int nod,int n)
{
    vector<int> visit(n);
    vector<int> s;
    fill(visit.begin(),visit.end(),0);
    stack<int> st;
    visit[nod]++;
    st.push(nod);
    int c=1;
    while(st.empty()==0)
    {
        nod=st.top();
        if(c==1)
        {
        
        s.push_back(st.top());
        }
        c=0;
        for(int i=0;i<v[nod].size();i++)
          if(visit[v[nod][i]]==0)
          {
              c=1;
              st.push(v[nod][i]);
              visit[v[nod][i]]++;
              break;
          }
        if(c==0)
         st.pop();
    }
    
    
   return s; 
}

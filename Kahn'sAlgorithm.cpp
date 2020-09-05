vector<int> kahnAlgo(int V,vector<vector<int>> v)
{
    
    vector<int> visit(V);
    fill(visit.begin(),visit.end(),0);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
            visit[v[i][j]]++;
    }
    queue<int> q;
    vector<int> s;
    for(int i=0;i<V;i++)
      if(visit[i]==0)
        q.push(i);
    int nod,c=0;
    while(q.empty()==0)
    {
        
        nod=q.front();
        for(int i=0;i<v[nod].size();i++)
           if(visit[v[nod][i]]!=0)
            {
                visit[v[nod][i]]--;
                if(visit[v[nod][i]]==0)
                   q.push(v[nod][i]);
            }
        s.push_back(q.front());
        c++;
        q.pop();
    }
    return s;
}

vector<int> BFS(vector<vector<int>> v,int nod,int n)
{
    
    vector<int> visit(n);
    vector<int> s;
    fill(visit.begin(),visit.end(),0);
    queue<int> q;
    visit[nod]++;
    q.push(nod);
    while(q.empty()==0)
    {
        nod=q.front();
        for(int i=0;i<v[nod].size();i++)
          if(visit[v[nod][i]]==0)
          {
              q.push(v[nod][i]);
              visit[v[nod][i]]++;
          }
        s.push_back(q.front());
        q.pop();
    }
    return s;
}

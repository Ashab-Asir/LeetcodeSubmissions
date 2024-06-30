class Solution {
public:
bool static comp(vector<int> &a ,vector<int> &b)//Compare according to type-3
{
    return a[0]>b[0];
}
int findparent(int node,vector<int> &parent)//find parent function (fro disjoint set)
{
    if(node==parent[node])
        return node;
    return parent[node]=findparent(parent[node],parent);
}
bool unionn(int u,int v,vector<int> &parent,vector<int> &rank)//Union function
{
    u=findparent(u,parent);
    v=findparent(v,parent);
    
    if(u!=v)// when u and v are not equal return true else return false
    {
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[u]>rank[v])
            parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
        return true;
    }
    return false;
}
int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
{
    sort(edges.begin(),edges.end(),comp);
    
    vector<int> parent_Alice(n+1);
    vector<int> parent_Bob(n+1);
    vector<int> rank_Alice(n+1);
    vector<int> rank_Bob(n+1);
    
    for(int i=0;i<parent_Alice.size();i++)
    {
        parent_Alice[i]=i;
        parent_Bob[i]=i;
        rank_Alice[i]=1;
        rank_Bob[i]=1;
    }
    int merge_Alice=1;
    int merge_Bob=1;
    
    int remove_edges=0;
    
    for(auto it:edges)
    {
        if(it[0]==3)
        {
            bool temp_Alice=unionn(it[1],it[2],parent_Alice,rank_Alice);
            bool temp_Bob=unionn(it[1],it[2],parent_Bob,rank_Bob);
             if(temp_Alice==true)
                merge_Alice++;
            
            if(temp_Bob==true)
                merge_Bob++;
            
            if(temp_Alice==false && temp_Bob==false)
                remove_edges++;
        }
        else if(it[0]==1)
        {
             bool temp_Alice=unionn(it[1],it[2],parent_Alice,rank_Alice);
            
             if(temp_Alice==true)
                merge_Alice++;
             else
                 remove_edges++;
        }
        else
        {
            bool temp_Bob=unionn(it[1],it[2],parent_Bob,rank_Bob);
             
            if(temp_Bob==true)
                merge_Bob++;
             else
                 remove_edges++;
        }
    }
    if(merge_Alice!=n || merge_Bob!=n)
    {
        return -1;
    }
    return remove_edges;
  }
  };
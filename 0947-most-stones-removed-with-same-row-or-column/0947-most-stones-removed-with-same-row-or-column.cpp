class Solution {
    struct DSU {
        vector<int> par, rank;
        int connectedComp;
        DSU (int n)
        {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
            rank.assign(n, 1);
            connectedComp = n;
        }
        int doFind(int x)
        {
            if (x != par[x])
                par[x] = doFind(par[x]);
            
            return par[x];
        }
        int doUnion(int n1, int n2)
        {
            int p1 = doFind(n1);
            int p2 = doFind(n2);

            if (p1 == p2)
                return false;
            
            if (rank[p1] < rank[p2])
                swap(p1, p2);
            
            rank[p1] += rank[p2];
            par[p2] = p1;
            connectedComp--;
            return true;
        }
        int isSame(int n1, int n2)
        {
            return doFind(n1) == doFind(n2);
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {

        DSU dsu(stones.size());
        
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = i + 1; j < stones.size(); j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    dsu.doUnion(i, j);
                }
            }
        }

        return stones.size() - dsu.connectedComp;
    }
};
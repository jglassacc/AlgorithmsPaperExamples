#include <iostream>
#include <vector>

class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

int main()
{
    int n = 10;
    UnionFind uf(n);

    // Union operations
    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.unite(4, 5);
    uf.unite(6, 7);
    uf.unite(7, 8);
    uf.unite(8, 9);

    // Find operations
    std::cout << "Find(0): " << uf.find(0) << std::endl;
    std::cout << "Find(3): " << uf.find(3) << std::endl;
    std::cout << "Find(6): " << uf.find(6) << std::endl;

    return 0;
}
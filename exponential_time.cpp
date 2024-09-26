#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

int calculateCost(const std::vector<std::vector<int>> &graph, const std::vector<int> &path)
{
    int cost = 0;
    int n = path.size();

    for (int i = 0; i < n - 1; ++i)
    {
        cost += graph[path[i]][path[i + 1]];
    }

    cost += graph[path[n - 1]][path[0]]; // Return to the starting point

    return cost;
}

int travelingSalesman(const std::vector<std::vector<int>> &graph, int n)
{
    std::vector<int> vertices;

    for (int i = 1; i < n; ++i)
    {
        vertices.push_back(i);
    }

    int minCost = INT_MAX;

    do
    {
        int currentCost = calculateCost(graph, vertices);
        minCost = std::min(minCost, currentCost);
    } while (std::next_permutation(vertices.begin(), vertices.end()));

    return minCost;
}

int main()
{
    std::vector<std::vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int n = graph.size();

    int result = travelingSalesman(graph, n);

    std::cout << "Minimum traveling cost: " << result << std::endl;

    return 0;
}
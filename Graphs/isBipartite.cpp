#include <vector>
#include <functional>

bool isBipartite(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> colors(n, 0);
    
    std::function<bool(int,int)> dfs = [&](int node, int c) {
        colors[node] = c;
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == 0) {
                if (!dfs(neighbor, -c)) {
                    return false;
                }
            } else if (colors[neighbor] == colors[node]) {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            if (!dfs(i, 1)) {
                return false;
            }
        }
    }
    return true;
}

#include <gtest/gtest.h>

TEST(IsBipartiteTest, EmptyGraph) {
    std::vector<std::vector<int>> graph;
    EXPECT_TRUE(isBipartite(graph));
}

TEST(IsBipartiteTest, SingleNode) {
    std::vector<std::vector<int>> graph = {{}};
    EXPECT_TRUE(isBipartite(graph));
}

TEST(IsBipartiteTest, TwoNodesOneEdge) {
    std::vector<std::vector<int>> graph = {{1}, {0}};
    EXPECT_TRUE(isBipartite(graph));
}

TEST(IsBipartiteTest, SimpleBipartite) {
    std::vector<std::vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    EXPECT_TRUE(isBipartite(graph));
}

TEST(IsBipartiteTest, TriangleGraph) {
    std::vector<std::vector<int>> graph = {
        {1, 2},
        {0, 2},
        {0, 1}
    };
    EXPECT_FALSE(isBipartite(graph));
}

TEST(IsBipartiteTest, DisconnectedGraph) {
    std::vector<std::vector<int>> graph = {
        {1},
        {0},
        {3, 4}, 
        {2, 4},
        {2, 3},
        {6, 7},
        {5, 7},
        {5, 6}
    };
    EXPECT_FALSE(isBipartite(graph));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

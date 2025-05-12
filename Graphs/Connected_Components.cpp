#include <vector>
#include <map>

void dfs(const std::map<int, std::vector<int>>& graph, int v, std::map<int, int>& visited, int color) {
    visited[v] = color;

    auto it = graph.find(v);
    if (it != graph.end()) {
        const std::vector<int>& neighbors = it->second;
        for (int i : neighbors) {
            if (visited[i] == 0) {
                dfs(graph, i, visited, color);
            }
        }
    }
}

std::map<int, int> find_connected_components(const std::map<int, std::vector<int>>& graph) {
    std::map<int, int> visited;

    if (graph.empty()) {
        return visited;
    }

    int color = 0;
    for (const auto& pair : graph) {
        int node = pair.first;
        if (visited[node] == 0) {
            color++;
            dfs(graph, node, visited, color);
        }
    }
    return visited;
}

#include "gtest/gtest.h"

TEST(ConnectedComponentsTest, ExampleGraph) {
    std::map<int, std::vector<int>> graph = {
        {1, {2, 3}},
        {2, {1, 3}},
        {3, {1, 2}},
        {4, {6, 7}},
        {5, {6, 7}},
        {6, {4, 5, 7}},
        {7, {4, 5, 6}},
        {8, {11}},
        {9, {10, 11}},
        {10, {9}},
        {11, {8, 9}}
    };
    std::map<int, int> expected = {
        {1, 1}, {2, 1}, {3, 1},
        {4, 2}, {5, 2}, {6, 2}, {7, 2},
        {8, 3}, {9, 3}, {10, 3}, {11, 3}
    };
    EXPECT_EQ(find_connected_components(graph), expected);
}

TEST(ConnectedComponentsTest, EmptyGraph) {
    std::map<int, std::vector<int>> graph = {};
    std::map<int, int> expected = {};
    EXPECT_EQ(find_connected_components(graph), expected);
}

TEST(ConnectedComponentsTest, SingleNodeNoEdges) {
    std::map<int, std::vector<int>> graph = {
        {1, {}}
    };
    std::map<int, int> expected = {
        {1, 1}
    };
    EXPECT_EQ(find_connected_components(graph), expected);
}

TEST(ConnectedComponentsTest, TwoDisconnectedNodes) {
    std::map<int, std::vector<int>> graph = {
        {1, {}},
        {2, {}}
    };
    std::map<int, int> expected = {
        {1, 1}, {2, 2}
    };
    EXPECT_EQ(find_connected_components(graph), expected);
}

TEST(ConnectedComponentsTest, SingleComponent) {
     std::map<int, std::vector<int>> graph = {
        {1, {2}},
        {2, {1, 3}},
        {3, {2, 4}},
        {4, {3}}
    };
    std::map<int, int> expected = {
        {1, 1}, {2, 1}, {3, 1}, {4, 1}
    };
    EXPECT_EQ(find_connected_components(graph), expected);
}

TEST(ConnectedComponentsTest, NodesOnly) {
    std::map<int, std::vector<int>> graph = {
        {1, {2}}, 
        {3, {4}}  
    };
    std::map<int, int> expected = {
        {1, 1}, {2, 1}, {3, 2}, {4, 2}
    };
    EXPECT_EQ(find_connected_components(graph), expected);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <vector>
#include <map>
#include <set>

bool dfs(const std::map<int, std::vector<int>>& graph,int vertex, int parent, std::set<int>& visited) {
    visited.insert(vertex);

    auto it = graph.find(vertex);
    if (it != graph.end()) {
        const std::vector<int>& neighbors = it->second;
        for (int neighbor : neighbors) {
            if (neighbor != parent) {
                if (visited.count(neighbor) || dfs(graph, neighbor, vertex, visited)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool has_cycle(const std::map<int, std::vector<int>>& graph) {
    std::set<int> visited;

    for (const auto& pair : graph) {
        int vertex = pair.first;
        if (!visited.count(vertex)) {
            if (dfs(graph, vertex, -1, visited)) {
                return true;
            }
        }
    }
    return false;
}

#include "gtest/gtest.h"

TEST(CycleTest, Empty) {
    std::map<int, std::vector<int>> graph = {};
    EXPECT_FALSE(has_cycle(graph));
}

TEST(CycleTest, SingleNode) {
    std::map<int, std::vector<int>> graph = {{1, {}}};
    EXPECT_FALSE(has_cycle(graph));
}

TEST(CycleTest, PairNoCycle) {
    std::map<int, std::vector<int>> graph = {{1, {2}}, {2, {1}}};
    EXPECT_FALSE(has_cycle(graph));
}

TEST(CycleTest, TriangleCycle) {
    std::map<int, std::vector<int>> graph = {{1, {2}}, {2, {3}}, {3, {1}}};
    EXPECT_TRUE(has_cycle(graph));
}

TEST(CycleTest, LineNoCycle) {
    std::map<int, std::vector<int>> graph = {{1, {2}}, {2, {1, 3}}, {3, {2}}};
    EXPECT_FALSE(has_cycle(graph));
}

TEST(CycleTest, DisconnectedWithCycle) {
    std::map<int, std::vector<int>> graph = {
        {1, {2}}, {2, {1}},
        {3, {4}}, {4, {5}}, {5, {3}}
    };
    EXPECT_TRUE(has_cycle(graph));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
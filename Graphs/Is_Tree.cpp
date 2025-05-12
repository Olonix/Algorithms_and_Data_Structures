#include <vector>
#include <map>
#include <set>
#include <queue>

bool isTree(const std::map<int, std::vector<int>>& graph, int start) {
    std::set<int> visited;
    std::queue<int> queue;
    std::map<int, int> parent;

    queue.push(start);
    visited.insert(start);
    parent[start] = -1;

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();

        auto it = graph.find(vertex);
        if (it != graph.end()) {
            const std::vector<int>& neighbors = it->second;
            for (int neighbor : neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    queue.push(neighbor);
                    parent[neighbor] = vertex;
                } else {
                    if (parent.count(vertex) && parent[vertex] != neighbor) {
                         return false;
                    }
                }
            }
        }
    }

    return visited.size() == graph.size();
}

#include "gtest/gtest.h"

TEST(TreeTest, Test1) {
    std::map<int, std::vector<int>> graph = {};
    EXPECT_FALSE(isTree(graph, 1));
}

TEST(TreeTest, Test2) {
    std::map<int, std::vector<int>> graph = {{1, {}}};
    EXPECT_TRUE(isTree(graph, 1));
}

TEST(TreeTest, Test3) {
    std::map<int, std::vector<int>> graph = {{1, {2}}, {2, {1}}};
    EXPECT_TRUE(isTree(graph, 1));
}

TEST(TreeTest, Test4) {
    std::map<int, std::vector<int>> graph = {{1, {2}}, {2, {1, 3}}, {3, {2}}};
    EXPECT_TRUE(isTree(graph, 1));
}

TEST(TreeTest, Test5) {
    std::map<int, std::vector<int>> graph = {{1, {2, 3}}, {2, {1, 3}}, {3, {1, 2}}};
    EXPECT_FALSE(isTree(graph, 1));
}

TEST(TreeTest, Test6) {
    std::map<int, std::vector<int>> graph = {{1, {2}}, {2, {1}}, {3, {4}}, {4, {3}}};
    EXPECT_FALSE(isTree(graph, 1));
}

TEST(TreeTest, Test7) {
     std::map<int, std::vector<int>> graph = {{1, {2}}, {2, {1}}};
     EXPECT_FALSE(isTree(graph, 3));
}

TEST(TreeTest, Test8) {
     std::map<int, std::vector<int>> graph = {{1, {2}}, {2, {1, 3}}};
     EXPECT_FALSE(isTree(graph, 1));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
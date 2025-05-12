#include <unordered_map>
#include <queue>
#include <limits>
#include <vector>
#include <functional>

std::unordered_map<int,double> dijkstra(const std::unordered_map<int,std::unordered_map<int,double>>& graph, int start) {
    std::unordered_map<int,double> distances;
    for (const auto& vertex : graph) {
        distances[vertex.first] = std::numeric_limits<double>::infinity();
    }

    if (distances.find(start) == distances.end()) {
        return distances;
    }

    distances[start] = 0.0;

    using Pair = std::pair<double,int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> priority_queue;
    // priority_queue.push(std::make_pair(0.0, start));
    priority_queue.emplace(0.0, start);

    while (!priority_queue.empty()) {
        auto [current_distance, current_vertex] = priority_queue.top();
        priority_queue.pop();

        if (current_distance > distances[current_vertex]) {
            continue;
        }

        for (const auto& [neighbor, weight] : graph.at(current_vertex)) {
            double distance = current_distance + weight;

            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                priority_queue.emplace(distance, neighbor);
            }
        }
    }
    return distances;
}

#include <gtest/gtest.h>

TEST(DijkstraTest, EmptyGraph) {
    std::unordered_map<int,std::unordered_map<int,double>> graph;
    auto d = dijkstra(graph, 0);
    EXPECT_TRUE(d.empty());
}

TEST(DijkstraTest, SingleNode) {
    std::unordered_map<int,std::unordered_map<int,double>> graph = {{0, {}}};
    auto d = dijkstra(graph, 0);
    EXPECT_EQ(d.size(), 1);
    EXPECT_DOUBLE_EQ(d[0], 0.0);
}

TEST(DijkstraTest, TwoNodesOneEdge) {
    std::unordered_map<int,std::unordered_map<int,double>> graph = {
        {0, {{1, 2.5}}},
        {1, {}}
    };
    auto d = dijkstra(graph, 0);
    EXPECT_DOUBLE_EQ(d[0], 0.0);
    EXPECT_DOUBLE_EQ(d[1], 2.5);
}

TEST(DijkstraTest, SimpleGraph) {
    std::unordered_map<int,std::unordered_map<int,double>> graph = {
        {0, {{1, 1.0}, {2, 4.0}}},
        {1, {{2, 2.0}, {3, 5.0}}},
        {2, {{3, 1.0}}},
        {3, {}}
    };
    auto d = dijkstra(graph, 0);
    EXPECT_DOUBLE_EQ(d[0], 0.0);
    EXPECT_DOUBLE_EQ(d[1], 1.0);
    EXPECT_DOUBLE_EQ(d[2], 3.0);
    EXPECT_DOUBLE_EQ(d[3], 4.0);
}

TEST(DijkstraTest, DisconnectedGraph) {
    std::unordered_map<int,std::unordered_map<int,double>> graph = {
        {0, {{1, 1.0}}},
        {1, {}},
        {2, {{3, 2.0}}},
        {3, {}}
    };
    auto d = dijkstra(graph, 0);
    EXPECT_DOUBLE_EQ(d[0], 0.0);
    EXPECT_DOUBLE_EQ(d[1], 1.0);
    EXPECT_EQ(d[2], std::numeric_limits<double>::infinity());
    EXPECT_EQ(d[3], std::numeric_limits<double>::infinity());
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
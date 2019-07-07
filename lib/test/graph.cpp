#include "../src/graph.hpp"
#include "iostream"
/**
 * 0->1->2,
 *    |
 *    v
 * 3->4,
 * weight: all 1
 */
graph sample_graph_1(){
    graph g(5);
    g[0].push_back({1,1});
    g[1].push_back({2,1});
    g[1].push_back({4,1});
    g[3].push_back({4,1});
    return g;
}
std::vector<std::vector<weight_t>> sample_graph_1_dijkstra_answer({
    {0,1,2,weight_infty,2},
    {weight_infty,0,1,weight_infty,1},
    {weight_infty,weight_infty,0,weight_infty,weight_infty},
    {weight_infty,weight_infty,weight_infty,0,1},
    {weight_infty,weight_infty,weight_infty,weight_infty,0}
});
std::vector<std::vector<std::vector<to_t>>> sample_graph_1_shortest_path_answer({
    {{0},{0,1},{0,1,2},{},{0,1,4}},
    {{},{1},{1,2},{},{1,4}},
    {{},{},{2},{},{}},
    {{},{},{},{3},{3,4}},
    {{},{},{},{},{4}}
});

/**
 * 0->1->2->...->(n-1)->0 (cyclic)
 * weight: all 1
 */
graph cyclic_graph(std::size_t n){
    graph g(n);
    for(std::size_t i=0;i<n-1;i++)g[i].push_back({i+1,1});
    g[n-1].push_back({0,1});
    return g;
}

// TEST(dijkstra,cyclic){
//     std::size_t test_size=50;
//     auto g=cyclic_graph(test_size);
//     auto w=dijkstra(g,0);
//     for(std::size_t i=0;i<test_size;i++){
//         ASSERT_EQ(i,w[i]);
//     }
// }

int main(){
    std::size_t correct=0,wrong=0;
    auto g=sample_graph_1();
    for(to_t i=0;i<5;i++){
        auto w=dijkstra(g,i);
        if(w==sample_graph_1_dijkstra_answer[i])correct++;
        else wrong++;
    }
    for(to_t i=0;i<5;i++){
        for(to_t j=0;j<5;j++){
            if(shortest_path(g,i,j)==sample_graph_1_shortest_path_answer[i][j])correct++;
            else wrong++;
        }
    }
    std::cout << correct << "," << wrong << std::endl;
    return 0;
}
#include "algorithm_common.hpp"

//////////////////////////// TASK 3 ////////////////////////////

int naive_bankruped(std::vector<int>& d) {
    std::stable_sort(d.begin(), d.end());
    return std::find_if(d.begin(), d.end(), [](int val) { return val < 0; }) - d.begin();
}

int optimized_bankruped(std::vector<int>& d) {
    // TASK: Improve
    std::stable_sort(d.begin(), d.end());
    return std::find_if(d.begin(), d.end(), [](int val) { return val < 0; }) - d.begin();
}


//////////////////////////// DETAIL ////////////////////////////
BENCHMARK_CAPTURE(algorithms, naive_bankruped, naive_bankruped, naive_bankruped)->Range(8, 8<<10)->Complexity();
BENCHMARK_CAPTURE(algorithms, optim_bankruped, optimized_bankruped, naive_bankruped)->Range(8, 8<<10)->Complexity();


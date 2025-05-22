#include <iostream>
#include "largest_divisible_subset.h"

int main() {
    std::vector<int> nums = { 1, 2, 3 };
    auto result = largestDivisibleSubset(nums);

    std::cout << "Largest divisible subset: [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
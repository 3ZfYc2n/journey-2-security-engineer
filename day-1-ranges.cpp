#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ranges>

int main() {
    std::vector<int> vec = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    std::ranges::sort(vec);

    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}

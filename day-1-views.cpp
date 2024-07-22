#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ranges>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto even = [](int i) { return i % 2 == 0; };
    auto square = [](int i) { return i * i; };

    for (int i : vec | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << " ";
    }

    return 0;
}

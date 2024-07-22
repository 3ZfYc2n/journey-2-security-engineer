#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm> // for std::ranges::sort, std::ranges::find, std::ranges::for_each

int main() {

    std::vector<int> vec = { 10, 3, 6, 1, 7, 4, 9, 2, 8, 5 };

    std::ranges::sort(vec);

    auto it = std::ranges::find(vec, 7);
    if (it != vec.end()) {
        std::cout << "Found 7 at position: " << std::distance(vec.begin(), it) << "\n";
    }
    else {
        std::cout << "7 not found in the vector.\n";
    }

    std::ranges::for_each(vec, [](int i) {
        std::cout << i * i << " ";
        });

    return 0;
}

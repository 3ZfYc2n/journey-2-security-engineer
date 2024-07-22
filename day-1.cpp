#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ranges>

std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
    size_t n = names.size();
    std::vector<size_t> indices(n);
    for (size_t i = 0; i < n; ++i) {
        indices[i] = i;
    }

    std::ranges::sort(indices, [&heights](size_t a, size_t b) {
        return heights[a] > heights[b];
        });

    std::vector<std::string> sorted_names;
    sorted_names.reserve(n); // Reserve space to avoid reallocations
    for (size_t i : indices) {
        sorted_names.push_back(names[i]);
    }

    return sorted_names;
}

int main() {
    std::vector<std::string> names = { "Mary", "John", "Emma" };
    std::vector<int> heights = { 180, 165, 170 };

    std::vector<std::string> result = sortPeople(names, heights);
    for (const auto& name : result) {
        std::cout << name << " ";
    }

    return 0;
}

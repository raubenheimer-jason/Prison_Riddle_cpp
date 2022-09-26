#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric> // iota

const size_t num_prisoners{10};
const size_t num_boxes{num_prisoners};

void display_boxes(const std::vector<size_t> &vec);

int main()
{
    // vector of size_t, num_boxes in size, all initialised to 0
    std::vector<size_t> boxes(num_boxes, 0);

    // set each value of the vector, starting at 0, and incrementing by 1
    std::iota(boxes.begin(), boxes.end(), 0);

    display_boxes(boxes);

    // shufle box numbers in boxes vector
    auto rng = std::default_random_engine{};
    std::shuffle(boxes.begin(), boxes.end(), rng);

    // display shuffled boxes
    display_boxes(boxes);

    return 0;
}

void display_boxes(const std::vector<size_t> &vec)
{
    size_t i{};
    std::cout << "\n";
    for (auto box : vec)
        std::cout << "Box " << i++ << ":\t" << box << std::endl;
}

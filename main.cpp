#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric> // iota

#include "Prisoner.h"

const bool random_search{false}; // set to true to search boxes randomly

const size_t num_prisoners{100};
const size_t num_boxes{num_prisoners};
const size_t max_search_boxes{num_boxes / 2};

void initialise_boxes(std::vector<size_t> &vec);
void initialise_prisoners(std::vector<Prisoner> &vec);
void display_boxes(const std::vector<size_t> &vec);
void display_prisoners(const std::vector<Prisoner> &vec);
void search_boxes(const std::vector<size_t> &boxes, Prisoner &prisoner);

int main()
{
    // vector of size_t, num_boxes in size, all initialised to 0
    std::vector<size_t> boxes(num_boxes, 0);
    initialise_boxes(boxes);
    // display shuffled boxes
    display_boxes(boxes);

    // vector of prisoners
    std::vector<Prisoner> prisoners;
    initialise_prisoners(prisoners);
    // display initialised prisoners
    display_prisoners(prisoners);

    if (random_search)
    {
        // search randomly
    }
    else
    {
        // search using proposed technique
        // loop over each prisoner and search for their number
        for (auto p : prisoners)
        {
            search_boxes(boxes, p);
        }
    }

    // display prisoners
    display_prisoners(prisoners);

    return 0;
}

void initialise_boxes(std::vector<size_t> &vec)
{
    // set each value of the vector, starting at 0, and incrementing by 1
    std::iota(vec.begin(), vec.end(), 0);
    // shufle box numbers in boxes vector
    auto rng = std::default_random_engine{};
    std::shuffle(vec.begin(), vec.end(), rng);
}

void initialise_prisoners(std::vector<Prisoner> &vec)
{
    for (size_t i{}; i < num_prisoners; ++i)
        vec.push_back(Prisoner{i, num_prisoners, max_search_boxes});
}

void display_boxes(const std::vector<size_t> &vec)
{
    size_t i{};
    std::cout << "\n=== Boxes ===" << std::endl;
    for (auto box : vec)
        std::cout << "Box " << i++ << ":\t" << box << std::endl;
}

void display_prisoners(const std::vector<Prisoner> &vec)
{
    std::cout << "\n=== Prisoners ===" << std::endl;
    std::cout << std::boolalpha;
    for (auto prisoner : vec)
        prisoner.display();
}

void search_boxes(const std::vector<size_t> &boxes, Prisoner &prisoner)
{
    bool found{false};
    while (!found && prisoner.still_boxes_left())
    {
        std::cout << "prisoner num: " << prisoner.get_number() << ", boxes searched: " << prisoner.get_boxes_searched() << ", searching box " << prisoner.get_box_to_search();
        size_t num_in_box = boxes.at(prisoner.get_box_to_search());
        std::cout << ", num in box: " << num_in_box;
        found = prisoner.search_box(num_in_box);

        std::cout << ", found: " << found << std::endl;
    }

    std::cout << std::endl;

    // select box at current prisoners number

    // see if the number in that box == prisoners number

    // next box
}
#include "Prisoner.h"
#include <iostream>

// Constructor
Prisoner::Prisoner(const size_t number, const size_t num_prisoners)
    : number{number}, num_prisoners{num_prisoners}, found_number{false}, boxes_searched{}
{
}

void Prisoner::search_box(const size_t num_in_box)
{
    boxes_searched++;
}

// method that checks if the number in the box is the prisoners number
bool Prisoner::is_number_found(const size_t num_in_box)
{
    if (num_in_box == number)
        found_number = true;

    return found_number;
}

bool Prisoner::num_boxes_left()
{
    return num_prisoners - boxes_searched;
}

void Prisoner::display() const
{
    std::cout << "Prisoner " << number << ":\t" << found_number << std::endl;
}

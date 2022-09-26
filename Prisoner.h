#ifndef _PRISONER_H_
#define _PRISONER_H_

// #include <cstddef>
#include <cstdint> // size_t

class Prisoner
{
private:
    size_t number;
    size_t num_prisoners;
    size_t boxes_searched;
    bool found_number;

public:
    // Prisoner();
    Prisoner(const size_t number, const size_t num_prisoners);
    void search_box(const size_t num_in_box);
    bool is_number_found(const size_t num_in_box);
    bool num_boxes_left();
    void display() const;
    // size_t next_box(const size_t num_in_box);
};

#endif // _PRISONER_H_
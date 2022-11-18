#ifndef ROW_HPP
#define ROW_HPP

/*

Rob Deans
row.hpp
OS
Fall 2022

*/

#include <vector>
#include <iostream>
#include <cassert>
class row{

private:

    std::vector<int> values;

public:

    // Default Ctor handled by stl
    row();
    // Ctor (from vec)
    row(const std::vector<int>&);
    // Cpy ctor
    row(const row&);
    // Dtor, handled by stl
    ~row();

    unsigned size();

    bool operator<(const row&) const;
    bool operator>(const row&) const;
    bool operator==(const row&) const;
    bool operator!=(const row&) const;
    bool operator<=(const row& rhs) const;
    bool operator>=(const row& rhs) const;

    row operator-(const row&);
    row operator+(const row&);
    row& operator+=(const row& rhs);
    row& operator-=(const row& rhs);

    unsigned get_size() const noexcept;

    // Access
    int operator[](int index) const;
    int& operator[](int);
    bool empty() const;

    // adding on
    void push_back(int element){values.push_back(element);}

    // printing
    void printRow();
};
#endif
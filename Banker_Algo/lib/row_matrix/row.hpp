#ifndef ROW_HPP
#define ROW_HPP

#include <vector>
#include <iostream>

class row{

private:

std::vector<int> values;

public:

// Default Ctor handled by stl
row(){}
// Ctor (from vec)
row(const std::vector<unsigned>&);
// Cpy ctor
row(const row&);
// Dtor, handled by stl
~row(){}

// prints current row, matrix will use std::endl to clear buffer.
void print(){for(unsigned i = 0; i < values.size(); i++) std::cout << values[i]; std::cout << "\n";}

bool operator<(const row&);
bool operator>(const row&);
bool operator==(const row&);
bool operator<=(const row& rhs){return *this < rhs && *this == rhs;}
bool operator>=(const row& rhs){return *this > rhs && *this == rhs;}

row operator-(const row&);
row operator+(const row&);
row& operator+=(const row& rhs){*this = *this + rhs; return *this;}
row& operator-=(const row& rhs){*this = *this - rhs; return *this;}
};

#endif
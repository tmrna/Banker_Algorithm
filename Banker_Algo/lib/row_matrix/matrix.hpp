#ifndef MATRIX_HPP
#define MATRIX_HPP

/*

Rob Deans
Matrix.hpp
OS
Fall 2022

*/
#include "row.hpp"

#include <vector>
#include <cassert>

class matrix{

private:

std::vector<row> rows;

public:

// default ctor
matrix();

// ctor for row
matrix(const row&);

// cpy ctor
matrix(const matrix&);

// dtor
~matrix();

// checks if all rows have the same length, if not throws an error.
void checkDim();

// gets dimensions of matrix
std::pair<unsigned, unsigned> size() const;

// determines if 2 matricies have the same dimensions
bool sameDim();

// adds on row to the bottom of matrix
void append(const row&);
void append(const std::vector<int>&);

// swaps two rows
void swapRows(int, int);

//////////  Comparison

bool operator<(const matrix&);

bool operator>(const matrix&);

bool operator==(const matrix&);

bool operator!=(const matrix&);

bool operator>=(const matrix&);

bool operator<=(const matrix&);

//////////   Addition / subtraction

matrix operator+(const matrix&);
matrix operator-(const matrix&);

matrix& operator+=(const matrix&);
matrix& operator-=(const matrix&);

// Access
// subscript operator (value)
row operator[](int) const;
// subscript operator (ref)
row& operator[](int);
};

#endif
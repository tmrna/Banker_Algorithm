#include "matrix.hpp"


// default ctor
matrix::matrix(){/*handled by stl*/}

// ctor for row
matrix::matrix(const row& toSet){
    rows.push_back(toSet);
}

// cpy ctor
matrix::matrix(const matrix& rhs){
    rows = rhs.rows;
}

// dtor
matrix::~matrix(){/*handled by stl*/}

// checks if all rows have the same length, if not throws an error.
void matrix::checkDim(){
    if(!rows.empty()){
   
        unsigned sz = rows[0].size();
        for(unsigned i = 0; i < rows.size(); i++){
            // make sure that we do not have mismatched rows
            assert(rows[i].size() == sz);
        }
    }
}

std::pair<unsigned, unsigned> matrix::size() const{

    std::pair<int, int> res = {0,0};

    res.first = rows.size();
    if(!rows.empty()){
        res.second = rows[0].size();
    }

    return res;
}
// adds on row to the bottom of matrix
void matrix::append(const row& toAppend){

    if(!rows.empty()){
        // matrix size will be set by then, previous rows will all be same size
        assert(rows[0].size() == toAppend.size());
    }
    rows.push_back(toAppend);
}

void matrix::append(const std::vector<int>& toAppend){
    row tacky(toAppend);
    append(tacky);
}

// swaps two rows
void matrix::swapRows(int a, int b){
    // make sure we are not out of scope
    assert(a < rows.size() && b < rows.size());

    // const time swap
    row tmp = rows[a];
    rows[a] = rows[b];
    rows[b] = tmp;
}

//////////  Comparison

bool matrix::operator<(const matrix& rhs){
    // will be used to determine safe state
    for(int i = 0; i < rows.size(); i++){
        for(int j = 0; j < rhs.rows.size(); j++){
            if(rows[i] >= rows[j]) return false;
        }
    }
    return true;
}

bool matrix::operator>(const matrix& rhs){
        // will be used to determine safe state
    for(int i = 0; i < rows.size(); i++){
        for(int j = 0; j < rhs.rows.size(); j++){
            if(rows[i] <= rows[j]) return false;
        }
    }
    return true;
}

bool matrix::operator==(const matrix& rhs){
    assert(rows.size() == rhs.rows.size());
    return rows == rhs.rows;
}

bool matrix::operator!=(const matrix& rhs){
    return rows != rhs.rows;
}

bool matrix::operator>=(const matrix& rhs){
    return *this > rhs && *this == rhs;
}

bool matrix::operator<=(const matrix& rhs){
    return *this < rhs && *this == rhs;
}

//////////   Addition / subtraction

matrix matrix::operator+(const matrix& rhs){
    assert(size() == rhs.size());
    matrix res(*this);
    for(unsigned i = 0; i < rows.size(); i++){
        res[i] += rhs[i];
    }
    return res;
}

matrix matrix::operator-(const matrix& rhs){
    assert(size() == rhs.size());
        matrix res(*this);
    for(unsigned i = 0; i < rows.size(); i++){
        res[i] -= rhs[i];
    }
    return res;
}

matrix& matrix::operator+=(const matrix& rhs){
    assert(size() == rhs.size());

    for(unsigned i = 0; i < rows.size(); i++){
        rows[i] += rhs[i];
    }

    return *this;
}

matrix& matrix::operator-=(const matrix& rhs){
    assert(size() == rhs.size());

    for(unsigned i = 0; i < rows.size(); i++){
        rows[i] -= rhs[i];
    }

    return *this;
}

// access

row matrix::operator[](int index) const{
    return rows[index];
}

row& matrix::operator[](int index){
    return rows[index];
}

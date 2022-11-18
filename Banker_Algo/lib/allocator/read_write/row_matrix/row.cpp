#include "row.hpp"

/*

Rob Deans
row.cpp
OS
Fall 2022

*/

//###########################################      Ctor + Dtor  #######################################################################

row::row(){/*handled by stl*/}

row::~row(){/*handled by stl*/}

row::row(const std::vector<int>& toSet){
    values = toSet;
}

row::row(const row& toCpy){
    values = toCpy.values;
}

//#######################################   Comparison  ################################################################################

bool row::operator<(const row& rhs) const{
    assert(rhs.values.size() == values.size());
    for(int i = 0; i < values.size(); i++){
        if(values[i] > rhs.values[i]) return false;
    }
    return rhs.values != values;
}

bool row::operator>(const row& rhs) const{
    assert(rhs.values.size() == values.size());
    for(int i = 0; i < values.size(); i++){
        if(values[i] < rhs.values[i]) return false;
    }
    return rhs.values != values;
}

bool row::operator<=(const row& rhs) const{
    return *this < rhs && *this == rhs;
}

bool row::operator>=(const row& rhs) const{
    return *this > rhs && *this == rhs;
}

bool row::operator!=(const row& rhs) const{
    return !(*this == rhs);
}

bool row::operator==(const row& rhs) const{
    return values == rhs.values;
}

//###############################################    Addition / Subtraction  ######################################################

row row::operator+(const row& rhs){
    row res(*this);
    for(int i=0; i < values.size(); i++){
        res.values[i]+=rhs.values[i];
    }
    return res;
}

row row::operator-(const row& rhs){
    row res(*this);
    for(int i=0; i < values.size(); i++){
        res.values[i]-=rhs.values[i];
    }
    return res;
}

row& row::operator+=(const row& rhs){
    for(int i = 0; i < values.size(); i++){
        values[i] += rhs.values[i];
    }
    return *this;
}

row& row::operator-=(const row& rhs){
    for(int i = 0; i < values.size(); i++){
        values[i] -= rhs.values[i];
    }
    return *this;
}

//#################################################  Other  #################################################################


unsigned row::get_size() const noexcept{
    unsigned res = values.size();
    return res;
}


//#################################################    Access    #########################################################

int row::operator[](int loc) const{
    return values[loc];
}

int& row::operator[](int loc){
    return values[loc];
}

bool row::empty() const{
    return values.empty();
}


//################################################  Printing ##########################################################

void row::printRow(){
    for(unsigned i = 0; i < values.size(); i++){
        std::cout << values[i];
        if(i < values.size() -1) std::cout << ", ";
    }
}
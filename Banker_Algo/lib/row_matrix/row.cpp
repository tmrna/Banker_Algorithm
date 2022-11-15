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

bool row::operator<(const row& rhs){
    for(int i = 0; i < values.size(); i++){
        if(values[i] > rhs.values[i]) return false;
    }
    return true;
}

bool row::operator>(const row& rhs){
    for(int i = 0; i < values.size(); i++){
        if(values[i] > rhs.values[i]) return false;
    }
    return true;
}

bool row::operator<=(const row& rhs){
    return *this < rhs && *this == rhs;
}

bool row::operator>=(const row& rhs){
    return *this > rhs && *this == rhs;
}

bool row::operator!=(const row& rhs){
    return !(*this == rhs);
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


//####################################################    Getter   ########################################################

std::vector<int> row::getVal(){
    return values;
}
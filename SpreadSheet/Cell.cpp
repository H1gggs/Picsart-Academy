#include <iostream>
#include "Cell.h"
#include <string>
#include <sstream>
Cell::Cell() {}
Cell::Cell(const std::string& str,const color& col):m_value(str),m_color(col) {}
Cell::~Cell() { /*std::cout << "Cell Dtor"; */ }
void Cell::SetValue(std::string& str){
	m_value = str;
}
std::string Cell::GetValue() { 
	return m_value; 
}
int Cell::ToInt() {  
    try
    {
        //std::cout << "std::stoi('" <<m_value << "'): ";
        const int i =  std::stoi(m_value,nullptr ,10);
        //std::cout << i << "; pos: " << m_value << '\n';
        return i;
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
    }
    
}
double Cell::ToDouble() {
    try
    {
        //std::cout << "std::stoi('" << m_value << "'): ";
        const double i = std::stod(m_value, nullptr);
        //std::cout << i << "; pos: " << m_value << '\n';
        return i;
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
    }
}
Date Cell::ToDate() {
    try
    {
        int arr[3];
        std::stringstream ss(m_value);
        std::string token;
        int index = 0;
        while (std::getline(ss, token, ',')) {
            arr[index] = std::stoi(token, nullptr, 10);
            index++;
        }//std::cout << "std::stoi('" << m_value << "'): ";

        //const int i = std::stoi(m_value, nullptr, 10);
        Date DMY(arr[0],arr[1],arr[2]);
        //std::cout << i << "; pos: " << m_value << '\n';
        return DMY;
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
    }
};
void Cell::Reset() { 
    m_value.clear();
    m_color = color::no_color;
}
bool Cell::operator== (Cell& other) { 
    if ((this->m_color == other.m_color) && (this->m_value == other.m_value)) {
        return true;
    }
    else {
        return false;
    }
}
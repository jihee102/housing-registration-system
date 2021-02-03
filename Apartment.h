//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_APARTMENT_H
#define TOETS_APARTMENT_H
#include <iostream>

class Apartment {
private:
    std::string suffix;
    std::string family;
    int number_of_residents;

public:
    Apartment(const std::string & suffix, const std::string &family, int number_of_residents);

    virtual ~Apartment();

    const std::string &get_family() const;

    int get_number_of_residents() const;

    const std::string &get_suffix() const;

    void print_apartment(std::ostream & out, const std::string &indentation ="") const;

};


#endif //TOETS_APARTMENT_H

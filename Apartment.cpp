//
// Created by jihee on 1/27/2021.
//

#include "Apartment.h"

Apartment::Apartment(const std::string & suffix,const std::string &family, int number_of_residents) : suffix(suffix),family(family),
                                                                         number_of_residents(number_of_residents) {}

Apartment::~Apartment() {

}


const std::string &Apartment::get_suffix() const {
    return suffix;
}


const std::string &Apartment::get_family() const {
    return family;
}

int Apartment::get_number_of_residents() const {
    return number_of_residents;
}

void Apartment::print_apartment(std::ostream &out, const std::string &indentation) const {
    out << indentation << suffix << ") is where " <<family <<" lives with "<< number_of_residents << " persons" << std::endl;
}

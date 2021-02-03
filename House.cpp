//
// Created by jihee on 1/27/2021.
//

#include "House.h"

House::House(const std::string &family, int numberOfResidents) : family(family),
                                                                 number_of_residents(numberOfResidents) {}



House::~House() {

}

void House::print_building(std::ostream &out) {
    out << get_id() << ") is a house where family "<<  family << " lives with "<< number_of_residents <<" persons"<< std::endl;
}

int House::get_residents() const {
    return number_of_residents;
}


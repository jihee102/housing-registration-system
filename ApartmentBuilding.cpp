//
// Created by jihee on 1/27/2021.
//

#include "ApartmentBuilding.h"

ApartmentBuilding::ApartmentBuilding(int number_of_apartments) : number_of_apartments(number_of_apartments) {
}

ApartmentBuilding::~ApartmentBuilding() {

}


std::shared_ptr<Apartment> ApartmentBuilding::find_apartment(const std::string &suffix) const {
    auto iterator = apartment_list.find(suffix);

    return iterator == apartment_list.cend() ? nullptr : iterator->second;
}


void ApartmentBuilding::add_apartment(const std::string &suffix, const std::string &family, int number_of_residents) {
    if(apartment_list.size() >= number_of_apartments){
        throw std::runtime_error("This apartment building has more than available apartments! ");
    }

    if(suffix.empty() || family.empty() || number_of_residents ==0){
        throw std::runtime_error("Apartment suffix or family name or number of resident cannot be empty or 0! ");
    }

    auto apartment = find_apartment(suffix);
    if(apartment){
        throw std::runtime_error("Apartment with the suffix "+suffix +" already exist!");
    }

    auto new_apartment = std::make_shared<Apartment>(suffix, family, number_of_residents);

    apartment_list[suffix] = new_apartment;

}


void ApartmentBuilding::print_building(std::ostream &out) {
    out << get_id() << ") is an apartment building with "<< number_of_apartments <<" apartments:"<< std::endl;
    for(auto iterator: apartment_list){
        iterator.second->print_apartment(out, "\t");
    }
}

int ApartmentBuilding::get_residents() const {
    int total = 0;

    for(auto iterator: apartment_list){
        total += iterator.second->get_number_of_residents();
    }

    return total;
}

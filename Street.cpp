//
// Created by jihee on 1/27/2021.
//

#include "Street.h"
#include "House.h"
#include "ApartmentBuilding.h"

Street::Street() {}

Street::~Street() {

}

std::shared_ptr<Building> Street::find_building(int building_id) const {
    auto iterator = building_list.find(building_id);

    return iterator == building_list.cend() ? nullptr : iterator->second;
}

void Street::add_house(const std::string &family, int number_of_residents) {
    if(family.empty() || number_of_residents ==0){
        throw std::runtime_error("Family name or number of residents cannot be empty or 0!");
    }

    auto house = std::make_shared<House>(family, number_of_residents);

    building_list[house->get_id()] = house;

}

void Street::add_apartment_building(int number_of_apartments) {
    if(number_of_apartments ==0){
        throw std::runtime_error("Number of apartment cannot be 0!");
    }

    auto apartment = std::make_shared<ApartmentBuilding>(number_of_apartments);

    building_list[apartment->get_id()] = apartment;
}

void Street::add_apartment_in_apartment_building(int building_id, const std::string &suffix, const std::string &family,
                                                 int number_of_residents) {
    auto building = find_building(building_id);
    if(!building){
        throw std::runtime_error("A building with given id doesn't exist!");
    }

    auto apartment_building = std::dynamic_pointer_cast<ApartmentBuilding>(building);

    if(!apartment_building){
        throw std::runtime_error("You can add an apartment only in an apartment building!");
    }

    apartment_building->add_apartment(suffix, family, number_of_residents);

}

const int Street::get_total_residents() const {
    int total = 0;

    for(auto iterator : building_list){
        total += iterator.second->get_residents();
    }

    return total;
}

void Street::print_buildings(std::ostream &out) const {
    out << "This street has " << get_total_residents() <<" residents." << std::endl;
    for(auto iterator: building_list){
        iterator.second->print_building(out);
    }
}

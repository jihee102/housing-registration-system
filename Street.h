//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_STREET_H
#define TOETS_STREET_H


#include <memory>
#include <map>
#include "Building.h"

class Street {
private:
    std::map<int, std::shared_ptr<Building>> building_list;

public:
    Street();

    virtual ~Street();

    std::shared_ptr<Building> find_building(int building_id) const;

    void add_house(const std::string &family, int number_of_residents);

    void add_apartment_building(int number_of_apartments);

    void add_apartment_in_apartment_building(int building_id, const std::string & suffix,const std::string &family, int number_of_residents);

    const int get_total_residents() const;

    void print_buildings(std::ostream & out) const;


};


#endif //TOETS_STREET_H

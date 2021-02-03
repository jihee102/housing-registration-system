//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_APARTMENTBUILDING_H
#define TOETS_APARTMENTBUILDING_H


#include <memory>
#include <vector>
#include <map>
#include "Building.h"
#include "Apartment.h"

class ApartmentBuilding : public Building{
private:
    int number_of_apartments;
    std::map<std::string, std::shared_ptr<Apartment>> apartment_list ;

public:
    ApartmentBuilding(int number_of_apartments);

    virtual ~ApartmentBuilding();

    int get_residents() const override;

    std::shared_ptr<Apartment> find_apartment(const std::string & suffix) const;

    void add_apartment (const std::string & suffix,const std::string &family, int number_of_residents);

    void print_building(std::ostream &out) override;


};


#endif //TOETS_APARTMENTBUILDING_H

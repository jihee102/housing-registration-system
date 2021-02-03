//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_HOUSE_H
#define TOETS_HOUSE_H


#include "Building.h"

class House : public Building{
private:
    std::string family;
    int number_of_residents;

public:
    House(const std::string &family, int numberOfResidents);

    virtual ~House();

    void print_building(std::ostream &out) override;

     int get_residents() const override;

};



#endif //TOETS_HOUSE_H

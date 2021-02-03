//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_BUILDING_H
#define TOETS_BUILDING_H
#include <iostream>

class Building {
private:
    static int increment;
    int id;
public:
    Building();

    virtual ~Building();

    int get_id() const;

    virtual void print_building(std::ostream & out) =0;

    virtual int get_residents() const =0;

};


#endif //TOETS_BUILDING_H

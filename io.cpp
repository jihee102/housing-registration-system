//
// Created by jihee on 1/27/2021.
//

#include <fstream>
#include "io.h"
#include <iostream>

void read_apartment_list(Street &street, int building_id, const std::string &filename) {
    std::ifstream input{filename};
    if(!input.is_open()){
        throw std::runtime_error("Fail to open the file "+ filename);
    }

    for(;;){
        std::string suffix, family;
        int residents;

        input >> suffix;
        if(suffix.empty() || input.eof()){
            return;
        }

        input >> family >> residents;

        street.add_apartment_in_apartment_building(building_id, suffix, family, residents);
    }

}

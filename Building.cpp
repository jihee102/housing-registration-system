//
// Created by jihee on 1/27/2021.
//

#include "Building.h"
int Building::increment = 1;
Building::Building() :id(increment++) {}

Building::~Building() {

}

int Building::get_id() const {
    return id;
}

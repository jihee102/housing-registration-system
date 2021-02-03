#include <iostream>
#include <memory>
#include "Street.h"
#include "io.h"

int main()
{
    /**
     * Possible errors are:
     *  - Adding more families to an apartment building than available apartments
     *  - Errors reading the input file (In this case the file is ok, but maybe in the future we will use a wrong file)
     *
     *  The same family name may be at different houses, this is not an error!
     */


    //TODO: Create an instance of the Street class (only one street is created)
    Street street;

    try{
        //TODO: Add the following house
        //Family: van Kleunen, residents: 3
        street.add_house("van Kleunen",3);

        //TODO; Add an apartment building with total 2 apartments and add the following families:
        //Suffix: a, Name: Pietersen, residents: 1
        //Suffix: b, Name: van Buren, residents: 2
        street.add_apartment_building(2);
        street.add_apartment_in_apartment_building(2, "a", "Pietersen", 1);
        street.add_apartment_in_apartment_building(2, "b", "van Buren", 2);


        //TODO: Add the following house
        //Family: van den Berg, residents: 2
        street.add_house("van den Berg",2);


        //TODO; Add an apartment building with total 3 apartments
        //TODO: Read the families who live here from the file "input.txt"
        //Format: [suffix] [family] [residents]
        street.add_apartment_building(3);
        read_apartment_list(street, 4, "input.txt");

        //TODO: tell the Street class to print out all the houses and apartments
        street.print_buildings(std::cout);
        //TODO: Release any memory you have allocated
    } catch (std::exception & exception) {
        std::cerr << exception.what() << std::endl;
    }
    return 0;
} 
    

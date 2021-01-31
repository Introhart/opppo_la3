#include <iostream>
// #include "list.h"
#include "plantFactory.cpp"
#include <map>


int main()
{
    
    std::map <std::string, std::string> *tree = new std::map <std::string, std::string>();

	tree->insert(std::pair<std::string, std::string>("Type", "Tree"));
	tree->insert(std::pair<std::string, std::string>("Name", "Cedar"));
	tree->insert(std::pair<std::string, std::string>("Age", "213"));
	tree->insert(std::pair<std::string, std::string>("Height", "942"));

	std::map <std::string, std::string> *bush = new std::map <std::string, std::string>();

	bush->insert(std::pair<std::string, std::string>("Type", "Bush"));
	bush->insert(std::pair<std::string, std::string>("Name", "Rose"));
	bush->insert(std::pair<std::string, std::string>("Month", "JUN"));
	bush->insert(std::pair<std::string, std::string>("Height", "80"));

	// std::map <std::string, std::string> *herb = new std::map <std::string, std::string>();

	// herb->insert(std::pair<std::string, std::string>("Type", "Herb"));
	// herb->insert(std::pair<std::string, std::string>("Name", "Lilliac"));
	// herb->insert(std::pair<std::string, std::string>("Color", "#FF231B"));
	// herb->insert(std::pair<std::string, std::string>("Height", "40"));



	TreeFabric af;
	
	Plant *plant = af.create(tree);

	if(plant != nullptr)
		std::cout << plant->toString() << std::endl;

    
    return 0;
}
#include <iostream>
#include <map>
#include <regex>

class Plant
{
	std::map <std::string, std::string> attr;
public:
	Plant(std::map <std::string, std::string> _attr) : attr(_attr) {}

	std::string toString()
	{
		std::string res = "";
		for(auto el : attr)
		{
			res +=  el.first + " : " + el.second + " \t " ;
		}

		return res;
	}
};


class AbstractFabric
{
public:
	// virtual Plant *create(std::map <std::string, std::string> *attr)
	// {
	// 	return new Plant(*attr);
	// }

protected:

	bool nameVerify(std::map <std::string, std::string> *attr)
	{
		auto attribName = attr->find("Name");

		if (attribName == attr->end())
			return false;

		if (attribName->second.length() == 0 ||	!isupper(attribName->second[0]))
			return false;
		
		return true;
	}

	//DUPLICATE
	bool heightVerify(std::map <std::string, std::string> *attr)
	{
		auto attribName = attr->find("Height");

		if (attribName == attr->end())
			return false;

		for(auto el : attribName->second)
			if(!isdigit(el))
				return false;

		return true;
	}


	std::string error(std::string errstring, std::map <std::string, std::string> *attr)
	{
		std::string errres = errstring + "\n\t";
		for(auto el : *attr)
		{
			errres += el.first + " : " + el.second + "\t";
		}
		return errres;
	}



};



//	TODO
// 	verify: AGEs

class TreeFabric : public AbstractFabric
{
public:
	Plant *create(std::map <std::string, std::string> *attr) 
	{
		if(!nameVerify(attr)) return nullptr;
		if(!ageVerify(attr)) return nullptr;
		if(!heightVerify(attr)) return nullptr;
		
		return new Plant(*attr);
	}

	bool ageVerify(std::map <std::string, std::string> *attr)
	{
		auto attribName = attr->find("Age");

		if (attribName == attr->end())
			return false;

		for(auto el : attribName->second)
			if(!isdigit(el))
				return false;
		
		return true;
	}
};




class BushFabric : public AbstractFabric
{
public:
	Plant *create(std::map <std::string, std::string> *attr) 
	{
		if(!nameVerify(attr)) return nullptr;
		if(!monthVerify(attr)) return nullptr;
		if(!heightVerify(attr)) return nullptr;
		
		return new Plant(*attr);
	}

	bool monthVerify(std::map <std::string, std::string> *attr)
	{
		auto attribName = attr->find("Month");

		if (attribName == attr->end())
			return false;

		std::string months[12] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};

		bool existence_flag = false;
		for(auto el : months)
			if(el == attribName->second)
				existence_flag = true;
		
		return existence_flag ? true : false;
	}
};




// class HerbFabric : public AbstractFabric
// {
// public:
// 	Plant *create(std::map <std::string, std::string> *attr) 
// 	{
// 		if(!nameVerify(attr)) return nullptr;
// 		if(!colorVerify(attr)) return nullptr;
// 		if(!heightVerify(attr)) return nullptr;
		
// 		return new Plant(*attr);
// 	}

// 	bool colorVerify(std::map <std::string, std::string> *attr)
// 	{
// 		auto attribName = attr->find("Color");

// 		if (attribName == attr->end())
// 			return false;

// 		std::string mask = "#([a-fA-F0-9]{6})";		
// 		return std::regex_match(attribName->second, std::regex(mask));
// 	}
// };
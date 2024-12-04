#ifndef Brain_HPP
#define Brain_HPP

#include "Animal.hpp"
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain& operator=(const Brain& other);
		std::string getIdea(int i) const;
		void setIdea(int i, std::string _idea);
};

#endif
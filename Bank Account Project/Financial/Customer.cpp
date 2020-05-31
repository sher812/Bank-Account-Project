#include "Customer.hpp"
#include <string>

int Customer::nextID = 0;

Customer::Customer(const std::string &name):name(name), id(nextID++) { //increment ID every time a new customer is created
	// TODO implement
	this->name = name;
}

std::string Customer::getName() const {
	// TODO implement
	return name;
}

int Customer::getID() const {
	// TODO implement

	return this->id;
}

Customer::~Customer() {
	// TODO implement
}


#pragma once
#include "Person.h"

// delegate the task about constructing an object (with many parameters) to separate entity PersonBuilder.
class PersonBuilder{
  
public:
    PersonBuilder(std::string name) : person(name) {}
    operator Person() const { return std::move(person); }
    
    PersonBuilder& lives();
    PersonBuilder& at(std::string street_address);
    PersonBuilder& with_postcode(std::string post_code);
    PersonBuilder& in(std::string city);
    PersonBuilder& works();
    PersonBuilder& with(std::string company_name);
    PersonBuilder& as_a(std::string position);
    PersonBuilder& earning(std::string annual_income);

private:
    Person person;
};
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"
#include "Person_Builder.h"

int main()
{
    Person p = Person::create("John")
                .lives()
                .at("123 London Road")
                .with_postcode("SW1 1GB")
                .in("London")
                .works()
                .with("PragmaSoft")
                .as_a("Consultant")
                .earning("1000000");

    std::cout << p << "\n";

    return EXIT_SUCCESS;
}
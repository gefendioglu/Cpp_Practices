#pragma once

// Before applying Open/Closed Principle
// ----------------------------------------------
// ----------------------------------------------

#ifdef BEFORE_OPEN_CLOSED_I

#define _CRT_SECURE_NO_WARNINGS
#define ALL(C)  begin(C), end(C)

#include<iostream> 
#include<string>
#include<vector>

enum class COLOR { RED, GREEN, BLUE };
enum class SIZE { SMALL, MEDIUM, LARGE };

struct Product {
    std::string  m_name;
    COLOR   m_color;
    SIZE    m_size;
};

using Items = std::vector<Product*>;

class ProductFilter {
public:
    static Items by_color(Items items, const COLOR e_color) {
        Items result;
        for (auto& i : items)
            if (i->m_color == e_color)
                result.push_back(i);
        return result;
    }
    static Items by_size(Items items, const SIZE e_size) {
        Items result;
        for (auto& i : items)
            if (i->m_size == e_size)
                result.push_back(i);
        return result;
    }
    static Items by_size_and_color(Items items, const SIZE e_size, const COLOR e_color) {
        Items result;
        for (auto& i : items)
            if (i->m_size == e_size && i->m_color == e_color)
                result.push_back(i);
        return result;
    }
};

int main() {

    const Items all{
        new Product{"Apple", COLOR::GREEN, SIZE::SMALL},
        new Product{"Tree", COLOR::GREEN, SIZE::LARGE},
        new Product{"House", COLOR::BLUE, SIZE::LARGE},
    };

    for (auto& p : ProductFilter::by_color(all, COLOR::GREEN))
        std::cout << p->m_name << " is green\n";

    for (auto& p : ProductFilter::by_size_and_color(all, SIZE::LARGE, COLOR::GREEN))
        std::cout << p->m_name << " is green & large\n";

    return EXIT_SUCCESS;
}

#endif // BEFORE_OPEN_CLOSED_I


// After applying Open/Closed Principle
// Adding the level of abstraction for extensibility
// ----------------------------------------------
// ----------------------------------------------

#ifdef AFTER_OPEN_CLOSED_I

#define _CRT_SECURE_NO_WARNINGS
#define ALL(C)  begin(C), end(C)

#include<iostream> 
#include<string>
#include<vector>

enum class COLOR { RED, GREEN, BLUE };
enum class SIZE { SMALL, MEDIUM, LARGE };

struct Product {
	std::string  m_name;
	COLOR   m_color;
	SIZE    m_size;
};

using Items = std::vector<Product*>;

template <typename T>
class Specification {
public:
	virtual ~Specification() = default;
	virtual bool is_satisfied(T* item) const = 0;
};

class ColorSpecification : public Specification<Product> {
public:
	ColorSpecification(COLOR e_color) : e_color(e_color) {}
	bool is_satisfied(Product* item) const override
	{
		return item->m_color == e_color;
	}
private:
	COLOR e_color;
};

class SizeSpecification : public Specification<Product> {
public:
	SizeSpecification(SIZE e_size) : e_size(e_size) {}
	bool is_satisfied(Product* item) const override
	{
		return item->m_size == e_size;
	}
private:
	SIZE e_size;
};

template <typename T>
class Filter {
public:
	virtual std::vector<T*> filter(std::vector<T*> items, const Specification<T>& spec) = 0;
};

// We do not have to modify filter method of BetterFilter. 
// It can work with all kind of specification now.
class BetterFilter : public Filter<Product> {
public:
	std::vector<Product*> filter(std::vector<Product*> items, const Specification<Product>& spec)
	{
		std::vector<Product*> result;
		for (auto& p : items)
			if (spec.is_satisfied(p))
				result.push_back(p);
		return result;
	}
};

// For two or more combined specifications
template <typename T>
class AndSpecification : public Specification<T> {
public:
	const Specification<T>& first;
	const Specification<T>& second;
	AndSpecification(const Specification<T>& first, const Specification<T>& second) : first(first), second(second) {}

	bool is_satisfied(T* item) const override
	{
		return first.is_satisfied(item) && second.is_satisfied(item);
	}
};

template <typename T>
AndSpecification<T> operator&&(const Specification<T>& first, const Specification<T>& second) {
	return { first, second };
}


int main() {

	const Items all{
		new Product{"Apple", COLOR::GREEN, SIZE::SMALL},
		new Product{"Tree", COLOR::GREEN, SIZE::LARGE},
		new Product{"House", COLOR::BLUE, SIZE::LARGE},
	};

	BetterFilter bf;

	// For testing ColorSpecification class
	for (auto& x : bf.filter(all, ColorSpecification(COLOR::GREEN)))
		std::cout << x->m_name << " is green\n";

	// For testing SizeSpecification class
	for (auto& x : bf.filter(all, SizeSpecification(SIZE::LARGE)))
		std::cout << x->m_name << " is large\n";

	// For testing AndSpecification class
	auto green_things = ColorSpecification{ COLOR::GREEN };
	auto large_things = SizeSpecification{ SIZE::LARGE };

	for (auto& x : bf.filter(all, green_things&& large_things))
		std::cout << x->m_name << " is green and large\n";

	return EXIT_SUCCESS;

	/*
		Apple is green
		Tree is green
		Tree is large
		House is large
		Tree is green and large
	*/
}

#endif // AFTER_OPEN_CLOSED_I 

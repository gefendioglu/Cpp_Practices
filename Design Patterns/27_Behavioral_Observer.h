#pragma once

// Observer Design Pattern 
// ----------------------------------------------
// ----------------------------------------------

#ifdef BEHAVIORAL_OBSERVER

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<vector> 

template<typename T>
class Observer {
public:
	virtual void field_changed(T& source, const std::string& field_name) = 0;
};

template<typename T>
class Observable {
public:
	void notify(T& source, const std::string& field_name) {
		for (auto observer : m_observers)
			observer->field_changed(source, field_name);
	}
	void subscribe(Observer<T>& observer) { 
		m_observers.push_back(&observer); 
	}
	void unsubscribe(Observer<T>& observer) {
		m_observers.erase(remove(m_observers.begin(), m_observers.end(), &observer), m_observers.end());
	}

private:
	std::vector<Observer<T>*> m_observers;
};

// Observable -------------------------------------
class Person : public Observable<Person> {
public:
	void set_age(uint8_t age) {
		auto old_can_vote = get_can_vote();
		this->m_age = age;
		notify(*this, "age");

		if (old_can_vote != get_can_vote()) 
			notify(*this, "can_vote");
	}
	uint8_t get_age() const { 
		return m_age; 
	}
	bool get_can_vote() const { 
		return m_age >= 16; 
	}

private:
	uint8_t m_age{ 0 };
};

// Observer ----------------------
class TrafficAdministration : public Observer<Person> {
public:
	void field_changed(Person& source, const std::string& field_name) {
		if (field_name == "age") {
			if (source.get_age() < 17)
				std::cout << "Not old enough to drive!\n";
			else {
				std::cout << "Mature enough to drive!\n";
				source.unsubscribe(*this);
			}
		}
	}
};

int main() {

	Person p;
	TrafficAdministration ta;
	p.subscribe(ta);
	p.set_age(16); 
	p.set_age(17);

	return EXIT_SUCCESS;

	/*
		Not old enough to drive!
		Mature enough to drive!
	*/
}

#endif // BEHAVIORAL_OBSERVER


// Observer Design Pattern with Boost Signals (TO BE CONTROLLED)
// ----------------------------------------------
// ----------------------------------------------

#ifdef BEHAVIORAL_OBSERVER_BOOST

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <string>
#include <boost/signals2.hpp> // no longer exists   

using namespace std;

template<typename T>
class Observable {
public:
	void subscribe(const auto&& observer) { 
		m_field_changed.connect(observer); 
	}
	void unsubscribe(const auto&& observer) { 
		m_field_changed.disconnect(observer); 
	}
protected:
	boost::signals2::signal<void(T&, const string&)>  m_field_changed;
};

// Observable 
class Person : public Observable<Person> {
public:
	void set_age(uint8_t age) {
		this->m_age = age;
		m_field_changed(*this, "age");
	}
	auto get_age() const { return m_age; }

private:
	uint32_t    m_age{ 0 };
};

// Observer
class TrafficAdministration { 
public:
	static void field_changed(Person& source, const string& field_name) {
		if (field_name == "age") {
			if (source.get_age() < 17)
				cout << "Not old enough to drive!\n";
			else {
				cout << "Mature enough to drive!\n";
				source.unsubscribe(TrafficAdministration::field_changed);
			}
		}
	}
};

int main() {

	Person p;
	p.subscribe(TrafficAdministration::field_changed);
	p.set_age(16);
	p.set_age(20);

	return EXIT_SUCCESS;
}

#endif // BEHAVIORAL_OBSERVER_BOOST

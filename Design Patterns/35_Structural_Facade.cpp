#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Alarm {
public:
	void alarm_on() {
		std::cout << "Alarm is on and house is secured" << "\n";
	}
	void alarm_off() {
		std::cout << "Alarm is off and you can go into the house" << "\n";
	}
};

class Ac {
public:
	void ac_on() {
		std::cout << "Ac is on" << "\n";
	}
	void ac_off() {
		std::cout << "AC is off" << "\n";
	}
};

class Tv {
public:
	void tv_on() {
		std::cout << "Tv is on" << "\n";
	}
	void tv_off() {
		std::cout << "TV is off" << "\n";
	}
};

class HouseFacade {
public:
	void go_to_work() {
		m_ac.ac_off();
		m_tv.tv_off();
		m_alarm.alarm_on();
	}
	void come_home() {
		m_alarm.alarm_off();
		m_ac.ac_on();
		m_tv.tv_on();
	}
private:
	Alarm   m_alarm;
	Ac      m_ac;
	Tv      m_tv;
};

//int main() {
//
//	HouseFacade hf;
//	// only have 2 functions are called 
//	// rather than calling several on-off functions
//	hf.go_to_work();
//	hf.come_home();
//
//	/*
//		AC is off
//		TV is off
//		Alarm is on and house is secured
//		Alarm is off and you can go into the house
//		Ac is on
//		Tv is on
//	*/
//	return EXIT_SUCCESS;
//}


// ----------------------------------------------
// ----------------------------------------------


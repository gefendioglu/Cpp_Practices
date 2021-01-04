#pragma once

#ifdef BEHAVIORAL_ITERATOR

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<algorithm> 
#include<iterator> 

class RadioStation {
public:
	RadioStation(float frequency) {
		this->frequency = frequency;
	}

	float getFrequency() {
		return this->frequency;
	}

protected:
	float frequency;
};

class StationList {
public:
	void addStation(RadioStation* station) {
		this->stations[] = station;
	}

	void removeStation(RadioStation toRemove) {
		float toRemoveFrequency = toRemove.getFrequency();

		this->stations = array_filter(this->stations) {
			return stations.getFrequency() != = toRemoveFrequency;
		});
	}

	int count() {
		return count(this->stations);
	}

	RadioStation current() {
		return this->stations[this->counter];
	}

	void key() {
		return this->counter;
	}

	void next() {
		this->counter++;
	}

	void rewind() {
		this->counter = 0;
	}

	bool valid() {
		return isset(this->stations[this->counter]);
	}

protected:
	int stations[];
	int counter;
};


int main()
{
	StationList* stationList = new StationList();
	
	// Adding stations (89, 101, 102, 103.2)
	stationList->addStation(new RadioStation(89));
	stationList->addStation(new RadioStation(101));
	stationList->addStation(new RadioStation(102));
	stationList->addStation(new RadioStation(103.2));

	for (auto station : stationList) {
		station.getFrequency();
	}

	// Removing station 89
	stationList->removeStation(new RadioStation(89));
}

#endif // BEHAVIORAL_ITERATOR


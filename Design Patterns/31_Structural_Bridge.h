#pragma once

#ifdef STRUCTURAL_BRIDGE_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Pure virtual class (abstract or interface class)
class DrawingAPI {
public:
	virtual void drawCircle() = 0;
	virtual void drawSquare() = 0;

};

class DrawingAPI_1 : public DrawingAPI {
public:
	void drawCircle() {
		std::cout << "Circle is drawn by API 1" << "\n";
	}
	void drawSquare() {
		std::cout << "Square is drawn by API 1" << "\n";
	}
};

class DrawingAPI_2 : public DrawingAPI {
public:
	void drawCircle() {
		std::cout << "Circle is drawn by API 2" << "\n";
	}

	void drawSquare() {
		std::cout << "Square is drawn by API 2" << "\n";
	}
};

// Shape class is an interface between DrawAPI and the shape types (Circle, Square)
class Shape {
public:
	Shape(DrawingAPI& drawingAPI) : m_drawingAPI{ drawingAPI } {}
	virtual void draw() = 0;
protected:
	DrawingAPI& m_drawingAPI;
};

class Circle : public Shape {
public:
	// Delegating base class constructor
	Circle(DrawingAPI& drawingAPI) : Shape{ drawingAPI } {}
	void draw() override { 
		m_drawingAPI.drawCircle(); 
	}
};

class Square : public Shape {
public:
	// Delegating base class constructor
	Square(DrawingAPI& drawingAPI) : Shape{ drawingAPI } {}
	void draw() override { 
		m_drawingAPI.drawSquare(); 
	}
};

int main() {

	DrawingAPI_1 API_1;
	DrawingAPI_2 API_2;

	Circle(API_1).draw();
	Circle(API_2).draw();

	Square(API_1).draw();
	Square(API_2).draw();

	return EXIT_SUCCESS;

	/*
		Circle is drawn by API 1
		Circle is drawn by API 2
		Square is drawn by API 1
		Square is drawn by API 2
	*/
}

#endif // STRUCTURAL_BRIDGE_I


// ----------------------------------------------------
// ----------------------------------------------------

#ifdef STRUCTURAL_BRIDGE_II

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// The implementor class in bridge pattern 
class Workshop {
public:
	virtual void work() = 0;
};

// Concrete implementation 
class Produce : public Workshop {
public:
	void work() override {
		std::cout << "Produced ";
	}
};

// Concrete implementation 
class Assemble :public Workshop {
public:
	void work()override {
		std::cout << "Assembled." << "\n";
	}
};

// The abstraction class in bridge pattern 
class Vehicle {
public:
	Vehicle(Workshop* wrkShp1, Workshop* wrkShp2){
		workShop1 = wrkShp1;
		workShop2 = wrkShp2;
	}
	virtual void manufacture() = 0;
protected:
	Workshop* workShop1;
	Workshop* workShop2;
};

class Car : public Vehicle {
public:
	// Delegating base class constructor
	Car(Workshop* workShop1, Workshop* workShop2) : Vehicle(workShop1, workShop2) {}

	void manufacture() override {
		std::cout << "Car ";
		workShop1->work();
		workShop2->work();
	}
};

class Bike : public Vehicle {
public:
	// Delegating base class constructor
	Bike(Workshop* workShop1, Workshop* workShop2) : Vehicle(workShop1, workShop2) {}

	void manufacture() override {
		std::cout << "Bike ";
		workShop1->work();
		workShop2->work();
	}
};

int main() {

	Vehicle* vehicle1 = new Car(new Produce(), new Assemble());
	vehicle1->manufacture();

	Vehicle* vehicle2 = new Bike(new Produce(), new Assemble());
	vehicle2->manufacture();

	return 0;

	/*
		Car Produced Assembled.
		Bike Produced Assembled.
	*/
}

#endif // STRUCTURAL_BRIDGE_II
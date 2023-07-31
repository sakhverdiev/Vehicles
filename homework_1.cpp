#include <iostream>
#include <stack>
using namespace std;

class Engine {
public:
    int engine_no;
    string company;
    int volume;
};

class Vehicle {
public:
    int id;
    string model;
    string vendor;
    Engine engine;

    virtual void show() = 0;
};

class Car : public Vehicle {
public:
    bool hasSpoiler;

    void show() override {
        cout << "ID: " << id << endl;
        cout << "Model: " << model << endl;
        cout << "Vendor: " << vendor << endl;
        cout << "Engine Number: " << engine.engine_no << endl;
        cout << "Company: " << engine.company << endl;
        cout << "Engine Volume: " << engine.volume << endl;
        cout << "Has Spoiler: " << (hasSpoiler ? "Yes" : "No") << endl;
        cout << endl;
    }
};

class Ship : public Vehicle {
public:
    bool hasSail;

    void show() override {
        cout << "ID: " << id << endl;
        cout << "Model: " << model << endl;
        cout << "Vendor: " << vendor << endl;
        cout << "Engine Number: " << engine.engine_no << endl;
        cout << "Company: " << engine.company << endl;
        cout << "Engine Volume: " << engine.volume << endl;
        cout << "Has Sail: " << (hasSail ? "Yes" : "No") << endl;
        cout << endl;
    }
};

class Airplane : public Vehicle {
public:
    int engineCount;
    int passengersCapacity;

    void show() override {
        cout << "ID: " << id << endl;
        cout << "Model: " << model << endl;
        cout << "Vendor: " << vendor << endl;
        cout << "Engine Number: " << engine.engine_no << endl;
        cout << "Company: " << engine.company << endl;
        cout << "Engine Volume: " << engine.volume << endl;
        cout << "Engine Count: " << engineCount << endl;
        cout << "Passengers Capacity: " << passengersCapacity << endl;
        cout << endl;
    }
};

class VehicleDepo {
public:
    stack<Car> cars;
    stack<Ship> ships;
    stack<Airplane> airplanes;

    void showAllVehicles() {
        cout << "Cars:" << endl;
        while (!cars.empty()) {
            Car car = cars.top();
            car.show();
            cars.pop();
        }

        cout << "Ships:" << endl;
        while (!ships.empty()) {
            Ship ship = ships.top();
            ship.show();
            ships.pop();
        }

        cout << "Airplanes:" << endl;
        while (!airplanes.empty()) {
            Airplane airplane = airplanes.top();
            airplane.show();
            airplanes.pop();
        }
    }
};

int main() {
    VehicleDepo depo;

    Car car;
    car.id = 1;
    car.model = "M5";
    car.vendor = "BMW";
    car.engine.engine_no = 635;
    car.engine.company = "BMW";
    car.engine.volume = 4395;
    car.hasSpoiler = true;
    depo.cars.push(car);

    Ship ship;
    ship.id = 2;
    ship.model = "Cargo";
    ship.vendor = "Maersk";
    ship.engine.engine_no = 789;
    ship.engine.company = "Maersk";
    ship.engine.volume = 100000;
    ship.hasSail = true;
    depo.ships.push(ship);

    Airplane airplane;
    airplane.id = 3;
    airplane.model = "Airbus A320";
    airplane.vendor = "Airbus";
    airplane.engine.engine_no = 1213;
    airplane.engine.company = "Airbus";
    airplane.engine.volume = 800000;
    airplane.engineCount = 2;
    airplane.passengersCapacity = 200;
    depo.airplanes.push(airplane);

    // SHow all vehicles
    depo.showAllVehicles();

    return 0;
}
#include<iostream>
using namespace std;
class Vehicle {
	const int registrationId;
	char* ownerName;
	double engineCapacity;
public:
	Vehicle(int rgId, const char* name, double engine) :registrationId(rgId)
	{
		engineCapacity = engine;
		ownerName = new char[strlen(name) + 1];
		strcpy_s(ownerName, strlen(name) + 1, name);

	}
	Vehicle(const Vehicle& v) :registrationId(v.registrationId)
	{
		ownerName = new char[strlen(v.ownerName) + 1];
		strcpy_s(ownerName, strlen(v.ownerName) + 1, v.ownerName);
		engineCapacity = v.engineCapacity;

	}
	void setEngine(double e)
	{
		engineCapacity = e;
	}

	double getEngine() const
	{
		return engineCapacity;
	}
	void display() const {
		cout << "Owner Name:" << ownerName << endl;
		cout << "Registration Id:" << registrationId << endl;
		cout << "Engine Capacity:" << engineCapacity << endl;
	}
 virtual~Vehicle()
	{
		delete[] ownerName;
	}
	const int getId() const
	{
		return registrationId;
	}
	Vehicle& upgradeEngine(double increment) {
		engineCapacity += increment;
		return *this;
	}
		
};
class ElectricVehicle :public Vehicle {
	double batteryCapacity;
	int chargingTime;
public:
	ElectricVehicle(double battery, int ctime, int Id, const char* name, double engine) :Vehicle(Id, name, engine) {
		batteryCapacity = battery;
		chargingTime = ctime;
	}
	ElectricVehicle(const ElectricVehicle& ev) :Vehicle(ev)
	{
		batteryCapacity = ev.batteryCapacity;
		chargingTime = ev.chargingTime;
	}
	void updateChargingTime(int a) {
		chargingTime = a;
	}
	void display() const {
		Vehicle::display();
		cout << "Batter Capacity:" << batteryCapacity << endl;
		cout << "Charging Time:" << chargingTime;
		}
};
class TransportOffice {
	const int officeCode;
	Vehicle** vehicles;
	int totalVehicles;
public:
	TransportOffice(int ocode, int tveh) :officeCode(ocode) {
		totalVehicles = tveh;
		vehicles = new Vehicle * [totalVehicles];
		for (int i = 0; i < totalVehicles; i++)
		{
			vehicles[i] = nullptr;
		}
	}
	TransportOffice(const TransportOffice& t) :officeCode(t.officeCode)
	{
		totalVehicles = t.totalVehicles;
	}
	void addVehicle(Vehicle* v)
	{
		char name[40];
		int id;
		double capacity;
		for (int i = 0; i < totalVehicles; i++)
		{
			cout << "Enter Vehicle:" << i + 1 << endl;
			cout << "Enter Name:";
			cin>>name;
			cout << "Enter regstration Id:";
			cin >> id;
			cout << "Enter Capacity:";
			cin >> capacity;
			vehicles[i] = new Vehicle(id, name, capacity);

		}
	}
	void dsiplay() const {
		for (int i = 0; i < totalVehicles; i++)
		{
			vehicles[i]->display();
		}
	}
	void findVehicle(int id)const {
		for (int i = 0; i< totalVehicles; i++)
		{
			if ((vehicles[i]->getId()) == id)
			{
				vehicles[i]->display();
		}
		}
	}
	~TransportOffice()
	{
		for (int i = 0; i < totalVehicles; i++)
		{
			delete vehicles[i];
		}
		delete[] vehicles;
	}

};
int main()
{
	ElectricVehicle e1(12, 89, 15, "Qaima", 34);
	ElectricVehicle e2 = e1;
	e2.display();
	TransportOffice t(1234,3);
	t.addVehicle(&e1);
	t.findVehicle(2);
	t.dsiplay();
	return 0;


}

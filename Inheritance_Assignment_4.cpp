#include<iostream>
#include<vector>
using namespace std;

class Vehicle{
	private:
		string vehicleId;
		string make;
		string model;
		int year;
		bool isRented;
	protected:
		double dailyRentalRate;
	public:
		//Getters for all attributes.....
		string getVehicleId(){
			return vehicleId;
		}
		bool getIsRented(){
			return isRented;
		}
		string getMaker(){
			return make;
		}
		string getModel(){
			return model;
		}
		int getYear(){
			return year;
		}
		void rentVehicle(){
			isRented = 1;
		}
		void returnVehicle(){
			isRented = 0;
		}
		double returnDailyRentalRate(){
			return dailyRentalRate;
		}
		
		//Calculate Rental Rete : Pure virtual function
		virtual double calculateRentalCost(int days) = 0;
		
		//Display vehicle details: Virtual function
		virtual void displayDetails(){
			cout<<"Vehicle Id : "<<vehicleId<<"\nMake : "<<make<<"\nModel : "<<model<<endl;
			cout<<"Year : "<<year<<"Daily Rental Rate : "<<dailyRentalRate<<endl;
			cout<<"Vehicle Rented? : "<<(isRented?"Yes" : "No")<<endl;
		}
		
		// Constructor to initialize all the attributes
		Vehicle(string vId, string mk, string modl, int yr, double rate){
			vehicleId = vId;
			make = mk;
			model = modl;
			year = yr;
			dailyRentalRate = rate;
			isRented = 0;
		}
};
//Derived class CAR
class Car : public Vehicle{
	private:
		int numberOfDoors;
		string fuelType;
	public:
		double calculateRentalCost(int days){
			return dailyRentalRate* days;
		}
		void displayDetails(){
			Vehicle::displayDetails();
			cout<<"Doors : "<<numberOfDoors<<"\nFuel Type : "<<fuelType<<endl;
		}
		Car(string vId, string mk, string modl, int yr, double rate, int doors, string fType):Vehicle(vId, mk, modl, yr, rate){
			numberOfDoors = doors;
			fuelType = fType;
		}
};
//Derived class Motorcycle
class Motorcycle : public Vehicle{
	private:
		string engineType;
		bool hasSideCar;
	public:
		double calculateRentalCost(int days){
			return dailyRentalRate * days + (hasSideCar?20*days:0);
		}
		void displayDetails(){
			Vehicle::displayDetails();
			cout<<"Engine Type : "<<engineType<<"\nHas Side car? : "<<(hasSideCar?"Yes":"No")<<endl;
		}
		Motorcycle(string vId, string mk, string modl, int yr, double rate, string engType,bool sideCar):Vehicle(vId, mk, modl, yr, rate){
			engineType = engType;
			hasSideCar = sideCar;
		}
};
// Derived class Truck
class Truck : public Vehicle{
	private:
		double cargoCapacity;
		int numberOfAxles;
	public:
		double calculateRentalCost(int days){
			return dailyRentalRate * days + (cargoCapacity*10*days);
		}
		void displayDetails(){
			Vehicle::displayDetails();
			cout<<"Cargo capacity : "<<cargoCapacity<<"cm3"<<"\nnumberOfAxles : "<<numberOfAxles<<endl;
		}
		Truck(string vId, string mk, string modl, int yr, double rate, double capacity, int axles):Vehicle(vId, mk, modl, yr, rate){
			cargoCapacity = capacity;
			numberOfAxles = axles;
		}
};
// Rental System Class

int main(){
    Car c1("123","Toyota","Fortuner",2023,2000000,4,"Petrol");
    c1.displayDetails();
    
    return 0;
}

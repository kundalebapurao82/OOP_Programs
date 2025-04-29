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
		
		//Calculate Rental Rate : Pure virtual function
		virtual double calculateRentalCost(int days) = 0;
		
		//Display vehicle details: Virtual function
		virtual void displayDetails(){
			cout<<"Vehicle Id : "<<vehicleId<<"\nMake : "<<make<<"\nModel : "<<model<<endl;
			cout<<"Year : "<<year<<"\nDaily Rental Rate : "<<dailyRentalRate<<endl;
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
class RentalSystem{
private:
    vector<Vehicle*> vehicles;
public:
    void addVehicle(Vehicle* vehicle){
        vehicles.push_back(vehicle);
    }
    void displayAvailableVehicles(){
        for (size_t i = 0; i < vehicles.size(); i++) {  
	        Vehicle* v = vehicles[i]; 
	        if (!v->getIsRented()) {
	            v->displayDetails();
	            cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
	        }
    	}
    }
    Vehicle* findVehicle(string vehicleID){
        for (size_t i = 0; i < vehicles.size(); i++) {  
	        Vehicle* v = vehicles[i]; 
	        if (v->getVehicleId() == vehicleID) {
	            return v;
	        }
   		}
        return NULL;
    }
    void rentVehicle(string vehicleID, int days){
        Vehicle* v = findVehicle(vehicleID);
        if(v && !v->getIsRented()){
            v->rentVehicle();
            cout << "Rental Cost: Rs" << v->calculateRentalCost(days) << endl;
        } else {
            cout << "Vehicle not available or doesn't exist." << endl;
        }
    }
    void returnVehicle(string vehicleID){
        Vehicle* v = findVehicle(vehicleID);
        if(v && v->getIsRented()){
            v->returnVehicle();
            cout << "Vehicle returned successfully!" << endl;
        } else {
            cout << "Invalid return request." << endl;
        }
    }
};

// Main Function with Menu
int main(){
    RentalSystem RS;
    RS.addVehicle(new Car("123","Toyota","Fortuner",2023,200,4,"Petrol"));
    RS.addVehicle(new Motorcycle("456","Honda","CBR600RR",2022,150,"Inline-4",false));
    RS.addVehicle(new Truck("789","Volvo","Bharatbenz",2020,300,20,4));
    
    int choice;
    string id;
    int days;
    do{
		cout << "\n1.Display Available Vehicles\n2.Rent a Vehicle\n3.Return a Vehicle\n4.Exit\nEnter your choice: ";
        cin >> choice;
        if(choice == 1){
            RS.displayAvailableVehicles();
        } 
		else if(choice == 2){
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter number of days: ";
            cin >> days;
            RS.rentVehicle(id, days);
        } 
		else if(choice == 3){
            cout << "Enter Vehicle ID: ";
            cin >> id;
            RS.returnVehicle(id);
        }
    } while(choice != 4);
    
    return 0;
}


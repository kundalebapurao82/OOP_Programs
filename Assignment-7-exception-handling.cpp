#include<iostream>
#include<string>
using namespace std;

class BankAccount{
private:
    string ownerName;
    double balance;

public:
    BankAccount(string name,double initialDeposit){   //Constructor to create account
        if(initialDeposit<0){
            cout<<"Invalid initial deposit amount!"<<endl;    // Handle invalid or negative initial diposit amount.
            balance = 0;
        } else {
            balance = initialDeposit;
        }
        ownerName = name;
        cout<<"Account created for "<<ownerName<<" with initial deposit "<<balance<<endl;
    }

    void deposit(double dAmount){
        if(dAmount<0){
            cout<<"Error: Cannot deposit negative amount!"<<endl;    //Handle negative diposite amount
            return;
        }
        balance += dAmount;
        cout<<"Deposited "<<dAmount<<" to "<<ownerName<<"'s account."<<endl;
    }

    void withdraw(double amount){
        if(amount < 0){
            cout<<"Error: Cannot withdraw negative amount!"<<endl;   //Handle negative withdrawel amount 
            return;
        }
        if(amount > balance){
            cout<<"Error: Insufficient funds!"<<endl;   // Handle less account balance 
            return;
        }
        balance -= amount;
        cout<<"Withdrawed "<<amount<<" from "<<ownerName<<"'s account."<<endl;
    }
	void divideBal(double n) {
        if(n == 0){
            cout<<"Error: Cannot divide by zero!"<<endl;   //Handle divide by zero
            return;
        }
        double result = balance/n;
        cout<<"Balance "<<balance<<" divided by "<<n<<" : after division balance = "<<result<<endl;
    }
    void transfer(BankAccount &to, double amount) {
        if(amount < 0){
            cout<<"Error: Cannot transfer negative amount!"<<endl;  // handle negative transfer ammount
            return;
        }
        if(amount >balance){
            cout<<"Error: Funds are insufficient for transfer!"<<endl;  //Handle insuficient bank balance while transfering amount
            return;
        }
        balance =balance- amount;
        to.balance = to.balance+ amount;
        cout<<"Transferred "<<amount<<" from " <<ownerName<<" to "<<to.ownerName<<"."<<endl;
    }
    

    void display(){
        cout<<"Account Holder: "<<ownerName<< ": Balance: "<<balance<<endl;
    }
};

int main() {
    BankAccount acc1("Akshay Kumar", 5000);
    acc1.deposit(1000);
    acc1.withdraw(7000); // should show insufficient funds
    acc1.withdraw(1000);

    BankAccount acc2("A Kumari", 0);
    acc2.deposit(4000);
    acc1.transfer(acc2, 3000);
    acc1.display();
    acc2.display();
    
    acc1.divideBal(0); // should show divide by zero error
    acc1.divideBal(2);

    return 0;
}


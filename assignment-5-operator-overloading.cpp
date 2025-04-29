#include <iostream>
using namespace std;

class Bank{
public:
    void deposit(int amount){
        cout<<"Rs"<<amount<<" diposited in cash."<< endl;
    }
    void deposit(double amount){
        cout<<"Rs"<<amount<<" diposited through digital payment."<<endl;
    }
    void deposit(int amt, string upiID){
        cout<<"Deposited Rs"<<amt<<" through UPI "<<upiID<< "."<<endl;
    }
};

class Account{
private:
    int accountNumber;
    double balance;
public:
    Account(int accNum, double bal){
    	accountNumber = accNum;
    	balance = bal;
	}
    void display(){
        cout<<"Account "<<accountNumber<<" Balance Rs: "<<balance<<endl;
    }

    Account operator+(double dAmount){
        balance = balance + dAmount;
        return *this;
    }
    
    Account operator-(double wAmount){
        if(balance >= wAmount) {
            balance = balance - wAmount;
        }
		else{
            cout<<"Balance is less than withdrawal ammount!" <<endl;
        }
        return *this;
    }
    
    void transfer(Account &to, double tAmount){
        if(balance >= tAmount){
            balance = balance -  tAmount;
            to.balance = to.balance + tAmount;
            cout << "Transferring Rs"<<tAmount<<" from Account "<<accountNumber<<" to Account "<<to.accountNumber<<"."<<endl;
        } 
		else{
            cout<<"Transfer failed: Insufficient balance!"<<endl;
        }
    }
};

int main(){
    Bank bank;
    bank.deposit(20000);
    bank.deposit(126162.34);
    bank.deposit(50000,"gpay@upi");
    
    Account acc1(87976449, 70000);
    Account acc2(61337782, 150000);
    
    acc1.display();
    acc2.display();
    
    acc1.transfer(acc2, 30000);
    acc1.display();
    acc2.display();
    
    acc2.transfer(acc1, 70000);
    
    acc1 = acc1 - 4000;
    cout << "Rs "<<4000<<" withrawed from Account 1."<<endl;
    acc1.display();
    
    return 0;
}


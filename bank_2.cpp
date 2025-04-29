#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    string accountType;
    double balance;

public:
    BankAccount(){
        accountHolder = "";
        accountNumber = 0;
        accountType= "";
        balance = 0.0;
    } 

    BankAccount(string holder, int number, string type, double bal){
        accountHolder = holder;
        accountNumber = number;
        accountType= type;
        balance = bal;
    }

    string getAccountHolder(){ 
        return accountHolder; 
    }
    int getAccountNumber(){ 
        return accountNumber;
    }
    string getAccountType(){ 
        return accountType; 
    }
    double getBalance(){ 
        return balance; 
    }


    void setAccountType(string newType){ 
        accountType = newType; 
    }

    void deposit(double amount){
        if(amount > 0){
            balance += amount;
            cout << "Deposited: " << amount << "\nNew Balance: " << balance << endl;
        }
        else{
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
            cout << "Withdrawn: " << amount << "\nNew Balance: " << balance << endl;
        }
        else{
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    void displayAccountDetails(){
        cout << "Account Details:\n";
        cout << "Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account1("Amar Patil", 123456, "Savings", 5000.00);
    BankAccount account2;
    
    account1.displayAccountDetails();
    

    cout << "\nDepositing 2000..." << endl;
    account1.deposit(2000);
    
    cout << "\nWithdrawing 1500..." << endl;
    account1.withdraw(1500);
    

    account1.setAccountType("Current");
    cout << "\nUpdated Account Type to Current." << endl;
    

    cout << "\nFinal Account Details:" << endl;
    account1.displayAccountDetails();
    
    return 0;
}

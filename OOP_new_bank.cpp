#include<iostream>
#include<fstream>

int last = -1;
using namespace std;
class Bank{
    float balance = 0.0;
    float transactions[10];
    int transactionCount = 0;
    
    public:
        float diposite_amount(float dAmount){
            balance += dAmount;
            recordTransaction(dAmount);
            return balance;
        }
        float withdraw_amount(float wAmount){
            if(balance - wAmount >= 100){
                balance = balance - wAmount;
                recordTransaction(-wAmount);
                return balance;
            }
            else{
                return 0;
            }
        }
        void showBankBalance(){
            cout<<"\nBank balance is "<<balance<<endl;
        }
        void recordTransaction(float amount){
            transactions[transactionCount % 10] = amount;
            transactionCount++;
        }
        void printTransactions(){
            cout<<"\nLast 10 Transactions:\n";
            int count = transactionCount < 10 ? transactionCount : 10;
            for(int i = transactionCount - count; i < transactionCount; i++){
                cout<<transactions[i % 10]<<endl;
            }
        }
};

void display_menu(){
    cout<<"\n1. Deposit Amount."<<endl;
    cout<<"2. Withdraw Amount."<<endl;
    cout<<"3. Show bank balance."<<endl;
    cout<<"4. Print last 10 transaction statements."<<endl;
    cout<<"5. Exit."<<endl;
}

int main(){
    int choice;
    float dAmount, wAmount, status;
    Bank bank;
    do{
        display_menu();
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter amount to deposit: ";
                    cin>>dAmount;
                    cout<<"\n"<<dAmount<<" credited to account and balance is "<<bank.diposite_amount(dAmount)<<endl;
            break;
            case 2: cout<<"Enter amount to withdraw: ";
                    cin>>wAmount;
                    status = bank.withdraw_amount(wAmount);
                    if(status == 0)
                        cout<<"\nRequest Denied. Bank balance low."<<endl;
                    else
                        cout<<"\n"<<wAmount<<" debited from account and balance is "<<status<<endl;
            break;
            case 3: bank.showBankBalance();
            break;
            case 4: bank.printTransactions();
            break;
        }
    }while(choice != 5);
}

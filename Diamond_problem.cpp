#include<iostream>
using namespace std;
class A {
    protected:
        int x;
    public:
        A(int val) {
            x = val;
            cout<<"Constructor of A : x = "<<x<<endl;
        }
        void displayA(){
            cout<<"Value from class A: "<<x<<endl;
        }
};

// Virtual inheritance to avoid duplicate A in D
class B : virtual public A {
    protected:
        int y;
    public:
        B(int valA, int valB):A(valA){
            y = valB;
            cout<<"Constructor of B: y = "<<y<<endl;
        }
        void displayB(){
            cout<<"Value from B: "<<y<<endl;
        }
};

class C : virtual public A{
    protected:
        int z;
    public:
        C(int valA, int valC) : A(valA){
            z = valC;
            cout << "Constructor of C: z = " << z << endl;
        }
        void displayC(){
            cout<<"Value from C: "<<z<<endl;
        }
};

class D : public B,public C{
    private:
        int total;
    public:
        D(int valA, int valB, int valC):A(valA),B(valA, valB),C(valA, valC){
            total = x+y+z;
            cout<<"Constructor of D called. Total sum : "<<total<<endl;
        }
        void displayD(){
            displayA();
            displayB();
            displayC();
            cout<<"Sum of x + y + z = "<<total<<endl;
        }
};

int main() {
	A a(5);
	a.displayA();
	cout<<"\n";
	B b(5,30);
	b.displayB();
	cout<<"\n";
	
	C c(5,7);
	c.displayC();
	cout<<"\n";
	
    D obj(10, 20, 30);
    cout << "\nDisplaying values from all classes.\n";
    obj.displayD();
    return 0;
}


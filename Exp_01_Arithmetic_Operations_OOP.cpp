/*Program to perform basic arithmetic operations.*/
// #include<iostream>
// float division(int x, int y){
//     return x/y;
// }
// int product(int x, int y){
//     return x*y;
// }
// int subtract(int x, int y){
//     return x-y;
// }
// int add(int x, int y){
//     return x+y;
// }
// int main(){
//     int a,b;
//     std::cout<<"Enter two numbers: "<<std::endl;
//     std::cin>>a>>b;

//     std::cout<<"Addition of "<<a<<" and "<<b<<" is :"<<add(a,b)<<std::endl;
//     std::cout<<"Subtraction of "<<a<<" and "<<b<<" is :"<<subtract(a,b)<<std::endl;
//     std::cout<<"Product of "<<a<<" and "<<b<<" is :"<<product(a,b)<<std::endl;
//     std::cout<<"Division of "<<a<<" and "<<b<<" is :"<<division(a,b)<<std::endl;
//     return 0;
// }

/*Using class and object:*/
#include<iostream>
class Arithmetic_Operations{
    int x;
    int y;
    public:
        int add(int x, int y){
            return x+y;
        }
        float division(float x, float y){
            return x/y;
        }
        int product(int x, int y){
            return x*y;
        }
        int subtract(int x, int y){
            return x-y;
        }

    

};


int main(){
    int a,b;
    Arithmetic_Operations arith;
    std::cout<<"Enter two numbers: "<<std::endl;
    std::cin>>a>>b;

    std::cout<<"Addition of "<<a<<" and "<<b<<" is :"<<arith.add(a,b)<<std::endl;
    std::cout<<"Subtraction of "<<a<<" and "<<b<<" is :"<<arith.subtract(a,b)<<std::endl;
    std::cout<<"Product of "<<a<<" and "<<b<<" is :"<<arith.product(a,b)<<std::endl;
    std::cout<<"Division of "<<a<<" and "<<b<<" is :"<<arith.division(a,b)<<std::endl;

    return 0;
}
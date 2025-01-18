#include<iostream>
#include<iomanip>
class Number{
    int n;
    int end = 10;
    public:
        int i;
        void multiplication_table(int n){
            for(i=1;i<=end;i++){
                std::cout<<std::setw(4)<<n*i<<std::endl;
            }
        }
};
int main(){
    int num;
    Number table;
    std::cout<<"Enter number for multiplication table :"<<std::endl;
    std::cin>>num;
    std::cout<<"Multiplication table of "<<num<<" is :"<<std::endl;
    table.multiplication_table(num);
}
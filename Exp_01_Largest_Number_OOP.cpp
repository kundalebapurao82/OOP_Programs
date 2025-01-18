#include<iostream>
class Numbers{
    int a,b,c;
    public:
        int largest_Number(int a, int b, int c){
            if(a>b && a>c){
                return a;
            }
            else if(b>c && b>>a){
                return b;
            }
            else{
                return c;
            }
        }
};
int main(){
    int x,y,z;
    Numbers large;
    std::cout<<"Enter three numbers: "<<std::endl;
    std::cin>>x>>y>>z;
    std::cout<<"Largets of "<<x<<", "<<y<<", and "<<z<<" is :"<<large.largest_Number(x,y,z);
    return 0;
}
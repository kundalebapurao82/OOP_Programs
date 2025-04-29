#include<iostream>
using namespace std;

class MajorityElement{
    public:
        int findMajorityElement(int nums[], int size){
            int count = 0;
            int candidate = 0;
            for(int i = 0; i < size; i++){
                if(count == 0){
                    candidate = nums[i];
                }

                if(nums[i] == candidate){
                    count++;
                } else {
                    count--;
                }
            }
            return candidate;
        }
};

int main(){
    MajorityElement mef;
    int nums1[] = {3, 2, 3};
    int size1 = sizeof(nums1)/sizeof(nums1[0]);
    cout<<"Majority element in first array: "<<mef.findMajorityElement(nums1, size1)<<endl;
    int nums2[] = {2, 2, 1, 1, 1, 2, 2};
    int size2 = sizeof(nums2)/sizeof(nums2[0]);
    cout<<"Majority element in second array: "<<mef.findMajorityElement(nums2, size2)<<endl;
    return 0;
}


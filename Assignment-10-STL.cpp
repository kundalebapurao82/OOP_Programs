#include<iostream>
#include<map>
#include<vector>
#include<numeric>
using namespace std;

class StudentManager{
private:
    map<string, vector<int> > studentRecords;    //Map initilization to store student marks

public:
    void addStudent(string name, int s1, int s2, int s3){   // function to add student records in map
        vector<int> marks;
        marks.push_back(s1);
        marks.push_back(s2);
        marks.push_back(s3);
        studentRecords[name] = marks;
    }
    void displayAllStudents(){			//Function to display all students
    	map<string, vector<int> >::iterator it;
		for(it = studentRecords.begin(); it != studentRecords.end(); ++it){
            string name = it->first;
            vector<int> marks = it->second;
            int total = accumulate(marks.begin(), marks.end(), 0);   // accumulate will calculate sum
            float avg = total / 3.0;			//Calculate average

            cout << "Student: " << name << ", Marks: ";
            for(int i = 0; i < marks.size(); i++){
                cout << marks[i] << " ";
            }
            cout<<", Average: "<<avg<<endl;    //Display averege
        }
    }

    void displayTopper(){   //function to display topper
        string top = "";     // initial declaration
        float maxAvg = 0.0;
        map<string, vector<int> >::iterator it;
		for(it = studentRecords.begin(); it != studentRecords.end(); ++it){
            vector<int> marks = it->second;
            float avg = accumulate(marks.begin(), marks.end(), 0)/3.0;   //accumulate will calculate average
            if(avg > maxAvg){  											//Update max_avg
                maxAvg = avg;
                top = it->first;										//Update topper
            }
        }

        if(top != ""){
            cout<<"Topper: "<<top<<" with average "<<maxAvg<<endl;		//Display topper
        }
    }
};

int main(){
    StudentManager stm;
    int choice;
    string name;
    int m1, m2, m3;

    do{
        cout << "\n1. Add Student\n2. Display All Students\n3. Display Topper\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"Enter student name: ";
                cin>>name;
                cout<<"Enter 3 subject marks: ";
                cin>>m1>>m2>>m3;
                stm.addStudent(name,m1,m2,m3);
                break;
            case 2:
                cout<<"\nAll Student Records:"<<endl;
                stm.displayAllStudents();
                break;
            case 3:
                cout<<"\nTopper:"<<endl;
                stm.displayTopper();
                break;
            case 4:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    } while(choice!= 4);
    return 0;
}


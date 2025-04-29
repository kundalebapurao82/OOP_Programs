#include<iostream>
#include<string>
using namespace std;
class Person{
	protected:
		string name;
		int age;
	public:
		Person(){     //To handle multiple inheritance problem
		}
		Person(string nm, int ag){   //constructor
			name = nm;
			age = ag;
		}
		virtual void display(){
			cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
		}
};
class Student : virtual public Person{     //using vertual to handle multiple inheritance "Diamond" problem
	protected:
		int rollNumber;
		string branch;
		int marks;
		
	public:
		Student(string nm, int ag, int roll, string bnch, int mks):Person(nm,ag){    //constructor
			rollNumber = roll;
			branch = bnch;
			marks = mks;
		}
		float calculateCGPA(){
			return marks/9.8;
		}
		
		void display() override{
			cout<<"Student Information:"<<endl;
			Person::display();
			cout<<"Roll Number: "<<rollNumber<<"\nBranch: "<<branch<<"\nMarks: "<<marks<<"\nCGPA: "<<calculateCGPA()<<endl;
		}
		
		friend class Administration;
};
class Faculty :virtual public Person{    //using vertual to handle multiple inheritance "Diamond" problem
	protected:
		int faculty_id;
		string department;
		float salary;
	public:
		void display() override{
			cout<<"Faculty Information: "<<endl;
			Person::display();
			cout<<"Faculty ID: "<<faculty_id<<"\nDepartment: "<<department<<"\nSalary: "<<salary<<endl;
		}
		Faculty(string nm, int ag, int F_id, string dept, float slr):Person(nm,ag){    //Constructor
			faculty_id = F_id;
			department = dept;
			salary = slr;
		}
		friend class Administration;
};
class TeachingAssistant:public Student, public Faculty{
	public:
		TeachingAssistant(string nm, int ag, int roll, string bnch, int mks, int F_id, string dept, float slr )
			:Person(nm,ag),Student(nm, ag, roll, bnch, mks),Faculty(nm, ag, F_id, dept, slr){
				
		}
		void display()override{
			cout<<"Teaching Assistant Info: "<<endl;
			Person::display();
			cout<<"Roll Number: "<<rollNumber<<"\nBranch: "<<branch<<"\nFaculty ID: "<<faculty_id<<"\nDepartment: "<<department<<"\nSalary: "<<salary<<endl;
		}		
	
};

//Friend class
class Administration{
	public:
		void displayStudentInfo(Student &s){
			cout<<"Student "<<s.name<<" from "<<s.branch<<" scored "<<s.marks<<" marks."<<endl;
			
		}
		void displayFacultyInfo(Faculty &f){
			cout<<"Faculty "<<f.name<<" teaches "<<f.department<<"."<<endl;
		}
		
};

int main(){
	
	Student s("Raj Malhotra", 20, 123456, "CSE(AIML)", 89);    //Initialization of student class cunstructor
	Faculty f("Dr. Sharma", 45, 1234, "Computer Science", 100000);  //Initialization of faculty class cunstructor
	TeachingAssistant t("Priya Desai", 25, 321456, "CSE(AIML)", 85, 2005, "Artificial Intelligence", 35000);   //Initialization of teaching assistant class cunstructor
	
	//Displaying info one by one:
	s.display();    //Student display function
	cout<<endl;

	f.display();	//Faculty display function
	cout<<endl;
	t.display();	//Teaching assistant display function
	cout<<endl;
	
	Administration ad;
	cout<<"Administration friend access private members:"<<endl;
	ad.displayStudentInfo(s);
	ad.displayFacultyInfo(f);
	return 0;
}

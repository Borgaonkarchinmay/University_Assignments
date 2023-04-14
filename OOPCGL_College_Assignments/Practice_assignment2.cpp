#include<iostream>
#include<string.h>
using namespace std;

class student{
	char* name, *mobno, *rollno;
	static int objcount;
	float m1, m2, m3;
	public:
		friend class result;
		student();
		student(student&);
		student(char*, char*, char*);
		void getdetails();
		void showdetails();
		void getmarks();
		static void dispcount();
		~student();
};

int student :: objcount = 0;

student :: student(){
	this->name = new char;
	this->mobno = new char;
	this->rollno = new char;
	objcount++;
}

student :: student(student& o){
	name = new char;
	rollno = new char;
	mobno = new char;
	this->name = o.name;
	this->rollno = o.rollno;
	this->mobno = o.mobno;
	objcount++;
}

student :: student(char* Name, char* RollNo, char* MobNo){
	int len = strlen(Name);
	this->name = new char[len];
	this->name = Name;
	
	len = strlen(RollNo);
	this->rollno = new char[len];
	this->rollno = RollNo;
	
	len = strlen(MobNo);
	this->mobno = new char[len];
	this->mobno = MobNo;
	
	objcount++;
}
	
void student :: getdetails(){
	cout<<endl;
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter Roll No: ";
	cin>>rollno;
	cout<<"Enter mob no: ";
	try{
		cin>>mobno;
		if(strlen(mobno) != 10){
			throw mobno;
		}
	}
	catch(char*){
		cout<<endl;
		cout<<"Invalid Mobile number!!"<<endl;
	}
}

void student :: showdetails(){
	cout<<"Name: "<<name<<"\tRoll no: "<<rollno<<"\tMob No: "<<mobno<<endl;
}

void student :: getmarks(){
	cout<<endl;
	cout<<"Enter marks of subject 1: ";
	cin>>m1;
	cout<<"Enter marks of subject 2: ";
	cin>>m2;
	cout<<"Enter marks of subject 3: ";
	cin>>m3;
}

void student :: dispcount(){
	cout<<"student count is: "<<objcount<<endl;
}

student :: ~student(){
	delete name;
	delete mobno;
	delete rollno;
}

class result{
	float result;
	public:
		void calMarks(student&);
};

void result :: calMarks(student& o){
	result = (o.m1 + o.m2 + o.m3)*100/150;
	cout<<"Percentage of student: "<<result<<"%"<<endl;
}

int main(){
	//Normal object creation and exception handling
	student s1;
	result stu1;
	s1.getdetails();
	s1.getmarks();
	cout<<endl;
	s1.showdetails();
	stu1.calMarks(s1);
	student :: dispcount();
	
	//parametrized constructor
	char *name, *rollno, *mobno;
	name = new char;
	rollno = new char;
	mobno = new char;
	cout<<endl;
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter roll no: ";
	cin>>rollno;
	cout<<"Enter mob no: ";
	try{
		cin>>mobno;
		if(strlen(mobno) != 10){
			throw mobno;
		}
	}
	catch(char*){
		cout<<"Invalid mobile number!!"<<endl;
	}
	
	cout<<endl;
	student s2(name, rollno, mobno);
	s2.getmarks();
	result stu2;
	s2.showdetails();
	stu2.calMarks(s2);
	student :: dispcount();
	
	
	//Copy constructor	
	student s3(s1);
	cout<<endl;
	s3.showdetails();
	student::dispcount();
	
	
	delete name;
	delete rollno;
	delete mobno;
	 
	return 0;
}

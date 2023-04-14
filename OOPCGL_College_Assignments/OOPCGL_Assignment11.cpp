#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Define class to store employee details
class Employee{
	string name;
	double salary;
	int ID;
	public:
		Employee();
		Employee(string);
		void getDetails();
		void fetchDetails();
		bool operator <(Employee&); //Used by sort() function
		bool operator ==(const Employee&); //Used by search() and find() functions
};
//Member functions of Employee Class
Employee :: Employee(){
	salary = 0;
	ID = 0;
}

Employee :: Employee (string Name){
	name = Name;
}

void Employee :: getDetails(){
	cout<<"Enter Employee Name: ";
	cin.ignore();
	getline(cin, name);
	cout<<"Enter Employee Salary: ";
	cin>>salary;
	cout<<"Enter Employee ID: ";
	cin>>ID;
}

void Employee :: fetchDetails(){
	cout<<"Name: "<<name<<"\tID: "<<ID<<"\tSalary: "<<salary<<endl;
}

bool Employee :: operator <(Employee& obj){
	if(salary < obj.salary){
		return true;
	}
	else{
		return false;
	}
}

bool Employee :: operator ==(const Employee& obj){
	if(name == obj.name){
		return true;
	}
	else{
		return false;
	}
}

//Non-Member functions
void showDetails(Employee& obj){
	//Function to access the fetchDetails() member function of Employee class
	//Its parameter will be the object of the Employee class
	obj.fetchDetails();
}

int main(){
	
	cout<<"Employee Information System-"<<endl;
	
	//Use Vector to store employees from various depts. of a company
	vector<Employee> InfosysAdminDept;
	
	while(true){
		int menu;
		cout<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"MENU\n1 ->Add new Employee\n2 ->Edit existing Employee details\n3 ->Remove Employee\n4 ->Search Employee\n5 ->Sort Employee Vector\n6 ->Display details of all Employees\n7 ->Exit"<<endl;
		cout<<"Enter Menu: ";
		cin>>menu;
		
		switch(menu){
			case 1:{
				//Add new Employee
				Employee newEmp;
				newEmp.getDetails();
				InfosysAdminDept.push_back(newEmp);
				}
				break;
				
			case 2:{
				//Edit existing Employee details
				string name;
				cout<<"\nEnter Employee name: ";
				cin>>name;
				Employee temp(name);
				vector<Employee> :: iterator itr;
				itr = find(InfosysAdminDept.begin(), InfosysAdminDept.end(), temp);
				if(itr != InfosysAdminDept.end()){
					cout<<"\nRe-enter details of the employee"<<endl;
					itr->getDetails();
				}	
				else{
					cout<<"Employee with "<<name<<" does not exits!!"<<endl;
				}
				}
				break;
				
			case 3:{
				//Remove specified employee
				string name;
				cout<<"\nEnter Employee name: ";
				cin>>name;
				Employee temp(name);
				vector<Employee> :: iterator currItr;
				vector<Employee> :: iterator Itr;
				currItr = find(InfosysAdminDept.begin(), InfosysAdminDept.end(), temp);
				for(Itr = currItr + 1; Itr != InfosysAdminDept.end(); Itr++){
					*currItr = *Itr;
					currItr++;
				}
				InfosysAdminDept.pop_back();
				}
				break;
				
			case 4:{
				//Search for employee in Vector using 'Name attribute'
				string name;
				cout<<"\nEnter Employee name: ";
				cin>>name;
				Employee temp(name);
				vector<Employee> :: iterator itr;
				itr = find(InfosysAdminDept.begin(), InfosysAdminDept.end(), temp);
				if(itr != InfosysAdminDept.end()){
					cout<<"\nDetails of the employee are:"<<endl;
					itr->fetchDetails();
				}	
				else{
					cout<<"Employee with name "<<name<<" not found!!"<<endl;
				}
				}
				break;
				
			case 5:{
				//Sort employee vector on the basis of Salary
				sort(InfosysAdminDept.begin(), InfosysAdminDept.end());
				//Display sorted Vector
				for_each(InfosysAdminDept.begin(), InfosysAdminDept.end(), showDetails);
				}
				break;
				
			case 6:
				//Display details of all the Employees
				cout<<"\nEmployee details are-"<<endl;
				for_each(InfosysAdminDept.begin(), InfosysAdminDept.end(), showDetails);
				break;	
				
			case 7:
				exit(0);
				break;
					
			default:
				cout<<"Invalid Menu"<<endl;
				break;
					
		}
	}
					
	return 0;
}

/*
OUTPUT:

Employee Information System-

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 1
Enter Employee Name: Donald
Enter Employee Salary: 6000
Enter Employee ID: 1

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 1
Enter Employee Name: John
Enter Employee Salary: 2500
Enter Employee ID: 2

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 1
Enter Employee Name: George
Enter Employee Salary: 4500
Enter Employee ID: 3

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 1
Enter Employee Name: Ron
Enter Employee Salary: 3000
Enter Employee ID: 4

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 1
Enter Employee Name: Benjamin
Enter Employee Salary: 250
Enter Employee ID: 5

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 6

Employee details are-
Name: Donald    ID: 1   Salary: 6000
Name: John      ID: 2   Salary: 2500
Name: George    ID: 3   Salary: 4500
Name: Ron       ID: 4   Salary: 3000
Name: Benjamin  ID: 5   Salary: 250

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 5
Name: Benjamin  ID: 5   Salary: 250
Name: John      ID: 2   Salary: 2500
Name: Ron       ID: 4   Salary: 3000
Name: George    ID: 3   Salary: 4500
Name: Donald    ID: 1   Salary: 6000

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 4

Enter Employee name: Ron

Details of the employee are:
Name: Ron       ID: 4   Salary: 3000

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 2

Enter Employee name: Benjamin

Re-enter details of the employee
Enter Employee Name: Benjamin
Enter Employee Salary: 8000
Enter Employee ID: 5

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 6

Employee details are-
Name: Benjamin  ID: 5   Salary: 8000
Name: John      ID: 2   Salary: 2500
Name: Ron       ID: 4   Salary: 3000
Name: George    ID: 3   Salary: 4500
Name: Donald    ID: 1   Salary: 6000

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 3

Enter Employee name: George

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 6

Employee details are-
Name: Benjamin  ID: 5   Salary: 8000
Name: John      ID: 2   Salary: 2500
Name: Ron       ID: 4   Salary: 3000
Name: Donald    ID: 1   Salary: 6000

-----------------------------------
MENU
1 ->Add new Employee
2 ->Edit existing Employee details
3 ->Remove Employee
4 ->Search Employee
5 ->Sort Employee Vector
6 ->Display details of all Employees
7 ->Exit
Enter Menu: 7

--------------------------------
Process exited after 211.6 seconds with return value 0
Press any key to continue . . .

*/

#include<iostream>
#include<map>
#include<string>
#include<iomanip>
using namespace std;

int main(){
	//Create a map to store state-population pair
	map<string, long int> population;
	
	while(true){
		int menu;
		cout<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<"1-> Store data in map\n2-> Display data in map\n3-> Get population\n4-> Exit"<<endl;
		cout<<"Enter menu: ";
		cin>>menu;
		switch(menu){
			case 1:{
				//Store data in map
				int recNo;
				cout<<endl;
				cout<<"Enter number of records: ";
				cin>>recNo;
				for(int i = 0; i < recNo ;i++){
					string state;
					long int pop;
					cout<<"Enter state: ";
					cin.ignore();
					getline(cin, state);
					map<string, long int> :: iterator itr;
					itr = population.find(state);
					if(itr != population.end()){
						cout<<state<<" state population is already stored!!"<<endl;
						cout<<"Re-enter state: ";
						getline(cin, state);
					}
					cout<<"Enter population of "<<state<<" : ";
					cin>>pop;
					population.insert(pair<string, long int>(state, pop));
					cout<<endl;
				}
			}
				break;
				
			case 2:{
				//Display data in map
				cout<<endl;
				map<string, long int> :: iterator itr;
				cout<<"State-Population data is-"<<endl;
				for(itr = population.begin(); itr != population.end(); itr++){
					cout<<"State: "<<itr->first<<" Population: "<<itr->second;
					cout<<endl;
				}
			}
				break;
				
			case 3:{
				//Get population of state
				cout<<endl;
				string state;
				cout<<"Enter name of state: ";
				cin.ignore();
				getline(cin, state);
				map<string, long int> :: iterator itr;
				itr = population.find(state);
				if(itr != population.end()){
					cout<<"Population of "<<state<<" is: "<<itr->second;
				}
				else{
					cout<<"State "<<state<<" does not exists in the map!!"<<endl;
				}
			}
				break;
				
			case 4:{
				exit(0);
			}
				break;
		}
	} 
	 
	return 0;
}

/*
OUTPUT:

------------------------------------
1-> Store data in map
2-> Display data in map
3-> Get population
4-> Exit
Enter menu: 1

Enter number of records: 3
Enter state: Madhya Pradesh
Enter population of Madhya Pradesh : 750000

Enter state: Punjab
Enter population of Punjab : 500000

Enter state: Punjab
Punjab state population is already stored!!
Re-enter state: Jharkhand
Enter population of Jharkhand : 95000


------------------------------------
1-> Store data in map
2-> Display data in map
3-> Get population
4-> Exit
Enter menu: 2

State-Population data is-
State: Jharkhand Population: 95000
State: Madhya Pradesh Population: 750000
State: Punjab Population: 500000

------------------------------------
1-> Store data in map
2-> Display data in map
3-> Get population
4-> Exit
Enter menu: 3

Enter name of state: Madhya Pradesh
Population of Madhya Pradesh is: 750000
------------------------------------
1-> Store data in map
2-> Display data in map
3-> Get population
4-> Exit
Enter menu: 4

--------------------------------
Process exited after 65.76 seconds with return value 0
Press any key to continue . . .
*/

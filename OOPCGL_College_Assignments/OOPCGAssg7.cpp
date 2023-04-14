#include<iostream>
using namespace std;

// Template function to perform selection sort on given array

template< class tempDT >

void selectionSort(int menu){
	
	// Declare local variable
	tempDT temp;  // Declare temp variable of template type
	int size, min;
	
	// Accept array size from the user
	cout<<"\nEnter size of array: ";
	cin>>size;
	cout<<endl;
	
	if(menu == 1)
	cout<<"Float array of size- "<<size<<" initialized"<<endl;
	
	if(menu == 2)
	cout<<"Int array of size- "<<size<<" initialized"<<endl;
	
	tempDT arr[size];
	
	// Accept array from the user
	cout<<"Enter elements in array: "<<endl;
	
	for(int i = 0; i < size; i++){
		cout<<"\nEnter element "<<i + 1<<": ";
		cin>>arr[i];
	}
	
	// Display array before performing selection sort
	cout<<"\nArray before sorting is: "<<endl;
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<"\t";
	}

	// Perform selection sort on array
	
	for(int i = 0; i < size; i++){
		
		min = i;
		
		for(int j = i; j < size; j++){
			
			// Compare the arr[i] with every elements after it in the array	
			if(arr[j] < arr[min]){ min = j;}
		
		}
			
		// Put min element of specific iteration at its appropriate place
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		
	}

	// Display array after performing insertion sort
	cout<<endl<<endl;
	cout<<"Array after sorting: "<<endl;
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<"\t";
	}

}


int main(){
	int menu;
	char choice = 'y';
	
	cout<<"    \tMenu:  "<<endl;
	cout<<"For 'float' array   enter-> 1"<<endl;
	cout<<"For 'int'   array   enter-> 2"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<endl;
	
	while(choice == 'y'){
	
	cout<<"\nEnter option no: ";
	cin>>menu;
	
	if(menu == 1){
		selectionSort <float> (1);
		
	}
	
	else if(menu == 2){
		selectionSort <int> (2);
	
	}
	
	else{
		cout<<"Invalid menu opted, Try again!!"<<endl;
	}
	
	cout<<"\n\nEnter y to continue and n to exit : "<<endl;;
	cin>>choice;
	
	if(choice == 'n') break;

	}

return 0;
}

/*
........

OUTPUT:
       Menu:
For 'float' array   enter-> 1
For 'int'   array   enter-> 2
----------------------------------


Enter option no: 1

Enter size of array: 5

Float array of size- 5 initialized
Enter elements in array:

Enter element 1: 18.10

Enter element 2: 19.24

Enter element 3: 7.83

Enter element 4: 22.21

Enter element 5: 19.65

Array before sorting is:
18.1    19.24   7.83    22.21   19.65

Array after sorting:
7.83    18.1    19.24   19.65   22.21

Enter y to continue and n to exit :
y

Enter option no: 2

Enter size of array: 3

Int array of size- 3 initialized
Enter elements in array:

Enter element 1: 11121

Enter element 2: 101

Enter element 3: 11131

Array before sorting is:
11121   101     11131

Array after sorting:
101     11121   11131

Enter y to continue and n to exit :
n

--------------------------------
Process exited after 44.87 seconds with return value 0
Press any key to continue . . .


*/

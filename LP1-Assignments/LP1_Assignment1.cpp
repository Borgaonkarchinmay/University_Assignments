#include<iostream>
#include<thread>
#include<mutex>
#include<map>
using namespace std;


std :: mutex seatResource;
std::mutex printer_mutex ;
bool is_printing = false; 



void wait_print()
{
    while(is_printing)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void printLine(std::string line ){

    if(printer_mutex.try_lock())
    {
        is_printing = true;
        std::cout<<line<<std::endl;
        printer_mutex.unlock();
        is_printing = false; 
    }
    else
    {
        wait_print();
        printLine(line);
    }

}



class TickestBookingSystem{
    int maxSeat= 25;
    int seat_available = maxSeat;
    map<string, int> ticketDB;
public:
    void bookSeat(string , int);    
    void cancelBooking(string ,int);
    void showStatus();
};


void TickestBookingSystem :: bookSeat(string name, int seatCount){
    seatResource.lock();
        
        if(seatCount <= seat_available){
            ticketDB.emplace(name, seatCount);
            seat_available -= seatCount;
            printLine(std :: to_string(seatCount) + " seats booked successfully against Name-> " + name);
            //cout<<seatCount<<" seats booked successfully against Name-> "<<name<<endl;
        }
        else{
            printLine("failed to book!! " + std :: to_string(seatCount) + " seats unavailable");
            //cout<<"failed to book!! "<<seatCount<<" seats unavailable"<<endl;
        }
    
    seatResource.unlock();
}

void TickestBookingSystem :: cancelBooking(string name,int seatCount){
    seatResource.lock();
        
        map<string, int> :: iterator itr = ticketDB.find(name);

        if(itr != ticketDB.end()){
            if(seatCount + seat_available <= maxSeat){
                seat_available += seatCount;
                
                if(seatCount == itr->second){
                    ticketDB.erase(name);
                    printLine(std :: to_string(seatCount) + " booked seats against name-> " + name + " canceled successfully!!");
                    //cout<<seatCount<<" booked seats against name-> "<<name<<" canceled successfully!!"<<endl;
                }
                else if(seatCount < itr->second){
                    itr->second -= seatCount;
                    printLine(std :: to_string(seatCount)+ " booked seats against name-> " + name + " canceled successfully!!");
                    //cout<<seatCount<<" booked seats against name-> "<<name<<" canceled successfully!!"<<endl;
                }
                else
                    printLine("Process failed!\nNo of seats booked against name-> " + name + " are only" + std :: to_string(itr->second));
                    //cout<<"Process failed!\nNo of seats booked against name-> "<<name<<" are only"<<itr->second<<endl;
            }
            else
                printLine("Failed to cancel!! " + std :: to_string(seatCount) + " Not possible");
                //cout<<"Failed to cancel!! "<<seatCount<<" Not possible"<<endl;
        }
        else
            printLine("No bookings available by Name: " + name);
            //cout<<"No bookings available by Name: "<<name<<endl;

    seatResource.unlock();
}

void TickestBookingSystem :: showStatus(){
    seatResource.lock();
        printLine("Available seats: " + std::to_string(seat_available));
        //cout<<"Available seats: "<<seat_available<<endl;
    seatResource.unlock();
}

int main(){
    cout<<endl<<endl;
    cout<<"--------Ticket Booking System----------------"<<endl;
    TickestBookingSystem tc;
    
    int choice = 0;
    printLine("MENU\n1. Show available tickets\n2. Book tickets\n3. Cancel booked ticket\n4. Exit");
    

    while(true){
        printLine("Enter choice: ");
        cin>>choice;
        switch(choice){
            case 1:{
                std::thread t1([&tc]()
                   { tc.showStatus(); });
                
                t1.detach();
                break;
            }
            case 2:{
                //Book seats

                string client_name1;
                int sc1 = 0;
                printLine("Enter name and number of seats to be booked: ");
                cin>>client_name1>>sc1;
                
                std::thread t2([&tc, client_name1, sc1]()
                   { tc.bookSeat(client_name1, sc1); });
                
                t2.detach();
                break;
            }
            case 3:{
                //Cancel booking

                string client_name2;
                int sc2 = 0;
                printLine("Enter name and number of seats to be cancelled: ");
                //cout<<"Enter name and number of seats to be cancelled: ";
                cin>>client_name2>>sc2;
                
                std::thread t3([&tc, client_name2, sc2]()
                   { tc.cancelBooking(client_name2, sc2); });
                
                t3.detach();
                break;
            }
            case 4:{
                return 0;
                break;
            }
        }
        //cout<<"MENU\n1. Show available tickets\n2. Book tickets\n3. Cancel booked ticket\n4. Exit"<<endl;
        
    }
    return 0;
}
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include <iomanip> 

using namespace std;

struct BusinessCard {
    string companyName;
    string address;
    string phoneNumber;
    string workingHours;
    string poc;        
    double priceQuoted; 
};

int main() {
    srand(time(0)); // Seeds the generator so results change every run

    // A pool of potential company names to choose from
    string namePool[] = {"Orange Co", "Tech Co", "Stark Ind", "Face Tech", "Febster Co" };
    string pocPool[] = {"Alex", "Gary", "Karina", "Penny", "John", };
    string addrPool[] = {"223 Orange St", "111 Tech St", "888 Stark Rd", "505 Face Blvd", "653 Febster St"};
    string phonePool[] = {"524-1111", "555-1890", "555-8822", "444-9782", "555-1234"};

    BusinessCard companies[5];

    cout << left << setw(20) << "Company" << setw(15) << "POC" << "Price Quoted" << endl;
    
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        int randomName = rand() % 5;
        int randomPoc = rand() % 5;

        // Assigning random details to the struct
        companies[i].companyName = namePool[i];
        companies[i].poc = pocPool[i];
        companies[i].address = addrPool[i];
        companies[i].phoneNumber = phonePool[i];
        
        companies[i].workingHours = "8am-7pm";
        
        // Task: Price quotes use rand +srand
        companies[i].priceQuoted = (rand() % 701) + 300; 
        
        cout << left << setw(20) << companies[i].companyName 
             << setw(15) << companies[i].poc 
             << "$" << fixed << setprecision(2) << companies[i].priceQuoted << endl;
    }

    // Logic to find the best price
    int winningIndex = 0; 
    for (int i = 1; i < 5; i++) {
        if (companies[i].priceQuoted < companies[winningIndex].priceQuoted) {
            winningIndex = i;
        }
    }

    cout << "\nTHE WINNER IS: " << companies[winningIndex].companyName << " ($" << companies[winningIndex].priceQuoted << ")" << endl;

    return 0;
}
/* ---------------------------------
BEYKOZ UNIVERSITY COMPUTER ENGINEERING
INTRODUCTION TO SOFTWARE ENGINEERING PROJECT
Kiosk Coffee Order
-------------------------------------*/

#include <iostream>
#include <string> //for string
#include <fstream> //for file printing
#include <unistd.h> //for sleep function

using namespace std;

//functions
void addCoffee();
void drinksMenu();
void menu(int choice);

class CoffeeMachine{
public:
    void getInformation(double coffeePrice){ //shows questions for customer
    
        string input_size,answer1,extra;
        price += coffeePrice;
        cout   << "In which size do you want to buy your espresso?/n [S] for small - [M] for medium - [L] for large size..."
                << endl;
        cin >> input_size;

            if ( input_size == "s" ||  input_size == "S") {

                price+= 0.5;

            } else if ( input_size == "m"||  input_size == "M") {

                price+= 1.0;
            } else if ( input_size == "L" ||  input_size == "l") {

                price += 1.5; //adds size price
            }

        cout << "Is there any sauce you'd like to add to it?/n [Y] for yes - [N] for no---" << endl;
        cin >> answer1;
        if (answer1 == "Y" || answer1 == "y") {
            cout << "[a]Soy Milk [b]Vanilla [c]Caramel"<<endl; //sauce choice
            cin >> extra;

           price+= 0.5; //adds extra price

        } else if (answer1 == "N" || answer1 == "n") {
            cout << "Ok." << endl;
        }
        system ("CLS");
        system("color 3");

        cout<< "Your coffee is preparing..."<<endl; //coffee preperation
        sleep(2);

        cout<<"Please take your coffee..."<<endl<<endl;
        cout<<"Your espresso with "<<input_size <<" size"<<endl<<"Enjoy your drink..."<<endl;
        
    }

    void getPrice() {
        cout << "Your payment is: " << price << "$" << endl; // prints final price
    }

private:
    double price = 0;
};

int main() {
    int choice;
    system("color C");
    drinksMenu(); //calls menu from txt
    addCoffee();
    
    return 0;

}

void drinksMenu(){

    ifstream DBFile;

    DBFile.open("drinksMenu.txt");
    string menu_info;
    while ( getline (DBFile, menu_info) )
    {
        cout <<menu_info<< endl; //prints menu txt on screen

    }
}
void menu(int choice) {

    cout<<endl;
    cout << "************" << endl;
    cout << "Welcome to the Asli's Coffee" << endl;
    cout << "************" << endl;
    cout << "What would you like to do?" << endl; //menu choices
    cout << "1. Buy coffee." << endl;
    cout << "2. Exit the program." << endl;
    cin >> choice;
    do
    {
        switch (choice) //for customer
        {
            case 1: addCoffee();
                break;
            case 2: 
			cout << "Goodbye." << endl; //ends program
                break;
           
        }
    } while (choice!= 2); //in case 2 it shut downs program
}

void addCoffee() { //adds coffee
    int choice=0;
    CoffeeMachine coffee;
    int input_coffee;
    double total;

    cout << "---Please select  from the menu your coffee---" << endl; // coffee choice
    cin >> input_coffee;
    switch (input_coffee) {

        case 1:
            total= 3.0; //total of coffee
            break;

        case 2:
            total= 4.0;
            break;

        case 3:
            total= 3.5;
            break;

        case 4:
            total= 4.0;
            break;

    }
    coffee.getInformation(total); //prints price
    coffee.getPrice();
    sleep(2);
    menu(choice); //back to menu
    
}

#include <iostream>
#include <string>
using namespace std;

 
class BankAccount {
    protected: 
        string accountHolder; // name of the account holder 
        double balance; // account balance 
    
    public:
        BankAccount (string name, double initialBalance) : accountHolder(name), balance(initialBalance) {}

        void deposit(double amount) {
            if (amount > 0) {
                balance += amount; 
                cout << "Deposited: $" << amount << " to " << accountHolder << "'s account.\n";
            } else {
                cout << "Invalid deposit amount.\n";
            }
        }

        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount; 
                cout << "Withdrew: $ " << amount << " from " << accountHolder << "'s account.\n";
            } else {
                cout << "Invalid withdrawl amount or insufficient balance.\n";
            }
        }

        void displayBalance() const {
            cout << accountHolder << "'s balance: $" << balance << endl;
        }
};

int main() {
    BankAccount account("Alice", 1000); // Initial balance: $1000

    // Test methods
    account.displayBalance(); 
    account.deposit(200);     
    account.withdraw(150);   
    account.displayBalance(); 

    return 0;

}
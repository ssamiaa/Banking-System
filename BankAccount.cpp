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

        virtual void withdraw(double amount) {
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

        virtual ~BankAccount() {} 
};

class SavingsAccount: public BankAccount {
    private: 
        double interestRate;

    public:
        SavingsAccount(string name, double initialBalance, double rate) : BankAccount(name, initialBalance), interestRate(rate) {}

        void addInterest() {
            double interest = balance * (interestRate / 100); 
            balance += interest; 
            cout << "Interest of $" << interest << " added to " << accountHolder << "'s savings account.\n";
        }
};

class CheckingAccount : public BankAccount {
    private: 
        double overdraftLimit; 
    
    public: 
        CheckingAccount(string name, double initialBalance, double overdraft) : BankAccount(name, initialBalance), overdraftLimit(overdraft) {}

        void withdraw(double amount) override {
            if (amount > 0 && amount <= (balance + overdraftLimit)) {
                balance -= amount; 
                cout << "Withdrew: $" << amount << " from " << accountHolder << "'s checking account.\n";
            } else { 
                cout << "Overdraft limit exceeded or invalid withdrawal amount.\n";            }
        }
};

int main() {
    // Create SavingsAccount and CheckingAccount 
    SavingsAccount savings("Alice", 1000, 5); 
    CheckingAccount checking("Bob", 500, 200); 

    // Test SavingsAccount
    savings.displayBalance();
    savings.deposit(200);
    savings.withdraw(150);
    savings.addInterest();
    savings.displayBalance();

    // Test CheckingAccount
    checking.displayBalance();
    checking.deposit(300);
    checking.withdraw(600); 
    checking.withdraw(500); //overdraft
    checking.displayBalance();

    return 0;

}
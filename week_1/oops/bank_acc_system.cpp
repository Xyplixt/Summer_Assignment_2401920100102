#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
  string ownerName;
  double balance;

public:
  Account(string name, double initialBalance) {
    ownerName = name;
    balance = initialBalance;
  }

  virtual void displayInfo() = 0;

  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      cout << "Deposited: Rs " << amount << endl;
    } else {
      cout << "Invalid deposit amount!" << endl;
    }
  }

  virtual void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      cout << "Withdrawn: Rs " << amount << endl;
    } else {
      cout << "Insufficient balance or invalid amount!" << endl;
    }
  }

  double getBalance() { return balance; }

  virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
  double interestRate;

public:
  SavingsAccount(string name, double balance, double rate)
      : Account(name, balance), interestRate(rate) {}

  void addInterest() {
    double interest = balance * interestRate / 100;
    balance += interest;
    cout << "Interest added: Rs " << interest << endl;
  }

  void displayInfo() override {
    cout << "\n--- Savings Account ---" << endl;
    cout << "Owner   : " << ownerName << endl;
    cout << "Balance : Rs " << balance << endl;
    cout << "Interest: " << interestRate << "%" << endl;
  }
};

class CurrentAccount : public Account {
private:
  double overdraftLimit;

public:
  CurrentAccount(string name, double balance, double limit)
      : Account(name, balance), overdraftLimit(limit) {}

  void withdraw(double amount) override {
    if (amount <= balance + overdraftLimit) {
      balance -= amount;
      cout << "Withdrawn: Rs " << amount << endl;
    } else {
      cout << "Exceeds overdraft limit!" << endl;
    }
  }

  void displayInfo() override {
    cout << "\n--- Current Account ---" << endl;
    cout << "Owner    : " << ownerName << endl;
    cout << "Balance  : Rs " << balance << endl;
    cout << "Overdraft: Rs " << overdraftLimit << endl;
  }
};

int main() {
  SavingsAccount s1("Rahul Sharma", 10000, 6.5);
  CurrentAccount c1("Priya Singh", 5000, 2000);

  s1.displayInfo();
  s1.deposit(3000);
  s1.addInterest();
  s1.withdraw(2000);
  s1.displayInfo();

  c1.displayInfo();
  c1.deposit(1000);
  c1.withdraw(7500);
  c1.displayInfo();

  cout << "\n--- Polymorphism Demo ---" << endl;
  Account *acc;
  acc = &s1;
  acc->displayInfo();
  acc = &c1;
  acc->displayInfo();

  return 0;
}

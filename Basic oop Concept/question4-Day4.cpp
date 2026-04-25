#include<iostream>
using namespace std;
class Account {
	const int accountNumber;
		char* accountHolder;
		double balance;
public:
	Account(int accNum, char aH[], double b) :accountNumber(accNum) {
		accountHolder = new char[strlen(aH) + 1];
		strcpy_s(accountHolder, strlen(aH) + 1, aH);
		balance = b;
		}
	Account(const Account& a):accountNumber(a.accountNumber)
	{
		balance = a.balance;
		accountHolder = new char[strlen(a.accountHolder) + 1];
		strcpy_s(accountHolder, strlen(a.accountHolder) + 1, a.accountHolder);

	}
	int getId() const
	{
		return accountNumber;
	}
	~Account()
	{
		delete[] accountHolder;
		}
	void  deposit(double d)
	{
		balance += d;
	}
	void withdraw(double w)
	{
		if (balance < w)
		{
			cout << "Balance is insufficient:" << endl;
		}
		else {
			balance -= w;
		}
		}
	virtual void display() const {
		cout << "Account Holder Name:" << accountHolder << endl;
		cout << "Balance:" << balance;
		cout << "Account Num:" << accountNumber << endl;
		}
};
class SavingAccount:public Account {
	double interestRate;
public:
	SavingAccount(char name[], int id, double ba, double rate) :Account(id, name, ba) {
		interestRate = rate;
	}
	SavingAccount(const SavingAccount& s):Account(s)
	{
		interestRate = s.interestRate;
	}
	void calculateInterest() {

	 }
	void display() const {
		Account::display();
		cout << "Intesrt Rate:" << interestRate << endl;
		}
};
class Bank {
	const int bankCode;
	 Account** accounts;
	 int totalAccounts;
public:
	Bank(int code, int t) :bankCode(code)
	{
		totalAccounts = t;
		accounts = new Account * [t];
		for (int i = 0; i < t; i++)
		{
			accounts[i] = nullptr;
		}
	}
		void addAccount(Account* ac) {
			for (int i = 0; i < totalAccounts; i++)
			{
				if (accounts[i] == nullptr)
				{
					accounts[i] = ac;
					break;
				}
			}
		}
		void  displayAll() const {
			for (int i = 0; i < totalAccounts; i++)
			{
				if (accounts[i] != nullptr)
				{
					accounts[i]->display();
				}
			}
			}
			void  findAccount(int id) const{
				for (int i = 0; i < totalAccounts; i++)
				{
					if (accounts[i] != nullptr) {
						if (accounts[i]->getId() == id)
						{
							accounts[i]->display();
						}
					}
				}
	}
			~Bank() {
				for (int i = 0; i < totalAccounts; i++)
				{
					delete accounts[i];
				}
				delete[] accounts;
			}
};
int main()
{
	int num;
	double balance;
	const int total = 3;
	SavingAccount* sa[total];
	int rate;

	for (int i = 0; i < total; i++)
	{
		char name[20];
		cout << "Enter Account Holder Name:";
		cin >> name;
		cout << "Enter Balance:";
		cin >> balance;
		cout << "Enter Accout Number:";
		cin >> num;
		cout << "Enter Interst Rate:";
		cin >> rate;
		sa[i] = new SavingAccount(name, num, balance, rate);
	}
	Bank b(1234, 3);
	for (int i = 0; i < total; i++) {
		b.addAccount(sa[i]);
	}
		b.displayAll();
		return 0;

}
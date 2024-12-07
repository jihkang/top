#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include <map>

struct Bank
{
private:
    struct Account {
    private:
        int id;
        int value;
        int loan;
    public:
        Account();
        Account(int id);
        Account(int _id, int _value);
        Account(int _id, int _value, int _loan);
    
    public:
        const int& getMoney() const;
        const int& getId() const;
        const int& getLoan() const;
    };

private:
    int liquidity;

	std::vector<Bank::Account *> clientAccounts;
    std::map<int, int> idForClientsIdx;

public:
    Bank();
    ~Bank();
private:
    Bank::Account* getAccount(int idx);
public:
    void createAccount(int idx, int value = 0, int loan = 0);
    void removeAccount(int idx);
    void pushMoney(int idx, int value = 0);
    bool loanMoney(int idx, int value);
    
    void showMoney(int idx);
    void showAccount(int idx);
public:
    Bank::Account* operator[](int idx);
};

#endif
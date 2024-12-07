
#include "Bank.hpp"

/** inner class For Save Account*/

/// @brief bank inner account struct
Bank::Account::Account() : id(-1), value(0), loan(0) {}
Bank::Account::Account(int id): id(id), value(0), loan(0) {}
Bank::Account::Account(int _id, int _value) : id (_id), value(_value), loan(0) {}
Bank::Account::Account(int _id, int _value, int _loan) : id (_id), value(_value), loan(_loan) {}

const int& Bank::Account::getMoney() const {
    return value;
}
const int& Bank::Account::getId() const {
    return id;
}
const int& Bank::Account::getLoan() const {
    return loan;
}

/// @brief bank struct
Bank::Bank() : liquidity(0) {}
Bank::~Bank() {
    for (unsigned int i = 0; i < this->clientAccounts.size(); i++) {
        delete this->clientAccounts[i];
    }
}
void Bank::createAccount(int idx, int value, int loan) {
        Bank::Account* findAccount = getAccount(idx);
        if (findAccount != NULL) {
            std::cout << "already exist" << std::endl;
            throw("already exist account");
        }

        liquidity = value * 0.05;
        value = value * 0.95;

        idForClientsIdx[idx] = clientAccounts.size() + 1;
        clientAccounts.push_back(new Account(idx, value, loan));
    }
void Bank::removeAccount(int idx) {
        Bank::Account* findAccount = getAccount(idx);
        if (findAccount == NULL)
            return ;

        delete findAccount;
        clientAccounts.erase(clientAccounts.begin() + idForClientsIdx[idx] - 1);
        idForClientsIdx.erase(idx);
    }
void Bank::pushMoney(int idx, int value) {
        if (value == 0)
            return ;

        Bank::Account* findAccount = getAccount(idx);
        int originValue = findAccount->getMoney() + value;
        int loanMoney = findAccount->getLoan();
        
        removeAccount(idx);
        createAccount(idx, originValue, loanMoney);
    }
bool Bank::loanMoney(int idx, int value) {
        if (value > liquidity) {
            std::cout << "you cannot loan money small" << "\n";
            return false;
        }

        Bank::Account* findAccount = getAccount(idx);
        int originValue = findAccount->getMoney();

        removeAccount(idx);
        createAccount(idx, originValue, value);
        liquidity -= value;

        return true;
    }
void Bank::showMoney(int idx) {
        Bank::Account* findAccount = getAccount(idx);
        std::cout << findAccount->getMoney() << "\n";
    }
void Bank::showAccount(int idx) {
        Bank::Account* findAccount = getAccount(idx);
        std::cout << findAccount->getMoney() << ", " << findAccount->getLoan() << "\n";
    }

Bank::Account* Bank::getAccount(int idx) {
        Bank::Account* ret = NULL;
        int accountIdx = idForClientsIdx[idx];
        if (accountIdx == 0) {
            return ret;
        }

        ret = clientAccounts[accountIdx - 1];
        return ret;
    }
Bank::Account* Bank::operator[](int idx) {
        Bank::Account* ret = NULL;
        int clientsIdx = idForClientsIdx[idx];
        if (clientsIdx == 0) {
            throw ("there is no account");
        }

        ret = clientAccounts[clientsIdx - 1];
        return ret;
    }

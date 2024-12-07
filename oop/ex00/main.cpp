#include "Bank.hpp"

int main()
{
    Bank bank;
    try {
        bank.createAccount(10, 1000);
        bank.showAccount(10);
        bank.pushMoney(10, 2000);
        bank.showAccount(10);
        bank.createAccount(10, 2000);
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
    try {
        std::cout << bank[10]->getMoney() << std::endl;
        bank.removeAccount(10);
        bank.createAccount(10, 1000);
        std::cout << bank[10]->getMoney() << std::endl;
        std::cout << bank[1]->getMoney() << std::endl;
        std::cout << bank.loanMoney(3, 300) << std::endl;
    } catch (const char * e){
        std::cout << e << std::endl;
    }
	return (0);
}

#pragma once

// Behavioral - Command Design Pattern - Example-I
// ----------------------------------------------------
// ----------------------------------------------------

#ifdef BEHAVIORAL_COMMAND_EXAMPLE_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<vector> 
#include<functional> 

class Walk {
public:
    void operator()() { 
        std::cout << "walk" << "\n"; 
    }
};

class Run {
public:
    void operator()() { 
        std::cout << "run" << "\n";
    }
};

class macroCommand: public std::vector<std::function<void()>> {
public:
    void operator()() {
        for (auto&& f : *this)
            f();
    }
};

void doIt(std::function<void()> f) {
    f();
}

int main() {

    doIt(Walk{});
    doIt(Run{}); // Temporary object 
    /*
        walk
        run
    */
    macroCommand cardio_workout;
    cardio_workout.push_back(Walk{});
    cardio_workout.push_back(Run{});
    cardio_workout();
    /*
        walk
        run
    */
    
    return EXIT_SUCCESS;
}

#endif // BEHAVIORAL_COMMAND_EXAMPLE_I


// Behavioral - Command Design Pattern - Example-II
// ----------------------------------------------------
// ----------------------------------------------------

#ifdef BEHAVIORAL_COMMAND_EXAMPLE_II 

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class BankAccount {
public:
    int32_t m_balance;

    void deposit(int32_t amount) {
        m_balance += amount;
    }
    void withdraw(int32_t amount) {
        m_balance -= amount;
    }
};

class Command {
public:
    virtual void execute() = 0;
};

class BankAccountCommand : public Command {
public:
    enum class Action : bool { deposit, withdraw };


    BankAccountCommand(BankAccount& bankAccount, Action action, int32_t amount)
        : m_bankAccount(bankAccount), m_action(action), m_amount(amount) {}

    void execute() {
        (m_action == Action::deposit) ? m_bankAccount.deposit(m_amount) : m_bankAccount.withdraw(m_amount);
    }

private:
    BankAccount& m_bankAccount;
    Action m_action;
    int32_t m_amount;
};


int main() {

    BankAccount ba1{};
    BankAccount ba2{};

    std::vector<BankAccountCommand> commands{

        BankAccountCommand{ba1,BankAccountCommand::Action::withdraw, 200},

        BankAccountCommand{ba2,BankAccountCommand::Action::deposit, 200}
    };

    for (auto& cmd : commands)
        cmd.execute();

    std::cout << ba1.m_balance << "\n"; // -200
    std::cout << ba2.m_balance << "\n"; // 200

    return EXIT_SUCCESS;
}

#endif // BEHAVIORAL_COMMAND_EXAMPLE_II

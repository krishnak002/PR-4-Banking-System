 #include <iostream>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    void accDetails()
    {
        cout << endl << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter account holder name: ";
        cin >> accountHolderName;

        cout << "Enter initial/current balance: ";
        cin >> balance;

        cout << "--- Your account is created successfully! ---" << endl;
    }

    void displayAccInfo(int accountType)
    {
        if (accountType == 1)
        {
            cout << endl << "Account Type: Savings Account" << endl;
        }
        else if (accountType == 2)
        {
            cout << endl << "Account Type: Checking Account" << endl;
        }
        else if (accountType == 3)
        {
            cout << endl << "Account Type: Fixed Deposit Account" << endl;
        }
        else
        {
            cout << "Invalid account type!" << endl;
        }

        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << getbalance() << endl;
    }

    void deposit()
    {
        double amount;
        cout << endl << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << endl << "Your amount is deposited.\n--- Your money is deposited successfully ---\nNew balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw()
    {
        double amount;
        cout << endl
             << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << endl << "Your amount is withdrawn.\n--- Your money is withdrawn successfully ---\nNew balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    double getbalance()
    {
        return balance;
    }
};

class SavingsAccount : public BankAccount
{
public:
    void calculateInterest()
    {
        int interestRate;
        cout << endl << "Enter interest rate: ";
        cin >> interestRate;

        double interest = (getbalance() * interestRate) / 100;
        cout << "Interest earned on " << getbalance() << " is " << interest << "." << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    void setOverdraftLimit(double limit)
    {
        overdraftLimit = limit;
        cout << "Overdraft limit: " << overdraftLimit << endl;
    }

    void withdraw()
    {
        double amount;
        cout << endl << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > 0 && amount <= (getbalance() + overdraftLimit))
        {
            double balance = getbalance() - amount;

            cout << endl << "Your amount is withdrawn.\n--- Your money is withdrawn successfully ---\nNew balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    void CalculateInterest()
    {
        int term;
        cout << endl << "Enter term (no. of years): ";
        cin >> term;

        double interest = (getbalance() * term) / 100;
        cout << endl << "You'll get " << interest << " interest on your fixed deposit." << endl;
        cout << "Your total amount after " << term << " years will be: " << getbalance() + interest << endl;
    }
};

int main()
{
    SavingsAccount savingsaccount;
    CheckingAccount checkingaccount;
    FixedDepositAccount fixeddepositaccount;

    int accountType = 0;

    cout << "----------Welcome to our Bank------------" << endl;

    cout << "Please select account type you want to create: " << endl;
    cout << "Press 1 for Savings Account." << endl;
    cout << "Press 2 for Checking Account." << endl;
    cout << "Press 3 for Fixed Deposit Account." << endl;

    cout << endl << "Enter your choice: ";
    cin >> accountType;

    if (accountType == 1)
    {
        savingsaccount.accDetails();
    }
    else if (accountType == 2)
    {
        checkingaccount.accDetails();
    }
    else if (accountType == 3)
    {
        fixeddepositaccount.accDetails();
    }
    else
    {
        cout << "Invalid account type!" << endl;
        return 1;
    }

    int choice;

    do
    {
        cout << endl << "------- MENU -------" << endl;
        cout << "Press 1 to deposit money." << endl;
        cout << "Press 2 to withdraw money." << endl;
        cout << "Press 3 to display account information." << endl;
        cout << "Press 4 to check balance." << endl;
        cout << "Press 5 to exit." << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (accountType == 1)
            {
                savingsaccount.deposit();
                savingsaccount.calculateInterest();
            }
            else if (accountType == 2)
            {
                checkingaccount.deposit();
            }
            else if (accountType == 3)
            {
                fixeddepositaccount.deposit();
                fixeddepositaccount.CalculateInterest();
            }
            break;
        case 2:
            if (accountType == 1)
            {
                savingsaccount.withdraw();
            }
            else if (accountType == 2)
            {
                checkingaccount.withdraw();
            }
            else if (accountType == 3)
            {
                fixeddepositaccount.withdraw();
            }
            break;
        case 3:
            cout << "--- Your account information is displayed successfully! ---" << endl;

            if (accountType == 1)
            {
                savingsaccount.displayAccInfo(accountType);
            }
            else if (accountType == 2)
            {
                checkingaccount.displayAccInfo(accountType);
            }
            else if (accountType == 3)
            {
                fixeddepositaccount.displayAccInfo(accountType);
            }
            break;
        case 4:
            cout << endl
                 << "--- Your balance is displayed successfully! ---" << endl;

            if (accountType == 1)
            {
                cout << "Your balance is: " << savingsaccount.getbalance() << endl;
            }
            else if (accountType == 2)
            {
                cout << "Your balance is: " << checkingaccount.getbalance() << endl;
            }
            else if (accountType == 3)
            {
                cout << "Your balance is: " << fixeddepositaccount.getbalance() << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 5);

    cout << "--- Thank you for using our bank services! ---" << endl;
    cout << "--- Have a good day! ---" << endl;

    return 0;
}
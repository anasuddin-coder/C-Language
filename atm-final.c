// ----------- ATM SYSTEM PROJECT -----------
#include <stdio.h>
#include <string.h>

#define PIN "1234"

// Here receipt printing function i made it
void print-Receipt(const char *type, float amount, float balance)
{
    printf("\n----------- RECEIPT -----------\n");
    printf("Transaction Type: %s\n", type);
    printf("Amount: $%.2f\n", amount);
    printf("Remaining Balance: $%.2f\n", balance);
    printf("-------------------------------\n");
}

int main()
{
    int choice;
    float balance = 1000.0; // initial balance
    float deposit, withdraw;
    char entered_pin[10];
    int attempts = 0;

    // PIN Login Systen in ATM
    while (1)
    {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%s", entered_pin);

        if (strcmp(entered_pin, PIN) == 0)
        {
            printf("Access granted.\n");
            break;
        }
        else
        {
            printf("Incorrect PIN. Try again.\n");
            attempts++;

            if (attempts >= 3)
            {
                printf("Too many incorrect attempts. Exiting...\n");
                return 1;
            }
        }
    }

    // ATM Menu System it will show again and again if user press 4 exit option then the program will end and the recipt will show to user
    while (1)
    {
        printf("\n--- ATM Menu System ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Your current balance is: $%.2f\n", balance);
            break;

        case 2:
            printf("Enter amount to deposit: $");
            scanf("%f", &deposit);

            if (deposit > 0)
            {
                balance += deposit;
                printf("Deposit successful. New balance: $%.2f\n", balance);
                print-Receipt("Deposit", deposit, balance);
            }
            else
            {
                printf("Invalid deposit amount.\n");
            }
            break;

        case 3:
            printf("Enter amount to withdraw: $");
            scanf("%f", &withdraw);
            if (withdraw > 0 && withdraw <= balance)
            {
                balance -= withdraw;
                printf("Withdrawal successful. New balance: $%.2f\n", balance);
                print-Receipt("Withdrawal", withdraw, balance);
            }
            else
            {
                printf("Invalid withdrawal amount or insufficient funds.\n");
            }
            break;

        case 4:
            printf("Thank you for using the ATM. Goodbye! Catch You Later\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

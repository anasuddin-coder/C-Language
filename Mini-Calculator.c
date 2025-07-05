// --------- Menu Based Mini Calculator in C ---------

#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        // Display a menu to user again and again
        printf("\n===== SIMPLE CALCULATOR MENU =====\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        // If user chooses Exit: thats why we added a condition
        if (choice == 5) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        // Input numbers from user
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Perform a task for selected operation
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            default:
                printf("Invalid option. Please choose from 1 to 5.\n");
        }
    }

    return 0;
}

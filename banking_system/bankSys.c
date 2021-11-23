#include <stdio.h>
#include <stdlib.h>

FILE *b;
#define PIN 1234

float readBalance() {
    float balance;
    b = fopen("balance.txt", "r");
    fscanf(b, "%f", &balance);
    fclose(b);
    return balance;
}

void writeBalance(float amount) {
    b = fopen("balance.txt", "w");
    fprintf(b, "%f", amount);
    fclose(b);
}

int withdraw(float amount) {
    if(amount > readBalance()) {
        return 1;
    } else {
        writeBalance(readBalance() - amount);
        return 0;
    }
}

void deposit(float amount) {
    float new_balance = readBalance() + amount;
    b = fopen("balance.txt", "w");
    fprintf(b, "%f", new_balance);
    fclose(b);
}

int main() {
    int user, x;
    float amount;  
    printf("------ATM------\n");
    for(x = 0; x < 3; ++x) {    
        printf("Enter your pin: ");
        scanf("%d", &user);
        if(user == PIN) {
            printf("Welcome, user\n");
	    break;
        } else {
            if(x != 2) {
                printf("Try again\n");
            } else {
                printf("Card is blocked, try again later\n");
                return 0;
            }
        }
    }
    printf(__DATE__);
    printf("\n1.Check Balance\n2.Deposit\n3.Withdraw\n4.Return card\n");
    while(user != 4) {
        printf(">> ");
        scanf("%d", &user);
        switch(user) {
        case 1:
            printf("Balance: %f\n", readBalance());
            break;
        case 2:
            printf("Enter amount you want to deposit: ");
            scanf("%f", &amount);
            deposit(amount);
            printf("Deposit made successfully!\n");
            break;
        case 3:
            printf("Enter the amount you want to withdraw: ");
            scanf("%f", &amount);
            int ver = withdraw(amount);
            if(ver == 0) {
                printf("Withdrawal made successfully\n");
            } else {
                printf("Make sure that you entered an amount\nless or equal than your balanace\n");
            }
            break;
        case 4:
            printf("Thank you for choosing us!\n");
            return 0;
        default:
            printf("Invalid Input\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 100
#define FILENAME "Account.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int accountNumber;
    int balance;
    int transactionCount;
} Account;

void deposit_money(Account *account, FILE *ptr);
void withdraw_money(Account *account, FILE *ptr);
void transfer_money(Account *account, FILE *ptr);
void checkDetail(Account *account);
void transaction_details(Account *account, FILE *ptr);
void menu();
int findAccountByName(char *name);
void createNewAccount(Account *newAccount, char *name);
void divider();

void divider() {
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
}

int findAccountByName(char *name) {
    FILE *ptr = fopen(FILENAME, "r");
    if (ptr == NULL) {
        return 0; // File does not exist
    }

    Account temp;
    while (fread(&temp, sizeof(Account), 1, ptr)) {
        if (strcmp(temp.name, name) == 0) {
            fclose(ptr);
            return 1; // Account found
        }
    }

    fclose(ptr);
    return 0; // Account not found
}

void createNewAccount(Account *newAccount, char *name) {
    srand(time(NULL));
    newAccount->accountNumber = rand(); // Generate a random account number
    strcpy(newAccount->name, name);
    newAccount->balance = 0;
    newAccount->transactionCount = 0;
}

int main() {
    char name[MAX_NAME_LENGTH];
    printf("Enter Account holder name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character

    int accountExists = findAccountByName(name);

    FILE *ptr = fopen(FILENAME, "a+");
    if (ptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    Account currentAccount;

    if (accountExists) {
        // Account exists, load the existing account details
        while (fread(&currentAccount, sizeof(Account), 1, ptr)) {
            if (strcmp(currentAccount.name, name) == 0) {
                break;
            }
        }
    } else {
        // Account does not exist, ask if the user wants to create a new account
        char response;
        printf("No account found for %s. Do you want to create a new account? (y/n): ", name);
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y') {
            createNewAccount(&currentAccount, name);
            fwrite(&currentAccount, sizeof(Account), 1, ptr);
        } else {
            fclose(ptr);
            printf("No account found. Exiting...\n");
            return 0;
        }
    }

    fclose(ptr);

    while (1) {
        menu();
        int ch;
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        ptr = fopen(FILENAME, "r+");
        if (ptr == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        switch (ch) {
            case 1:
                deposit_money(&currentAccount, ptr);
                break;
            case 2:
                withdraw_money(&currentAccount, ptr);
                break;
            case 3:
                transfer_money(&currentAccount, ptr);
                break;
            case 4:
                checkDetail(&currentAccount);
                break;
            case 5:
                transaction_details(&currentAccount, ptr);
                break;
            case 6:
                fclose(ptr); // Close the file before exiting
                exit(0);
            default:
                printf("**** Invalid choice ****\n");
        }

        fclose(ptr); // Close the file after each transaction
    }

    return 0;
}

void menu (){
    divider ();
    printf ("\n\tMENU\n");
    divider ();
    printf ("\nl.Deposit Money\n");
    printf ("2.Withdraw Money \n");
    printf ("3.Transfer Money \n");
    printf ("4.Account details\n"); 
    printf ("5.Transaction details\n");
    printf ("6.Exit\n");
    divider ();
}

void deposit_money(Account *account, FILE *ptr) {
    time_t tm;
    time(&tm);

    printf("\t**** DEPOSITING MONEY ****\n");
    divider();
    printf("\nEnter the amount you want to deposit : ");
    int dip_amt;
    scanf("%d", &dip_amt);

    account->balance += dip_amt;
    printf("*** Money Deposited ***\n");
    printf("Now balance : %d\n", account->balance);

    fseek(ptr, ftell(ptr) - sizeof(Account), SEEK_SET);
    fwrite(account, sizeof(Account), 1, ptr);

    // Append the transaction details
    fprintf(ptr, "\nRs%d had been deposited to your account \n", dip_amt);
    fprintf(ptr, "Date/Time of transaction : %s\n", ctime(&tm));
    account->transactionCount++;
}

void withdraw_money(Account *account, FILE *ptr) {
    time_t tm;
    time(&tm);

    printf("\t**** WITHDRAWING MONEY ****\n");
    divider();
    printf("\nEnter the amount you want to withdraw : ");
    int with_amt;
    scanf("%d", &with_amt);

    if (account->balance < with_amt) {
        printf("*** Insufficient balance ***\n");
    } else {
        account->balance -= with_amt;
        printf("**** Money withdrawn ****\n");
        printf("Current balance : %d\n", account->balance);

        fseek(ptr, ftell(ptr) - sizeof(Account), SEEK_SET);
        fwrite(account, sizeof(Account), 1, ptr);

        // Append the transaction details
        fprintf(ptr, "\nRs%d had been withdrawn from your account \n", with_amt);
        fprintf(ptr, "Date/Time of transaction : %s\n", ctime(&tm));
        account->transactionCount++;
    }
}

void transfer_money(Account *account, FILE *ptr) {
    time_t tm;
    time(&tm);

    printf("\t**** TRANSFERRING MONEY ****\n");
    divider();

    printf("\nEnter the account no. in which you want to transfer the money : ");
    int trans_amt, ac;
retake:
    scanf("%d", &ac);

    if (ac == account->accountNumber) {
        printf("ERROR - Transferring to own account! Enter a valid account number of someone : ");
        goto retake;
    }

    printf("\nEnter the amount you want to transfer : ");
    scanf("%d", &trans_amt);

    if (account->balance < trans_amt) {
        printf("*** You have insufficient balance ***\n");
    } else {
        account->balance -= trans_amt;
        printf("*** Money Transferred ***\n");
        printf("Current balance : %d\n", account->balance);

        fseek(ptr, ftell(ptr) - sizeof(Account), SEEK_SET);
        fwrite(account, sizeof(Account), 1, ptr);

        // Append the transaction details
        fprintf(ptr, "\nRs %d had been transferred from your account to %d\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction : %s\n", ctime(&tm));
        account->transactionCount++;
    }
}

void checkDetail(Account *account) {
    printf("\n\t\tACCOUNT DETAILS\n");
    divider();
    printf("\n");
    printf("Name : %s\n", account->name);
    printf("Account No. : %d\n", account->accountNumber);
    printf("Total balance = %d\n", account->balance);
    printf("%d transactions have been made from your account till now.\n", account->transactionCount);
}

void transaction_details(Account *account, FILE *ptr) {
    printf("\n\tTRANSACTION DETAILS\n");
    divider();
    printf("\n");
    // Rewind the file to the beginning
    rewind(ptr);

    Account temp;
    while (fread(&temp, sizeof(Account), 1, ptr)) {
        if (temp.accountNumber == account->accountNumber) {
            break;
        }
    }

    // Consume the '\n' character after reading the account details
    fgetc(ptr);

    // Move the file pointer to the start of the transactions for the current account
    fseek(ptr, -((long)sizeof(Account)), SEEK_CUR);
    while (fgetc(ptr) != '\n') {
        // Move the file pointer to the start of the next line
    }

    char c;
    int lines = 0;
    while ((c = fgetc(ptr)) != EOF) {
        putchar(c);
        if (c == '\n') {
            lines++;
        }
    }

    if (lines == 0) {
        printf("\n****** NO RECENT TRANSACTION ******\n");
    }

    printf("\n");
}

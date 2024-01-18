
/* 
Hello visitor ! This code of mine that I wrote in first semester is on Bank management system that allow a bank 
customer to perform the necessary requirements like creating an account, deposits, withdrawal, transfer of money, 
getting account details and getting transaction history. Here we will use "Account.txt" as our database to store the information
If you are new to these concept don't worry you don't need to create any file name "Account.txt", instead it will be created 
automatically on your first run of code. 
             
ITS A VERY SIMPLE AND PLEASURABLE CODE ! Check out below. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> 

char *name;
int dip_amt, amt = 100000, acc_no, ac, count = 0; 
int trans_amt;
int with_amt;

void deposit_money();
void withdraw_money(); 
void transfer_money();
void checkDetail();
void LastDetail();
void transaction_details ();
void menu();

void divider(){
    for (int i = 0; i < 50; i++){
        printf ("-");
    }
}

int main (){
    FILE *ptr = fopen ("Account.txt", "w");
    int ch;
    printf ("Account Holder name : ");
    fgets(name,sizeof(name),ptr);
    fprintf (ptr, "\nName : %s\n", name);
    printf ("Enter your account no. : ");
    scanf ("%d", &acc_no);
    fprintf(ptr,"Account no. : %d\n", acc_no);
    fclose(ptr);

    while (1){
        menu() ;
        printf ("\nEnter your choice : ");
        scanf ("%d", &ch);
        switch (ch){
        case 1:
            deposit_money() ;
            break;
        case 2:
            withdraw_money();
            break;
        case 3:
            transfer_money();
            break;
        case 4:
            checkDetail();
            break;
        case 5:
            transaction_details();
            break;
        case 6:
            LastDetail();
            exit (0);
        default:
            printf("**** Invalid choice ****");
        }
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

void deposit_money(){
    time_t tm;
    time (&tm);
    FILE *ptr = fopen ("Account.txt", "a");
    printf("\t**** DEPOSITING MONEY ****\n");
    for (int i = 0; i < 50; i++){
        printf ("-");
    }
    printf ("\nEnter the amount you want to deposit : "); 
    scanf ("%d", &dip_amt);
    amt += dip_amt;
    printf ("\t*** Money Deposited ***\n"); 
    printf ("Now balance : %d\n", amt);
    fprintf (ptr, "\nRs%d had been deposited to your account \n", dip_amt);
    fprintf (ptr, "Date/Time of transaction : %s\n", ctime (&tm)); 
    count++;
    fclose (ptr);
    printf ("\n\nPress any key to view menu.\n");
    getch();
}

void withdraw_money(){
    time_t tm;
    time (&tm);
    FILE *ptr = fopen ("Account.txt","a");
    printf("\t**** WITHDRAWING MONEY ****\n");
    for (int i = 0; i < 50; i++){
        printf ("-");
    }
    printf ("\nEnter the amount you want to withdraw : "); 
    scanf ("%d",&with_amt);
    if (amt < with_amt){
        printf ("*** Insufficient balance ***\n");
    }
    else{
        amt = amt - with_amt;
        printf("**** Money withdrawn ****\n");
        printf ("Current balance : %d\n", amt);
        fprintf (ptr,"\nRs%d had been withdrawn from your account \n", with_amt);
        fprintf (ptr,"Date/Time of transaction : %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("\n\nPress any key to view menu.\n");
    getch();
}

void transfer_money(){
    time_t tm;
    time (&tm);
    FILE *ptr = fopen("Account.txt","a");
    printf("\t**** TRANSFERRING MONEY ****\n");
    for (int i = 0; i < 50; i++){
        printf ("-");
    }

    printf ("\nEnter the account no. in which you want to transfer the money : ");
    retake:
    scanf ("%d", &ac);
    if(ac == acc_no){
        printf("\nERROR - Transferring to own account ! Enter valid account of someone :  ");
        goto retake;
    }
    printf ("\nEnter the amount you want to transfer : ");
    scanf ("%d", &trans_amt);

    if (amt < trans_amt){
        printf ("\t *** You have not sufficient balance ***\n");
    }
    else{
        amt = amt - trans_amt;
        printf ("\t*** Money Transferred ***\n"); 
        printf ("Current balance : %d\n", amt);
        fprintf (ptr,"\nRs %d had been transferred from your account to %d\n", trans_amt, ac);
        fprintf (ptr,"Date/Time of transaction : %s\n", ctime (&tm));
        count++;
    }
    fclose(ptr);
    printf ("\n\nPress any key to view menu.\n");
    getch ();
}

void checkDetail ()
{
    printf("\n\t\tACCOUNT DETAILS \n");
    for (int i = 0; i < 35; i++){
        printf ("-");
    }   
    printf ("\nInName : %s\n", name);
    printf ("Account No. : %d\n", acc_no);
    printf ("Total balance = %d\n",amt);
    printf ("%d transactions have been made from your account till now. \n", count);
    printf ("\n\nPress any key to view menu.\n");
    getch();
}

void transaction_details(){
    FILE *ptr;
    ptr=fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF){
        printf (" TRANSACTION DETAILS \n");
        divider ();
        printf ("\n ****** NO RECENT TRANSACTION ****** \n");
    }
    else{
        printf ("TRANSACTION DETAILS\n");
        divider ();
        printf ("\n%d transactions have been made from your account \n", count);
        while (c != EOF){   // EOF = END OF FILE
            printf ("%c",c);
            c = fgetc(ptr);
        }
        printf("\n\nEnter any key to view the menu.\n");
        getch ();
    }
}

void LastDetail(){
    printf ("\n\n ACCOUNT DETAILS at the end\n");
    for (int i=0;i<50;i++){
        printf ("-");
    }
    printf ("\nName : %s\n", name);
    printf ("Account No. : %d\n", acc_no);
    printf ("Total balance = %d\n ", amt);
    printf ("\n\nPress any key to exit.");
    getch();
}

/* 
Hello visitor! This code project - that I wrote in my first semester is on IRCTC reservation system. The aim of this code is to 
help any passenger or organisation with the reservation data that will be stored in "myfile.txt" as database. Here we've used
structure a user defined data-type to deal with different kinds of information of a passenger.
5 Functionalities of this code are as follow :
1. PNR Search.
2. List of passengers with in a coach with different berth.
3. Find out List of senior passengers.
4. List of all passengers.
5. Passengers under waiting list.

NOTE : NOTE THAT OUR DATABASE HAS 50 PASSENGER DETAILS and 13 coach. If any error encounters cross check if you are maintaining
the file "myfile.txt" properly <it is available in same GitHub repo> . Data in the file is in order 
<Pnr> <name> <age> <coach> <berth> <boardingPoint> <destination> for persons under waiting list berth is zero.
      
*/

#include<stdio.h>
struct passenger{
	int pnr;
	char name[25];
	int age;
 	int bearth;
	int coach;
	char start[10];
	char stop[10];
};


void one(struct passenger[],int);
void two(struct passenger[],int);
void three(struct passenger[],int);
void four(struct passenger[],int);
void five(struct passenger[],int);
void printpassenger(struct passenger[],int );


int main(){
    int n,i,q;
	struct passenger o[50];
	FILE *p;
	p=fopen("myfile.txt","r");
	fscanf(p,"%d",&n);
	for(i=0;i<n;i++){
		fscanf(p,"%d%s%d%d%d%s%s",&o[i].pnr,o[i].name,&o[i].age,&o[i].coach,&o[i].bearth,o[i].start,o[i].stop);
	}

	while(q){
		printf("WHAT WOULD YOU LIKE TO PERFORM. PRESS CORRESPONDING NUMBER -\n");
		printf("\t 1 for PNR search\n");
		printf("\t 2 for list of passengers with different berths in a coach\n");
		printf("\t 3 for senior passengers list\n");
		printf("\t 4 for list of passengers in a coach\n");
		printf("\t 5 for waiting list passenger names\n");
		printf("\t 6 to exit\n");
		printf("ENTER THE NUMBER TO PERFORM THE OPERATION : ");
		scanf("%d",&q);
		printf("\n");
		if(q==1){
		one(o,n);
		printf("\nTHANK YOU \n \n \n");
		continue;
		}
		else if(q==2){
		two(o,n);
		printf("\nTHANK YOU \n \n \n");
		continue;
		}
		else if(q==3){
		three(o,n);
		printf("\nTHANK YOU \n \n \n");
		continue;
		}
		else if(q==4){
		four(o,n);
		printf("\nTHANK YOU \n \n \n");
		continue;
		}
		else if(q==5){
		five(o,n);
		printf("\nTHANK YOU \n \n \n");
		continue;
		}
		else{
		printf("\nTHANK YOU \n \n \n");
		break;
		}	
	}
	return 0;
}

void printpassenger(struct passenger o[],int i){
	printf("%d	%s	%d	%d	%d	%s     %s\n",o[i].pnr, o[i].name, o[i].age, o[i].coach, o[i].bearth, o[i].start, o[i].stop);
}

void one(struct passenger o[],int n){
	int x,i,j=0;
    printf("ENTER PNR NO. ");
    scanf("%d",&x);
    for(i=0;i<n;i++) {
        if(o[i].pnr==x){
        printf("%d is pnr of %s. Details are as follow.\n",x,o[i].name);
		printf("PnrNo.	Name	Age	Coach	Berth	Start	Stop\n");
        printpassenger(o,i);
        j++;
        break;
        }
    }
    if(j==0)
    printf("PNR - %d NOT FOUND , ",x);
}

void two(struct passenger o[],int n){
	int i,m;
	printf("Enter coach number : ");
	scanf("%d",&m);
	printf("PASSENGERS WITH LOWER BIRTH ARE : \n");
	printf("PnrNo.	Name	Age	Coach	Berth	Start	Stop\n");
	for(i=0;i<n;i+=3) {
		if(o[i].coach==m && o[i].bearth != 0){
			printpassenger(o,i);
		}
	}
	printf("PASSENGERS WITH MIDDLE BERTH ARE : \n");
	printf("PnrNo.	Name	Age	Coach	Berth	Start	Stop\n");
	for(i=1;i<n;i+=3) {
		if(o[i].coach==m && o[i].bearth != 0)
			printpassenger(o,i);
	}
	printf("PASSENGERS WITH UPPER BERTH ARE :\n");
	printf("PnrNo.	Name	Age	Coach	Berth	Start	Stop\n");
	for(i=2;i<n;i+=3) {
		if(o[i].coach==m && o[i].bearth != 0)
			printpassenger(o,i);
	}
}

void three(struct passenger o[],int n){
	int i;
    printf("\nLIST OF SENIOUR CITIZENS (i,e. age>60) ARE : \n");
	printf("PnrNo.	Name	Age	Coach	Berth	Start	Stop\n");
    for(i=0;i<n;i++){	
        if(o[i].age>60)
        printpassenger(o,i);
    }	
}

void four(struct passenger o[],int n){
	int i,m;
	printf("enter coach number : ");
	scanf("%d",&m);
	printf("PnrNo.	Name	Age	Coach	Berth	Start	Stop\n");
	for(i=0;i<n;i++){
		if(o[i].coach==m && o[i].bearth != 0)
		printpassenger(o,i);
	}
}

void five(struct passenger o[],int n){
	int i;
	printf("PnrNo.	Name	Age	Coach	Berth	Start	Stop\n");
	for(i=0;i<n;i++){
		if(o[i].bearth==0)
		printpassenger(o,i);
	}
	printf("\n\n Since these passengers are in waiting list, Berth is showing zero.");
	printf("\n But we are showing highest probable coach he/she may get.");
}
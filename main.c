#include <stdio.h>
#include <stdlib.h>
#define MAXPATIENTS 100

void patientRegistration();
void bedAvailability ();
void bedStatusDisplay();


char name[MAXPATIENTS][50];
int age[MAXPATIENTS];
int emergency[MAXPATIENTS];
int specialtySelection[MAXPATIENTS];
int admission[MAXPATIENTS];
int ward[MAXPATIENTS];
int days[MAXPATIENTS];
int patientCount = 0;
char specialtyName[4][50]={
"General Practice(OPD)",
"Paediatrics",
"Cardiology",
"Neurology"
};
int consultFee[4]={1500, 2500,4500,5000};
int consultTime[4]={15,20,30,30};
int dailyCap[4]={30,20,12,10};
char wardName[4][50]={
"General Ward",
"Paediatric Ward",
"Surgical Ward",
"ICU(Intensive care unit)",
};
int dailyBedRate[4]={3000,6000,12000,25000};
int bedCapacity[4]={20,10,10,5};
int bedOccupancy[4][20];

int main()
{
     int choice=0;
     bedAvailability();
    do {
    printf("====================================\n");
    printf("      SMART HOSPITAL SYSTEM\n");
    printf("====================================\n");
    printf("1.Register Patient\n");
    printf("2.Display Bed Status\n");
    printf("3.Emergency Priority\n");
    printf("4.Generate Report\n");
    printf("5.Exit\n");
    printf("Enter your choice(1-5) :");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
             patientRegistration();
             break;
        case 2:
             bedStatusDisplay();
             break;
        case 3:
             break;
        case 4:
             break;
        case 5:
            printf("Exiting program\n");
             break;
        default:
            printf("Invalid input");
    }

    } while (choice!=5);
    return 0;
}

void patientRegistration()
{
    printf("    Patient Registration\n");
    printf("============================\n");
    printf("Enter patient name:");
    scanf(" %[^\n]", name[patientCount]);
    printf("Enter age:");
    scanf("%d", &age[patientCount]);
    printf("Enter urgency level (1-Normal, 2-Urgent, 3-Critical):");
    scanf("%d", &emergency[patientCount]);
    printf("Enter specialty ID (1-4):");
    scanf("%d", &specialtySelection[patientCount]);
    printf("Is the patient admitted? (1-Yes, 0-No):");
    scanf("%d", &admission[patientCount]);

    if(admission[patientCount] == 1)
    {
        printf("Enter ward ID (1-4):");
        scanf("%d", &ward[patientCount]);
        printf("Enter admitted days:");
        scanf("%d", &days[patientCount]);
    }
    else
    {
        ward[patientCount] = 0;
        days[patientCount] = 0;
    }

    patientCount++;

    printf("Patient registration done.\n");
}

void bedAvailability()
{
    int i, j;
    for (i=0;i<4;i++)
    {
        for (j=0;j<bedCapacity[i];j++)
        {
            bedOccupancy[i][j]=0;
        }
    }
    
}

void bedStatusDisplay()
{
    int i=0,j=0;
    printf("       Bed Status\n==============================\n");
    for(i=0;i<4;i++)
    {
        printf("%s\n", wardName[i]);
        for (j=0;j<bedCapacity[i];j++)
        {
         if (bedOccupancy[i][j]==0)
         {
             printf("Bed %2d : Available\n", j+1);
         }
         else
         {
             printf("Bed %2d: Unavailable\n", j+1);
         }
        }
    }
}



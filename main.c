#include <stdio.h>
#include <stdlib.h>
#define MAXPATIENTS 100

void patientRegistration();

char name[MAXPATIENTS][50];
int age[MAXPATIENTS];
int emergency[MAXPATIENTS];
int specialtySelection[MAXPATIENTS];
int admission[MAXPATIENTS];
int ward[MAXPATIENTS];
int days[MAXPATIENTS];
int patientCount = 0;
int main()
{
     int choice=0;
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


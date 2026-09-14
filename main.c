#include <stdio.h>
#include <stdlib.h>

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

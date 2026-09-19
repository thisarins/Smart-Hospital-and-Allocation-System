#include <stdio.h>
#include <stdlib.h>
#define MAXPATIENTS 100

void patientRegistration();
void bedAvailability ();
void bedStatusDisplay();
void selectBed();
void estimateWaitingTime();
void generateBill();
void generateReport();


char name[MAXPATIENTS][50];
int age[MAXPATIENTS];
int emergency[MAXPATIENTS];
int specialtySelection[MAXPATIENTS];
int admission[MAXPATIENTS];
int ward[MAXPATIENTS];
int days[MAXPATIENTS];
int patientCount = 0;
int bedNo[MAXPATIENTS];
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
             generateReport();
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
    printf("Enter specialty ID (1-OPD, 2-Paediatrics, 3-Cardiology, 4-Neurology):");
    scanf("%d", &specialtySelection[patientCount]);
    printf("Is the patient admitted? (1-Yes, 0-No):");
    scanf("%d", &admission[patientCount]);

    if(admission[patientCount] == 1)
    {
        printf("Enter ward ID (1-General, 2-paediatric, 3-surgical, 4-ICU):");
        scanf("%d", &ward[patientCount]);
        printf("Enter admitted days:");
        scanf("%d", &days[patientCount]);
        selectBed();

    }
    else
    {
        ward[patientCount] = 0;
        days[patientCount] = 0;
    }
     generateBill();
     estimateWaitingTime();
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
void selectBed()
{
    int i;
    for(i=0;i<bedCapacity[ward[patientCount]-1];i++)
    {
        if (bedOccupancy[ward [patientCount]-1][i]==0)
        {
            bedOccupancy[ward [patientCount] - 1][i]=1;
            printf(" %d Bed Selected\n",i+1);
            return;
        }
    }

    printf("No Available Beds\n");
    }
 void estimateWaitingTime()
    {
        int i,currentQueue=0,currentSpecialty;
        currentSpecialty=specialtySelection[patientCount];
        for(i=0;i<patientCount;i++)
        {
            if(currentSpecialty==specialtySelection[i])
            {
                currentQueue++;
            }
        }
        float waitingTime;
        waitingTime = currentQueue*consultTime[currentSpecialty-1];
        printf("Estimated Waiting Time   : %.2f\n", waitingTime);
    }

void generateBill()
{
    double surcharge, baseFee,discount, wardFee;
    printf("   SMART HOSPITAL ADMISSION & BILL\n===============================================\n");
    printf("Patient ID               :PAT-%4d\n",1000+patientCount);
    printf("Patient Name             :%s\n",name[patientCount]);


    if (age[patientCount]<5||age[patientCount]>65){
        printf("Patient Age              :%d (15%%Subsidy Eligible)\n", age[patientCount]);
    }
    else{
        printf("Patient Age              :%d\n", age[patientCount]);
    }
    printf("Specialty                :%s\n",specialtyName[specialtySelection[patientCount]-1]);


    if (admission[patientCount]==1){
        printf("Assigned Ward            :%s (Bed %2d)\n",wardName[ward[patientCount]-1],bedNo[patientCount]);
        wardFee=days[patientCount]*dailyBedRate[ward[patientCount]-1];
    }

    else{
        printf("Assigned Ward            :Not admitted\n");
        wardFee=0;
    }

     baseFee=consultFee[specialtySelection[patientCount]-1];
    if (emergency[patientCount]==1){
        printf("Urgency Level            :Level 1 (Normal)\n");
        surcharge=0;
    }
    else  if (emergency[patientCount]==2){
        printf("Urgency Level            :Level 2 (Urgent)\n");
        surcharge=baseFee*0.2;
    }
    else{
        printf("Urgency Level            :Level 3 (Critical)\n");
        surcharge=baseFee*0.5;
    }

    double grossBill=baseFee+surcharge+wardFee;
    if (age[patientCount]<5||age[patientCount]>65){
        discount=grossBill*0.15;
    }

    printf("\n------------------------------------------------\n");
    printf("Base Counsultation Fee   :LKR %.2f\n",baseFee);
    if (emergency[patientCount]==1){
    printf("Emergency Surcharge      :LKR %.2f(0%%)\n",surcharge);
    }
    else if (emergency[patientCount]==2)
    {
      printf("Emergency Surcharge      :LKR %.2f(20%%)\n",surcharge);
    }
    else {
        printf("Emergency Surcharge      :LKR %.2f(50%%)\n",surcharge);
    }

    printf("Ward Stay Cost(%d Days)   :LKR %.2f\n",days[patientCount],wardFee);
    printf("\n------------------------------------------------\n");
    printf("Gross Bill               :LKR %.2f\n",grossBill);
    printf("Age Subsidy Discount     :LKR %-.2f\n",discount);
    printf("Final Payable Amount     :LKR %.2f\n",grossBill-discount);
}
void generateReport()
{
    int normal=0,urgent=0,critical=0,i,highestPatient,j;
    double surcharge,wardFee,grossBill, discount,baseFee,finalBill;
    double totalRevenue=0,totalDiscount=0,highestBill=0;
    printf("    Performance Report\n------------------------------------\n");
    printf("Total Patients  : %d\n", patientCount);

    for(i=0;i<patientCount;i++)
    {
        if (emergency[i]==1){
            normal++;
        }
        if (emergency[i]==2){
            urgent++;
        }
        if (emergency[i]==3){
            critical++;
        }

    }
    for (i=0;i<patientCount;i++)
    {
          baseFee=consultFee[specialtySelection[i]-1];
        if (emergency[i]==1){
            surcharge=0;
        }
        if (emergency[i]==2){
            surcharge=baseFee*0.2;
        }
        if (emergency[i]==3){
            surcharge=baseFee*0.5;
        }

        if (admission[i]==1)
            {
             wardFee=days[i]*dailyBedRate[ward[i]-1];
            }
        else{
            wardFee=0;
        }

         grossBill=baseFee+surcharge+wardFee;
        if (age[i]<5||age[i]>65)
        {
            discount= grossBill*0.15;
        }
        else {
            discount=0;
        }
        finalBill=grossBill-discount;

        totalRevenue+=finalBill;
        totalDiscount+=discount;
        if (finalBill>highestBill){
            highestBill=finalBill;
            highestPatient=i;
        }

    }
    printf("Number of Normal Patients    : %3d\n", normal);
    printf("Number of Urgent Patients    : %3d\n", urgent);
    printf("Number of Critical Patients  : %3d\n", critical);
    printf("Total Revenue                : %.2f\n",totalRevenue);
    printf("Total Discount               : %.2f\n",totalDiscount);
    printf("Highest paying patient name  : %s\n",name[highestPatient]);
    printf("Highest Bill                 : %.2f\n",highestBill);


    for(i = 0; i < 4; i++)
    {   int selected;
        selected = 0;
        for(j = 0; j < bedCapacity[i]; j++)
        {
            if(bedOccupancy[i][j] == 1){
                selected++;
            }
        }
printf("Bed Occupancy %15s: %.2f%%\n",wardName[i],(selected * 100.00) / bedCapacity[i]);
    }
}




int menu()
{
    printf("\tWelcome to Smart Hospital & Resource Allocation System\n\nHow can I help you? Enter the choice number.\n");
    printf("1. Lookup Data & Bed Occupancy Matrix\n2. Patient Intake & Data Input\n3. Search and Sort\n4. Bill\n5. Performance Reports & Analytics\n6. Save\n7. Exit\n");
    int x;
    scanf("%d",&x);
    printf("\n");
    return x;
}

void lookups(int beds[4][20]) {
    int i,j;
struct Specialty specialties[] = {
    {1, "General Practice (OPD)", 1500.00, 15, 30},
    {2, "Paediatrics",             2500.00, 20, 20},
    {3, "Cardiology",              4500.00, 30, 12},
    {4, "Neurology",               5000.00, 30, 10}
};

printf("ID\tSpecialty\t\t  Fee\t\tTime(min)\tCap\n");
printf("-------------------------------------------------------------------\n");

    for (i = 0; i < 4; i++) {
        printf("%d\t%-25s %.2f\t%d\t\t%d\n",
               specialties[i].id,
               specialties[i].name,
               specialties[i].fee,
               specialties[i].consultationTime,
               specialties[i].dailyPatientCap);
    }
    printf("\n\n");
    struct Ward wards[] = {
    {1, "General Ward",             3000.00, 20},
    {2, "Paediatric Ward",          6000.00, 10},
    {3, "Surgical Ward",           12000.00, 10},
    {4, "ICU (Intensive Care Unit)", 25000.00, 5}
};
printf("Ward ID\tWard Name\t\t\tDaily Rate\tCapacity\n");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < 4; i++) {
        printf("%d\t%-30s %.2f\t\t%d\n",
               wards[i].wardID,
               wards[i].wardName,
               wards[i].dailyBedRate,
               wards[i].totalBedCapacity);
    }
printf("\n\n\tBeds Occupancy\n\n");

for(i=0;i<4;i++)
{
   if (i==0) {
    for(j=0;j<20;j++)
    {
        printf("%d ",beds[i][j]);
    } }

    else if (i==1 || i==2)  {
    for(j=0;j<10;j++)
    {
        printf("%d ",beds[i][j]);
    } }

    else  {
    for(j=0;j<5;j++)
    {
        printf("%d ",beds[i][j]);
    } }
        printf("\n");
}
}

char* patientName()
{
    static char name[50];
    while (getchar() != '\n');
    printf("Enter Patient's Name : ");
    fgets(name,50,stdin);
    return name;
}
int patientAge()
{
    int age;
    printf("\nEnter Patient's Age : ");
    scanf("%d",&age);
    return age;
}
int emergencyLevel()
{
    int level;
    printf("1 = Normal\n2 = Urgent\n3 = Critical\n\nEnter the Emergency/Triage Level : ");
    scanf("%d",&level);
    if (level==1 || level==2 || level==3)
    {return level;}
    else {return 0;}
}
int specialtySelection()
{
    int spec;
    printf("Enter the Specialty(1-4) : ");
    scanf("%d",&spec);
    return spec;
}
int isAdmittedToWard()
 {
    int admitted;
    printf("Enter if Admitted to Ward(1) or Not(0) : ");
    scanf("%d",&admitted);
    return admitted;
}
void inputWardID_and_Days(int idAndDays[2])
{
    printf("Enter Ward ID : ");
    scanf("%d",&idAndDays[0]);
    printf("Enter the no of Days: ");
     scanf("%d",&idAndDays[1]);
}

int estimatedWaitingTime(int specialty)
{
    int time;
    switch(specialty)
    {
        case 1: time = 15*30;
        break;
         case 2: time = 20*20;
        break;
         case 3: time = 30*12;
        break;
         case 4: time = 30*10;
        break;
    }
    return time;
}
float emergencySurcharge(int level,int specialty)
{
    float surcharge,baseFee;
    switch(specialty)
    {
        case 1 : baseFee = 1500.00;
        break;
         case 2 : baseFee = 2500.00;
        break;
         case 3 : baseFee = 4500.00;
        break;
         case 4 : baseFee = 5000.00;
        break;
    }
    switch(level)
    {
        case 1: surcharge = 0;
        break;
        case 2: surcharge = baseFee*0.2;
        break;
        case 3: surcharge = baseFee*0.5;
        break;
    }
    return surcharge;
}
float wardCost(int idAndDays[2])
{
    float dailyRate;
    switch (idAndDays[0])
    {
        case 1 : dailyRate=3000.00;
        break;
        case 2 : dailyRate=6000.00;
        break;
        case 3 : dailyRate=12000.00;
        break;
        case 4 : dailyRate=25000.00;
        break;
        default : printf("Invalid!");
        break;
    }
    float cost = idAndDays[1] * dailyRate;
    return cost;
}
float grossTotal(int specialty,float emeCharge,float wardCost)
{
    float baseFee,total;
switch(specialty)
    {
        case 1 : baseFee = 1500.00;
        break;
         case 2 : baseFee = 2500.00;
        break;
         case 3 : baseFee = 4500.00;
        break;
         case 4 : baseFee = 5000.00;
        break;
        default : printf("Invalid");
    }
    total = baseFee + emeCharge + wardCost;
    return total;
}

float ageSubsidyDiscount(int age,float grossTotal)
{
    float discount;
    if (age<5 || age>65)
        discount = grossTotal*0.15;
    else
        {discount = 0.0;}
        return discount;
}
float finalAmountPayable(float grossTotal,float discount)
{
    float finalAmount = grossTotal - discount;
    return finalAmount;
}

void sort(char names[][50],int n,int levels[])
{
    printf("\n\tPatient List\n\n");
    int i,j,k=1;
for(j=3;j>=1;j--){
for(i=0;i<n;i++)
{
   if(levels[i]==j)
   {
       printf("%d. %s\n",k,names[i]);
       k++;;
   }
}
}
}

void bill(int a,char* name,int age,int specialty,int isAdmitted,int idAndDays[2],int level,float emeCharge,float wardCost,float grossTot,float discount,float finalAmount,int waitingTime)
{
    printf("=========================================================\n\tSMART HOSPITAL ADMISSION & BILL\n--------------------------------------------------------------\n");
    printf("Patient ID : PAT %04d\nPatient Name : %s\nAge : %d years",a,name,age);
    if (discount>0)
        printf("(15%% Subsidy Eligible)");

    float baseFee;
        char specName[20],wardName[20],levName[20];
switch(specialty)
    {
        case 1 : baseFee = 1500.00;
                strcpy(specName,"General Practice (OPD)");
        break;
         case 2 : baseFee = 2500.00;
                strcpy(specName,"Paediatrics");
        break;
         case 3 : baseFee = 4500.00;
                strcpy(specName,"Cardiology");
        break;
         case 4 : baseFee = 5000.00;
                strcpy(specName,"Neurology");
        break;
        default : printf("Invalid");
    }
switch(idAndDays[0])
{
    case 1 : strcpy(wardName,"General");
    break;
    case 2 : strcpy(wardName,"Paediatric");
    break;
    case 3 : strcpy(wardName,"Surgical");
    break;
    case 4 : strcpy(wardName,"ICU");
    break;
    default :  printf("Invalid");
}
switch(level)
{
    case 1 : strcpy(levName,"Normal");
    break;
    case 2 : strcpy(levName,"Urgent");
    break;
    case 3 : strcpy(levName,"Critical");
    break;
}

    printf("\nSpecialty : %s\nAssigned Ward : %s\nUrgency Level : Level %d(%s)\n----------------------------------------------------------------------",specName,wardName,level,levName);
    printf("\nBase Consultation Fee : %.2f\nEmergency Surcharge : %.2f\nWard Stay Cost (%d Days) : %.2f\nGross Total Bill : %.2f\nAge Subsidy Discount : -%.2f\n",baseFee,emeCharge,idAndDays[1],wardCost,grossTot,discount);
    printf("------------------------------------------------------------------------\nFinal Payable Amount : %.2f\nEstimated Waiting Time : %d mins\n============================================================\n",finalAmount,waitingTime);

    FILE *fp=NULL;
    fp = fopen("patient_records.txt","a");
    if (fp == NULL)
        {printf("Empty!");
        exit(1);}
    fprintf(fp,"\nSpecialty : %s\nAssigned Ward : %s\nUrgency Level : Level %d(%s)\n----------------------------------------------------------------------",specName,wardName,level,levName);
    fprintf(fp,"\nBase Consultation Fee : %.2f\nEmergency Surcharge : %.2f\nWard Stay Cost (%d Days) : %.2f\nGross Total Bill : %.2f\nAge Subsidy Discount : -%.2f\n",baseFee,emeCharge,idAndDays[1],wardCost,grossTot,discount);
    fprintf(fp,"------------------------------------------------------------------------\nFinal Payable Amount : %.2f\nEstimated Waiting Time : %d mins\n============================================================\n",finalAmount,waitingTime);
    fclose(fp);
}

void reports(char names[][50],int levels[],float revenues[],float discounts[],int beds[4][20],int i)
{
    int x,y,z;
    printf("1) Total patients registered and categorized by Urgency Level.\n\tNormal\tUrgent\tCritical\n-------------------------------------------------\n");
    for(x=0;x<i;x++)
    {
       switch(levels[x])
       {
       case 1:
           printf("\t%s\n",names[x]);
        break;
         case 2:
           printf("\t\t%s\n",names[x]);
        break;
         case 3:
           printf("\t\t\t%s\n",names[x]);
        break;
       }
    }
    float totRev = 0.0,totDis = 0.0;
    for(x=0;x<i;x++)
    {
        totRev += revenues[x];
        totDis += discounts[x];
    }
    printf("\n2) Total revenue earned and total discounts granted.\n\nTotal Revenue : %.2f\nTotal Discounts : %.2f\n",totRev,totDis);

    printf("\n3) Bed occupancy percentage per ward.\n\n");
    float percentage=0.0;
     int count=0;
     for(x=0;x<i;x++)
     {
         switch(x)
         {
            case 0: z = 20;
            printf("General Ward : ");
            break;
            case 1: z = 10;
            printf("Paediatric Ward : ");
            break;
            case 2: z = 10;
            printf("Surgical Ward : ");
            break;
            case 3: z = 5;
            printf("ICU : ");
            break;
         }
         for(y=0;y<z;y++){
         switch(beds[x][y])
         {
             case 1 : count+=1;
         }
         }
         percentage = (float)count/z*100;
     printf("%.0f%%\n",percentage);

     }
    printf("\n4) Name and total bill of the highest-paying patient.\n\n");
}

void bedsText(int beds[4][20])
{
     FILE *fp=NULL;
    fp = fopen("beds_status.txt","w");
    if (fp == NULL)
        {printf("Empty!");
        exit(1);}
    int i,j,k;
    for(i=0;i<4;i++)
    { switch(i)
    {
        case 0 : k=20;
        break;
        case 1 : k=10;
        break;
        case 2 : k=10;
        break;
        case 3 : k=5;
        break;
    }
        for(j=0;j<k;j++)
            fprintf(fp,"%d ",beds[i][j]);
            fprintf(fp,"\n");
    }
fclose(fp);
}

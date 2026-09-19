#ifndef HOSPITAL_SYSTEM_H_INCLUDED
#define HOSPITAL_SYSTEM_H_INCLUDED
struct Specialty {
    int id;
    char name[50];
    float fee;
    int consultationTime;
    int dailyPatientCap;
};
struct Ward {
    int wardID;
    char wardName[50];
    float dailyBedRate;
    int totalBedCapacity;
};

int menu();
void lookups(int beds[4][20]);
char* patientName();
int patientAge();
int emergencyLevel();
int specialtySelection();
int isAdmittedToWard();
void inputWardID_and_Days(int idAndDays[2]);

int estimatedWaitingTime(int);
float emergencySurcharge(int,int);
float wardCost(int idAndDays[2]);
float grossTotal(int,float,float);
float ageSubsidyDiscount(int,float);
float finalAmountPayable(float,float);

void sort(char names[][50],int,int levels[]);

void bill(int,char*,int,int,int,int idAndDays[2],int,float,float,float,float,float,int);

void reports(char names[][50],int levels[],float revenues[],float discounts[],int beds[4][20],int);

void bedsText(int beds[4][20]);


#endif // HOSPITAL_SYSTEM_H_INCLUDED

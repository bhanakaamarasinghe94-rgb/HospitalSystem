#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospital_system.h"

int main()
{
  int selection;
  static int beds[4][20] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0}};


   char names[1000][50];
    int levels[1000];
    float revenues[1000];
    int ages[1000];
    float discounts[1000];
    int specialties[1000];
    int admissions[1000];
    int idAndDaysList[1000][2];
    float emeCharges[1000];
    float wardCsts[1000];
    float grossTots[1000];
    float finalAmounts[1000];
    int waitingTimes[1000];

int i=0;
  do
  {selection = menu();

  switch(selection)
  {
      case 1:
    lookups(beds);
    printf("\n");
    break;

  case 2:
    char *name;
    name = patientName();
    int age = patientAge();
    int level = emergencyLevel();
    levels[i] = level;
    strcpy(names[i],name);

    int specialty = specialtySelection();
    int isAdmitted = isAdmittedToWard();
    int id,daysAdmitted;
    static int idAndDays[2];
    if (isAdmitted==1)
    {
        inputWardID_and_Days(idAndDays);
        id = idAndDays[0];
        daysAdmitted = idAndDays[1];
        printf("\n");
        int x,j;
        switch(id)
        {
            case 1 : j=20;
            break;
            case 2 : j=10;
            break;
            case 3 : j=10;
            break;
            case 4 : j=5;
            break;
        }
        for(x=0;x<j;i++)
        {
            if (beds[id-1][x]==0)
        {beds[id-1][x] = 1;
        break;}
        }
    }
    else if (isAdmitted==0)
    {
        daysAdmitted = 0;
    }
    else {printf("Invalid");}

    int waitingTime = estimatedWaitingTime(specialty);
    float emeCharge = emergencySurcharge(level,specialty);
    float wardCst = wardCost(idAndDays);
    float grossTot = grossTotal(specialty,emeCharge,wardCst);
    float discount = ageSubsidyDiscount(age,grossTot);
    float finalAmount = finalAmountPayable(grossTot,discount);

    revenues[i] = finalAmount;
    discounts[i] = discount;
    specialties[i] = specialty;
    ages[i] = age;
    admissions[i] = isAdmitted;
    idAndDaysList[i][0] = idAndDays[0];
    idAndDaysList[i][1] = idAndDays[1];
    emeCharges[i] = emeCharge;
    wardCsts[i] = wardCst;
    grossTots[i] = grossTot;
    discounts[i] = discount;
    finalAmounts[i] = finalAmount;
    waitingTimes[i] = waitingTime;
     i++;
    break;

    case 3:
        sort(names,1000,levels);
    break;

    case 4:
        bill(i,name,age,specialty,isAdmitted,idAndDays,level,emeCharge,wardCst,grossTot,discount,finalAmount,waitingTime);
        break;
    case 5:
        reports(names,levels,revenues,discounts,beds,i);
        int y;
        float highest;
        highest=revenues[0];
        for(y=1;y<i;y++)
        {
            if(highest<revenues[y])
                highest=revenues[y];
        }
        bill(y,names[y-1],ages[y-1],specialties[y-1],admissions[y-1],idAndDaysList[y-1],levels[y-1],emeCharges[y-1],wardCsts[y-1],grossTots[y-1],discounts[y-1],finalAmounts[y-1],waitingTimes[y-1]);
        break;

    case 6:
   bedsText(beds);

        break;

    case 7:
        printf("Thanks for using us. Have a Good Day!");
    break;

  default:
    printf("Invalid! Please try again\n");
  } }
  while (selection != 7);
  return 0;
}




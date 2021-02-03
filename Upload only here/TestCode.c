
#include <stdio.h>
#include <stdlib.h>
#define readTemp 0
#define Cooling 1
#define Heating 2
#define STANDBY 3


int HVACStatus = readTemp;

int testEventSequence[] = {18,5,6,15,27};

int testSequenceLength = sizeof(testEventSequence)/sizeof(testEventSequence[0]);

int exptectedOutputTestEventSequence[] = {Cooling, Heating};

int testOutputTestEventSequence[]={0,0,0,0,0};
int countErrors=0;

void validationTestRun();
void printTestResult();
int control(int Even);
int getState();

int main(void) {
validationTestRun();
printTestResult();
return EXIT_SUCCESS;
}

void validationTestRun(){

for(int testIndex =0; testIndex < 1; testIndex++){
control(testEventSequence[testIndex]);
if(getState() == exptectedOutputTestEventSequence[testIndex]){
testOutputTestEventSequence[testIndex]=1;
}else{
testOutputTestEventSequence[testIndex]=0;
}

}
}

void printTestResult(){
if(countErrors){
printf("%d error(s) identified.\n",countErrors);
for(int i=0; i<testSequenceLength; i++){
if(!testOutputTestEventSequence[i]){
printf("Error at event count %d. \n",i);
printf("Expected state for event %d is %d\n",testEventSequence[i],exptectedOutputTestEventSequence[i]);
}
}
}else{
printf("No errors identified!\n");
	}
}
int control (int Even)
{
switch(HVACStatus)
{
case readTemp:

    if(Even >=20)
        HVACStatus=Cooling;

    else if(Even <=16)
        HVACStatus=Heating;
        else {
            printf("StandBy Mode \n");
        HVACStatus= STANDBY;}

        break;

case Cooling:
    HVACStatus= readTemp;
    printf("The System is in the Cooling state\n");
    break;

case Heating:
    HVACStatus =readTemp;
    printf("The System is in the Heating state\n");
    break;

case STANDBY:
    printf("HVAC is OFF \n");
    HVACStatus=readTemp;

default:
    break;
}

return 0;
}
int getState(){

return HVACStatus;
}

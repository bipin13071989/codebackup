#include<iostream>
#include<conio.h>
#define MAX 100
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct Job 
{

char id[5];  

int deadline;

int Profit;

};

void jobSequencing(Job jobs[],int n);// funtion prototype

int minvalue(int x,int y)

{

if(x<y)

return x;

return y;

}

int main (void)

{

int i ,j ,n;
Job jobs[5];

cout<<"\nEnter the number of jobs";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\nEnter the job";

cin>>jobs[i].id;

cout<< "\nEnter the Profit";

cin>>jobs[i].Profit;

cout<<"\nEnter deadline";

cin>>jobs[i].deadline;



}

Job temp;//STRUCTURE VARIABLE // SORT JOBS TEMP OF TYPE Job

cout<<"\nJob(i)\t Profit\t Deadline\t \n\n";

cout<<"--------------------------------------------------";

for(i=0;i<n;i++)

{

cout<<endl<<endl;

cout<<jobs[i].id<<"\t\t"<<jobs[i].Profit<<"\t\t"<<jobs[i].deadline;

}

for(i=1;i<n;i++)// sort the job details in decreasing order of profit

{

for(j=0;j<n-i;j++)

{

if(jobs[j+1].Profit>jobs[j].Profit)// j+1 is greater than j 

{

temp=jobs[j+1];  

jobs[j+1]=jobs[j];// descending order

jobs[j]=temp;

}

}

}

cout<<"\n\nTotal nuber of jobs;"<<n<<endl;// print total number of jobs

jobSequencing(jobs,n);//total number of jobs stored

getch();

return 0;

}

void jobSequencing(Job jobs[],int n)

{

int i,j,k,maxprofit;

int timeslot[MAX];// INTEGER Array time slot of size MAX ,number of free time slot

int filledTimeSlot= 0;// SET VALUE 0

int dmax= 0;// 0 // USED TO STORE THE MAXIMUM DEADLINE VALUE

for (i= 0;i<n;i++) // find the maximum deadline

{

if(jobs[i].deadline>dmax) // COMPARING WITH THE DEADLINE IS GREATER THAN ASSIGN TO DMAX

{

dmax =jobs[i].deadline;// ASSIGNMENT

}





}



cout<<"\nTotal time slot:"<<dmax;// TIME SLOT WHICH WILL BE PRINTED

for(i=1;i<=dmax;i++) // intialize free time slot array

{

timeslot[i]=-1;// EMPTY OR FREE TIME SLOT

}

cout<<"\n\nnumber of jobs done:"<<dmax; // total number of jobs

for(i=1;i<=n;i++)// fill the time slot

{

k=minvalue(dmax,jobs[i-1].deadline);// EACH JOB IS TAKING THE SINLE TIME SLOT TO EXECUTE,minimum return to variable k

while(k>=1)// till value 

{

if(timeslot[k]==-1)// if time slot corrospond to k is free

{

timeslot[k]=i-1;// assign the current job number to time slot at k

filledTimeSlot++;// increment the count

break;// terminate the while loop

}

k--;//decrement the value

}

if(filledTimeSlot==dmax)// if filled

{ 

 break;

}

}

// cout<<"\nJobs done \:n";

for(i=1;i<=dmax;i++)

{

cout<<"\tJob"<<jobs[timeslot[i]].id<<"at time:"<<i<<endl;// at particular time slot

}

maxprofit=0;

for(i=1;i<=dmax;i++)

{

maxprofit+=jobs[timeslot[i]].Profit;

}

    cout<<"\ntotal profit"<<maxprofit;

}

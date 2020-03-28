

#include <bits/stdc++.h> 
using namespace std; 


struct process {
    int at ;
    int bt ;
    int pr ;
    int pno; 
}; 
  
process proc[100]; 
int no_of_processes ;
/* 
Writing comparator function to sort according to priority if  
arrival time is same  
*/
  
bool compare_condition(process a,process b) {

    if(a.at == b.at) { 
        return a.pr < b.pr; 
    } 
    else
    { 
        return a.at < b.at; 
    } 
} 
  
// Using FCFS Algorithm to find Waiting time 
void getWaitingTime(int wt[]) 
{ 
    // declaring service array that stores cumulative burst time  
    int service[50] ; 
  
    // Initilising initial elements of the arrays 
    service[0] = 0 ; 
    wt[0] = 0 ; 
  
  
    for(int i = 1 ; i < no_of_processes ; i++) 
    { 
        service[i] = proc[i-1].bt + service[i-1] ; 
  
        wt[i] = service[i] - proc[i].at + 1 ; 
  
        // If waiting time is negative, change it into zero 
      
        if(wt[i] < 0) { 
            wt[i] = 0 ; 
        } 
    } 
  
} 
  
void getTurnaroundTime(int tat[],int wt[]) 
{ 
// Filling turnaroundtime array 
  
    for(int i = 0 ; i < no_of_processes ; i++) 
    { 
        tat[i] = proc[i].bt + wt[i] ; 
    } 
      
} 
  
void GanttChart() 
{ 
    //Declare waiting time and turnaround time array 
    int wt[50], tat[50] ; 
  
    double wavg=0, tavg=0; 
  
    // Function call to find waiting time array 
    getWaitingTime(wt); 
    //Function call to find turnaround time 
    getTurnaroundTime(tat, wt); 
      
    int stime[50], ctime[50];

    stime[0] = 1 ; 
    ctime[0] = stime[0] + tat[0] ; 
    // calculating starting and ending time 
    for(int i = 1 ; i < no_of_processes ; i++) 
    { 
        stime[i] = ctime[i-1] ; 
        ctime[i] = stime[i] + tat[i] - wt[i] ; 
    } 
    cout << "[+]------------------------------------------------------------------------------------[+]\n" ;
    cout << "[+] Process_no   |  Start_time  |  Complete_time  |  Turn_Around_Time  |  Waiting_Time [+]"<<endl; 
    
    // display the process details 
      
    for(int i = 0 ; i < no_of_processes ; i++) 
    { 
        wavg += wt[i] ; 
        tavg += tat[i] ; 
          
        cout << "[+]\t " << proc[i].pno << "\t |\t" << stime[i] << "\t|\t" << ctime[i] << "\t  |\t   " << tat[i] << "\t       |\t" << wt[i] <<"      [+]"<< endl; 
    }  
    cout << "[+]------------------------------------------------------------------------------------[+]\n" ;

        // display the average waiting time 
        //and average turn around time 
    cout << endl ;
    cout << "[-] Average waiting time is : "; 
    cout << wavg/(float)no_of_processes<<endl; 
    cout << "[-] Average turnaround time : "; 
    cout << tavg/(float)no_of_processes<<endl; 
  
} 
  
int main() 
{
    // Color Coding
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
    //


    int arrivaltime[100] ; 
    int bursttime[100] ; 
    int priority[100] ; 
    

    cout << blue << "[+]-----------------------------------------------------------------------[+]\n" ;
    cout << "[+]                     Priority Scheduling Algorithm                     [+]\n" ;
    cout << "[+]                            Dipankar Lama                              [+]\n" ;
    cout << "[+]                                C++                                    [+]\n" ;
    cout << "[+]-----------------------------------------------------------------------[+]\n" << normal ;

    cout << endl ;

    cout << "[-] Enter The Number of Processes : " ;

    cin >> no_of_processes ;
    cout << endl ;

    for(int i = 0 ; i < no_of_processes ; i++) {

        int inputFromUser ;
        cout << "[+] Enter Process Number : " ;
        cin >> inputFromUser ;
        cout << "[+] Enter The Priority of the Process : " ;
        cin >> priority[i] ;
        //new_process -> setPriority(inputFromUser) ;
        cout << "[+] Enter The Burst Time of the Process : " ;
        cin >> bursttime[i] ;
        //new_process -> setBurstTime(inputFromUser) ;
        cout << "[+] Enter The Arrival Time of the Process : " ;
        cin >> arrivaltime[i] ;
        //new_process -> setArrivalTime(inputFromUser) ;

        cout << endl ;

    }



    for(int i = 0 ; i < no_of_processes ; i++) 
    { 
        proc[i].at = arrivaltime[i] ; 
        proc[i].bt = bursttime[i] ; 
        proc[i].pr = priority[i] ;
        proc[i].pno = i + 1 ;
    }  
      
    sort(proc, proc + no_of_processes, compare_condition) ;     // Sorting using inbuild Sort function in STL
     
    GanttChart() ;                                              //Calling function findgc for finding Gantt Chart  
  
    return 0 ; 
} 

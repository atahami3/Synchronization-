// cs351_assignment3_Ali_Tahami.cpp : Synchronization.
// Copyright (c) Ali Tahami 03/09/2022
//

#include <iostream>      // cout
#include <thread>        // thread
#include <mutex>         // mutex
#include <fstream>       // files
using namespace std;

mutex mtx;            // mutex for critical section
ofstream outfile ("synch.txt");

void thread_A_numeric(){
  mtx.lock();
  for (int i=0; i<20; ++i) { 
      for(int j = 1; j <= 26; ++j){
          outfile << j <<" ";//add numbers
      }
      outfile<<"\n";
     }
  mtx.unlock();
}


void thread_B_alphabhet(){
    mtx.lock();
    for(int i = 0; i < 20; ++i){
        for(int j = 0; j < 26; ++j){
            outfile << char('A' + j) << " "; //add alpabet
        }
        outfile<<"\n";
    }
    mtx.unlock();
}


int main ()
{
  thread thread_A(thread_A_numeric);
  thread thread_B(thread_B_alphabhet);

  thread_A.join();
  thread_B.join();
 
  return 0;
}
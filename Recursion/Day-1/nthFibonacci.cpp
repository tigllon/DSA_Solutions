/*
########### Problem Statement ########
The Fibonacci sequence is defined as follows: the first number of the sequence is 0, the second number is 1 and the nth number is the sum of the (n -1)th  and (n -2)th  numbers. Write a function that takes in an integer n and returns the nth Fibonacci number.

*/

//solutions


// ##############Iterative Approach ###########
#include<iostream>
using namespace std;

void  solve(int num){
  int num1 = 0;
  int num2=1;
  int temp;
  if (num==1)
  cout<<num1<<endl;
  else if(num==2)
  cout<<num2<<endl;
  else {
    for(int i=3;i<=num;i++){
      temp=num1+num2;
      num1=num2;
      num2=temp;
    }
    cout<<temp<<endl;
  }
}

int main(){
  int n;
  cin>>n;
  solve(n);
}


// ############  Recusive Approach ################
#include<iostream>
using namespace std;

int solve(int a ,int b ,int n){
  if(n==1)
  return a ;
  else if(n==2)
  return b;
  else 
  solve(b,a+b,--n);
}

int main(){
  int n;
  cin>>n;
  int num1=0;
  int num2=1;
  cout<<solve(num1,num2,n)<<endl;
}


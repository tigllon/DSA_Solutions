

// ###################  Iterative Approach ########################
#include<iostream>
using namespace std;
int fact(int num){
  int result=1;
  for(int i=1;i<=num;i++)
  result*=i;
  return result;
}

int main(){
  string  s;
  cin>>s;
  int sum=0;
  //starting scanning the array
  int mult_factor=0;
  int minus=0;
  int num=0;
  for(int i=0;i<s.length();i++)
  {
    if(s.at(i)=='['){
      mult_factor++;
      continue;
    }
    if(s.at(i)==']'){
      mult_factor--;
      // continue;
    }
    if(s.at(i)=='-')
    {
      minus=1;
      continue;
    }
    if(s.at(i)!=',' && s.at(i)!=']')
    {
      num=num*10+(s.at(i)-48);
      continue;
    }
    else {
      // cout<<"I am here"<<endl;
      if(s.at(i)==','){
        if(minus){
        sum-=(num*fact(mult_factor));
        minus=0;
      }
      else {
        sum+=(num*fact(mult_factor));
      }
      }
      else {
        int temp_mult;
        if(s.at(i)=='[')
        temp_mult=mult_factor-1;
        else
        temp_mult=mult_factor+1;
        if(minus){
        sum-=(num*fact(temp_mult));
        minus=0;
      }
      else {
        sum+=(num*fact(temp_mult));
      }
      }
      num=0;
    }
  }
  cout<<sum<<endl;
}

// ################## Recursive Approach ##################
#include<iostream>
using namespace std;
int fact(int num){
  int result=1;
  for(int i=1;i<=num;i++)
  result*=i;
  return result;
}

int solve(string  s){
  int num=0;
  int sum=0;
  static int multi_factor=0;
  static int index = 0;
  int minus=0;
  for(;index<s.length();index++){
    if(s.at(index)=='-')
    {
      minus=1;
      continue;
    }
    if(s.at(index)==']'){
      sum+=num*fact(multi_factor);
      index++;
      multi_factor--;
      return sum;
    }
    else if(s.at(index)=='[')
    {
      index++;
      multi_factor++;
      sum= sum+solve(s);
    }
    else {
      if(s.at(index)==','){
        sum+=num*fact(multi_factor);
        num=0;
        minus=0;
      }
      else {
        if(minus)
        num=num*10-(s.at(index)-48);
        else 
        num=num*10+(s.at(index)-48);
      }
    }
  }
  return sum;
}

int main(){
  string s;
  cin>>s;
  int output  = solve(s);
  cout<<output<<endl;
}

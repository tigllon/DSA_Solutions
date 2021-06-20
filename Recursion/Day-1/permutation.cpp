
// #####################################Recursive Approach ##########################

#include<iostream>
using namespace std;
void copy(string *a,string *b,int len){
    for(int i=0;i<len;i++)
    b[i]=a[i];
}

void solve(string *s , int end  , int start,int len){
    if(start-end<=0){
        cout<<"[ ";
        for(int i=0;i<len;i++)
        cout<<s[i]<<",";
        cout<<"] ";
    }
    for(int i=end ; i>=start;i--){
        for(int j=end ; j>i;j--){
        string temp[len];
        copy(s,temp,len);
        //swapping the values
        string t = temp[i];
        temp[i]=temp[j];
        temp[j]=t;
        solve(temp,end , i+1,len);
        }
    }
}



int main(){
    int n ; 
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    cout<<"[ ";
    solve(s,n-1,0,n);
    cout<<" ]";
    cout<<endl;
}


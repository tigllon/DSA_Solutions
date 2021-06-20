//#######################Recusive Approach######################


#include<iostream>
#include<vector>
using namespace std;
vector <int> keep_track;
string str[]={"1" ,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","0"};


void rec(vector <string> &s , int *num , int index,int end){
    if(index==end){
        for(int j=0;j<str[num[index]].length();j++){
        string st="";
        for(int i=0;i<=end;i++){
            st+=str[num[i]].at(keep_track[i]);
        }
        // cout<<st<<endl;
        s.push_back(st);
        keep_track[index]++;
        }
        keep_track[index]=0;
    }
    else {
        while(keep_track[index]<str[num[index]].length()){
            rec(s,num,index+1,end);
            // cout<<"Index = "<<index<<"Num index="<<num[index]<<" "<<keep_track[index]<<endl;
            keep_track[index]++;
            for(int i=index+1;i<=end;i++)
            keep_track[i]=0;
        }
    }
}

vector <string> solve(string s){
    int num[s.length()];
    for(int i=0;i<s.length();i++){
        if(s.at(i)!='0')
    num[i]=(s.at(i)-48)-1;
    else
    num[i]=9;
    }
    vector <string>  v ;
    for(int i=0;i<s.length();i++)
    keep_track.push_back(0);
    rec(v,num,0,s.length()-1);
    return v;
}

int main(){
    string s;
    cin>>s;
    vector<string> v =solve(s);
    // cout<<v.size()<<endl;
    cout<<"[ ";
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<",";
    cout<<"]";
}




// ############################iterative approach #########################
#include<iostream>
#include<vector>
using namespace std;
string str[]={"1" ,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","0"};

vector <string> solve(string s){
    int num[s.length()];
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='0')
        num[i]=9;
        else
        num[i]=s.at(i)-48-1;
    }
    vector <string> v ; // This vector we will gonna to return
    //iterative approach will begin
    vector <int> keep_track(s.length(),0) ;
    while(1){
        string st="";
        for(int i=0;i<s.length();i++){
            st+=str[num[i]].at(keep_track[i]);
        }
        v.push_back(st);
        keep_track[s.length()-1]++;
        for(int j=s.length()-1;j>=0;j--){
            if(keep_track[j]==str[num[j]].length() && j==0)
            return v;
            else if(keep_track[j]==str[num[j]].length() && j!=0){
                j--;
                while(j>=0 && keep_track[j]+1>=str[num[j]].length())
                j--;
                if(j==-1)
                return v;
                else {
                    keep_track[j]++;
                    for(int k=j+1;k<s.length();k++)
                    keep_track[k]=0;
                    break;
                }
            }
        }
    }
    return v;
}

int main(){
    string s;
    cin>>s;
    vector <string> v =solve(s);
    cout<<"[ ";
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<",";
    cout<<" ]";
}
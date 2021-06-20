// ############################### Recursive Approach ##########################
#include <iostream>
#include <vector>
using namespace std;
vector <int> old_keep_track;
vector <int> new_keep_track;


void set_to_zero(vector <int> &v){
    for(int i=0;i<v.size();i++)
    v[i]=0;
}

void rec(vector <string> &t , int s,int n ,int steps , int index){
    if(steps==s){
        string st="";

        for(int i=0;i<=index;i++){
            char ch = (char)(new_keep_track[i]+48);
            st+=ch;
            st+=",";
            // cout<<"St="<<st<<endl;
        }
        //copying new one into old one
        t.push_back(st);
        set_to_zero(old_keep_track);
        for(int i=0;i<index;i++)
        old_keep_track[i]=new_keep_track[i];
    }
    else if(steps>s){}
    else {
        new_keep_track[index+1]=1;
        rec(t, s,n,steps+1,index+1);
            // index--;
            while(index>=0 && new_keep_track[index]+1 > n)
            index--;
            if(index==-1){}
            else{
                new_keep_track[index]++;
                int so=0;
                for(int i=0;i<=index;i++)
                so+=new_keep_track[i];
            rec(t,s,n,so,index);
            }
    }
}


vector<string> solve(int s, int n)
{
    for(int i=0;i<n;i++)
    for(int i=0;i<n;i++){
        old_keep_track.push_back(0);
        new_keep_track.push_back(0);
    }
    set_to_zero(new_keep_track);
    vector <string> v ; //This we will gonna to return
    rec(v,s,n,0,-1);
    return v;
}

int main()
{
    int s, n;
    cin >> s >> n;
    vector<string> v = solve(s, n);
    cout<<"[ ";
    for(int i=0;i<v.size();i++){
        cout<<"[";
        cout<<v[i];
        cout<<"],";
    }
    cout<<" ]";
    return 0;
}
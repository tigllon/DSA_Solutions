// ######################## Recusive Approach #######################

#include<iostream>
#include<vector>
using namespace std;
vector <int> keep_track;
void rec(vector <string> &v , int start , int end,int index,int len,string *s){
    if(end==0){v.push_back("");}
    else if(end==1){
        for(int  i =0;i<len;i++)
        v.push_back(s[i]);
    }
    else if(start==end-1){
        int lol = keep_track[end-2];
        // cout<<"Lol="<<lol<<endl;
        string st="";
        for(int i=0;i<end-1;i++)
        st+=s[keep_track[i]]+",";
        // cout<<"St="<<st<<endl;
        for(int i=lol+1;i<len;i++)
        {
            string test = st+s[i];
            v.push_back(test);
        }
    }
    else {
        int temp = index;
        while(temp!=(len-1)-(end-1-(start))){
            temp++;
            keep_track[start]=temp;
            // for(int i=0;i<end;i++)
            // cout<<keep_track[i]<<" ";
            // cout<<endl;
        rec(v,start+1,end,temp,len,s);
        }
    }
}


vector <string> solve(string *s, int n){
    for(int i=0;i<n;i++)
    keep_track.push_back(0);
    vector <string> v;
    for(int i=0;i<n;i++){
        rec(v,0,i,-1,n,s);
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    vector <string> v = solve(s,n);
    cout<<"[ ";
    for(int i=0;i<v.size();i++)
    {
        cout<<"[";
        cout<< v[i];
        cout<<"],";
    }
    cout<<" ]";
}




// ####################### Iterative Apporaoch #####################
#include<iostream>
#include<vector>
using namespace std;

vector <string> solve(string *s ,int n){
    vector <string> v ;
    vector <int> keep_track ; 
    for(int i=0;i<n;i++){
        if(i==0)
        v.push_back("");
        else if( i==1)
        {
            for(int j=0;j<n;j++)
            v.push_back(s[j]);
        }
        else {
            for(int j=0;j<i;j++)
            keep_track.push_back(j);
            // string st="";
            // for(int k=0;k<i-1;k++)
            // st+=s[keep_track[k]]+",";
            while(1){
                string st="";
                for(int k=0;k<i-1;k++)
                st+=s[keep_track[k]]+",";
                int lol = keep_track.back();
                for(int pos=lol ; pos<n;pos++){
                    string set = st+s[pos];
                    v.push_back(set);
                }
                int len = keep_track.size()-2;
                while(len >=0 && keep_track[len]+1 > ((n-1)-((i-1)-(len))))
                len--;
                if(len==-1)
                break;
                // cout<<"len ="<<len<<endl;
                keep_track[len]++;
                for(int z=len+1;z<keep_track.size();z++)
                keep_track[z]=keep_track[z-1]+1;
                // for(int p=0;p<keep_track.size();p++)
                // cout<<keep_track[p]<<" ";
                // cout<<endl;
            }
            keep_track.clear();
        }
    }
    return v;
}


int main(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    vector <string> v  =solve(s,n);
    cout<<"[ ";
    for(int i=0;i<v.size();i++){
        cout<<"[";
        cout<<v[i];
        cout<<"],";
    }
    cout<<" ]";
}
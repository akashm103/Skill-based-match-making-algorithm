#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void solve(int i,vector<int> v,int n,int m,int c)
{
    if(m==c)
    {
        ans.push_back(v);
        return ;
    }
    if(n==i)
        return ;
    for(int j=i+1;j<n;j++)
    {
        vector<int> xx=v;
        xx.push_back(j);
        solve(j,xx,n,m,c+1);
    }
}
bool cmp(pair<pair<int,int>,float>p1,pair<pair<int,int>,float>p2){
    int x1=p1.second,x2=p2.second;
    return x1<x2;
}
main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int m,n;
    cin>>m;
    int i,j,k;
    int a,b;
    string s,s1;
    vector<pair<string,int>> v,v1;
    i=0;
    cin.ignore();
    getline(cin,s);
    while(!s.empty())
    {
        string xx="";
        for(i=0;i<s.size();i++){
            if(s[i]==' '){
                break;
            }
            xx+=s[i];
        }
        int val=0;
        for(j=i+1;j<s.size();j++){
            val=val*10+(s[j]-'0');
        }
        v.push_back({xx,val});
        getline(cin,s);
    }
    for(i=0;i<v.size();i++)
    {
        // cout<<v[i].first<<" ";
        vector<int>vs;
        vs.push_back(i);
        solve(i,vs,v.size(),m,1);
    }
    vector<pair<pair<int,int>,float>>superans;
    for(i=0;i<ans.size();i++){
        unordered_map<int,int>mm;
        float avg=0;
        for(j=0;j<ans[i].size();j++){
            mm[ans[i][j]]=1;
            avg=avg+float(v[ans[i][j]].second);
        }
        avg=avg/float(ans[i].size());
        for(j=i+1;j<ans.size();j++){
            int flag=0;
            float avg1=0;
            for(k=0;k<ans[j].size();k++){
                avg1=avg1+float(v[ans[j][k]].second);
                if(mm[ans[j][k]]==1){
                    flag=1;
                    break;
                }
            }
            avg1=avg1/float(ans[j].size());
            if(flag==0){
                superans.push_back({{i,j},abs(avg-avg1)});
            }
        }
    }
    sort(superans.begin(),superans.end(),cmp);
    for(auto x:superans){
        float f=0;
        for(auto xx:ans[x.first.first]){
            f=f+float(v[xx].second);
            cout<<v[xx].first<<", ";
        }
        f=f/float(ans[x.first.first].size());
        cout<<"("<<f<<") vs ";
        f=0;
        for(auto xx:ans[x.first.second]){
            f=f+float(v[xx].second);
            cout<<v[xx].first<<", ";
        }
        f=f/float(ans[x.first.second].size());
        cout<<"("<<f<<")";
        cout<<endl;
    }
}
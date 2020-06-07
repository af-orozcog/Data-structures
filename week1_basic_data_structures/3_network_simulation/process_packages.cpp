#include <bits/stdc++.h>
using namespace std;

int main() {
    int s,n;
    scanf(" %d %d",&s,&n);
    int last = 0;
    queue<pair<int,pair<int,int>>> q;
    vector<int> ans(n);
    for(int i = 0; i < n;++i){
        int a,p;
        scanf(" %d %d",&a,&p);
        if((int)q.size() < s)
            q.push({a,{p,i}});
        else{
            while(q.size() && max(last,q.front().first) + q.front().second.first <= a){
                ans[q.front().second.second] = max(last,q.front().first);
                last = max(last,q.front().first) + q.front().second.first;
                q.pop();
            }
            if((int)q.size() < s) q.push({a,{p,i}});
            else ans[i] = -1;
        }
    }
    while(q.size()){
        ans[q.front().second.second] = max(last,q.front().first);
        last = max(last,q.front().first) + q.front().second.first;
        q.pop();
    }
    for(auto va:ans) printf("%d\n",va);
    return 0;
}

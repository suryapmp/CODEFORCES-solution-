//GNU C++17//

#include<bits/stdc++.h>
using namespace std;
int main() {

int t,i;
cin>>t;
while(t--) {
    string s;
    cin>>s;
    if((s[s.length()-1]-48)%2==0) {
        cout<<0<<endl;
    }
    else {
            int o=0;
        for(i=0;i<s.length();i++) {
            if((s[i]-48)%2==1)
              o++;
        }
    if(o==s.length())
        cout<<-1<<endl;
    else
    {
      if((s[0]-46)%2==0)
        cout<<1<<endl;
      else
        cout<<2<<endl;
    }


}
}
}

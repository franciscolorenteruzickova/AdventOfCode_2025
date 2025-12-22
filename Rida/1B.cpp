#include<bits/stdc++.h>
using namespace std;

int main(){
    int password = 0, dial = 50;
    string s;
    while(getline(cin, s)){
        char c = s[0];
        s.erase(0, 1);
        int rotation = stoi(s);
        if(c == 'L'){
            for(int i = 0; i<rotation; i++){
                dial = (dial-1)%100;
                if(dial==0){
                    ++password;
                }
                if(dial<0){
                    dial += 100;
                }
            }
        }
        if(c == 'R'){
            for(int i = 0; i<rotation; i++){
                dial = (dial+1)%100;
                if(dial==0){
                    ++password;
                }
            }
        }
    }
    cout << password << "\n";
    return 0;
}

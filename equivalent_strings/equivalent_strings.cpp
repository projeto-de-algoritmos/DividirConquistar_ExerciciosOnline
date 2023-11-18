#include<bits/stdc++.h>
using namespace std;
 
string makeEqual(string s) {
    if(s.length() % 2 == 1) return s;
    string s1 = makeEqual(s.substr(0, s.length()/2));
    string s2 = makeEqual(s.substr(s.length()/2, s.length()));
    if(s1 < s2) return s1 + s2;
    else return s2 + s1;
}
 
int main() {
    string a, b;
    cin >> a >> b;
    if(makeEqual(a) == makeEqual(b)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
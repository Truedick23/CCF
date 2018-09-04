#include<iostream>
#include<cctype>
#include<string>
#include<vector>
using namespace std;

string manipulate(string oldstr, int flag) {
    int len = oldstr.length();
    string str = oldstr;
    if(!flag) {
        for(int i = 0; i < len; i++) {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

int main() {
    string mod;
    int flag, n;
    vector<string> ls;
    cin >> mod;
    cin >> flag;
    mod = manipulate(mod, flag);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        ls.push_back(str);
    }
    for(int i = 0; i < ls.size(); i++) {
        string oldstr = ls[i];
        string str = manipulate(oldstr, flag);
        if(str.find(mod) != string::npos)
            cout << oldstr << endl;
    }
    return 0;
}

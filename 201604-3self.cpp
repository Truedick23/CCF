#include<cstring>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

vector<string> subs[11];
vector<string> father;
string father_dir;

vector<string> split(string str, string s) {
    vector<string> ls;
    int i = 0 , j = str.find(s);
    while(j != string::npos) {
        string subs = str.substr(i, j - i);
        cout << subs << endl;
        ls.push_back(subs);
        i = j + 1;
        j = str.find(s, i);
    }
    string subs = str.substr(i, str.length() - i);
    cout << subs << endl;
    ls.push_back(subs);
    return ls;
}

string[] manip(string[] str, int n) {
    string format_str[11];
    string format = "";
    for(int i = 0; i < n; i++)
        subs[i] = split(str[i], "/");
    if(subs[0] != "") {

    }
    for(int i = 0; i < n; i++) {
        len = subs[i].size();
        for(int j = 0; j < len; j++) {
            string s = subs[i][j];
            if(s == "")
                continue;
            else if(s == ".") {
                if(j == 0)
                    format = father_dir;
                else
                    continue
            }
            if(s == "..") {
                if(j == 0)
                    format =
            }
        }
    }
}



int main() {
    int p;
    string str[11];
    cin >> p;
    cin >> father_dir;
    father = split(father_dir, "/");
    for(int i = 0; i < p; i++)
        cin >> str[i];
    manip
    return 0;
}

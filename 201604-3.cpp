#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> split(string str, string ch);

string handle(vector<string> v);
vector<string> vCurPath;
string curPath;

int main() {
    int num = 0;
    cin >> num;
    cin >> curPath;
    vCurPath = split(curPath, "/");
    string *arr = new string[num];
    for(int i = 0; i < num; i++)
        cin >> arr[i];
    vector<string> v;
    for(int i = 0; i < num; i++) {
        v = split(arr[i], "/");
        string res = handle(v);
        cout << res << endl;
    }
    return 0;
}

vector<string> split(string str, string ch) {
    int a = 0, b = 0;
    b = str.find(ch, a);
    string temp;
    vector<string> v;
    while(b != string::npos){
        temp = str.substr(a, b - a);
        v.push_back(temp);
        a = b + 1;
        b = str.find(ch, a);
    }
    temp = str.substr(a);
    v.push_back(temp);
    return v;
}

string handle(vector<string> v) {
    vector<string> vTemp;
    if(v[0] != "") {
        vTemp = vCurPath;
        vTemp.erase(vTemp.begin());
    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == "." || v[i] == "")
            continue;
        else if(v[i] == "..") {
            if(vTemp.size() != 0)
                vTemp.pop_back();
            continue;
        }
        else
            vTemp.push_back(v[i]);
    }
    string res;
    for(int i = 0; i < vTemp.size(); i++)
        res = res + "/" + vTemp[i];
    if(vTemp.size() == 0)
        res = "/";
    return res;
}

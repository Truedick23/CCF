#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<ctype.h>

using namespace std;

bool legal(char *s) {
    for(int i = 0; i < strlen(s); i++)
        if(s[i] != '/' && s[i] != '-' && s[i] != '_' && !(isalpha(s[i])||isdigit(s[i])))
            return false;
    return true;
}

bool int_right(string s) {
    for(int i = 0; i < s.length(); i++)
        if(!isdigit(s[i]))
            return false;
    return true;
}

struct Rule {
    vector<string> rule;
    string name;
    bool flag;
}r[105];

vector<string> url;
vector<string> para;

int n;

void init() {
    string tmp;
    char a[110];
    int pos = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%s", a);
        int len = strlen(a);
        if(len > 0 && a[len - 1] == '/')
            r[pos].flag = true;
        else
            r[pos].flag = false;
        cin >> r[pos].name;
        char *sp = strtok(a, "/");
        while(sp) {
            r[pos].rule.push_back(sp);
            sp = strtok(NULL, "/");
        }
        pos++;
    }
}

bool postfix;

void match(char *a) {
    url.clear();
    char *sp = strtok(a, "/");
    while(sp) {
        url.push_back(sp);
        sp = strtok(NULL, "/");
    }
    for(int i = 0; i < n; i++) {
        int j, k;
        para.clear();
        bool flag = true;
        for(j = 0, k = 0; j < r[i].rule.size() && k < url.size(); j++, k++) {
            string s = r[i].rule[j];
                if(s == "<int>") {
                    if(!int_right(url[k])) {
                        flag = false;
                        break;
                    }
                    else {
                        string str = url[k];
                        for(int t = 0; t < str.length() && str[t] == '0'; t++)
                            str.erase(t, 1);
                        if(str != "")
                            para.push_back(str);
                    }
                }

                else if(s == "<str>")
                    para.push_back(url[k]);

                else if(s == "<path>") {
                    string tmp = url[k++];
                    for(; k < url.size(); k++)
                        tmp = tmp + "/" + url[k];
                    if(postfix)
                        tmp += "/";
                    para.push_back(tmp);
                }

                else {
                    if(s != url[k]) {
                        flag = false;
                        break;
                    }
                }
            }
        if(flag && j >= r[i].rule.size() && k >= url.size() && r[i].flag == postfix) {
            cout << r[i].name;
            for(int ii = 0; ii < para.size(); ii++)
                cout << " " << para[ii];
            cout << endl;
            return;
        }
    }
    cout << "404" << endl;
}

int main() {
    int m;
    string s;
    cin >> n >> m;
    init();
    while(m--) {
        char a[110];
        scanf("%s", &a);
        int len = strlen(a);
        if(len > 0 && a[len - 1] == '/')
            postfix = true;
        else
            postfix = false;
        if(!legal(a)) {
            cout << "404" << endl;
            continue;
        }
        match(a);
    }
    return 0;
}






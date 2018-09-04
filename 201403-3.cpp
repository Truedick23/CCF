#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;

#define NOTEXIST 0
#define NOPARAM 1
#define HASPARAM 2

map<char, int> type;
map<char, string> dict;

int query(string format, string str) {
    int index;
    if(str.length() == 2 && str[0] != '-' || (index = format.find(str[1])) == string::npos)
        return NOTEXIST;
    else {
        if(format[index + 1] == ':')
            return HASPARAM;
        else return NOPARAM;
    }
}

int main() {
    string str[21];
    string format, s;
    int N;
    getline(cin, format);
    cin >> N;
    getchar();
    for(int i = 0; i < N; i++)
        getline(cin, str[i]);
    for(int i = 0; i < N; i++) {
        type.clear();
        dict.clear();
        queue<string> q;
        char ls[256];
        int len = str[i].length();
        for(int j = 0; j < len; j++)
            ls[j] = str[i][j];
        ls[len++] = '\0';
        char *tok = strtok(ls, " ");
        while(tok) {
            //cout << tok << " ";
            if(strcmp(tok, "ls") != 0)
                q.push(tok);
            tok = strtok(NULL, " ");
        }
        while(!q.empty()) {
            string elem = q.front();
            //cout << elem << endl;
            q.pop();
            int flag = query(format, elem), param = 0;
            if(flag == NOTEXIST)
                break;
            if(flag == NOPARAM)
                dict[elem[1]] = "";
            if(flag == HASPARAM) {
                string value = q.front();
                q.pop();
                dict[elem[1]] = value;
            }
        }
        cout << "Case " << i + 1 << ": ";
        for(map<char, string>::iterator iter = dict.begin(); iter != dict.end(); iter++) {
            cout << '-' << iter->first << " ";
            if(iter->second != "")
                cout << iter->second << " ";
        }
        cout << endl;
    }
    return 0;
}

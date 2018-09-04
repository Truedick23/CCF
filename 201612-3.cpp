#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

const int NOVALUE = -1;
const int TRUE = -2;
const int FALSE = -3;

using namespace std;

struct _privilege {
    string category;
    int level;
};
vector<_privilege> privilege;

struct _role {
    string role;
    int s;
    vector<_privilege> privilege;
};
vector<_role> role;

struct _user {
    string user;
    int t;
    vector<string> role;
};
vector<_user> user;

string getcategory(string& s) {
    int pos = s.find(":");

    if(pos == (int)string::npos)
        return s;
    else
        return s.substr(0, pos);
}

int getlevel(string &s) {
    int pos = s.find(":");

    if(pos == (int)string::npos)
        return NOVALUE;
    else
        return atoi(s.substr(pos + 1, s.length() - 1).c_str());
}


int privilegematch(_privilege& p1, _privilege& p2) {
    if(p1.category != p2.category)
        return FALSE;
    else if(p2.level == NOVALUE) {
        if(p1.level == NOVALUE)
            return TRUE;
        else
            p1.level;
    } else {
        if(p1.level == NOVALUE)
            return TRUE;
        else {
            if(p1.level >= p2.level)
                return TRUE;
            else
                return FALSE;
        }
    }
}

int rolematch(string& rl, _privilege& prvl) {
    int ans = FALSE;
    for(int i = 0; i < (int)role.size(); i++) {
        if(role[i].role == rl) {
            for(int j = 0; j < role[i].s; j++) {
                int rt = privilegematch(role[i].privilege[j], prvl);
                if(rt > ans)
                    ans = rt;
            }
        }
    }
    return ans;
}

int query(string& usr, _privilege& prvl) {
    for(int i = 0; i < (int)user.size(); i++) {
        if(user[i].user == usr) {
            int ans = FALSE;
            for(int j = 0; j < user[i].t; j++) {
                int rt = rolematch(user[i].role[j], prvl);
                if(rt > ans)
                    ans = rt;
            }
            return ans;
        }
    }
    return FALSE;
}

int main() {
    int p, r, u, q;
    cin >> p;
    string c;
    _privilege prvl;
    for(int i = 1; i <= p; i++) {
        cin >> c;
        prvl.category = getcategory(c);
        prvl.level = getlevel(c);
        privilege.push_back(prvl);
    }

    cin >> r;
    for(int i = 1; i <= r; i++) {
        _role r1;
        cin >> r1.role >> r1.s;
        for(int j = 1; j <= r1.s; j++) {
            cin >> c;
            prvl.category = getcategory(c);
            prvl.level = getlevel(c);
            r1.privilege.push_back(prvl);
        }
        role.push_back(r1);
    }

    cin >> u;
    for(int i = 1; i <= u; i++) {
        _user us;
        cin >> us.user >> us.t;
        for(int j = 1; j <= us.t; j++) {
            cin >> c;
            us.role.push_back(c);
        }
        user.push_back(us);
    }

    cin >> q;
    string suser;
    for(int i = 1; i <= q; i++) {
        cin >> suser >> c;
        prvl.category = getcategory(c);
        prvl.level = getlevel(c);
        int ans = query(suser, prvl);
        if(ans == TRUE)
            cout << "true" << endl;
        else if(ans == FALSE)
            cout << "false" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}











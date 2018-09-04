#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isInteresting(int num, int n) {
    int digits[1001];
    vector<int> num0, num1, num2, num3;
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        int digit = num % 10;
        //cout << digit << " " << i << " " << num << endl;
        num /= 10;
        if(digit == 0) {
            if(num1.empty())
                return false;
            num0.push_back(digit);
        }
        else if(digit == 1)
            num1.push_back(digit);
        else if(digit == 2) {
            if(num3.empty())
                return false;
            num2.push_back(digit);
        }
        else if(digit == 3)
            num3.push_back(digit);
        else {
            //cout << "another digit" << endl;
            return false;
        }
    }
    if(num0.empty() || num1.empty() || num2.empty() || num3.empty()) {
        //cout << "empty stack" << endl;
        return false;
    }
    /*if(num1[num1.size()-1] > num0[0] || num3[num3.size()-1] > num2[0]) {
        cout << "error digit" << endl;
        cout << num1[num1.size()-1] << ">" << num0[0] << endl;
        cout << num3[num3.size()-1] << ">" << num2[0] << endl;
        return false;
    }*/
    return true;
}

int main() {
    int n, num = 0;
    cin >> n;
    for(int i = pow(10, n - 1); i < 2.4 * pow(10, n - 1); i++) {
        if(isInteresting(i, n)) {
            //cout << i << endl;
            num++;
        }
    }
    //cout << isInteresting(2301, 4) << endl;
    cout << num << endl;
    return 0;
}

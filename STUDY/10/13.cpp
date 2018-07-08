#include <bits/stdc++.h>  
using namespace std;  
  
struct sup {  
    int a[1001], len;  
    bool minus;  
    sup(int x = 0) { //x非负  
        for(int i=0; i<1001; i++) a[i] = 0;  
        len = 0;  
        do {  
            a[++len] = x % 10;  
            x /= 10;  
        } while(x);  
        minus = 0;  
    }  
    bool operator <(sup b) const {  
        if(len == b.len) {  
            for(int i=len; i>=1; i--)  
                if(a[i] < b.a[i]) return true;  
                else if(a[i] > b.a[i]) return false;  
            return false;  
        }  
        return len < b.len;  
    }  

    sup operator *(sup b) {  
        sup ans;  
        ans.len = len + b.len;  
        for(int j=1; j<=b.len; j++) {  
            for(int i=1; i<=len; i++) {  
                ans.a[i+j-1] += b.a[j] * a[i];  
                ans.a[i+j] += ans.a[i+j-1] / 10;  
                ans.a[i+j-1] %= 10;  
            }  
            if(ans.a[b.len+len]) {  
                ans.a[b.len+len+1] += ans.a[b.len+len] / 10;  
                ans.a[b.len+len] %= 10;  
            }  
        }  
        while(ans.len > 1 && !ans.a[ans.len]) ans.len --;  
        return ans;  
    }  
    sup operator /(const int &b) { //除以低精  
        if(*this < sup(b)) return sup(0);  
        sup ans;  
        ans.len = len;  
        int r = 0;  
        for(int i=ans.len; i>=1; i--) {  
            r = r * 10 + a[i];  
            ans.a[i] = r / b;  
            r %= b;  
        }  
        while(ans.len > 1 && !ans.a[ans.len]) ans.len --;  
        return ans;  
    }  
    sup operator /(sup b) {  
        if(*this < b) return sup(0);  
        sup ans;  
        ans.len = len - b.len + 1;  
        for(int i=ans.len; i>=1; i--) {  
            for(int j=1; j<=9; j++) {  
                ans.a[i] ++;  
                if((*this) < (ans * b)) {  
                    ans.a[i] --;  
                    break;  
                }  
            }  
            if(ans.a[ans.len] == 0) ans.len --;  
        }  
        while(ans.len > 1 && !ans.a[ans.len]) ans.len --;  
        return ans;  
    }  
    void Scan(int x) {  
        char s[1001];  
        
        len = strlen(s);  
        for(int i=0; i<len; i++) a[len-i] = s[i] - '0';  
    }  
    void Print(bool h) const {  
        if(minus) cout << '-';  
        for(int i=len; i>=1; i--)  
            cout << a[i];  
        if(h) cout << endl;  
    }  
} A, B;  
  
int main() {  
    cout << "Input a, b (a > b):\n";  
    A.Scan(1231321);  
    B.Scan(1231231);  
    cout << "A * B = ";  
    (A*B).Print(1);  
    cout << "A / B = ";  
    (A/B).Print(1);  
    return 0;  
}  
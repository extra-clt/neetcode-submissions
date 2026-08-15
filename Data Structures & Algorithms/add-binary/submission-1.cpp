class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a,b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        //a is larger
        //could try xor
        string sol;
        int carry = 0;;
        for (int i = 0; i < b.size(); i++) {
            cout << a[i] << " " << b[i] << endl;
            if (carry == 0) {
                if (a[i] == '0' && b[i] == '0') {
                    carry = 0; a[i] = '0';
                }
                else if (a[i] == '0' && b[i] == '1') {
                    carry = 0; a[i] = '1';
                }
                else if (a[i] == '1' && b[i] == '0') {
                    carry = 0; a[i] = '1';
                }
                else {
                    carry = 1; a[i] = '0';
                }
            }
            else {
                if (a[i] == '0' && b[i] == '0') {
                    carry = 0; a[i] = '1';
                }
                else if (a[i] == '0' && b[i] == '1') {
                    carry = 1; a[i] = '0'; 
                }
                else if (a[i] == '1' && b[i] == '0') {
                    carry = 1; a[i] = '0'; 
                }
                else {
                    carry = 1; a[i] = '1';
                }
            }
        }
        cout << "a: " << a << endl;
        
        if (carry == 1) {
            int idx = b.size() ;
            cout << idx << endl;
            while (idx < a.size() && carry == 1) {
                if (a[idx] == '0') {
                    a[idx] = '1'; carry = 0; cout << "true1";
                }
                else {
                    a[idx] = '0'; carry = 1; cout << "true2";
                }
                cout << a[idx] << endl;
                idx++;
            }
            if (carry == 1) {
                sol += a;
                sol += '1';
                reverse(sol.begin(), sol.end());
                return sol;
            }
        }
        reverse(a.begin(), a.end());
        return a;
    }
};
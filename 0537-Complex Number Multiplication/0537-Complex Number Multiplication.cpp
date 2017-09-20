class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        vector<int> ca = extract(a);
        vector<int> cb = extract(b);
        int x = ca[0] * cb[0] - ca[1] * cb[1];
        int y = ca[0] * cb[1] + ca[1] * cb[0];
        
        return to_string(x) +  '+' + to_string(y) + 'i';
    }
    
private:
    vector<int> extract(string& s)
    {
        int i = 0;
        int signx = 1, signy = 1;
        int x = 0, y = 0;
        if (s[i] == '-')
        {
            ++i;
            signx = -1;
        }
        
        while (s[i] != '+')
        {
            x = x * 10 + (s[i++] - '0');
        }
        
        x *= signx;
        
        ++i;
        if (s[i] == '-')
        {
            ++i;
            signy = -1;
        }
        
        while (s[i] != 'i')
        {
            y = y * 10 + (s[i++] - '0');
        }
        y *= signy;
        
        return {x, y};
    }
};

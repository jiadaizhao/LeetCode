class StringIterator {
public:
    StringIterator(string compressedString) {
        start = 0;
        str = compressedString;
        if (str.size())
        {
            c = str[start++];
        }
        count = 0;
        
        while (start < str.size() && isdigit(str[start]))
        {
            count = count * 10 + (str[start] - '0');
            ++start;
        }
    }
    
    char next() {
        if (hasNext())
        {
            char result = c;
            --count;
            if (count == 0)
            {
                if (start < str.size())
                {
                    c = str[start++];
                }
                while (start < str.size() && isdigit(str[start]))
                {
                    count = count * 10 + (str[start] - '0');
                    ++start;
                }
            }
            
            return result;
        }
        else
        {
            return ' ';
        }
    }
    
    bool hasNext() {
        return count;        
    }
    
private:
    string str;
    int start;
    int count;
    char c;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
 
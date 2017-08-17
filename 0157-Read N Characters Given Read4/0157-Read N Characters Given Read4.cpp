// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n)
        {
            int num = read4(buf);
            i += num;
            buf += num;
            if (num < 4)
            {
                break;
            }            
        }
        
        return min(i, n);
    }
};

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
        while (i < n) {
            if (i4 == n4) {
                i4 = 0;
                n4 = read4(buf4);
                if (n4 == 0) {
                    break;
                }
            }
            buf[i++] = buf4[i4++];
        }
        
        return i;
    }
    
private:
    char buf4[4];
    int i4 = 0, n4 = 0;
};

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (i4 == n4) {
                i4 = 0;
                n4 = read4(buf4);
                if (n4 == 0) {
                    break;
                }
            }
            int len = min(n4 - i4, n - i);
            memcpy(buf + i, buf4 + i4, len);
            i += len;
            i4 += len;
        }
        
        return i;
    }
    
private:
    char buf4[4];
    int i4 = 0, n4 = 0;
};

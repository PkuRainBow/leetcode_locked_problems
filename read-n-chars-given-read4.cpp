/** Solution Post : https://leetcode.com/discuss/100831/summary-of-the-solutions-for-no-157-%26-no-158 **/


/**	
	NO.157  Read N characters Given Read4

	The API: int read4(char *buf) reads 4 characters at a time from a file.

	The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

	By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

**/



// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    /** There are 2 corner cases:
     *   1) read more chars than n, but we need only n chars
     *   2) read chars less than 4, we have read all the data 
     **/
    int read(char *buf, int n) {
        int result = 0;
        /** we have not read enough chars **/
        while(n > 0) {
            int temp = min(read4(buf), n);
            result += temp;
            buf += temp;
            /** we have meet the EOF of the file **/
            if(temp < 4)
                break;
            n -= 4;
        }
        return result;
    }
};



/**	
	NO.158  Read N characters Given Read4 -- Call Multiple times

	The API: int read4(char *buf) reads 4 characters at a time from a file.

	The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

	By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

	Note : The read function maybe called multiple times
**/

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
        if(n == 0)
            return 0;
        int total = 0;
        /** read n chars into the queue with temp **/
        while(this->buffer.size() < n && !this->endOfFile) {
            char* temp = new char[4];
            int r = read4(temp);
            if(r < 4)
                this->endOfFile = true;
            for(int i = 0; i < r; i++)
                this->buffer.push(temp[i]);
        }
        /** read n chars from the queue **/
        int l = min((int)this->buffer.size(), n);
        for(int i = 0; i < l; i++) {
            buf[i] = this->buffer.front();
            this->buffer.pop();
            total++;
        }
        return total;
    }
private:
    queue<char> buffer;
    bool endOfFile = false;
};
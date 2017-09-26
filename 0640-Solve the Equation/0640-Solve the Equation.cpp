class Solution {
public:
    string solveEquation(string equation) {
        int n = equation.size();
        int i = 0;
        int leftx = 0, rightx = 0;
        int leftsum = 0, rightsum = 0;
        int num = 0;
        bool prenum = false;
        int sign = 1;
        while (i < n && equation[i] != '=')
        {
            if (isdigit(equation[i]))
            {
                num = num * 10 + (equation[i] - '0');
                prenum = true;
            }
            else if (equation[i] == 'x')
            {
                if (prenum)
                {
                    leftx += sign * num;
                }
                else
                {
                    leftx += sign;
                }
                num = 0;
            }
            else
            {
                leftsum += sign * num;
                sign = (equation[i] == '+') ? 1 : -1;
                num = 0;
                prenum = false;
            }
            
            ++i;
        }
        
        leftsum += sign * num;
        ++i;
        num = 0;
        sign = 1;
        prenum = false;
        
        while (i < n)
        {
            if (isdigit(equation[i]))
            {
                num = num * 10 + (equation[i] - '0');
                prenum = true;
            }
            else if (equation[i] == 'x')
            {
                if (prenum)
                {
                    rightx += sign * num;
                }
                else
                {
                    rightx += sign;
                }
                num = 0;
            }
            else
            {
                rightsum += sign * num;
                sign = (equation[i] == '+') ? 1 : -1;
                num = 0;
                prenum = false;
            }
            
            ++i;
        }
        rightsum += sign * num;
        
        int xnum = leftx - rightx;
        int val = rightsum - leftsum;
        
        if (xnum == 0)
        {
            if (val == 0)
            {
                return "Infinite solutions";
            }
            else
            {
                return "No solution";
            }
        }
        else
        {
            return "x=" + to_string(val / xnum);
        }
    }
};

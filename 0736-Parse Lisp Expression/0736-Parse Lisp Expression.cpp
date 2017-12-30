class Solution {
public:
    int evaluate(string expression) {
        scope.push_back(unordered_map<string, int>());
        int result = evaluate_inner(expression);
        scope.pop_back();
        return result;
    }
    
private:
    vector<unordered_map<string, int>> scope;
    int evaluate_inner(const string& expression) {
        if (expression[0] != '(') {
            if (isdigit(expression[0]) || expression[0] == '-') {
                return stoi(expression);
            }
            for (int i = scope.size() - 1; i >= 0; --i) {
                if (scope[i].count(expression)) {
                    return scope[i][expression];
                }
            }
        }
        
        int start = expression[1] == 'm' ? 6 : 5;
        vector<string> tokens = parse(expression.substr(start, expression.size() - 1 - start));
        if (expression.find("add", 1) == 1) {
            return evaluate(tokens[0]) + evaluate(tokens[1]);
        }
        else if (expression.find("mult", 1) == 1) {
            return evaluate(tokens[0]) * evaluate(tokens[1]);
        }
        else {
            // "let"
            for (int j = 1; j < tokens.size(); j += 2) {
                scope.back()[tokens[j - 1]] = evaluate(tokens[j]);
            }
            return evaluate(tokens.back());
        }
    }
     
    vector<string> parse(const string& expression) {
        vector<string> result;
        int bal = 0;
        stringstream ss(expression);
        string token;
        string buf;
        while (getline(ss, token, ' ')) {
            for (char c : token) {
                if (c == '(') ++bal;
                if (c == ')') --bal;
            }
            if (buf.size() > 0) buf += ' ';
            buf += token;
            if (bal == 0) {
                result.push_back(buf);
                buf = "";
            }            
        }
        
        if (buf.size() > 0) {
            result.push_back(buf);
        }
        
        return result;
    }
};

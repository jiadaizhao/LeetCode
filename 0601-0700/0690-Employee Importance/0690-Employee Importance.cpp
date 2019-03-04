/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> table;
        for (auto e : employees) {
            table[e->id] = e;
        }
        
        if (table.find(id) == table.end()) {
            return 0;
        }
        int sum = 0;
        queue<Employee*> Q;
        Q.push(table[id]);
        while (!Q.empty()) {
            Employee* e = Q.front();
            Q.pop();
            sum += e->importance;
            for (int i : e->subordinates) {
                Q.push(table[i]);
            }
        }
        
        return sum;        
    }    
};

class FileSystem {
public:
    FileSystem() {
        table[""] = -1;
    }
    
    bool createPath(string path, int value) {
        string parent = path.substr(0, path.rfind("/"));
        if (!table.count(parent) || table.count(path)) {
            return false;
        }
        else {
            table[path] = value;
            return true;
        }
    }
    
    int get(string path) {
        return table.count(path) ? table[path] : -1;
    }
    
private:
    unordered_map<string, int> table;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

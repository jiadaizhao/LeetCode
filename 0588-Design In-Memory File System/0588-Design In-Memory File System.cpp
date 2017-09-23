class FileSystem {
public:
    FileSystem() {
        root = new Dir();
    }
    
    vector<string> ls(string path) {
        Dir* node = root;
        vector<string> result;
        if (path != "/")
        {
            vector<string> paths = split(path);

            int n = paths.size();
            for (int i = 0; i < n - 1; ++i)
            {
                node = node->dirs[paths[i]];
            }

            if (node->files.find(paths.back()) != node->files.end())
            {
                result.push_back(paths.back());
                return result;
            }
            else
            {
                node = node->dirs[paths.back()];
            }
        }
        
        for (auto dir : node->dirs)
        {
            result.push_back(dir.first);
        }
        
        for (auto file : node->files)
        {
            result.push_back(file.first);
        }
        
        sort(result.begin(), result.end());
        return result;    
    }
    
    void mkdir(string path) {
        Dir* node = root;
        vector<string> paths = split(path);
        
        int n = paths.size();
        for (int i = 0; i < n; ++i)
        {
            if (node->dirs.find(paths[i]) == node->dirs.end())
            {
                node->dirs[paths[i]] = new Dir();
            }
            node = node->dirs[paths[i]];
        }                
    }
    
    void addContentToFile(string filePath, string content) {
        Dir* node = root;
        vector<string> paths = split(filePath);

        int n = paths.size();
        for (int i = 0; i < n - 1; ++i)
        {
            node = node->dirs[paths[i]];
        }
        
        if (node->files.find(paths.back()) == node->files.end())
        {
            node->files[paths.back()] = content;
        }
        else
        {
            node->files[paths.back()] += content;
        }
    }
    
    string readContentFromFile(string filePath) {
        Dir* node = root;
        vector<string> paths = split(filePath);

        int n = paths.size();
        for (int i = 0; i < n - 1; ++i)
        {
            node = node->dirs[paths[i]];
        }
        
        return node->files[paths.back()];
    }
    
private:
    struct Dir {
        unordered_map<string, Dir*> dirs;
        unordered_map<string, string> files;
    };
    Dir* root;
    vector<string> split(string path)
    {
        stringstream ss(path);
        string s;
        vector<string> paths;
        while (getline(ss, s, '/'))
        {
            if (s.size())
            {
                paths.push_back(s);
            }
        }
        return paths;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
 
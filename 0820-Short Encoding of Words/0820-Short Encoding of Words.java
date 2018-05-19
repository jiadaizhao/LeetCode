import java.util.Arrays;

class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> table = new HashSet(Arrays.asList(words));
        for (String word : words) {
            for (int i = 1; i < word.length(); ++i) {
                table.remove(word.substring(i));
            }
        }

        int total = 0;
        for (String word : table) {
            total += word.length() + 1;
        }
        return total;
    }
}

class Solution {
    public int minimumLengthEncoding(String[] words) {
        TrieNode root = new TrieNode();
        Map<TrieNode, Integer> table = new HashMap();
        for (int i = 0; i < words.length; ++i) {
            TrieNode node = root;
            for (int j = words[i].length() - 1; j >= 0; --j) {
                int index = words[i].charAt(j) - 'a';
                if (node.next[index] == null) {
                    node.next[index] = new TrieNode();
                }
                ++node.count;
                node = node.next[index];
            }
            table.put(node, i);
        }

        int total = 0;
        for (TrieNode node : table.keySet()) {
            if (node.count == 0) {
                total += words[table.get(node)].length() + 1;
            }
        }
        return total;
    }
}

class TrieNode {
    TrieNode[] next;
    int count;
    TrieNode() {
        next = new TrieNode[26];
        count = 0;
    }
}

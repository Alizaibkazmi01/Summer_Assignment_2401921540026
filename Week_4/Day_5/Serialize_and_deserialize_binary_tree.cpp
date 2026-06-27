/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // This is BFS, which means level order traversal using queue.
    string serialize(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        string serializedTree = "";

        while (!queue.empty()) {
            TreeNode* element = queue.front();
            queue.pop();
            if (element == nullptr) {
                serializedTree += "n,";
                continue;
            } 

            serializedTree += to_string(element -> val);
            serializedTree += ",";

            queue.push(element->left);
            queue.push(element->right);
        }

        // Check if it will work without this
        // if (serializedTree == "") return serializedTree;

        serializedTree.pop_back();
        return serializedTree;
    }

    // Decodes your encoded data to tree.
    // 1,2,3,n,n,4,5,n,n,n,n
    TreeNode* deserialize(string data) {
        queue<TreeNode*> connectionQueue;
        vector<TreeNode*> nodes;
        int index = 0;
        stringstream streamData(data);
        string tempstr; 

        while (getline(streamData, tempstr, ',')) {
            if (tempstr == "n") {
                nodes.push_back(nullptr);
            } else {
                nodes.push_back(new TreeNode(stoi(tempstr)));
            }   
        }

        if (nodes.empty()) return nullptr;

        connectionQueue.push(nodes[index++]);

        while (!connectionQueue.empty()) {
            TreeNode* element = connectionQueue.front();
            connectionQueue.pop();
            if (element == nullptr) {
                continue;
            } 

            TreeNode* left = nodes[index++];
            TreeNode* right = nodes[index++];
            connectionQueue.push(left);
            connectionQueue.push(right);
                
            element -> left = left;
            element -> right = right;
        }

        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

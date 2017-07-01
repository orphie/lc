class Solution {
public:
    typedef std::unordered_map<TreeNode*, TreeNode*> Node2Parent;
    typedef std::unordered_set<TreeNode*> Nodes;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) return root;
        if (p == q) return p;
        Node2Parent n2p;

        size_t cnt = 0;
        exploreNode(root, cnt, p, q, n2p); 

        Nodes nodes;
        TreeNode* parentOfP = p;
        TreeNode* parentOfQ = q;
        while (parentOfP != root ||
               parentOfQ != root) {            
            if (parentOfP != root) {
                if (nodes.find(parentOfP) != nodes.end()) return parentOfP;
                nodes.insert(parentOfP);
                parentOfP = n2p[parentOfP];
            }      
            if (parentOfQ != root) {
                if (nodes.find(parentOfQ) != nodes.end()) return parentOfQ;
                nodes.insert(parentOfQ);
                parentOfQ = n2p[parentOfQ];
            }   
        }   
        return root;
    }   

    inline void exploreNode(TreeNode* node, size_t& cnt, TreeNode* p, TreeNode* q, Node2Parent& n2p)
    {   
        if (!node || cnt == 2) return;
        if (node == p || node == q) {
            ++cnt;
        }
        if (node->left) {
            n2p[node->left] = node;
            exploreNode(node->left,  cnt, p, q, n2p);
        }
        if (node->right) {
            n2p[node->right] = node;
            exploreNode(node->right, cnt, p, q, n2p);
        }
    }
};

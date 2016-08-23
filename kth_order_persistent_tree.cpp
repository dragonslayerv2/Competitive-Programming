#include<iostream>
#include<vector>
using namespace std;

// 0 indexed persistent segment tree.
// 0th version will contain all elements to be defaultValue.
class PersistentSegmentTree {
    public:
        struct Node {
            int leftRange, rightRange;
            int value;
            Node *leftNode, *rightNode;
            
            Node() {
                leftRange = rightRange = -1;
                value = 0;
                leftNode = rightNode = NULL;
            }
        
            Node(Node *node) {
                leftRange = node->leftRange;
                rightRange = node->rightRange;
                value = node->value;
                leftNode = node->leftNode;
                rightNode = node->rightNode;
            }
        };

        PersistentSegmentTree() {}

        PersistentSegmentTree(int size, int defaultValue = 0) {
            assign(size, defaultValue);
        }
    
        void assign(int size, int defaultValue = 0) {
            roots.clear();
            roots.push_back(new Node());
            generateTree(roots.back(), 0, size - 1, defaultValue);
        }
    
        void update(int position, int value) {
            roots.push_back(new Node(roots.back()));
            update(roots.back(), position, value);
        }
    
        int query(int version, int queryLeft, int queryRight) {
            return query(roots[version], queryLeft, queryRight);
        }
    
        Node* getRootNode(int version) {
            return roots[version];
        }

    private:
        vector<Node*> roots;

        void generateTree(Node *currentNode, int leftRange, int rightRange, int defaultValue) {
            currentNode->leftRange = leftRange;
            currentNode->rightRange = rightRange;
            if (leftRange == rightRange) {
                currentNode->value = defaultValue;
            } else {
                currentNode->leftNode = new Node();
                currentNode->rightNode = new Node();
                generateTree(currentNode->leftNode, leftRange, (leftRange + rightRange)/2, defaultValue);
                generateTree(currentNode->rightNode, (leftRange + rightRange)/2 + 1, rightRange, defaultValue);
                currentNode->value = currentNode->leftNode->value + currentNode->rightNode->value;
            }
        }
    
        inline bool inRange(int point, Node *node) {
            if (point < node->leftRange || point > node->rightRange) {
                return false;
            } else {
                return true;
            }
        }
    
        inline bool rangesIntersect(int range1Left, int range1Right, int range2Left, int range2Right) {
            if (range1Left > range2Right || range1Right < range2Left) {
                return false;
            } else {
                return true;
            }
        }
    
        void update(Node *currentNode, int position, int value) {
            if (currentNode->leftRange == position && currentNode->rightRange == position) {
                currentNode->value += value;
            } else {
                if (inRange(position, currentNode->leftNode)) {
                    currentNode->leftNode = new Node(currentNode->leftNode);
                    update(currentNode->leftNode, position, value);
                } else {
                    currentNode->rightNode = new Node(currentNode->rightNode);
                    update(currentNode->rightNode, position, value);
                }
                currentNode->value = currentNode->leftNode->value + currentNode->rightNode->value;
            }
        }
    
        int query(Node *currentNode, int queryLeft, int queryRight) {
            if (!rangesIntersect(queryLeft, queryRight, currentNode->leftRange, currentNode->rightRange)) {
                return 0;
            } else if (currentNode->leftRange >= queryLeft && currentNode->rightRange <= queryRight) {
                return currentNode->value;
            } else {
                return query(currentNode->leftNode, queryLeft, queryRight)
                    + query(currentNode->rightNode, queryLeft, queryRight);
            }
        }
};

// KthOrderTree. Elements must be positive and must be less than maxElement. Use coordinate compression for large or negative elements.
class KthOrderTree {
    private:
        PersistentSegmentTree persistentSegmentTree;
    
    public:
        KthOrderTree(vector<int> &elements, int maxElement) {
            persistentSegmentTree.assign(maxElement, 0);
            for (int i = 0; i < elements.size(); i++) {
                persistentSegmentTree.update(elements[i], 1);
            }
        }
    
        // Returns the kth element in the range. Range must be [1, elements.size()]. Left and Right must be [1, elements.size()]
        int kthQuery(int leftRange, int rightRange, int k) {
            if (k > rightRange - leftRange + 1) {
                return -1;
            }
            PersistentSegmentTree::Node* leftSegmentTreeNode = persistentSegmentTree.getRootNode(leftRange - 1);
            PersistentSegmentTree::Node* rightSegmentTreeNode = persistentSegmentTree.getRootNode(rightRange);
            while (leftSegmentTreeNode->leftRange != leftSegmentTreeNode->rightRange) {
                int lessThanRangeMidElements = rightSegmentTreeNode->leftNode->value - leftSegmentTreeNode->leftNode->value;
                if (lessThanRangeMidElements >= k) {
                    leftSegmentTreeNode = leftSegmentTreeNode->leftNode;
                    rightSegmentTreeNode = rightSegmentTreeNode->leftNode;
                } else {
                    k -= lessThanRangeMidElements;
                    leftSegmentTreeNode = leftSegmentTreeNode->rightNode;
                    rightSegmentTreeNode = rightSegmentTreeNode->rightNode;
                }
            }
            return leftSegmentTreeNode->leftRange;
        }

        // Returns the kth element in the range. Range must be [1, elements.size()]. Left and Right must be [1, elements.size()]
        int rankQuery(int leftRange, int rightRange, int element) {
            int rank = 0;
            PersistentSegmentTree::Node* leftSegmentTreeNode = persistentSegmentTree.getRootNode(leftRange - 1);
            PersistentSegmentTree::Node* rightSegmentTreeNode = persistentSegmentTree.getRootNode(rightRange);
            while (leftSegmentTreeNode->leftRange != leftSegmentTreeNode->rightRange) {
                if (element > leftSegmentTreeNode->leftNode->rightRange) {
                    rank += rightSegmentTreeNode->leftNode->value - leftSegmentTreeNode->leftNode->value;
                    leftSegmentTreeNode = leftSegmentTreeNode->rightNode;
                    rightSegmentTreeNode = rightSegmentTreeNode->rightNode;
            } else {
                leftSegmentTreeNode = leftSegmentTreeNode->leftNode;
                rightSegmentTreeNode = rightSegmentTreeNode->leftNode;
            }
        }
        rank += rightSegmentTreeNode->value - leftSegmentTreeNode->value;
        return rank;
    }
};

int main() {
    int arr[] = {1 , 2, 5, 4 , 3, 1, 4 ,2, 3, 6};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(*arr));
    KthOrderTree kthOrderTree(vec, 10);
}

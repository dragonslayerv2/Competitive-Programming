#include<iostream>
#include<vector>
using namespace std;

// 0 indexed persistent segment tree.
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
    
    
    
        PersistentSegmentTree(int size, int defaultValue = 0) {
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

int main() {
    PersistentSegmentTree ST(10);
    for (int i = 0; i < 10; i++) {
        ST.update(i, i);
        cout << ST.query(i + 1,i,i);
    }
}

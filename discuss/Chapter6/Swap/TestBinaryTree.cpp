#include "BinaryTree.h" // 二叉链表类

int main(void)
{
    BinTreeNode<char>* p;
    char pre[] = {'A', 'B', 'D', 'E', 'G', 'H', 'C', 'F', 'I'}; // 先序序列
    char in[] = {'D', 'B', 'G', 'E', 'H', 'A', 'C', 'F', 'I'};  // 中序序列
    int n = 9;                                                  // 结点个数
    BinaryTree<char> bt;
    char c = 'x', e;

    bt = CreateBinaryTree(pre, in, n); // 构造二叉树

    cout << "由先序：A,B,D,E,G,H,C,F,I和中序：D,B,G,E,H,A,C,F,I构造的二叉树:" << endl;
    DisplayBTWithTreeShape<char>(bt);
    cout << endl;

	cout << "将二叉树所有结点的左右子树交换:" << endl;
    bt.Swap(bt.GetRoot());
    DisplayBTWithTreeShape<char>(bt);
    cout << endl;

    return 0;
}

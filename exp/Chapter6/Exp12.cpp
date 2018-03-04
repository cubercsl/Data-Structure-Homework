template <class ElemType>
ThreadBinTreeNode<ElemType>* PreThreadBinTree<ElemType>::GetNext(ThreadBinTreeNode<ElemType>* p) const
// 返回先序序列中p的后继结点
{
    return p->leftTag ? p->rightChild : p->leftChild;
}
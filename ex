#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CBinNode
{
    CBinNode(int _v)
    { value = _v; nodes[0] = nodes[1] = 0;  }
    int value;
    CBinNode* nodes[2];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool Insert(int x);
    bool Remove(int x);
    void Print();
private:
    bool Find(int x, CBinNode**& p);
    CBinNode** Rep(CBinNode** p);
    void InOrder(CBinNode* n);
    CBinNode* m_root;
    bool m_b;
};

CBinTree::CBinTree()
{
    m_root = 0;
    m_b = 1;
}

CBinTree::~CBinTree()
{
    // ?
}

bool CBinTree::Find(int x, CBinNode**& p)
{
    for ( p = &m_root;
          *p && (*p)->value != x;
          p = &((*p)->nodes[(*p)->value < x]) );
    return *p != 0;
}

bool CBinTree::Insert(int x)
{
    CBinNode** p;
    if ( Find(x,p) ) return 0;
    *p = new CBinNode(x);
    return 1;
}

bool CBinTree::Remove(int x)
{
    CBinNode** p;
    if ( !Find(x,p) ) return 0;
    if ( (*p)->nodes[0] && (*p)->nodes[1] )
    {
        CBinNode** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }
    CBinNode* t = *p;
    *p = (*p)->nodes[(*p)->nodes[0]==0];
    delete t;
    return 1;
}

CBinNode** CBinTree::Rep(CBinNode** p)
{
    assert(*p!=0);
    CBinNode** q;
    for ( q = &((*p)->nodes[!m_b]);
          (*q)->nodes[m_b];
          q = &((*q)->nodes[m_b]) );
    m_b = !m_b;
    return q;
}

void CBinTree::InOrder(CBinNode* n)
{
    if ( !n ) return;
    InOrder(n->nodes[0]);
    std::cout<<n->value<<" ";
    InOrder(n->nodes[1]);
}

void CBinTree::Print()
{
    InOrder(m_root);
    std::cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    
    t.Insert(50); t.Insert(30); t.Insert(60);
    t.Insert(80); t.Insert(55); t.Insert(11);
    t.Insert(33); t.Insert(5); t.Insert(14);
    t.Insert(31); t.Insert(48);
    t.Print();
    
    t.Remove(31); t.Print(); //case 0
    t.Remove(14); t.Print(); //case 0
    
    t.Remove(11); t.Print(); //case 1, left
    t.Remove(33); t.Print(); //case 1, right
    
    t.Remove(50); t.Print(); //case 2
    
    t.Remove(60); t.Print();
    t.Remove(48); t.Print();
    t.Remove(55); t.Print();
    t.Remove(5);  t.Print();
    t.Remove(80); t.Print();
    
    t.Remove(30); t.Print();
}

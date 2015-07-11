#ifndef _tree_h
#define ElementType int

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *Searchtree;

Searchtree MakeEmpty(Searchtree t);
Position Find(ElementType x, Searchtree t);
Position Findmin(Searchtree t);
Position Findmax(Searchtree t);
Searchtree Insert(ElementType x, Searchtree t);
Searchtree Delete(ElementType x, Searchtree t);
ElementType Retrieve(Position p);

#endif /* _tree_h*/

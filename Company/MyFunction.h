//二叉链表的创建及基本操作

const int MAXN = 100;

typedef char *TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild, *parent;
    bool l, r; //判断是否存在左右孩子
} BiTNode, *BiTree;

BiTree CreatNode(TElemType ch);
void Print(BiTree &T, int i);
void AddNode(BiTree &T, TElemType employer, TElemType employee);
void DeleteNode(BiTree &T, TElemType employer);
void Replace(BiTree &T);
BiTree getNextNode(BiTree &T);
BiTree getMinNode(BiTree &T);
int BiTreeDepth(BiTree &T);

bool get_Value_String1(char *str1, const char *str2);
char *get_Value_String_Employee(char *str1, const char *str2);
int get_Value_String2(char *str1, const char *str2);

//二叉链表的创建及基本操作

const int MAXN = 100;

typedef char* TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild, * rchild, * tempchild, * parent;
    bool l, r;//判断是否存在左右孩子
    bool flag;
}BiTNode, * BiTree;
//二叉链表的链式存储 

BiTree CreatNode(TElemType ch);
void Print(BiTree& T);
void AddNode(BiTree& T, TElemType employer, TElemType employee);
void DeleteNode(BiTree& T, TElemType employer);
void Replace(BiTree& T);
BiTree getNextNode(BiTree& T);
BiTree getMinNode(BiTree& T);

bool get_Value_String1(char* str1, const char* str2);//error in this function
char* get_Value_String_Employee(char* str1, const char* str2);
int get_Value_String3(char* str1, const char* str2);

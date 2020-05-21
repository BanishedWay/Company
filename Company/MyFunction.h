//二叉链表的创建及基本操作

const int MAXN = 100;

typedef char* TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild, * parent;
	bool l, r; //判断是否存在左右孩子
} BiTNode, * BiTree;

BiTree CreatNode(TElemType ch);
void Print(BiTree& T, int i);//先序遍历输出二叉树
void AddNode(BiTree& T, TElemType employer, TElemType employee);//找到employer所在的结点，并对它添加孩子结点
void DeleteNode(BiTree& T, TElemType employer);//调用Replace函数删除结点
void Replace(BiTree& T);//判断结点是否存在左右孩子并对其做出相应的操作
BiTree getNextNode(BiTree& T);//在Replace函数中T如果左右孩子都存在，则递归调用此函数对其子树依次替换
BiTree getMinNode(BiTree& T);//找到左叶子结点
int BiTreeDepth(BiTree& T);

bool get_Value_String1(char* str1, const char* str2);//判断str1中是否包含str2，用以判断输入的字符串中是否含有hires，fire,或print
char* get_Value_String_Employee(char* str1, const char* str2);//从字符串中提取雇员字符串
int get_Value_String2(char* str1, const char* str2);//返回雇员字符串首地址在输入字符串中所处的位置

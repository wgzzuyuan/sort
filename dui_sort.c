/*这个版本来自百度百科的堆排序*/
#include <stdio.h>
#include <stdlib.h>
 
void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
 
void max_heapify(int arr[], int start, int end) 
{
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)  //若子节点指标在范围内才做比较
        {
            if (son + 1 <= end && arr[son] < arr[son + 1]) 
            //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
            return;
        else  //否则交换父子内容再继续子节点和孙节点比较
        {
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
 
void heap_sort(int arr[], int len) 
{
    int i;
    //初始化，i从最後一个父节点开始调整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    //先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = len - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}
 
int main() {
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}



/*视频中的版本======这个来自于视频，手抄的*/
#include <stdio.h>

/*******************************************************




*******************************************************/

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
/*
功能：构建一个堆
参数：tree[]树，n 树的节点个数，i 要操作树中的第几个节点
返回值：无
*/
void heapify(int tree[],int n,int i){
	if( i >= n ){
		return;
	}
	int leftchild=2*i+1;
	int rightchild=2*i+2;
	int max = i;//最开始i是第一个节点的数据，假设第一个节点的值最大
	if(leftchild<n&&tree[leftchild]>tree[max]){
		max = leftchild;
	}
	if(rightchild<n&&leftchild<n&&tree[rightchild]>tree[max]){
		max = rightchild;
	}
	if(max != i){
		swap(tree,max,i);
		heapify(tree,n,max);
	}
}
/*
功能：
参数：tree
返回值：
*/
void build_heap(int tree[],int n){
	int last_node = n-1;
	int parent = (last_node - 1)/2;
	int i;
	for (i = parent; i >= 0; i--){
		heapify(tree,n,0);
	}
}

/*
功能：
参数：
返回值：
*/
void heap_sort(int tree[],int n){
	build_heap(tree,n);
	int i;
	for(i = n-1; i>= 0;i--){
		swap(tree,i,0);
		heapify( tree, i, 0);		
	}
}
int main(){
#ifdef 0
	int tree[]={4,10,3,5,1,2};
	int n=6;
	heap_sort(tree,n);
	static int i=0;
	for(i=0; i<n; i++; ){
		printf("%d\n",arr[i]);
	}
#endif
	return 0;

}

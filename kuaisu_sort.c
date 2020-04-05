/*
1，以前学习方法不对，不应该一下排序10个数，直接排序5个数就可以了，这样做的好处是容易培养思路
2，实战中必须要学的2种算法：快速排序和归并排序，从平均时间来看，快速排序是效率最高的，但快速排序在最坏情况下的时间性能不如堆排序和归并
排序。而后者相比较的结果是，在n较大时归并排序使用时间较少，但使用辅助空间较多。
3，时间性能好的排序算法：快速排序、堆排序、希尔排序等时间性能较好
4，上面的算法实现大多数是使用线性存储结构，像插入排序这种算法用链表实现更好，省去了移动元素的时间。具体的存储结构在具体的实现版本中也是不同的。
排序还要考虑你的内存空间是怎么排布的。

还有要会分析算法的时间和空间复杂度。通常查找和排序算法的考察是面试的开始，
*/

/*
各种算法的应用场景
1，时间短，快速排序
2，稳定性，基数排序
3，时间断，最坏情况下，用归并排序(就是N较大时)。
*/
/*不得不承认学习C++可以锻炼自己写算法的能力，这个看视频就能看出来，模块化编程*/

/*
最核心的东西是要看递归是怎么用的，从这个角度将，算法分为2步
1，进行第一次比较，分成2个序列
2，递归排序左面的序列和右面的序列
从这个步骤上看，你主要要实现的是怎么把序列分为2个序列，写的过程写完这个就没别的事了
*/


/*
把序列分为2个序列
该函数的返回值是中间的那个分割点，



*/

/**
 *@Description:<p>实现快速排序算法</p>
 *@author 王旭
 *@time 2016-3-3 下午5:07:29
 */
public class QuickSort {
    //一次划分
    public static int partition(int arr[] , int left, int right) {
        int pivotKey = arr[left];
        int pivotPointer = left;
    while(left &lt; right) {
        while(left &lt; right &amp;&amp; arr[right] &gt;= pivotKey)
            right --;
        while(left &lt; right &amp;&amp; arr[left] &lt;= pivotKey)
            left ++;
        swap(arr, left, right); //把大的交换到右边，把小的交换到左边。
    }
    swap(arr, pivotPointer, left); //最后把pivot交换到中间
    return left;
}

public static void quickSort(int arr[] , int left, int right) {
    if(left &gt;= right)
        return ;
    int pivotPos = partition(arr, left, right);
    quickSort(arr, left, pivotPos-1);
    quickSort(arr, pivotPos+1, right);
}

public static void sort(int arr[] ) {
    if(arr == null || arr.length == 0)
        return ;
    quickSort(arr, 0, arr.length-1);
}

public static void swap(int arr[] , int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

}



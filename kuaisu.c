

#include "stdio.h"



int Partion(int *arr,int low,int high)       //一次找基准过程

{

    int temp = arr[low];

    while(low < high)        //当low = high时退出循环,此时的位置为基准位置

    {

       while(low < high && arr[high] > temp)

       {

         high--;                              

       }

       if(low >= high)

       { 

           break;

       }

       else

       {

           arr[low] = arr[high];

       }

       while(low < high && arr[low] < temp)

       {

         low++;

       }

       if(low >= high)

       { 

           break;

       }

       else

       {

           arr[high] = arr[low];

       }

   }

   arr[low] = temp;

   return low;

}




void Quick(int *arr,int start,int end)     

{

    int par = Partion(arr,start,end);      //一次找基准

    if(par > start+1)

    {

        Quick(arr,start,par - 1);

    }

    if(par < end - 1)

    {  

        Quick(arr,par+1,end);

    }

}

void Quick_Sort(int *arr,int  len)      //len为数组的长度

{

    Quick(arr,0,len-1);

}

int aaa[]={3,67,4,6,89,24,7,9,94};
void main(){
int i=0;	
	Quick(aaa,0,8);
	for(i=0;i<9;i++){
	
printf("%d\n",aaa[i]);	
	}
}




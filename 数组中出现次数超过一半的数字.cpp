#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//找中位数，类似于快排的思想
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //找中位数，如果超过长度的一半，还需判断是否符合条件
        if(numbers.empty())
            return 0;
        int mid=numbers.size()/2;
        int l=0,r=numbers.size()-1;
        int index=Partition(numbers,l,r);
        while(index!=mid)
        {
            if(index>mid)
            {
                r=index-1;
                index=Partition(numbers,l,r);
            }
            else{
                l=index+1;
                index=Partition(numbers,l,r);
            }
        }
        int res=numbers[mid];
        return check(numbers,res)?res:0;
        
    }
    
private:
    //快排，返回最左侧数应该在的位子
    int Partition(vector<int>& numbers,int l,int r)
    {
        int cur=numbers[l];
        int j=l;
        for(int i=l+1;i<=r;++i)
        {
            if(numbers[i]<cur)
            {
                j++;
                swap(numbers[j],numbers[i]);
            }
        }
        swap(numbers[j],numbers[l]);
        return j;
    }
    
    bool check(vector<int>& numbers,int res)
    {
        int count=0;
        for(int x:numbers)
        {
            if(x==res)
                count++;
        }
        if(count*2<=numbers.size())
            return false;
        else
            return true;
    }
};


//找中位数，类似于快排的思想
//考虑到数组内重复情况较多，使用三路快排进行优化。
class Solution1{
public:
    //找中位数，如果超过长度的一半，还需判断是否符合条件
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int mid=numbers.size()/2;
        int l=0,r=numbers.size()-1;
        pair<int,int> index=Partition(numbers,l,r);
        while(index.first>mid||index.second<mid)
        {
            if(index.first>mid)
            {
                r=index.first-1;
                index=Partition(numbers,l,r);
            }
            else if(index.second<mid)
            {
                l=index.second+1;
                index=Partition(numbers,l,r);
            }
        }
        int res=numbers[mid];
        int length=index.second-index.first+1;
        return (2*length>numbers.size())?res:0;
 
    }
 
private:
    //三路快排
    pair<int,int> Partition(vector<int>& numbers,int l,int r)
    {
        int cur=numbers[l];
        int lt=l,gt=r+1,i=l;
        while (i<gt)
        {
            if(numbers[i]<cur)
            {
                swap(numbers[lt+1],numbers[i]);
                lt++;
                i++;
            }
            else if(numbers[i]>cur)
            {
                swap(numbers[i],numbers[gt-1]);
                gt--;
            }
            else
                i++;
        }
        swap(numbers[l],numbers[lt]);
        return make_pair(lt,gt-1);
 
    }
 
 
};

//根据数组的特点进行解决

import java.io.*;
import java.util.*;
class HistogramArea{
    public int largestRectangleArea(int[] a) {
        int n=a.length;
        int left[]=new int[n];//index of 1st smaller in left
    int right[]=new int[n];//index of 1st smaller in right
    Stack<Integer> st=new Stack<>();
    for(int i=0;i<n;i++)
    {
        while(st.size()!=0 && a[st.peek()]>=a[i])
        {
            st.pop();
        }
        if(st.size()==0)
        left[i]=-1;
        else
        left[i]=st.peek();
        st.push(i);
    }
    while(st.size()!=0)
    st.pop();
    
    for(int i=n-1;i>=0;i--)
    {
        while(st.size()!=0 && a[st.peek()]>=a[i])
        {
            st.pop();
        }
        if(st.size()==0)
        right[i]=n;
        else
        right[i]=st.peek();
        st.push(i);
    }
    
    int maxi=Integer.MIN_VALUE;
    
    for(int i=0;i<n;i++)
    {
        if((right[i]-left[i]-1)*a[i]>maxi)
        maxi=(right[i]-left[i]-1)*a[i];
    }
    
    return maxi;
    }
    
    
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no. of bars in the histogram : ");
        int n=sc.nextInt();
        System.out.println("\nEnter the array of heights : ");
        
        int[] heights = new int[n];  
        for(int i=0;i<n;i++)
            heights[i]=sc.nextInt();
        HistogramArea h=new HistogramArea();
        System.out.println("\nThe area of the largest possible Rectangle in the histogram is :"+h.largestRectangleArea(heights));

    }
}

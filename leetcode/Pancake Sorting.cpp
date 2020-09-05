class Solution {
public:
    void flip(int arr[], int i)  {  
        int temp, start = 0;  
        while (start < i)  
        {  
            temp = arr[start];  
            arr[start] = arr[i];  
            arr[i] = temp;  
            start++;  
            i--;  
        }  
    }  
    int findMax(int arr[], int n)  {  
        int mi, i;  
        for (mi = 0, i = 0; i < n; ++i)  
            if (arr[i] > arr[mi])  
                mi = i;  
        return mi;  
    } 
    vector<int> pancakeSort(vector<int>& A) {
        int arr[100];
        for(int i=0;i<A.size();i++){
            arr[i] = A[i];
        }
        int n = A.size();
        vector<int> result;
        for (int curr_size = n; curr_size > 1; --curr_size)  {  
            // Find index of the  
            // maximum element in  
            // arr[0..curr_size-1]  
            int mi = findMax(arr, curr_size);  

            // Move the maximum  
            // element to end of  
            // current array if  
            // it's not already  
            // at the end  
            if (mi != curr_size-1)  
            {  
                // To move at the end,  
                // first move maximum  
                // number to beginning  
                flip(arr, mi);  
                result.push_back(mi+1);
                // Now move the maximum  
                // number to end by  
                // reversing current array  
                flip(arr, curr_size-1);  
                result.push_back(curr_size);
            }  
        }
        return result;
    }
};
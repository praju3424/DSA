class Solution {
public:
    void sortColors(vector<int>& arr) {

        // int low=0,mid=0;
        // int high = arr.size()-1;
        // while(mid<=high){
        
        // if(arr[mid]==0){
        //     swap(arr[low],arr[mid]);
        //     low++;
        //     mid++;

        // }else if(arr[mid]==1){
        //     mid++;
        // }
        // else{
        //     swap(arr[mid],arr[high]);
        //     high--;
        // }

        // }
        int count0 =0;
        int count1 =0;
        int count2 =0;

        for(int i =0; i<arr.size(); i++){
            if(arr[i]==0){
                count0 ++;

            }else if(arr[i]==1){
                count1 ++;
            }else{
                count2 ++;
            }
        }
        for(int i =0; i<count0; i++){
            arr[i] = 0;
        }
        for(int i= count0 ; i<count0+count1; i++){
            arr[i] = 1;
        }
        for(int i=count0+count1; i<count1+count2+count0;i++){
            arr[i]=2;
        }
        
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        if(rowIndex == 0){
            ret.push_back(1);
            return ret;
        }else if(rowIndex == 1){
            ret.push_back(1);
            ret.push_back(1);
            return ret;
        }
        vector<int> before;
        before.push_back(1);
        before.push_back(1);
        for(int i=2;i<=rowIndex;i++){
            ret.clear();
            ret.push_back(1);
            for(int j=0;j<before.size()-1;j++){
                ret.push_back(before[j]+before[j+1]);
            }
            ret.push_back(1);
            before = ret;
        }
        return ret;
    }
};
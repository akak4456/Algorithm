class Solution {
public:
    string toGoatLatin(string S) {
        size_t previous = 0, current;
        current = S.find(' ');
        vector<string> arr;
        while (current != string::npos){
            string substring = S.substr(previous, current - previous);
            arr.push_back(substring);
            previous = current + 1;
            current = S.find(' ',previous); 
        }
        arr.push_back( S.substr(previous, current - previous));
        for(int i=0;i<arr.size();i++){
            char first = arr[i][0];
            
            if(first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u'||
              first == 'A' || first == 'E' || first == 'I' || first == 'O' || first == 'U'){
                
            }else{
                arr[i].erase(0,1);
                arr[i] += first;
            }
            arr[i] += "ma";
            for(int j=-1;j<i;j++){
                arr[i] += "a";
            }
        }
        string ret = "";
        for(int i=0;i<arr.size();i++){
            ret += arr[i];
            if(i != arr.size()-1){
                ret += " ";
            }
        }
        return ret;
    }
};
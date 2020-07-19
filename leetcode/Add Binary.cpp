class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        string carry = "0";
        if(a.size() <b.size()){
            string tmp = a;
            a = b;
            b = tmp;
        }
        int aIdx = a.size()-1,bIdx = b.size()-1;
        while(bIdx >= 0){
            if(carry == "0"){
                if(a[aIdx] == '0'&&b[bIdx] == '0'){
                    carry = "0";
                    ret = "0"+ret;
                }else if(a[aIdx] == '1' && b[bIdx] == '1'){
                    carry = "1";
                    ret = "0"+ret;
                }else{
                    carry = "0";
                    ret = "1"+ret;
                }
            }else if(carry == "1"){
                if(a[aIdx] == '0' && b[bIdx] == '0'){
                    carry = "0";
                    ret = "1"+ret;
                }else if(a[aIdx] == '1' && b[bIdx] == '1'){
                    carry = "1";
                    ret = "1"+ret;
                }else{
                    carry = "1";
                    ret = "0"+ret;
                }
            }
            aIdx--;
            bIdx--;
            cout <<"bIdx "<< carry << " " << ret << endl;
        }
        while(aIdx >= 0){
            if(carry == "0"){
                ret = a[aIdx]+ret;
            }else if(carry == "1"){
                if(a[aIdx] == '0'){
                    carry = "0";
                    ret = "1"+ret;
                }else if(a[aIdx] == '1'){
                    carry = "1";
                    ret = "0"+ret;
                }
            }
            aIdx--;
            cout <<"aIdx "<< carry << " " << ret << endl;
        }
        if(carry == "1"){
            ret = "1"+ret;
        }
        return ret;
    }
};
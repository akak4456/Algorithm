#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int order[3] = {0,0,0};
//1:가장 낮은... 3:가장 높은 +,-,*
bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*';
}
string ex;
int mapChToIdx(char ch){
    if(ch == '+'){
        return 0;
    }else if(ch == '-'){
        return 1;
    }else{
        return 2;
    }
}
long long int calc(){
    stack<long long int> operand;
    stack<char> opcode;
    int start = 0;
    for(int i=0;i<ex.size();i++){
        if(isOperator(ex[i])){
            string tmp = ex.substr(start,i-start);
            operand.push(stoi(tmp));
            while(!opcode.empty()&&order[mapChToIdx(ex[i])] <= order[mapChToIdx(opcode.top())]){
                long long int o2 = operand.top();
                operand.pop();
                long long int o1 = operand.top();
                operand.pop();
                char op = opcode.top();
                opcode.pop();
                if(op == '+'){
                    operand.push(o1+o2);
                }else if(op == '-'){
                    operand.push(o1-o2);
                }else if(op == '*'){
                    operand.push(o1*o2);
                }
            }
            opcode.push(ex[i]);
            start = i+1;
        }    
    }
    operand.push(stoi(ex.substr(start,ex.size()-start)));
    while(!opcode.empty()){
        long long int o2 = operand.top();
        operand.pop();
        long long int o1 = operand.top();
        operand.pop();
        char op = opcode.top();
        opcode.pop();
        if(op == '+'){
            operand.push(o1+o2);
        }else if(op == '-'){
            operand.push(o1-o2);
        }else if(op == '*'){
            operand.push(o1*o2);
        }
    }
    return operand.top();
}
long long solution(string expression) {
    ex = expression;
    long long answer = 0;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(i == j){
                continue;
            }
            for(int k=1;k<=3;k++){
                if(i == k || j == k){
                    continue;
                }
                order[0] = i;
                order[1] = j;
                order[2] = k;
                answer = max(answer,abs(calc()));
            }
        }
    }
    return answer;
}
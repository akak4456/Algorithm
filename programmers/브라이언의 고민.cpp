#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
�ణ ������ �̻��Ѱ� ����
���� ��Ȳ�� ���� �� ���⵵ �� 
*/

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
bool isLower(char ch){
    return 'a' <= ch && ch <= 'z';
}
bool isUpper(char ch){
    return 'A' <= ch && ch <= 'Z';
}
int getIdx(char ch){
    return ch-'a';
}
vector<string> token;
vector<bool> used;
string solution(string sentence) {
    string answer = "";
    token.clear();
    used = vector<bool>(26,false);
    for(int i=0;i<sentence.size();i++){
    	if(sentence[i] == ' '){
    		return "invalid";
		}
	}
	string startSentence = sentence;
    while(!sentence.empty()){
   // cout << "START:"<<sentence[0] << ' ' << sentence<< endl;
    	//	for(int i=0;i<token.size();i++){
		//		cout << token[i] << ' ';
		//	}
		//	cout << endl;
    
        if(isLower(sentence[0])){
        	
            if(used[getIdx(sentence[0])]){
                //������ ��� �� ���� ������
                return "invalid";
            }
            if(isLower(sentence[1])){
                //���� ���ڰ� �ҹ����̸�
                return "invalid";
            }
            
            used[getIdx(sentence[0])] = true;
            if(isUpper(sentence[2])){
                //�ٴ��� ���ڰ� �빮���̸�
                //aBB...a�� ���� ��Ģ�� ������� �ǹ�
                //���� �ٶ������� ���� ���ڵ� ���� �� ����
                bool isFinish = false;
                int end = 3;
                while(end < sentence.size()){
                    if(sentence[end] == sentence[0]){
                        isFinish = true;
                        break;
                    }else if(isUpper(sentence[end])){
                        end++;
                    }else{
                        return "invalid";
                    }
                }
                if(!isFinish){
                    return "invalid";
                }
                token.push_back(sentence.substr(1,end-1));
                sentence.erase(0,end+1);
            }
            if(isLower(sentence[2])){
                //�ٴ��� ���ڰ� �ҹ����̸�
                //aBc�� ���� ��Ģ�� ����� ���ɼ��� ����
                if(sentence[0] == sentence[2]){
                	string tmp = "";
                	tmp += sentence[1];
                	token.push_back(tmp);
                	sentence.erase(0,3);
                	continue;
				}
                if(used[getIdx(sentence[2])]){
                    return "invalid";
                }
                used[getIdx(sentence[2])] = true;
                int end = 3;
                bool isFinish = false;
                while(end < sentence.size()){
                //	cout << end << endl;
                    if(end%2 == 1){
                        //�빮�ڰ� ���;߸� ��
                        if(isLower(sentence[end])){
                            return "invalid";
                        }
                        end++;
                    }else{
                        if(sentence[0] == sentence[end]){
                           isFinish = true;
                            break;
                        }else if(sentence[end] == sentence[2]){
                            end++;
                        }else{
                            return "invalid";
                        }
                    }
                }
                //cout << "ISFINISH:" << isFinish << endl;
                if(!isFinish){
                    return "invalid";
                }
                string tmp = "";
                for(int i=1;i<end;i++){
                    if(isUpper(sentence[i]))
                        tmp += sentence[i];
                }
                token.push_back(tmp);
                sentence.erase(0,end+1);
                continue;
            }
        }else{
        	int lowerFirst = 1;
        	while(isUpper(sentence[lowerFirst])){
        		lowerFirst++;
			}
			
			if(lowerFirst >= sentence.size()){
				//������ ������ ������
				token.push_back(sentence); 
				break;
			}
			if(used[getIdx(sentence[lowerFirst])]){
				return "invalid";
			}
			if(lowerFirst+1 >= sentence.size()||isLower(sentence[lowerFirst+1])){
				//ó�� �ҹ��� ���� ���ڰ� �ҹ����� ��� 
				return "invalid";
			}
			if(lowerFirst+2 >= sentence.size()){
				return "invalid";
			} 
			if(isUpper(sentence[lowerFirst+2])){
			//	cout << "CASE\n";
				bool isFinish = false;
				int end = lowerFirst+3;
				while(end < sentence.size()){
					if(sentence[end] == sentence[lowerFirst]){
						isFinish = true;
						break;
					}
					end++;
				}
				if(isFinish){
					token.push_back(sentence.substr(0,lowerFirst));
					sentence.erase(0,lowerFirst);
					continue;
				}else{
					if(lowerFirst-1 > 0)
						token.push_back(sentence.substr(0,lowerFirst-1));
					string tmp = "";
					for(int i=lowerFirst-1;i<=lowerFirst+1;i++){
						if(isUpper(sentence[i])){
							tmp += sentence[i];
						}
					}
					token.push_back(tmp);
					sentence.erase(0,lowerFirst+2);
					continue;
				}
				
			}else{
				if(sentence[lowerFirst] == sentence[lowerFirst+2]){
					//BaBa�� ���� ����� �� ����
					if(lowerFirst-1 > 0)
						token.push_back(sentence.substr(0,lowerFirst-1));
					int end = lowerFirst+3;
					int cnt = 1;
					while(end < sentence.size()){
						if(cnt%2 == 1){
							if(isLower(sentence[end])){
								return "invalid";
							}
							end++;
							cnt++;
						}else{
							if(sentence[end] == sentence[lowerFirst]){
								end++;
								cnt++;
							}else{
								break;
							}
						}
					} 
					string tmp = "";
					for(int i=lowerFirst-1;i<end;i++){
						if(isUpper(sentence[i])){
							tmp += sentence[i];
						}
					}
					used[getIdx(sentence[lowerFirst])] = true;
					token.push_back(tmp);
					sentence.erase(0,end);
					continue;
				}else{
					//aBcBcBa�� ���� ��� �� �� ����
					token.push_back(sentence.substr(0,lowerFirst));
					sentence.erase(0,lowerFirst);
					continue;
				}
			}
		}
    }
    for(int i=0;i<token.size();i++){
    	answer += token[i];
    	if(i != token.size()-1)
    		answer += " ";
	}
    return answer;
}

int main() { vector<string> testcase; 
testcase.push_back("aBBBa");//BBB
testcase.push_back("aBcBcBa");//BBB
testcase.push_back("aBaBaBa");//invalid
testcase.push_back("aBcBdBa");//invalid
testcase.push_back("HaEaLaLaObWORLDb"); //HELLO WORLD 
testcase.push_back("SpIpGpOpNpGJqOqA"); //SIGONG JOA 
testcase.push_back("A"); //A 
testcase.push_back("HELLOWORLD"); //HELLOWORLD 
testcase.push_back("aHbEbLbLbOacWdOdRdLdDc"); //HELLO WORLD 
testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD 
testcase.push_back("AAA"); //AAA 
testcase.push_back("aHELLOWORLDa"); //HELLOWORLD 
testcase.push_back("AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"); //AA ABA BBBB C BBBB C BB GG GGG RRRRRR 
testcase.push_back("aIaAM"); //I AM 
testcase.push_back("bAaOb"); //AO 
testcase.push_back("AxAxAxAoBoBoB"); //invalid 
testcase.push_back("a"); //invalid 
testcase.push_back("Aa"); //invalid 
testcase.push_back("aA"); //invalid 
testcase.push_back("HaEaLaLaOWaOaRaLaD"); //invalid 
testcase.push_back("abHELLObaWORLD"); //invalid 
testcase.push_back("aHELLOa bWORLDb"); //invalid 
testcase.push_back("TxTxTxbAb"); //invalid 
testcase.push_back("bTxTxTaTxTbkABaCDk"); //invalid 
testcase.push_back("baHELLOabWORLD"); //invalid 
testcase.push_back("AxAxAxABcBcBcB"); //AAAA BBBB 
testcase.push_back("A B"); //invalid 
testcase.push_back("oBBoA"); //BB A 
testcase.push_back("AxAxAxA"); //AAAA 
testcase.push_back("HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA"); //HELLO WORLD SIGONG J O A GWFD GWL BB AAA AAAA A 
testcase.push_back("aBcAadDeEdvAvlElmEEEEm"); //BA DE A E EEEE 
testcase.push_back("AcAcABaBaB"); //A A AB B B 
testcase.push_back("aGbWbFbDakGnWnLk"); //GWFD GWL 
testcase.push_back("aCaCa"); //invalid 
testcase.push_back("AaAaA");//AAA
testcase.push_back("AaAaAcA");//invalid
testcase.push_back("xAaAbAaAx");//invalid
testcase.push_back("TxTxTxbAb");//invalid
testcase.push_back("bTxTxTaTxTbkABaCDk");//invalid
for (int i = 0; i < testcase.size(); ++i) { cout << '[' << solution(testcase[i]) << ']' << '\n'; } 
return 0; }


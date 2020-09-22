#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftX = 0,rightX = 2;
    int leftY = 3,rightY = 3;
    for(int i=0;i<numbers.size();i++){
        cout << "BEFORE\n";
        cout << "LEFT:"<<leftX << ' ' << leftY << endl;
        cout << "RIGHT:"<<rightX << ' ' << rightY << endl << endl;
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            if(numbers[i] == 1){
                leftX = 0;
                leftY = 0;
            }else if(numbers[i] == 4){
                leftX = 0;
                leftY = 1;
            }else if(numbers[i] == 7){
                leftX = 0;
                leftY = 2;
            }
        }
        else if(numbers[i] == 3||numbers[i] == 6||numbers[i] == 9){
            answer += "R";
            if(numbers[i] == 3){
                rightX = 2;
                rightY = 0;
            }else if(numbers[i] == 6){
                rightX = 2;
                rightY = 1;
            }else if(numbers[i] == 9){
                rightX = 2;
                rightY = 2;
            }
        }else{
            int posX,posY;
            if(numbers[i] == 2){
                posX = 1;
                posY = 0;
            }else if(numbers[i] == 5){
                posX = 1;
                posY = 1;
            }else if(numbers[i] == 8){
                posX = 1;
                posY = 2;
            }else if(numbers[i] == 0){
                posX = 1;
                posY = 3;
            }
            //cout << posX << ' ' << posY << endl;
            int leftDist = abs(posX-leftX)+abs(posY-leftY);
            int rightDist = abs(posX-rightX)+abs(posY-rightY);
            bool isLeft = true;
            cout << "POS:" <<posX << ' ' << posY << endl; 
            cout << i<<' '<< numbers[i] << endl;
            cout << "DIST:"<<leftDist << ' ' << rightDist << endl << endl;
            if(leftDist < rightDist){
                isLeft = true;
            }else if(leftDist == rightDist){
                if(hand == "right"){
                    isLeft = false;
                }else{
                    isLeft = true;
                }
            }else{
                isLeft = false;
            }
            if(isLeft){
                leftX = posX;
                leftY = posY;
                answer += "L";
            }else{
                rightX = posX;
                rightY = posY;
                answer += "R";
            }
        }
        cout << "AFTER\n";
        cout << "LEFT:"<<leftX << ' ' << leftY << endl;
        cout << "RIGHT:"<<rightX << ' ' << rightY << endl << endl;
    }
    return answer;
}
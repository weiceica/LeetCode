#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
using namespace std;

int countDifferentLetters(const string& input) {
    unordered_map<char, bool> lower;
    unordered_map<char, bool> upper;
    int count = 0;
    for(int i = 0; i < input.length(); ++i){
        if(islower(input[i])){
            if(lower.find(input[i]) == lower.end()) lower[input[i]] = false;
            if(upper.count(toupper(input[i])) != 0 && upper[toupper(input[i])] == true){
                if(lower[input[i]] == false){
                    count--;
                    lower[input[i]] = true;
                }
            }
        }
        else{
            if(upper.count(input[i]) == 0){
                if(lower.find(tolower(input[i])) != lower.end()){
                    cout << input[i] << i << endl;
                    count++;
                    upper[input[i]] = true;
                }
                else upper[input[i]] = false;
            }
            else upper[input[i]] = false;
        }
    }
    return count;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int result = countDifferentLetters(input);
    cout << "Number of different letters with lowercase occurrences before uppercase: " << result << endl;

    return 0;
}

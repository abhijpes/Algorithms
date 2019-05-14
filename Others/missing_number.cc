/*
Given a contiguous sequence of numbers in which each number repeats thrice, there is exactly one missing number. Find the missing number.
eg: 11122333 : Missing number 2
11122233344455666 Missing number 5
*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void check_missing_approach_1(vector<int> const& int_sequence, int& num){
    // Assuming the array is sorted and there is exactly one element missing
    // every third number should be same as first number
    int prev_num = -1;
    for(auto it = int_sequence.begin(); it < int_sequence.end() ; it = it + 2){
            if(prev_num == -1){
                // Will hit only the very first time
                prev_num = *it;
            }
            else if(prev_num == *it){
                //it's there.. skip it.
                it = it+1;
                prev_num = *it;
            }
            else{
                //Got it! return
                num = prev_num;
                return;
            }
        }
}

void check_missing_approach_2(vector<int>& int_sequence, int& num){
    // Here we won't assume array is sorted.
    //Space complexity is constant and time is O(n)
    cout << "reached in here";
    for(int i = 0; i < int_sequence.size() ; i++){
        if(int_sequence[i] == 0)continue;
        while(int_sequence[i] != i || int_sequence[int_sequence[i]] >= 0){
            swap(&int_sequence[int_sequence[i]],&int_sequence[i]);
            int_sequence[int_sequence[i]] = -1;
        }
        if(int_sequence[int_sequence[i]] < 0){
            if(int_sequence[int_sequence[i]] != int_sequence[i]){
                int_sequence[i] = 0;
            }
            int_sequence[int_sequence[i]] -= 1;
        }
    }
    cout << "After processing" << endl;
    for (std::vector<int>::iterator it = int_sequence.begin(); it < int_sequence.end(); ++it){
        cout << *it << endl;
    }
}

void check_missing_approach_3(vector<int> const& int_sequence, int& num){
    // Note that the problem states that exactly one number is missing
    // Hence the difference of the expected and actual sum will tell us that number
    int actual_sum=0, expected_sum;
    int max_num = ceil(int_sequence.size() / 3.0);
    expected_sum =  (max_num * (max_num + 1) / 2) * 3;
    for(auto it = int_sequence.begin(); it < int_sequence.end() ; ++it){
        actual_sum+=(*it);
    }
    num = expected_sum - actual_sum;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string sequence;
    int num;
    stringstream stream;
    vector<int> int_sequence;
    cout << "Enter a sequence" << endl;
    getline(cin, sequence);
    stream << sequence;
    stream >> num;
    for (auto i = sequence.begin(); i < sequence.end(); ++i){
        int_sequence.emplace_back(*i - 48);
    }
    cout << "Following is your integer output" << endl;
    for (std::vector<int>::iterator it = int_sequence.begin(); it < int_sequence.end(); ++it){
        cout << *it << endl;
    }
    check_missing_approach_2(int_sequence, num);
    cout << "Following is the missing number" << endl;
    cout << num;
    return 0;
}

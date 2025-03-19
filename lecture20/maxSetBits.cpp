//i can flip 1 bit from 0 to 1 so that i have max number of possible consecutive 1 

#include <iostream>
#include <algorithm>
using namespace std;
int longestSequenceWithOneFlip(int num) {
    if (num == 0) return 1;

    int maxLength = 0;
    int currentLength = 0;
    int previousLength = 0;

    while (num > 0) {
        if (num & 1) {
            currentLength++;
        } else {
            maxLength = max(maxLength, previousLength + currentLength + 1);
            previousLength = currentLength;
            currentLength = 0;
        }
        num >>= 1;
    }

    maxLength = max(maxLength, previousLength + currentLength + 1);

    return maxLength;
}

int main() {
    int num = 13;
    cout << "Longest sequence with one flip: " << longestSequenceWithOneFlip(num) << endl;
    return 0;
}

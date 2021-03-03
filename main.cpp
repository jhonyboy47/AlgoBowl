#include <iostream>
#include <utility>
#include <vector>
using namespace std;
/*    arr - array to store the combination
    index - next location in array
    num - given number
    reducedNum - reduced number */

struct addPair {
    int num1;
    int num2;
};
void findCombinationsUtil(int arr[], vector<addPair> &outputVector, int index, int num, int reducedNum)
{
    // Base condition
    if (reducedNum < 0)
        return;

    // If combination is found, print it
    if (reducedNum == 0)
    {
        int counter = 0;
        addPair sumToTarget;
        for (int i = 0; i < index; i++) {
            counter++;
//            cout << arr[i] << " ";
        }
//        cout << endl << counter << endl;
        if (counter == 2){
            sumToTarget.num1 = arr[0];
            sumToTarget.num2 = arr[1];
            outputVector.push_back(sumToTarget);
        }
        return;
    }

    // Find the previous number stored in arr[]
    // It helps in maintaining increasing order
    int prev = (index == 0)? 1 : arr[index-1];

    // note loop starts from previous number
    // i.e. at array location index - 1
    for (int k = prev; k <= num ; k++)
    {
        // next element of array is k
        arr[index] = k;

        // call recursively with reduced number
        findCombinationsUtil(arr, outputVector, index + 1, num,
                             reducedNum - k);
    }
}

/* Function to find out all combinations of
   positive numbers that add upto given number.
   It uses findCombinationsUtil() */
void findCombinations(int n, vector<addPair> &outputVector)
{
    // array to store the combinations
    // It can contain max n elements
    int arr[n];
    //find all combinations
    findCombinationsUtil(arr, outputVector, 0, n, n);


//    for (int i = 0; i < outputVector.size(); ++i) {
//
//        cout << outputVector[i].num1 + " " + outputVector[i].num2;
//
//    }
}

// Driver code
int main()
{
    int n = 5;
    vector<addPair> outputVector;

    findCombinations(n, outputVector);

//    for (int i = 0; i < outputVector.size(); i++) {
//        cout << outputVector.at(i).num1 + " " + outputVector.at(i).num2;
//    }
    cout << outputVector.at(0).num1 << " ";
    cout << outputVector.at(0).num2;
    cout << endl;
//    cout << outputVector.size();

    return 0;
}
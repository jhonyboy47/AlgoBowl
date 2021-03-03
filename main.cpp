#include <iostream>
#include <vector>
#include <fstream>
#include <set>
using namespace std;
/*    arr - array to store the combination
    index - next location in array
    num - given number
    reducedNum - reduced number */

class addPair {
public:
    int result;
    int num1;
    int num2;
};
void findCombinations(int n, vector<addPair> &outputVector);
void findCombinationsUtil(int arr[], vector<addPair> &outputVector, int index, int num, int reducedNum);
void addPairResult( addPair& tempAddPair);
bool checkDuplicates( vector <addPair> vec, addPair tempAddPair);




// Driver code
int main()
{
    int n = 5;

    ifstream inputFile("inputFile0.txt");
//    if ( !inputFile.is_open()){
//
//        cerr << "Could not open output file" << endl;
//    }
//
//    int numOfValues;
//    inputFile >> numOfValues;
    vector<int> inputVector = {10};
//    int counter = 0;
//    int intBuffer;
//    while( counter < numOfValues ){
//
//        numOfValues >> intBuffer;
//
//        inputVector.push_back(numOfValues);
//    }
//
//    inputFile.close();

    vector <addPair> outputVector;
    for (int i = 0; i < inputVector.size(); ++i) {
        findCombinations(inputVector.at(i), outputVector);

    }

    cout << outputVector.at(0).num1 << " ";
    cout << outputVector.at(0).num2;
    cout << endl;

    set <addPair> outputSet;
    //TODO: We must ensure uniquenes here!
    for (auto pair: outputVector) {
        cout << pair.num1;
        cout << " ";
        cout << pair.num2;
        cout << endl;
        outputSet.insert(pair);
    }

//
//    for (auto pair: outputSet){
//        cout << pair.num1 << " " << pair.num2 << endl;
//    }
//    cout << outputVector.size();

    return 0;
}

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
            addPairResult(sumToTarget);

            if(!checkDuplicates(outputVector, sumToTarget)) {
                findCombinations(sumToTarget.num1, outputVector);
                findCombinations(sumToTarget.num2, outputVector);
                outputVector.push_back(sumToTarget);
            }
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

void addPairResult( addPair& tempAddPair){
    tempAddPair.result = tempAddPair.num1 + tempAddPair.num2;
}

bool checkDuplicates( vector <addPair> vec, addPair tempAddPair){

    for (auto addPair: vec) {
        if (addPair.num1 == tempAddPair.num1 && addPair.num2 == tempAddPair.num2){
            return true;
        }

    }

    return false;
}
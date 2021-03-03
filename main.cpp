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

    ifstream inputFile("inputFile0.txt");

    //TODO: Finish up file input ( preferrably after code functionality is done
//    if ( !inputFile.is_open()){
//
//        cerr << "Could not open output file" << endl;
//    }
//
//    int numOfValues;
//    inputFile >> numOfValues;
    vector<int> inputVector = {2,5,10};
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

    //Holds all of the combinations for numbers that up to the numbers listed in inputVector
    vector <addPair> outputVector;
    for (int i = 0; i < inputVector.size(); ++i) {
        findCombinations(inputVector.at(i), outputVector);
    }

    cout << outputVector.at(0).num1 << " ";
    cout << outputVector.at(0).num2;
    cout << endl;

    //Outputs to the contents of outputVector to the console!
    for (auto pair: outputVector) {
        cout << pair.num1;
        cout << " ";
        cout << pair.num2;
        cout << endl;
    }


    return 0;
}

//Finds all possible combinations that add up num
void findCombinationsUtil(int arr[], vector<addPair> &outputVector, int index, int num, int reducedNum)
{
    // Base condition
    if (reducedNum < 0) return;

    // If combination is found add it to our outputVector
    if (reducedNum == 0)
    {
        //We only want the valued addition hence the counter without this the code would add all of the additions that add up to num
        int counter = 0;
        addPair sumToTarget;
        for (int i = 0; i < index; i++) {
            counter++;
        }

        //Checking it is an addition of two values
        if (counter == 2){

            sumToTarget.num1 = arr[0];
            sumToTarget.num2 = arr[1];
            if(!checkDuplicates(outputVector, sumToTarget)) {
                addPairResult(sumToTarget);
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
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//variables
string currentLine;
int n = 2;
vector<int> neededInts;
vector<int> copyOfNeededInts = {3, 5};
int iterations = 1;
vector<string> outputLists;
unordered_set<string> outputList;
vector<int> numsToUse;
vector<string> lines;
//{3, 5, 8, 16, 20, 41, 104, 198, 348, 399, 518}{3, 5, 8, 16, 20, 41, 104, 198, 348, 399, 518}

int main() {
    // file read in
    string currentLine;
    ifstream myFile ("testInput.txt");
    if(myFile.is_open()) {
        while(getline(myFile,currentLine)) {
            lines.emplace_back(currentLine);
        }
        myFile.close();
    }

    for(int p = 0; p < lines.at(1).length(); p++) {
        if(lines.at(1).at(p) == ' ') {
            neededInts.emplace_back(stoi(lines.at(1).substr(0, p)));
            lines.at(1).erase(0, p);
        }
    }
    for(int q = 0; q < neededInts.size(); q++) {
        cout << neededInts.at(q);
        cout << endl;
    }

    //actual heuristic or whatever
    numsToUse.push_back(1);
    outputLists.emplace_back(" ");

    for(int k = 0; k < neededInts.size(); k++) {
        int tempInt = 0;
        bool foundNeededInt = false;
        string tempString = "";
        for(int i = numsToUse.size() - 1; i >= 0; i--) {
            for(int j = numsToUse.size() - 1; j >= 0; j--) {
                tempInt = numsToUse.at(i) + numsToUse.at(j);
                tempString = to_string(numsToUse.at(i)) + " " + to_string(numsToUse.at(j));
                if(tempInt == neededInts[k]) {
                    numsToUse.emplace_back(tempInt);
                    if(outputLists.back() != tempString) {
                        outputLists.emplace_back(tempString);
                    }
                    foundNeededInt = true;
                    break;
                }
                else if(tempInt < neededInts[k]) {
                    numsToUse.emplace_back(tempInt);
                    if(outputLists.back() != tempString) {
                        outputLists.emplace_back(tempString);
                    }
                    i = numsToUse.size() - 1;
                    break;
                }
            }
            if(foundNeededInt) {
                break;
            }
        }
    }
    for(int m = 0; m < outputLists.size(); m++) {
        cout << outputLists.at(m);
        cout << endl;
    }
}


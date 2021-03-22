/*
Canada has a multi-party system of government. Each candidate is generally associated with a party, and the 
party whose candidates win the most ridings generally forms the government. Some candidates run as independents, 
meaning they are not associated with any party. Your job is to count the votes for a particular riding and 
to determine the party with which the winning candidate is associated.

Input
The first line of input contains a positive integer 𝑛 satisfying 2≤𝑛≤20, the number of candidates in the riding. 
𝑛 pairs of lines follow: the first line in each pair is the name of the candidate; the second line is the name 
of the party, or the word “independent” if the candidate has no party. No candidate name is repeated and no 
party name appears more than once in this part of the input.

The next line contains a positive integer 𝑚≤10000, and is followed by 𝑚 lines each indicating the name of a 
candidate for which a ballot is cast. Any names not in the list of candidates should be ignored.

Each name line consists of at least 1 and at most 80 characters, uses only ASCII characters 32 to 126 
(inclusive), and does not contain any leading or trailing blanks.

Output
Output consists of a single line containing one of:

The name of the party with whom the winning candidate is associated, if there is a winning candidate and that 
candidate is associated with a party.

The word “independent” if there is a winning candidate and that candidate is not associated with a party.

The word “tie” if there is no winner; that is, if no candidate receives more votes than every other candidate
*/

/*
Sample input
3
Marilyn Manson
Rhinoceros
Jane Doe
Family Coalition
John Smith
independent
6
John Smith
Marilyn Manson
Marilyn Manson
Jane Doe
John Smith
Marilyn Manson

Output 
Rhinoceros

3
Marilyn Manson
Rhinoceros
Jane Doe
Family Coalition
John Smith
independent
6
John Smith
Marilyn Manson
John Smith
Jane Doe
Jane Doe
Marilyn Manson

Output 
tie
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n, m;
    // candidate map
    map<string,string> candidates;
    map<string, int> votes;
    string temp;
    cin >> n;
    char _[20];
    getline(cin, temp);
    while (n--){
        // read the n pairs of lines to populate map
        string candidate, party;
        getline(cin, candidate);
        getline(cin, party);
        candidates[candidate] = party;
        votes[candidate] = 0;
    }
    
    cin >> m;
    getline(cin, temp);
    int max = 0;
    bool tie = true;
    string winner = "empty";
    for ( int j = 0; j < m; j ++){
        // read the votes
        string candidate;
        getline(cin, candidate);
        if (votes.count(candidate)){
            votes[candidate] += 1;
            if (votes[candidate] > max){
                tie = false;
                max = votes[candidate];
                winner = candidate;
            } else if (votes[candidate] == max){
                tie = true;
            }
        }
    }
    
    if (tie) {
        cout << "tie";
    } else {
        cout << candidates[winner];
    }
    return 0;
}
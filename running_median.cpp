//submission link - https://www.hackerrank.com/challenges/find-the-running-median/submissions/code/429267710

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    vector<double> medians;
// Max-heap for the smaller half
priority_queue<int> maxHeap;
// Min-heap for the larger half
priority_queue<int, vector<int>, greater<int>> minHeap;

for (int num : a) {
// Step 1: Insert into appropriate heap
if (maxHeap.empty() || num <= maxHeap.top()) {
maxHeap.push(num);
} else {
minHeap.push(num);
}
// Step 2: Balance the heaps
if (maxHeap.size() > minHeap.size() + 1) {
minHeap.push(maxHeap.top());
maxHeap.pop();
} else if (minHeap.size() > maxHeap.size()) {
maxHeap.push(minHeap.top());
minHeap.pop();
}
// Step 3: Compute the median
if (maxHeap.size() == minHeap.size()) {
double median = (maxHeap.top() + minHeap.top()) / 2.0;
medians.push_back(median);
} else {
medians.push_back(maxHeap.top());
}
}
return medians;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
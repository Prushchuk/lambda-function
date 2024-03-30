#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

void processList(vector<int>& numbers, function<int(int)> operation) {
    for (int& number : numbers) {
        number = operation(number);
    }
}

int main()
{
    vector<int> numbers = { 1,2,3,4,5 };

    processList(numbers, [](int x) {return x + 10; });
    processList(numbers, [](int x) {return x * 2; });
    processList(numbers, [](int x) { return x * x; });
    processList(numbers, [](int x) { return (x != 0) ? 1 / x : 0; });

    cout << "Processed numbers: ";
    for(int number : numbers){
        cout << " " << number;
    }
    cout << endl;

    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum of numbers: " << sum << endl;

    double average = static_cast<double>(sum) / numbers.size();
    cout << "Average of numbers: " << average << endl;

    int maxNumber = *max_element(numbers.begin(), numbers.end());
    int minNumber = *min_element(numbers.begin(), numbers.end());
    cout << "Maximum number: " << maxNumber << endl;
    cout << "Minimum number: " << minNumber << endl;

    vector<int> evenNumbers;
    copy_if(numbers.begin(), numbers.end(), back_inserter(evenNumbers), [](int x) { return x % 2 == 0; });
    cout << "Even numbers:";
    for (int number : evenNumbers) {
        cout << " " << number;
    }
    cout << endl;

    sort(numbers.begin(), numbers.end());
    cout << "Sorted numbers in ascending order:";
    for (int number : numbers) {
        cout << " " << number;
    }
    cout << endl;

    sort(numbers.rbegin(), numbers.rend());
    cout << "Sorted numbers in descending order:";
    for (int number : numbers) {
        cout << " " << number;
    }
    cout << endl;
}
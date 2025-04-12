#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;

// 1 - Nhập mảng
void inputArray(vector<int>& arr) {
    int n;
    do {
        cout << "Enter number of elements (1 - 100): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
}

// 2 - Xuất mảng
void outputArray(const vector<int>& arr) {
    cout << "Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// 3 - In mảng theo thứ tự giảm dần
void sortDescending(vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    cout << "Array sorted in descending order:\n";
    outputArray(arr);
}

// 4 - Kiểm tra tất cả phần tử là số lẻ
void checkAllOdd(const vector<int>& arr) {
    bool allOdd = all_of(arr.begin(), arr.end(), [](int x) { return x % 2 != 0; });
    cout << (allOdd ? "All elements are odd.\n" : "Not all elements are odd.\n");
}

// 5 - Tìm số xuất hiện bao nhiêu lần
void searchValue(const vector<int>& arr) {
    int x, count = 0;
    cout << "Enter value to search: ";
    cin >> x;
    for (int num : arr)
        if (num == x)
            count++;
    cout << "Value " << x << " appears " << count << " time(s).\n";
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// 6 - In ra các số nguyên tố
void printPrimes(const vector<int>& arr) {
    cout << "Prime numbers in the array: ";
    bool found = false;
    for (int num : arr) {
        if (isPrime(num)) {
            cout << num << " ";
            found = true;
        }
    }
    if (!found) cout << "None";
    cout << endl;
}

// 7 - Thoát chương trình
bool confirmQuit() {
    int confirm;
    cout << "Are you sure to quit? Enter 1 to confirm: ";
    cin >> confirm;
    return confirm == 1;
}

// Menu
int main() {
    vector<int> arr;
    int choice;
    bool running = true;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Input the array\n";
        cout << "2. Output the array\n";
        cout << "3. Sort array in descending order\n";
        cout << "4. Check if all elements are odd\n";
        cout << "5. Search a value\n";
        cout << "6. Display prime numbers\n";
        cout << "7. Quit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: inputArray(arr); break;
            case 2: outputArray(arr); break;
            case 3: sortDescending(arr); break;
            case 4: checkAllOdd(arr); break;
            case 5: searchValue(arr); break;
            case 6: printPrimes(arr); break;
            case 7:
                if (confirmQuit()) {
                    running = false;
                    cout << "Exiting program.\n";
                }
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (running);

    return 0;
}

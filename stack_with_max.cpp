#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;

class StackWithMax {
    vector<int> stack;
    int max_element;

  public:

    void Push(int value) {
        if(stack.empty())
            {
                stack.push_back(value);
                max_element=value;
                return;
            }
        if(value > max_element)
        {
            stack.push_back(2 * value - max_element); 
            max_element = value;
            return; 
        }
        else
            stack.push_back(value);

    }

    void Pop() {
       int t=stack.back();
        stack.pop_back();
        if (t > max_element) {  
            max_element = 2 * max_element - t; 
        }
    }

    int Max() {
        return max_element;
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
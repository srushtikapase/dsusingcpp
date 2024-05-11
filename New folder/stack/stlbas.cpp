#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    st.push(5);
    st.push(10);
    st.push(15);

    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Top element after pop: " << st.top() << endl;

    return 0;
}

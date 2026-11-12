#include <iostream>
using namespace std;

class Tracer {
private:
    int id;
public:
    Tracer(int n) {
        id = n;
        cout << "Tracer " << id << " created." << endl;
}
~Tracer() {
    cout << "Tracer " << id << " destroyed." << endl;
}
};

int main() {
    for (int i = 1; i <= 5; i++) {
        Tracer* t = new Tracer(i);
        cout << "Using Tracer " << i << endl;
        delete t;
    }
    cout << "Program finished." << endl;
    return 0;
}
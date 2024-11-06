

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int value,Node* next,Node* prev): value(value),next(next),prev(prev){}
};
class List {
    Node* head;
    Node* tail;
    int size;
public:
    List() : head(nullptr), tail(nullptr) {}
    List(const initializer_list<int>list)
    {
        head = nullptr;
        for (int i = 0; i < list.size(); i++)
        {

        }

    }

    void addtohead(int value) {
        Node* newNOde = new Node(value, head, nullptr);
        if (isEnty()) {
            head = tail = newNOde;

        }
        head->prev = newNOde;
        head = newNOde;



    }
    void addtotail(int value) {
        Node* newNOde = new Node(value, nullptr, tail);
        if (isEnty()) {
            head = tail = newNOde;
        }
        tail->next = newNOde;
        tail = newNOde;
    }
    bool isEnty()const {
        return head == nullptr;
    }
    void Show()const {
        for (auto i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }cout << "************************************** \n";
    }
    void Clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    ~List() {
        Clear();
    }
    void deletefromtail() {
        if (isEnty())return;
        if (head == nullptr) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* beforelast = tail->prev;
        beforelast->next = nullptr;
        delete tail;
        tail = beforelast;
    }
    int operator[](int index) {
        Node* current = head;
        int i = 0;
        while (current != nullptr) {
            if (index = i)return current->value;
            current = current->next;
            ++i;
        }
    }
    void deletebyvalue(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
            
            else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }

    cout << "Value not found" << endl;
}
    int findmax()const {
        if (head ==nullptr) {
            return 0;
        }
        int maxValue = head->value;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->value > maxValue) {
                maxValue = current->value;
            }
            current = current->next;
        }
        return maxValue;
    }
    int findmin()const {
        if (head == nullptr) {
            return 0;
        }
        int minValue = head->value;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->value < minValue) {
                minValue = current->value;
            }current = current->next;
        }
        return minValue;
  }
    int getelement() {
        return size;
    }
    void reverse() const {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->prev;
        }
        cout << endl;
    }
};
int main()
{
    List list ;
    list.addtohead(1);
    list.addtohead(3);
    list.Show();
    
    list.Show();
    list.addtotail(4);
    list.addtotail(5);
    list.addtotail(6);
    list.Show();
    list.deletefromtail();
    list.Show();
    cout << "Reverse list : ";
    list.reverse();
    cout << list[4] << " ";
    cout << list[3] << " ";
    int maxVal = list.findmax();
    cout << "Max value : " << maxVal << endl;
    int minVal = list.findmin();
    cout << "MIn value :  " << minVal << endl;
    cout << "List size :  " << list.getelement() << endl;
    list.deletebyvalue(42);
    list.Show();

}


#include<iostream>
using namespace std;

struct MyNode{
    MyNode *pred = nullptr;
    MyNode *succ = nullptr;
    char data = '\0';
    MyNode(char value = '\0', MyNode *p = nullptr, MyNode *s = nullptr) : data(value), pred(p), succ(s){}
    ~MyNode() { delete pred; delete succ; }
};

class MyList{
public:
    MyList(){ header = new MyNode; tailer = new MyNode; size = 0; header->succ = tailer; tailer->pred = header;}
    ~MyList(){ remove(0, tailer); delete header; delete tailer; }
    MyNode *insert(const char value, MyNode *position){
        MyNode *node = new MyNode(value, position->pred, position);
        position->pred->succ = node;
        position->pred = node;
        ++size;
        return position;
    }
    MyNode *remove(MyNode *begin, MyNode *end){ 
        while (begin != end){
            begin->pred->succ = begin->succ;
            begin->succ->pred = begin->pred;
            begin = begin->succ;
            --size;
            }
            return begin;
    }
    char operator[](int n){
        MyNode *temp = header;
        while (n--){ temp = header->succ; }
        return temp->data;
    }
    void deduplicate(MyNode *);
    MyNode *first() { return header->succ; }
    MyNode *last() { return tailer->pred; }
    friend ostream &operator<<(ostream &, const MyList &);
    int size = 0;

private:
    MyNode *header = nullptr;
    MyNode *tailer = nullptr;
};

void MyList::deduplicate(MyNode *position){
    while (true){
        if (size < 3) { break; }
        MyNode *pred1 = position->pred, *succ1 = position->succ;
        if (position != tailer && succ1 != tailer && succ1->data == position->data){
            MyNode *succ2 = succ1->succ;
            if (succ2->data == position->data){ position = remove(position, succ2->succ); continue; }
            else if (pred1->data == position->data){
                MyNode *pred2 = pred1->pred;
                if (pred2->data == position->data){ position = remove(pred2, succ1->succ); continue; }
                else{ position = remove(pred1, succ2); continue; }
            } 
        }else if (pred1->data == position->data){
            MyNode *pred2 = pred1->pred;
            if (pred2->data == position->data){ position = remove(pred2, succ1); continue; }
        }
        break;
    }
}

ostream &operator<<(ostream &output, const MyList &list){
    MyNode *temp = list.header->succ;
    if(temp == list.tailer) { output << '-'; }
    while (temp!=list.tailer){
        output << temp->data;
        temp = temp->succ;
    }
    return output;
}

MyList *mainList = new MyList;

int main(){
    int numOperate;
    char tempChar;
    MyNode *iter = mainList->first();
    while ((tempChar = getchar()) != '\n'){ iter = mainList->insert(tempChar, iter); }
    scanf("%d", &numOperate);
    while (numOperate--)
    {
        int position;
        char value;
        scanf("%d %c", &position, &value);
        MyNode *temp = mainList->first();
        while (position--){ temp = temp->succ; }
        temp = mainList->insert(value, temp);
        mainList->deduplicate(temp->pred);
        cout << *mainList << endl;
    }
}
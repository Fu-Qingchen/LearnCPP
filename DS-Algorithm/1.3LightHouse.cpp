#include<iostream>
using namespace std;

struct LightHouse
{
    LightHouse *pred = nullptr;
    LightHouse *succ = nullptr;
    long long x_position = 0;
    long long y_position = 0;
    LightHouse(long long x = 0, long long y = 0, LightHouse *ppred = nullptr, LightHouse *psucc = nullptr) : 
        x_position(x), y_position(y), pred(ppred), succ(psucc){}
    
};

class LightHouseList
{
public:
    LightHouseList(){
        size = 0;
        header = new LightHouse();
        tailer = new LightHouse();
        header->succ = tailer;
        tailer->pred = header;
    }
    ~LightHouseList() { clear(); delete header; delete tailer; }
    long long size = 0;
    void insert(const unsigned long long x, const unsigned long long y, LightHouse *position){
        LightHouse *node = new LightHouse(x, y, position, position->succ);
        position->succ->pred = node; position->succ = node;
        ++size;
    }
    LightHouse *first() { return header->succ; }
    LightHouse *last() { return tailer->pred; }
    void sort(LightHouse *, long long);
    long long getInversePair(LightHouse *, long long);
    friend ostream &operator<<(ostream &, const LightHouseList &);

private:
    void clear(){ while (size != 0) { remove(header->succ); }}
    void remove(LightHouse *position){
        position->pred->succ = position->succ;
        position->succ->pred = position->pred;
        --size;
        delete position;
    }
    LightHouse *header = nullptr;
    LightHouse *tailer = nullptr;
};

ostream &operator<<(ostream &output, const LightHouseList &list){
    LightHouse *temp = list.header->succ;
    while (temp!=list.tailer){
        output << temp->x_position << " ";
        temp = temp->succ;
    }
    return output;
}

void LightHouseList::sort(LightHouse *begin, long long number){
    if (number < 2){ return; }
    long long mid = number >> 1, size_right = number - mid, temp_x, temp_y;
    LightHouse *midNode = begin;
    while (mid--){ midNode = midNode->succ; }
    LightHouse *copy_begin = begin->pred;
    sort(begin, number >> 1);
    LightHouse *copy_midNote = midNode->pred;
    sort(midNode, number - (number >> 1));
    midNode = copy_midNote->succ;
    begin = copy_begin->succ;
    while (size_right){
        if (begin == copy_midNote->succ){ break; }
        if (midNode->x_position < begin->x_position){
            temp_x = midNode->x_position, temp_y = midNode->y_position;
            midNode = midNode->succ;
            remove(midNode->pred);
            insert(temp_x, temp_y, begin->pred);
            --size_right;
        }else{ begin = begin->succ; }
    }
}

long long LightHouseList::getInversePair(LightHouse *begin, long long number){
    if (number < 2){ return 0; }
    long long mid = number >> 1, size_right = number - mid, temp_x, temp_y, num_left, num_right;
    LightHouse *midNode = begin;
    while (mid--){ midNode = midNode->succ; }
    LightHouse *copy_begin = begin->pred;
    num_left = getInversePair(begin, number >> 1);
    LightHouse *copy_midNote = midNode->pred;
    num_right = getInversePair(midNode, number - (number >> 1));
    midNode = copy_midNote->succ;
    begin = copy_begin->succ;
    long long begin_count = 0, count = 0;
    while (size_right){
        if (begin == copy_midNote->succ){ break; }
        if (midNode->y_position < begin->y_position){
            temp_x = midNode->x_position, temp_y = midNode->y_position;
            midNode = midNode->succ;
            remove(midNode->pred);
            insert(temp_x, temp_y, begin->pred);
            --size_right;
            count += ((number >> 1) - begin_count);
        }else{ begin = begin->succ; ++begin_count; }
    }
    return num_left + count + num_right;
}

int main(){
    LightHouseList lightHouseList;
    long long number, x, y;
    cin >> number;
    if (number < 2){ cout << 0; return 0; }
    long long temp = number;
    while (number--){
        cin >> x >> y;
        lightHouseList.insert(x, y, lightHouseList.last());
    }
    lightHouseList.sort(lightHouseList.first(), lightHouseList.size);
    cout << (temp)*(temp - 1)/2 - lightHouseList.getInversePair(lightHouseList.first(), lightHouseList.size);
    return 0;
}
///problem link: https://leetcode.com/problems/lru-cache/


class LRUCache {
    list<int>l;  ///order maintain karna h doubly linked list
    map<int,pair<list<int>::iterator,int>> m ;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    ///return value of a key
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;

           ///delete previous entry and insert new entry at head
            auto it=m[key].first;
            l.erase(it);

            ///insert it again at start
            l.push_front(key);
            m[key].first = l.begin();  ///l.begin() gives address of starting element

            return m[key].second;


    }

    ///insert a new data in cache
    void put(int key, int value) {
        //if it in already in cache
        if(m.find(key)!=m.end()){
            ///delete previous entry and insert new entry at head
            auto it=m[key].first;
            l.erase(it);

            ///insert it again at start
            l.push_front(key);
            m[key].first = l.begin();  ///l.begin() gives address of starting element
            m[key].second = value;
            return;
        }

        ///check if cahce is full or not
        if(m.size()==cap){
            ///delete last entry
           auto it= l.rbegin(); ///gives the address of last element
            int x=*it;
            l.remove(x);
            m.erase(x);

        }
          ///insert it again at start
            l.push_front(key);
            m[key].first = l.begin();  ///l.begin() gives address of starting element
            m[key].second = value;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

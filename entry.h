#ifndef __ENTRY_H_
#define __ENTRY_H_
template <typename K,typename V> struct Entry
{
    K key; V value;
    Entry(K k=K(),V v=V()):key(k),value(v){};
    Entry(Entry<K,V> const&e):key(e.key),value(e.value){};
    bool operator< (Entry<K,V> const & e){return key<e.key;}
    bool operator>(Entry<K,V> const& e){return key>e.key;}
    bool operator==(Entry<K,V> const&e){return key==e.key;}
    bool operator!=(Entry<K,V> const&e){return key!=e.key;}
};

#endif  //__ENTRY_H_

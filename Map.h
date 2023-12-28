#include <vector>
#include <iostream>

class notFound{};

template <typename Key, typename Value>
class Pair
{
public:
    Key key;
    Value value;
    Pair() {}
    Pair(Key k, Value v) : key(k), value(v) {}
};

template <typename Key, typename Value>
class Map
{
private:
    std::vector<Pair<Key, Value>> Data;

public:
    // Searches by key, add at the end.
    void add(Key newKey, Value newValue)
    {
        for (size_t i = 0; i < Data.size(); ++i)
        {
            if (Data[i].key == newKey)
            {
                Data[i].value = newValue;
                return;
            }
        }
        Data.push_back(Pair<Key, Value>(newKey, newValue));
    }

    // Searches by key, return value.
    Value *find(const Key &findKey)
    {
        for (size_t i = 0; i < Data.size(); ++i)
        {
            if (Data[i].key == findKey)
            {
                return &Data[i].value;
            }
        }
        throw notFound();
    }

    friend std::ostream& operator<<(std::ostream& out, const Map<Key, Value>& map) {
        for (const auto& pair : map.Data) {
            out << "Key: " << pair.key << ", Value: " << pair.value << std::endl;
        }
        return out;
    }

};
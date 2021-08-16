#include <bits/stdc++.h>
using namespace std;

template <typename V>
class mapNode
{
public:
    string key;
    V value;
    mapNode *next;

    mapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~mapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    mapNode<V> **buckets;
    int count;
    int numbuckets;

public:
    ourmap()
    {
        count = 0;
        numbuckets = 5;
        buckets = new mapNode<V> *[numbuckets];
        for (int i = 0; i < numbuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numbuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        mapNode<V> *head = buckets[bucketIndex];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hasCode = 0;

        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hasCode += key[i] * currentCoeff;
            hasCode = hasCode % numbuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numbuckets;
        }
        return hasCode % numbuckets;
    }

    void rehash()
    {
        mapNode<V> **temp = buckets;
        buckets = new mapNode<V> *[2 * numbuckets];
        for (int i = 0; i < 2 * numbuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketCount = numbuckets;
        numbuckets *= 2;
        count = 0;
        for (int i = 0; i < oldBucketCount; i++)
        {
            mapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++)
        {
            mapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (1.0 * count) / numbuckets;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        mapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        mapNode<V> *node = new mapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0 * count) / numbuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        mapNode<V> *head = buckets[bucketIndex];
        mapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {

                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};
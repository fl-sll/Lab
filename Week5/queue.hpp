#include <iostream>
#include <array>

// CONSTANT VARIABLE
#define MAX 100

namespace dsa
{
    // DECLARATIONS
    template <typename T>
    class Queue
    {
    public:
        // PROPERTIES
        std::array<T, MAX> items;
        int size;
        int i; // iterator property

        // COSTRUCTOR
        Queue() : items(), size(0), i(0) {}

        // CLASS FUNCTIONS
        void enqueue(T item);
        T dequeue();
        void del(T item);
        void search(T item);
        void print();
    };
}

// IMPLEMENTATIONS
template <typename T>
void dsa::Queue<T>::enqueue(T item)
{
    // ACCESSING
    this->items[this->size] = item;
    // // INCREMENT
    ++this->size;
}

template <typename T>
T dsa::Queue<T>::dequeue()
{
    return this->items[this->i++];
}

template <typename T>
void dsa::Queue<T>::print()
{
    std::cout << "SIZE PROPERTY: " << this->i << std::endl;

    for (int x = this->i; x < this->size; x++)
    {
        std::cout << this->items[x] << std::endl;
    }

    if (this->size == 0){
        std::cout << "Empty Queue" << std::endl;
    }

    this->i = 0;
}

template <typename T>
void dsa::Queue<T>::del(T item)
{
    dsa::Queue<int> tempQueue;
    int cnt = 0;

    for (int x = this->i; x < this->size; x++){
        if (this->items[cnt] != item){
            tempQueue.enqueue(this->items[cnt]);
            this->dequeue();
            cnt++;
        }
    }

    if (this->size == 0){
        std::cout << "Element not found" << std::endl;
        while (tempQueue.size != 0){
            this->enqueue(tempQueue.items[i]);
            tempQueue.dequeue();
        }
    }
    else {
        this->dequeue();
        while (tempQueue.size != 0){
            this->enqueue(tempQueue.items[i]);
            tempQueue.dequeue();
        }
        int k = this->size - cnt - 1;
        while (k != 0){
            k--;
            int p = this->i;
            this->dequeue();
            this->enqueue(p);
        }
    }
}

template <typename T>
void dsa::Queue<T>::search(T item)
{
    for (int x = this->i ; x < this->size; x++)
    {
        if (items[x] == item){
            std::cout << "Item is in queue" << std::endl;
        } else {
            std::cout << "This item is not in the queue" << std::endl;
        }
    }
}
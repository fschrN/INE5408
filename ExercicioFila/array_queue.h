// Copyright 2018 <Nicolas Fischer>
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>  //  std::size_t
#include <stdexcept>  //  C++ Exceptions

namespace structures {
/**
 * Nicolas Fischer
 */
template<typename T>
class ArrayQueue {
 public:
    ArrayQueue();
    explicit ArrayQueue(std::size_t max);
    ~ArrayQueue();
    void enqueue(const T& data);
    T dequeue();
    T& back();
    void clear();
    std::size_t size();
    std::size_t max_size();
    bool empty();
    bool full();

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    static const auto DEFAULT_SIZE = 10u;  //  tamanho padrão
};
}  // namespace structures
    #endif
/**
 * construtor sem arg
 */
template<typename T>
structures::ArrayQueue<T>::ArrayQueue() {
max_size_ = DEFAULT_SIZE;
contents = new T[max_size];
size_ = 0;
}
/**
 * construtor com arg
 */
template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max) {
    max_size_ = max;
    contents = new T[max_size_];
    size_ = 0;
}
/**
 * delete
 */
template<typename T>
structures::ArrayQueue<T>::~ArrayQueue() {
    delete [] contents;
}
/**
 * add dado
 */
template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data) {
    if (full()) {
      throw std::out_of_range("Fila já cheia.");
    } else {
      size_ = size_ + 1;
      contents[size_-1] = data;
    }
}
/**
 * elimina dado
 */
template<typename T>
T structures::ArrayQueue<T>::dequeue() {
    if (empty()) {
      throw std::out_of_range("Fila está vazia.");
    } else {
       T exit = contents[0];
        for (int i = 0; i < size_-1; i++) {
           contents[i] = contents[i+1];
        }
        size_ = size_ -1;
      return exit;
    }
}
/**
 * ultimo da fila
 */
template<typename T>
T& structures::ArrayQueue<T>::back() {
  if (empty()) {
       throw std::out_of_range("Fila vazia");
  } else {
      return contents[size_-1];
  }
}
/**
 *limpa fila
 */
template<typename T>
void structures::ArrayQueue<T>::clear() {
size_ = 0;
}
/**
 * tamanho atual fila
 */
template<typename T>
std::size_t structures::ArrayQueue<T>::size() {
    return size_;
}
/**
 * tamanho max
 */
template<typename T>
std::size_t structures::ArrayQueue<T>::max_size() {
    return max_size_;
}
/**
 * checa vazia
 */
template<typename T>
bool structures::ArrayQueue<T>::empty() {
  if (size_ == 0) {
    return true;
  } else {
    return false;
  }
}
/**
 * checa cheia
 */
template<typename T>
bool structures::ArrayQueue<T>::full() {
    if (size_  == max_size_) {
      return true;
    } else {
      return false;
    }
}

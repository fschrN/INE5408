// Copyright 2018 <Nicolas Fischer>
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>   // std::size_t
#include <stdexcept>   // C++ exceptions

namespace structures {

template<typename T>
/**
 *  Nicolas
 */
class ArrayStack {
 public:
    ArrayStack();  // pilha criada
    explicit ArrayStack(std::size_t max);  // s
    ~ArrayStack();  // t
    void push(const T& data);  // empilha
    T pop();  // desempilha
    T& top();  // ve topo
    void clear();   // limpa
    std::size_t size();  // tamanho
    std::size_t max_size();  // maximo tamanho
    bool empty();  // vazia
    bool full();  // cheia

 private:
    T* contents;
    int top_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;  // tamanho padrao
};

}  // namespace structures

#endif
/**
 *  construtor sem argu
 */
template<typename T>
structures::ArrayStack<T>::ArrayStack() {
max_size_ =  DEFAULT_SIZE;
contents = new T[DEFAULT_SIZE];
top_ = -1;
}
/**
 *  construtor ccom arg
 */
template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
max_size_ = max;
contents = new T[max_size_];
top_ = -1;
}
/**
 *  deleta
 */
template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
    delete []contents;
}
/**
 *  empilha dados
 */
template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
    if (full()) {
        throw std::out_of_range("Pilha cheia");
    } else {
        top_ += 1;
        contents[top_] = data;
    }
}
/**
 *  desempilha
 */
template<typename T>
T structures::ArrayStack<T>::pop() {
      if (empty()) {
         throw std::out_of_range("Pilha vazia");
      } else {
         top_ -=1;
        return contents[top_+1];
      }
  }
/**
 *  retorna dado do topo
 */
template<typename T>
T& structures::ArrayStack<T>::top() {
     if (empty()) {
          throw std::out_of_range("Pilha vazia");
     } else {
         return contents[top_];
     }
}
/**
 *  limpa a pilha
 */
template<typename T>
void structures::ArrayStack<T>::clear() {
     top_ = -1;
}
/**
 *  checa tamanho pilha
 */
template<typename T>
std::size_t structures::ArrayStack<T>::size() {
     return top_+1;
}
/**
 *  checa max size
 */
template<typename T>
std:: size_t structures::ArrayStack<T>::max_size() {
     return max_size_;
}
/**
 *  checa se está vazia
 */
template<typename T>
bool structures::ArrayStack<T>::empty() {
     if (top_ == -1) {
          return true;
     } else {
        return false;
     }
}
/**
 *  checa Lista Cheia
 */
template<typename T>
bool structures::ArrayStack<T>::full() {
    if (top_ == max_size_ -1) {
        return true;
    } else {
        return false;
    }
}

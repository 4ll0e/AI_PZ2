#ifndef STACKMANAGER_H
#define STACKMANAGER_H

#include <string>
#include <vector>

struct Stack {
    std::string from;
    std::string to;
    int dist;
};

class StackManager {
private:
    std::vector<Stack> bt_stack;
    int tos; // Top of stack

public:
    // Конструктор
    StackManager();

    // Добавить элемент в стек
    void push(const std::string& from, const std::string& to, int dist);

    // Удалить элемент из стека
    void pop(std::string& from, std::string& to, int& dist);

    // Получить расстояние последнего элемента в стеке
    int getDistance() const;

    // Получить количество элементов в стеке
    int getTos() const;
};

#endif // STACKMANAGER_H

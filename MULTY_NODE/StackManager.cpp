#include "StackManager.h"
#include <iostream>

// �����������
StackManager::StackManager() : tos(0) {}

// �������� ������� � ����
void StackManager::push(const std::string& from, const std::string& to, int dist) {
    if (tos < 100) {
        bt_stack.push_back({ from, to, dist });
        ++tos;
    }
    else {
        std::cout << "Stack full.\n";
    }
}

// ������� ������� �� �����
void StackManager::pop(std::string& from, std::string& to, int& dist) {
    if (tos > 0) {
        --tos;
        from = bt_stack[tos].from;
        to = bt_stack[tos].to;
        dist = bt_stack[tos].dist;
    }
    else {
        std::cout << "Stack underflow.\n";
    }
}

// �������� ���������� ���������� �������� � �����
int StackManager::getDistance() const {
    if (tos > 0) {
        return bt_stack[tos - 1].dist;
    }
    return 0;
}

// �������� ���������� ��������� � �����
int StackManager::getTos() const {
    return tos;
}

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
    // �����������
    StackManager();

    // �������� ������� � ����
    void push(const std::string& from, const std::string& to, int dist);

    // ������� ������� �� �����
    void pop(std::string& from, std::string& to, int& dist);

    // �������� ���������� ���������� �������� � �����
    int getDistance() const;

    // �������� ���������� ��������� � �����
    int getTos() const;
};

#endif // STACKMANAGER_H

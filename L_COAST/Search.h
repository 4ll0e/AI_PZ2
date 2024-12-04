#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include "Flight.h"
#include "Stack.h"

extern std::vector<Flight> flightDatabase; // ���� ������ ������
extern Stack bt_stack; // ���� ��� ��������

int match(const std::string& from, const std::string& to);
int find(const std::string& from, std::string& anywhere);
void route(const std::string& to);
void isflight(const std::string& from, const std::string& to);

#endif

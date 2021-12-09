#pragma once
#include <string>
#include <iostream>

const int MaxSize = 256;

int DType(char c);
bool checkBrackets(std::string s);
bool checkOperands(std::string s);
bool checkOper(std::string s);
int priority (char c);
bool checkAll(std::string s);
void inPoint(std::string s);
bool operand_true(char c);
bool operand_true_1(std::string s);
void inputVar(std::string s);
bool checkUnarMinus(std::string s);
void unarMinus(std::string s);
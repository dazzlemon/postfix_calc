#include "postfix_evaluator.h"
#include <iostream>

int main() {
	PostfixEvaluator pe;
	std::string expr = "1 2 + 3 /";
	std::cout << expr << " = " << pe.eval(expr) << std::endl;
}

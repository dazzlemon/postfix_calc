#include "postfix_evaluator.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>

void tests() {
	PostfixEvaluator pe;
	std::vector<std::pair<std::string, std::string>> tests = {
		{"1 2 + 3 /",                      "1"},
		{"8 7 +",                         "15"},
		{"99 11 + 8 7 + +",              "125"},
		{"4 7 *",                         "28"},
		{"4 7 * 5 2 * *",                "280"},
		{"8 3 -",                          "5"},
		{"33 3 - 10 6 - -",               "26"},
		{"36 9 /",                         "4"},
		{"90 3 / 30 5 / /",                "5"},
		{"15 7 1 1 + - / 3 * 2 1 1 + + -", "5"},
		{"2",                              "2"},
		{"3 4 +",                          "7"},
		{"12 4 / 1 -",                     "2"},
		{"12 4 1 - /",                     "4"},
		{"15 7 1 1 + - / 3 * 2 1 1 + + -", "5"},
                {"15 0 /",   "error: division by zero"},
		{"15 0 678 8", "error: bad expression"},
		{"/ + * -",    "error: bad expression"}
	};
	
	int tests_passed = 0;
	for (auto& test : tests) {
		std::cout << "expression: " << test.first << std::endl;
		std::cout << "expected result: " << test.second << std::endl;
		auto res = pe.eval(test.first);
		std::cout << "given result: " << res << std::endl;
		bool passed = res == test.second;
		tests_passed += passed;
		std::cout << (passed ? "TEST PASSED" : "TEST FAILED") << std::endl << std::endl;
	}
	std::cout << tests_passed << " out of " << tests.size() << " tests passed" << std::endl;
}

bool getCont() {
	char cont;
	do {
	std::cout << "Do you want to continue?(y/n): ";
	std::cin >> cont;
	getchar();//skip enter
	} while (cont != 'y' && cont != 'Y' && cont != 'N' && cont != 'n');
	return cont == 'y' || cont == 'Y';
}

int main() {
	//tests();

	PostfixEvaluator pe;
	std::string expr;
	bool continue_ = true;

	while(continue_) {
		std::cout << "Input expression: " << std::endl;
		std::getline(std::cin, expr);
		std::cout << "Result: " << pe.eval(expr) << std::endl;
		continue_ = getCont();
	}
}

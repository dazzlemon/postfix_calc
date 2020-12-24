#include "postfix_evaluator.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
	PostfixEvaluator pe;
	std::vector<std::pair<std::string, std::string>> tests = {
		{"1 2 + 3 /", "1"}
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
	std::cout << tests_passed << " out of " << tests.size() << "tests passed" << std::endl;
}

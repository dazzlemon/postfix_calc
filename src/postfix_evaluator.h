#include "stack.h"
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <iterator>

#include <iostream>

class PostfixEvaluator {
public:
	std::string eval(const std::string& postfix) {
		std::vector<std::string> postfix_tokenized = __tokenize(postfix);
		std::string res;
		try {
			res =  __eval(postfix_tokenized);
		}
		catch (const std::exception& e) {
			res = std::string("error: ") + std::string(e.what());
		}
		return res;
	}
private:
	std::vector<std::string> __tokenize(const std::string& postfix) {
		std::istringstream iss(postfix);
		std::vector<std::string> tokenized(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
		return tokenized;
	}

	std::string __eval(const std::vector<std::string>& postfix) {
		ops.clear();
		for (auto& token : postfix)
			ops.push(try_stoi(token) ? __itoken : calc(token));
		return std::to_string(ops.pop());
	}

	int calc(const std::string& op) {
		int a, b, res;
		try {
			a = ops.pop();
			b = ops.pop();
		}
		catch (...) {
			throw std::runtime_error("bad expression");
		}
		switch (op[0]) {
			case '+':
				res = b + a;
				break;
			case '-':
				res = b - a;
				break;
			case '*':
				res = b * a;
				break;
			case '/':
				if (a == 0)
					throw std::runtime_error("division by zero");
				res = b / a;
				break;
		}
		return res;
	}
	
	bool try_stoi(const std::string& token) {
		try {
			__itoken = stoi(token);
		}
		catch (const std::invalid_argument&) {
			return false;
		}
		return true;
	}

	int __itoken;
	Stack<int> ops;
};

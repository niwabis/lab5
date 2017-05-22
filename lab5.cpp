#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class HugeInt {
	friend ostream &operator <<	(ostream&, const HugeInt&);
	friend istream &operator >> (istream &, HugeInt &);

public:
	HugeInt() {}
	HugeInt(int a) {
		stringstream ss;
		ss << a;
		ss >> num;
		ss.str("");
		ss.clear();
		for (int i = num.size() - 1; i >= 0; --i) {
			number.push_back(num[i] - '0');
		}
	}
	HugeInt(string b) {
		num = b;
		for (int j = b.length() - 1; j >= 0; --j) {
			number.push_back(num[j] - '0');
		}
	}
	void operator=(vector<int>r) {
		number = r;
	}
	vector<int>number;
	string num;
	//int sss = number.size();
private:
	int x;
	


};

ostream & operator <<(ostream & out, HugeInt &Huge) {
	for (int g = 0; g <= Huge.number.size() - 1; ++g) {
		Huge.num[g] = Huge.number[g];
	}
	out << Huge.num;
	return out;
}
istream &operator >> (istream & in, HugeInt & Huge) {
	in >> Huge.num;
	for (int k = Huge.num.length() - 1; k >= 0; --k) {
		Huge.number.push_back(Huge.num[k] - '0');
	}
	return in;
}
vector<int> operator+(HugeInt A, HugeInt B) {
	int size = A.number.size();
	int s = B.number.size();
	vector<int>re;
	if (size > s) {
		for (int l = size - 1; l >= 0; --l) {
			if (l <= s) {
				re.push_back(A.number[l] + B.number[l]);
			}
			else re.push_back(A.number[l]);
		}
	}
	else if(size<s){
		for (int l = s - 1; l >= 0; --l) {
			if (l <= size) {
				re.push_back(A.number[l] + B.number[l]);
			}
			else re.push_back(B.number[l]);
		}
	}
	else {
		for (int l = s - 1; l >= 0; --l) {
				re.push_back(A.number[l] + B.number[l]);
		}
	}
	for (int i = re.size() - 1; i >= 0; --i) {
		if (re[i] >= 10) {
			re[i + 1] += 1;
			re[i] -= 10;
		}
	}
	if (re[re.size()] >= 10) {
		re.push_back(1);
		re[re.size()] -= 10;
	}
	return re;
}
vector<int> operator-(HugeInt A, HugeInt B) {
	int size = A.number.size();
	int s = B.number.size();
	vector<int>re;
	if (size > s) {
		for (int l = size; l >= 0; --l) {
			if (l <= s) {
				re.push_back(A.number[l] - B.number[l]);
			}
			else {
				re.push_back(A.number[l]);
			}
		}
		for (int i = size - 1; i >= 0; --i) {
			if (re[i] < 0) {
				re[i] += 10;
				re[i + 1] -= 1;
			}
		}

	}
	else if (size < s) {
		for (int l = s; l >= 0; --l) {
			if (l <= size) {
				re.push_back(A.number[l] - B.number[l]);
			}
			else {
				re.push_back(A.number[l]);
			}
		}
		for (int i = s - 1; i >= 0; --i) {
			if (re[i] < 0) {
				re[i] = re[i] + 10;
				re[i + 1] -= 1;
			}
		}

	}
	else {
		for (int l = size; l >= 0; --l) {
			re.push_back(A.number[l] - B.number[l]);
		}
		for (int i = re.size() - 1; i >= 0; --i) {
			if (re[i] < 0) {
				re[i] = re[i] + 10;
				re[i + 1] -= 1;
			}
		}

	}

	return re;
}


int main() {
	HugeInt x;
	HugeInt y(28825252);
	HugeInt z("314159265358979323846");
	HugeInt result;

	cin >> x;
	result = x + y;

	cout << x << "+" << y << " = " << result << endl;
	result = z - x;

	cout << result << endl;
	return 0;
}


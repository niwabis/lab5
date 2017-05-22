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
	/*	for(int i=1;i<=r.size();i++){
			number.push_back(r[i]);
		}*/
		number=r;
	}
	vector<int>number;
	string num;
	//int sss = number.size();
private:
	int x;
	
};

ostream & operator <<(ostream & out, HugeInt &Huge) {
	for (int g = Huge.number.size()-1; g >=0 ; --g) 
		out << Huge.number[g];
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
		for (int l = 0; l <= size-1; ++l) {
			if (l <= s) {
				re.push_back(A.number[l] + B.number[l]);
			}
			else re.push_back(A.number[l]);
		}
	}
	else if(size<s){
		for (int l = 0; l <= s-1; ++l) {
			if (l <= size-1) {
				re.push_back(A.number[l] + B.number[l]);
			}
			else re.push_back(B.number[l]);
		}
	}
	else {
		for (int l = 0; l <= s-1; ++l) {
				re.push_back(A.number[l] + B.number[l]);
			}
		}
	for (int i = re.size()-1; i >= 1; --i) {
		if (re[i] >= 10) {
			re[i - 1] ++ ;
			re[i] - 10;
		}
	}
	
	return re;
}
vector<int> operator-(HugeInt A, HugeInt B) {
	int size = A.number.size();
	int s = B.number.size();
	vector<int>re;
	if (size > s) {
		for (int l = 0; l <= size-1; ++l) {
			if (l <= s) {
				re.push_back(A.number[l] - B.number[l]);
			}
			else {
				re.push_back(A.number[l]);
			}
		}
	}
	else if (size < s) {
		for (int l = 0; l <= s-1; ++l) {
			if (l <= size) {
				re.push_back(A.number[l] - B.number[l]);
			}
			else {
				re.push_back(A.number[l]);
			}
		}
	}
	else {
		for (int l = 0; l <= size-1; ++l) {
			re.push_back(A.number[l] - B.number[l]);
		}
	}
	for (int i = 1; i <= re.size()-1; ++i) {
		if (re[i] < 0) {
			re[i - 1] + 1;
			re[i] + 10;
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
	cout<<x<<endl;
	result = x + y;
	cout<<y<<endl;
	cout<<result<<endl;
	cout << x << "+" << y << " = " << result << endl;
	result = z - x;
	cout<<z<<endl;

	cout << result << endl;
	return 0;
}


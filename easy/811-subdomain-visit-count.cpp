#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> table;
		vector<string> r;
		int count;
		for (auto domain : cpdomains) {
			count = stoi(domain.substr(0, domain.find(' ')));
			for (string d = domain.substr(domain.find(' ')+1);
				 d.size() > 0;
				 d = (d.find('.') == string::npos) ? "" : d.substr(d.find('.')+1))
			{ table[d] += count; }
		}
		for (auto d : table) { r.push_back(to_string(d.second) + " " + d.first); }
		return r;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> domains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
	// vector<string> domains = {"900 google.mail.com"};
	auto ss = s.subdomainVisits(domains);
	for (auto st : ss) {
		cout << st << endl;
	}
	return 0;
}

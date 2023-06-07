#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2)
{
	unordered_map<char, char> charCount;

	for (int i = 0; i < str1.length(); i++)
	{
		if (charCount.count(str1[i]))
		{
			if (charCount[str1[i]] != str2[i]) {
				return false;
			}
		}
		else {
			vector<char> values;
			for (auto it : charCount) {
				values.push_back(it.second);
			}
			if (find(values.begin(), values.end(), str2[i])
				!= values.end()) {
				return false;
			}
			else {
				charCount[str1[i]] = str2[i];
			}
		}
	}
	return true;
}

int main()
{
	string s = "egg";
	string t = "add";
	if (s.length() == t.length()
		&& areIsomorphic(s, t)) {
		cout << "True\n";
	}
	else {
		cout << "False\n";
	}
	return 0;
}

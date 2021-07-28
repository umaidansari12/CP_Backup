#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void decodeWays(string s, int idx, string res, map<string, string>& m, int &cnt)
{
	if (idx == s.size())
	{
		stringstream ss(res);
		string token;
		bool flag = false;
		while (getline(ss, token, ' '))
		{
			if (m.find(token) == m.end())
			{
				flag = true;
				break;
			}
			//cout << res << endl;
		}
		if (!flag)
			cnt++;
		return;
	}
	decodeWays(s, idx + 1, res + s[idx], m, cnt);
	decodeWays(s, idx + 1, res + s[idx] + " ", m, cnt);
}

void decodeWaysOther(string s, int idx, vector<string> &res, string temp, map<string, string>&m, int &cnt)
{
	if (idx == s.size())
	{
		// bool flag = false;

		// for (int i = 0; i < res.size(); i++)
		// {
		// 	cout << res[i] << " ";
		// 	if (m.find(res[i]) == m.end())
		// 	{
		// 		flag = true;
		// 		break;
		// 	}
		// }
		// while (getline(ss, token, ' '))
		// {

		// 	//cout << res << endl;
		// }
		// if (!flag)
		// 	cnt++;
		cout << temp << endl;
		return;
	}
	decodeWaysOther(s, idx + 1, res, temp + s[idx], m, cnt);
	decodeWaysOther(s, idx + 1, res, temp , m, cnt);
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		map<string, string> m;
		m["1"] = 'A';
		m["2"] = 'B';
		m["3"] = 'C';
		m["4"] = 'D';
		m["5"] = 'E';
		m["6"] = 'F';
		m["7"] = 'G';
		m["8"] = 'H';
		m["9"] = 'I';
		m["10"] = 'J';
		m["11"] = 'K';
		m["12"] = 'L';
		m["13"] = 'M';
		m["14"] = 'N';
		m["15"] = 'O';
		m["16"] = 'P';
		m["17"] = 'Q';
		m["18"] = 'R';
		m["19"] = 'S';
		m["20"] = 'T';
		m["21"] = 'U';
		m["22"] = 'V';
		m["23"] = 'W';
		m["24"] = 'X';
		m["25"] = 'Y';
		m["26"] = 'Z';
		int cnt = 0;
		vector<string> res;
		decodeWaysOther(s, 0, res, "", m, cnt);
		cout << cnt / 2 << endl;
	}

	return 0;
}
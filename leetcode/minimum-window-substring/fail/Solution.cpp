#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
		int16_t	hash_map[255] = {0}, aux_map[255], aux = 0, tmp_aux;
		size_t	sz_s = s.size(), sz_t = t.size(), start, end, tmp_start;
		string solution = "", res;

		for (auto c: t) {
			hash_map[c]--;
			aux += hash_map[c];
		}

		start = 0;
		for (; start < sz_s - (sz_t - 1); start++) {

			for (; start < sz_s and !hash_map[s[start]]; start++);
			for (end = start + (sz_t - 1); end < sz_s and !hash_map[s[end]]; end++);
			if (start - end < sz_t - 1)
				return solution;


			memcpy(aux_map, hash_map, 255*2);
			tmp_aux = aux;
			tmp_start = start;
			while (tmp_start <= end) {
				tmp_aux -= aux_map[s[tmp_start]];
				aux_map[s[tmp_start]]++;
				tmp_start++;
			}
			if (!tmp_aux) {
				res = s.substr(start, end - start + 1);
				if (res.size() < solution.size() or solution.size() == 0)
					solution = res;
			}
		}

		return solution;
    }
};

int main() {
	Solution sl;

	cout << "res: " << sl.minWindow("cabwefgewcwaefgcf","cae") << endl;
	cout << "res: " << sl.minWindow("a","a") << endl;
	cout << "res: " << sl.minWindow("acbbaca","aba") << endl;
	cout << "res: " << sl.minWindow("ADOBECODEBANC","ABC") << endl;
	cout << "res: " << sl.minWindow("bdab","ab") << endl;

	return 0;
}

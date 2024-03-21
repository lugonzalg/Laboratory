#include <vector>
#include <string>
#include <iostream>

using namespace std;

# define NO_MATCH false
# define MATCH 	  true

# define S1 0
# define S2 1

# define HASH_MAP_SIZE 2
# define AtoZ 26

/*
 Through this function we are looking for the permuctation of s1 within s2.

	 First part:
		Check if the lenght of s1 is bigger than s2, making impossible to contain it.

	Second part:
		Fill both hash maps with the values of its pairs:
			hash_map[S1] <-> s1
			hash_map[S2] <-> s2

	Third part:
		Increase match by 1 per each equal value. Where a equal value is a posotion
		of a hash_map that previously have been increased in 'Second part'.

 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

		uint16_t	hash_map[HASH_MAP_SIZE][AtoZ] = {0};
		size_t		n1 = s1.size(), n2 = s2.size(), match = 0;

		//First part
		if (s1 > s2)
			return NO_MATCH;

		//Second part
		for (size_t idx = 0; idx < n1; idx++) {
			hash_map[S1][s1[idx] - 'a']++;
			hash_map[S2][s2[idx] - 'a']++;
		}

		//Third part
		for (size_t idx = 0; idx < AtoZ; idx++) {
			if (hash_map[S1][idx] == hash_map[S2][idx])
				match++;
		}

		//Fourth part
		for (size_t idx = 0; idx < n2 - n1; idx++) {

			//Fifth part
			if (match == AtoZ)
				return MATCH;

			hash_map[S2][s2[idx] - 'a']--;
			hash_map[S2][s2[idx + 1] - 'a']++;

			if (hash_map[S1][s2[idx + 1] - 'a'] == hash_map[S2][s2[idx + 1] - 'a'])
				match++;
			else
				match--;
		}
		return NO_MATCH;
	}
};

int main() {
	Solution sl;

	string s1 = "ab";
	string s2 = "eidbaooo";

	cout << "Match: " << sl.checkInclusion(s1, s2) << endl;

	return 0;
}


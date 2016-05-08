/** 
	170. Two Sum 3

	Design and implement a TwoSum class. It should support the following operations: add and find.

	add - Add the number to an internal data structure.
	find - Find if there exists any pair of numbers which sum is equal to the value.

	For example,
	add(1); add(3); add(5);
	find(4) -> true
	find(7) -> false

**/

/** Solution 1 **/

class TwoSum {
    unordered_map<int,int> map;
public:
    void add(int number) {
        map[number]++;
    }

    bool find(int value) {
        for (unordered_map<int,int>::iterator it = map.begin(); it != map.end(); it++) {
            int i = it->first;
            int j = value - i;
            if ((i == j && it->second > 1) || (i != j && map.find(j) != map.end())) {
                return true;
            }
        }
        return false;
    }
};

/** Solution 2 **/

class TwoSum {
    unordered_multiset<int> nums;
public:
    void add(int number) {
        nums.insert(number);
    }
    bool find(int value) {
        for (int i : nums) {
        	/** if 2*i == value, we need to check count > 1**/
            int count = i == value - i ? 1 : 0;
            if (nums.count(value - i) > count) {
                return true;
            }
        }
        return false;
    }
};
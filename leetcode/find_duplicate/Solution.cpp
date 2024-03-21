class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        std::unordered_map<int, int>::iterator    it_list;
        std::vector<int>::iterator      it;

        for (it = nums.begin(); it < nums.end(); it++) {

            it_list = this->_num_list.find(*it);
            if (it_list != this->_num_list.end())
                return true;
            else
                this->_num_list[*it] = 1;

        }
        return false;
    }
private:
    std::unordered_map<int, int>  _num_list;
};

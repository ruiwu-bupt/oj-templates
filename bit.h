// pos represents position in nums parameter, not in bit array
#include <vector>
template<typename T>
class BIT{
private:
	std::vector<T> bit;
	inline int low_bit(int x) {
		return x & -x;
	}
public:
	BIT(std::vector<T> nums);
	void add(int pos, T value);
	T prefix(int pos);
	T range_sum(int pos1, int pos2);
};

template<typename T>
void BIT<T>::add(int pos, T value) {
	pos += 1;
	while (pos < bit.size()) {
		bit[pos] += value;
		pos += low_bit(pos);
	}
}

template<typename T>
BIT<T>::BIT(std::vector<T> nums) {
	bit = std::vector<T> (nums.size()+1, 0);
	for (int i = 0; i < nums.size(); i++)
		add(i, nums[i]);
}

template<typename T>
T BIT<T>::prefix(int pos) {
	T rst = 0;
	pos += 1;
	while (pos) {
		rst += bit[pos];
		pos -= low_bit(pos);
	}
	return rst;
}

template<typename T>
T BIT<T>::range_sum(int pos1, int pos2) {
	return prefix(pos2) - prefix(pos1-1);
}

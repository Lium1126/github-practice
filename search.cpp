#include <vector>
#include <algorithm>

namespace githubPractice
{
	/**
	 * dataの中からtargetを探す
	 * 
	 * @param[in] vector<int> data 探索元データ
	 * @param[in] int target 探索対象データ
	 * @return bool targetがdataに含まれていればtrueを返す
	 */
	bool search(std::vector<int> data, int target)
	{
		int left = 0, right = data.size(), mid;

		while (left < right)
		{
			mid = (left + right) / 2;
			if (data[mid] == target)
				return true;
			else if (target < data[mid])
				right = mid;
			else if (data[mid] < target)
				left = mid + 1;
		}

		return false;
	}
}
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
		for (int x : data)
		{
			if (x == target)
				return true;
		}

		return false;
	}
}
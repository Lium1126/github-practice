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
		int i = 0;
		std::vector<int> cp(data.size());
		std::copy(data.begin(), data.end(), cp.begin());

		// set guard
		cp.push_back(target);

		while (cp[i] != target)
			i++;

		return i != data.size();
	}
}
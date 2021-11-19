#include <vector>

namespace githubPractice
{
	/**
	 * データを昇順にソートする
	 *
	 * @param[in] vector<int> data ソート対象データ
	 * @return vector<int> 昇順ソート済みデータ
	 */
	std::vector<int> sort(std::vector<int> data)
	{
		for (int h = data.size() / 2; h > 0; h /= 2)
		{
			for (int i = h; i < data.size(); i += 1)
			{
				int k = data[i];

				int j;
				for (j = i; j >= h && data[j - h] > k; j -= h)
				{
					data[j] = data[j - h];
				}

				data[j] = k;
			}
		}

		return data;
	}
}

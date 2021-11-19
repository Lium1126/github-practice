#include <vector>

namespace github_practice
{
	/**
	 * データを昇順にソートする
	 * 
	 * @param[in] vector<int> data ソート対象データ
	 * @return vector<int> 昇順ソート済みデータ
	 */
	std::vector<int> sort(std::vector<int> data)
	{
		for (int i = 0; i < data.size() - 1; i++)
		{
			for (int j = data.size() - 1; j > i; j--)
			{
				if (data[j] < data[j - 1])
				{
					int tmp = data[j];
					data[j] = data[j - 1];
					data[j - 1] = tmp;
				}
			}
		}
		return data;
	}
}

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

	// calculate bucket size
	int bucket_size = data[0];
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] > bucket_size)
		{
			bucket_size = data[i];
		}
	}
	bucket_size += 1;

	// create empty buckets
	std::vector<int> bucket[bucket_size];

	// put data elements into buckets depending on the value
	for (int i = 0; i < data.size(); i++)
	{
		bucket[data[i]].push_back(data[i]);
	}

	// concatenate all buckets into data
	int id = 0;
	for (int i = 0; i < bucket_size; i++)
	{
		for (int j = 0; j < bucket[i].size(); j++)
		{
			data[id++] = bucket[i][j];
		}
	}

	return data;
}

}

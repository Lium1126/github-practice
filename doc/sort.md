# ソートアルゴリズム

## バブルソート
```c++
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
```

## バケットソート
```c++
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
```

## シェルソート
```c++
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
```

### 参考
> https://bi.biopapyrus.jp/cpp/
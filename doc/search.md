# 探索アルゴリズム

## 線形探索
```c++
bool search(std::vector<int> data, int target)
{
	for (int x : data)
	{
		if (x == target)
			return true;
	}

	return false;
}
```

## 番兵
```c++
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
```

## 二分探索
```c++
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
```
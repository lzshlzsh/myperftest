
# performace sheet
- 测试环境
```
T430: 8core-16G
Intel(R) Core(TM) i7-3840QM CPU @ 2.80GHz
```
|test_case|性能|说明|
|:--:|:--:|:--:|
|getpid|2500w/s||
|close|1800w/s||
|socket|19w/s||
|shmat|100w/s||
|shmdt|100w/s||
|shmget|300w/s||
|shmctl|250w/s||
|random|6000w/s||

|容器大小300w|find|update|
|:--:|:--:|:--:|
|std::map|150w/s|100w/s|
|std::unordered_map|350w/s|250w/s|
|boost::unordered_map|300w/s|250w/s|
|std::set|150w/s|100w/s|
|std::unordered_set|350w/s|300w/s|
|boost::unordered_set|300w/s|250w/s|

# 环境准备
- 更新依赖库
```
git subtree pull -P .Makefile http://git.code.oa.com/shield_docker/Makefile.git master --squash
```

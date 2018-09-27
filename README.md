
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
|std::map::find|150w/s|大小300w|
|std::unordered_map::find|350w/s|大小300w|
|boost::unordered_map::find|300w/s|大小300w|
|std::map::update|100w/s|大小300w|
|std::unordered_map::update|250w/s|大小300w|
|boost::unordered_map::update|250w/s|大小300w|

# 环境准备
- 更新依赖库
```
git subtree pull -P .Makefile http://git.code.oa.com/shield_docker/Makefile.git master --squash
```

from typing import List


class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        dict_list = {}
        arr = ['0'] * len(score)
        for i in range(len(score)):
            dict_list[i] = score[i]
        dict_list = dict(sorted(dict_list.items(), key=lambda item: item[1], reverse=True))
        count = 1
        for key, value in dict_list.items():
            if count < 4:
                if count == 1:
                    arr[key] = 'Gold Medal'
                    count += 1
                elif count == 2:
                    arr[key] = 'Silver Medal'
                    count += 1
                elif count == 3:
                    arr[key] = 'Bronze Medal'
                    count += 1
            else:
                arr[key] = str(count)

                count += 1
        return arr


def main() -> None:
    s1 = Solution()
    arr = [1, 2, 3, 4, 5]
    out = s1.findRelativeRanks(arr)
    print(out)


if __name__ == '__main__':
    main()

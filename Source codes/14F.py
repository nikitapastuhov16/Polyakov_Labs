def keyFunction(value):
    return value % 10
file=open("input.txt")
nums=[int(i) for i in file]
file.close()
nums.sort(key=keyFunction)
file=open("output.txt", "a")
for i in nums:
    file.write(str(i))
    if(i != nums[len(nums) - 1]):
        file.write("\n")
file.close()
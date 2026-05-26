sum=0
count=0
 
# use while.
# print every element user input\n
while [ $# -gt 0 ]; do
    num=$1
    echo "$num"
    sum=$((sum + num))
    count=$((count + 1))
    shift
done
 
average=$(echo "scale=2; $sum / $count" | bc)
echo "합계: $sum"
echo "평균: $average"
 
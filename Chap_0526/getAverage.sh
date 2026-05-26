sum=0
count=0
 
for num in "$@"; do
    echo "$num"
    sum=$((sum + num))
    count=$((count + 1))
done
 
average=$(echo "scale=2; $sum / $count" | bc)
echo "합계: $sum"
echo "평균: $average"
 
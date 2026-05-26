i=1
sum=0
 
while [ $i -le 100 ]; do
    if [ $((i % 2)) -eq 1 ]; then
        sum=$((sum + i))
    fi
    i=$((i + 1))
done
 
echo "1~100 홀수의 합: $sum"
 


if [ $# -eq 0 ]; then
    echo "사용:"
    exit 1
fi

sum=0
count=0


for num in "$@"; do
    # 숫자 유효성 검사

    echo "  $num"
    sum=$((sum + num))
    count=$((count + 1))
done

average=$(echo "scale=2; $sum / $count" | bc)

echo "  합   계   : $sum"
echo "  평   균   : $average"
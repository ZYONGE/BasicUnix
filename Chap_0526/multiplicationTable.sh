while true; do
    printf "구구단 출력: "
    read input

    # q 입력 시 종료
    if [ "$input" = "q" ] || [ "$input" = "Q" ]; then
        echo "quit"
        break
    fi

    for i in $(seq 1 9); do
        result=$((input * i))
        printf "%d x %d = %d\n" "$input" "$i" "$result"
    done
    echo ""
done
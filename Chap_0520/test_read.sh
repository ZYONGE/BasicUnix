#!/bin/bash
# 키보드 입력 처리를 테스트 하는 스크립트

echo "Input x : "
read x 
echo "The value of x is $x" # 사용자가 임의의 값을 입력하면 출력

read -p "Input y : " y 
echo "x is $x y is $y"      # Input y :를 출력한 후 입력 기다림

echo -n "Please enter your name : " 
read first last 
echo "Hi $first"            # Please~ 문을 출력하고 줄을 안 바꿈, 첫 단어는 first에 저장

printf "Put your ID such as %d\n" "$x" # C 언어의 형식으로 표현
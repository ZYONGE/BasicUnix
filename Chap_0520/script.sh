#!/bin/bash
# 사용자로부터 두 개의 파일명을 입력받아 복사하는 스크립트

# -n 옵션으로 줄바꿈 없이 프롬프트 메시지 출력
echo -n "복사할 파일과 복사될 파일 명을 입력 (예: file1 file2): "

# 두 개의 파일명을 공백을 기준으로 나누어 각각 변수에 저장
read source_file target_file

# cp 명령어를 사용하여 파일 복사 실행
cp "$source_file" "$target_file"

# 복사 완료 안내 메시지 출력
echo "완료: '$source_file' 파일이 '$target_file' 로 성공적으로 복사되었습니다."
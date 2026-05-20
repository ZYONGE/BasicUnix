#!/bin/bash
# test_position parameter: 명령행 인자를 테스트

echo ‘$* : ‘ $*
echo '$# : ' $#
echo '$@ : ' $@
echo $0 $1 $2 $3
set --
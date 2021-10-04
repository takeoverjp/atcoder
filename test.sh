#!/bin/bash

if ! type oj &>/dev/null; then
  echo "Need online-judge-tools"
  echo "  $ pip3 install --user online-judge-tools"
  exit 1
fi

if [ $# -ne 1 ]; then
  echo "[USAGE] $0 PROBLAM_NAME"
  echo "  Ex) $0 abc086_a"
  exit 1
fi

if [ ! -f $1.cc ]; then
  echo "Error: $1.cc not found"
  exit 1
fi

set -ex

problem_name=$1
test_dir=test/${problem_name}
contest_name=${problem_name%_*}

if [ ! -d ${test_dir} ]; then
  oj dl -d test/${problem_name} https://atcoder.jp/contests/${contest_name}/tasks/${problem_name//-/_}
fi

if [ ! -f ${problem_name}.out ] ||
  [ ${problem_name}.cc -nt ${problem_name}.out ]; then
  g++-9 -std=c++17 -fsanitize=address,undefined \
    -Wall -W -Werror \
    -g \
    -o ${problem_name}.out \
    ${problem_name}.cc
fi

oj test -c ./${problem_name}.out -d ${test_dir}

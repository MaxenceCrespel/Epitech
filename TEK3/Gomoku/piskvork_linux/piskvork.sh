#!/bin/bash

rm -f piskvork_pipe
mkfifo piskvork_pipe

./piskvork/linux-piskvork "$@" < piskvork_pipe | ./pbrain-gomoku-ai 1> piskvork_pipe
rm piskvork_pipe

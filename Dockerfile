FROM alpine

RUN apk add --no-cache g++ cmake make git && \
    git clone --depth=1 -q https://github.com/google/googletest.git /var/tmp/googletest && \
    mkdir /var/tmp/googletest/build && \
    cd /var/tmp/googletest/build && \
    cmake .. && make && make install

WORKDIR /home/aoc2023

COPY ./ ./

RUN g++ -o main main.cpp tests/*.cpp src/*.cpp -lgtest

ENTRYPOINT ["./main"]

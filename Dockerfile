FROM debian:buster

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && apt-get -y install --no-install-recommends \
    build-essential \
    cmake \
    gdb \
    valgrind

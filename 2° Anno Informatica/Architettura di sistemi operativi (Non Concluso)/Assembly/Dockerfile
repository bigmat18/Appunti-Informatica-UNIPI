### start from current ubuntu image
FROM ubuntu:latest
MAINTAINER marcod
### install base programming tools
RUN apt update
RUN apt install -y vim nano gcc-arm-linux-gnueabihf qemu-user gdb-multiarch make
### set up service ssh and net tools
RUN apt install -y ssh openssh-server net-tools
RUN service ssh start
### fix user
RUN useradd -ms /bin/bash aeso2022
### da rimettere a posto alla fine
USER aeso2022
WORKDIR /home/aeso2022
RUN mkdir /home/aeso2022/target

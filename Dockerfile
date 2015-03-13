FROM phusion/baseimage:0.9.16

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y build-essential

ADD . /csc1253

WORKDIR /csc1253

RUN g++ -o prog1/prog1 prog1/prog1.cpp
RUN g++ -o prog2/prog2 prog2/prog2.cpp
RUN g++ -o prog3/prog3 prog3/prog3.cpp
RUN g++ -o prog4/prog4 prog4/prog4.cpp
RUN g++ -o prog5/prog5 prog5/prog5.cpp
RUN g++ -o prog6/prog6 prog6/prog6.cpp
RUN g++ -o prog7/prog7 prog7/prog7.cpp
RUN g++ -o prog8/prog8 prog8/prog8.cpp

ENTRYPOINT ["/bin/bash"]

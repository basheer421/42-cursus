FROM basheer421/valgrind_debian:v1
RUN apt-get update && apt-get -y upgrade && mkdir -m 666 /project
COPY . /project
WORKDIR /project
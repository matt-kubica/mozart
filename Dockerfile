FROM gcc:latest

COPY . /usr/src/app
WORKDIR /usr/src/app

RUN apt -y update
RUN apt -y install flex bison

RUN make build
CMD ["make", "run"]
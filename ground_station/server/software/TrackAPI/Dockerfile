FROM golang

ADD . /sct
WORKDIR /sct
RUN go get -d . ...
RUN apt-get update
RUN apt-get install -y build-essential

RUN make
ENTRYPOINT ./server
EXPOSE 9200

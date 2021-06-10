### Running language shell using Docker

In order to run application using docker, 
after applying any changes to source code or in case of first usage,
image needs to be build using command below.
```bash
docker build . -t mozart-lang
```
Running container will start language shell instantly.
```bash
docker run -it --rm --name mozart mozart-lang 
```

### Running language shell using `make`
On Unix-like systems, language shell can be build and executed using make.
```bash
make build
make run
make clean
```
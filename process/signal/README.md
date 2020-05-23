# 使用方法
```
make
./_main

```

# sigreceive
运行sigreceive signo &，可获得该进程的ID，假设为pid，然后再另一终端上运行kill -s signo pid验证信号的发送接收及处理。
同时，可验证信号的排队问题。
$ sigreceive 10 or 36
$ kill -s 10 or 36 pid

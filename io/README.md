#### 理解page cache对程序速度影响
    $ sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'
    $ time python hello.py 
    Hello World! Love, Python

    real	0m0.142s
    user	0m0.000s
    sys	0m0.020s
    
    $ time python hello.py
    ...
    real	0m0.018s
    ...
    # 两次时间差很大！

#### 理解mmap
    $ gcc mmap.c
    $ ./a.out 
    print "Hello World! Love, Python"

#### 符号链接硬链接
$ touch a.txt
$ ln a.txt b.txt
$ ln -li
$ ln -s a.txt c.txt
$ ln -li

#### 模拟文件一致性问题
1. create image and format
$ dd if=/dev/zero of=image bs=4096 count=1024
$ mkfs.ext4 -b 4096 image 

2. chech block bitmap and inode bitmap
$ dumpe2fs image

3. read inode bitmap
$ dd if=image bs=4096 skip=18 | hexdump -C -n 32

4. mount image, create a file, and check its inode
$ mkdir aaa
$ mount -o loop image aaa
$ cd aaa
$ touch hello.txt
$ ls -li hello.txt

5. umount image, and check inode bitmap
$ umount aaa
$ dd if=image bs=4096 skip=18 | hexdump -C -n 32

6. modify inode bitmap (destroy)
$ vim -b image
%!xxd -g 1
%!xxd -r
$ dd if=image bs=4096 skip=18 | hexdump -C -n 32

fsck can not idenify this error.
$ fsck.ext4 image

but file "hello.txt" still exists.
$ mount -o loop image aaa
$ cd aaa
$ ls -li

!!!!!! but this FS still work normally

7. create new file
$ touch bye.txt
IO error will happen!!

#### debugfs
$ sudo debugfs -R 'stat /home/qiaoweir/fork1.c' /dev/sda1
$ sudo dd if=/dev/sda1 of=1 skip=$((563005*8)) bs=512 count=1
$ sudo debugfs -R 'icheck block_num' /dev/sda1 //通过block号查看inode号
$ sudo debugfs -R 'ncheck inode_num' /dev/sda1 //通过inode号查看文件路径


